/*
   @Sketch: Tema2_Robot_Monitorea_Distancia.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------Firmware configuration--------------//
#define BLYNK_TEMPLATE_ID "TMPL27ZDCDaTq"
#define BLYNK_TEMPLATE_NAME "Biped ESP32 IoT"
#define BLYNK_AUTH_TOKEN "LWZ0MJLMnob92ZVSZB8WJGyl3k198DTD"
//-------------------------------------------------//

//----------------------Header---------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
//Incluir el archivo BlynkSimpleEsp32.h de la librería Blynk
#include <BlynkSimpleEsp32.h>
#include <Robot_IoT.h>
//-------------------------------------------------//

//---------------------Variable--------------------//
float distancia;
//-------------------------------------------------//

//----------------------Objeto---------------------//
Robot_IoT ESP32Biped;
BlynkTimer timer;
//-------------------------------------------------//
void setup() {
  //-------------------------------------------------//
  // Configurar el robot ESP32Biped
  ESP32Biped.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Conectar a Blynk con SSID y Contraseña de la red Wi-Fi
  Blynk.begin(BLYNK_AUTH_TOKEN, "Taller robotica", ".*89LuisUnivLM");
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Configurar el timer cada 60000ms para que se ejecute la funcion program_Ultrasound
  timer.setInterval(60000, program_Ultrasound);
  //-------------------------------------------------//
}

void loop() {
  //-------------------------------------------------//
  //Mantiene la conexión activa del ESP32 con el servidor Blynk
  Blynk.run();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Iniciar el temporizador cada 60000ms previamente configurado
  timer.run();
  //-------------------------------------------------//
}

//-------------------------------------------------//
//Función donde Notifica cuando el dispositivo, como un ESP32, se ha conectado correctamente al servidor de Blynk
BLYNK_CONNECTED() {
  //Blynk actualiza el valor actual del pin virtual V7 cuando se conecte al servidor de Blynk
  Blynk.syncVirtual(V7);
}
//-------------------------------------------------//

//-------------------------------------------------//
void program_Ultrasound() {            //Programa que se ejecutara cada 60000ms
  distancia = ESP32Biped.ultrasound();  //Obtener el valor numerico al medir la distancia
  Blynk.virtualWrite(V7, distancia);   //Enviar la distancia al servidor de Blynk
}
//-------------------------------------------------//