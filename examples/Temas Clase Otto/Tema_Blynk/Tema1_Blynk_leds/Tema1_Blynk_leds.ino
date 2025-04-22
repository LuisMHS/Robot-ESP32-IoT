/*
   @Sketch: Tema1_Robot_Leds.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------Firmware configuration--------------//
#define BLYNK_TEMPLATE_ID "TMPL27ZDCDaTq"
#define BLYNK_TEMPLATE_NAME "Biped ESP32 IoT
#define BLYNK_AUTH_TOKEN "LWZ0MJLMnob92ZVSZB8WJGyl3k198DTD"
//-------------------------------------------------//

//----------------------Header---------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
//Incluir el archivo BlynkSimpleEsp32.h de la librería Blynk
#include <BlynkSimpleEsp32.h>
#include <Robot_IoT.h>
//-------------------------------------------------//

//----------------------Objeto---------------------//
Robot_IoT ESP32Biped;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  // Configurar el robot ESP32Biped
  ESP32Biped.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Conectar a Blynk con SSID y Contraseña de la red Wi-Fi
  Blynk.begin(BLYNK_AUTH_TOKEN, "Taller robotica", ".*89LuisUnivLM");
  //-------------------------------------------------//
  
}

void loop() {
  //-------------------------------------------------//
  //Mantiene la conexión activa del ESP32 con el servidor Blynk
  Blynk.run();
  //-------------------------------------------------//
}

//-------------------------------------------------//
//Función donde Notifica cuando el dispositivo, como un ESP32, se ha conectado correctamente al servidor de Blynk
BLYNK_CONNECTED() {
  //Blynk actualiza el valor actual del pin virtual V0, V1 cuando se conecte al servidor de Blynk
  Blynk.syncVirtual(V0, V1);
}
//-------------------------------------------------//

//-------------------------------------------------//
// Función que se ejecuta cuando hay un cambio en el valor del pin virtual V0
BLYNK_WRITE(V0) {  // Led1 en el lado derecho
  // Encender o apagar el led1 según el valor recibido por el param.asInt()
  ESP32Biped.led1(param.asInt());
}
//-------------------------------------------------//

//-------------------------------------------------//
// Función que se ejecuta cuando hay un cambio en el valor del pin virtual V1
BLYNK_WRITE(V1) {  // Led2 en el lado izquierdo
  // Encender o apagar el led2 según el valor recibido por el param.asInt()
  ESP32Biped.led2(param.asInt());
}
//-------------------------------------------------//

/*servidor de Blynk:
 Encargado de gestionar la comunicación entre la aplicación Blynk, los dispositivos IoT 
 como el ESP32 y la nube*/