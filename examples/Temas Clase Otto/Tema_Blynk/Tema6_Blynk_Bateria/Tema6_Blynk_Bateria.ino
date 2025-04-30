/*
   @Sketch: Tema6_Robot_Bateria.ino
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

//----------------------Objeto---------------------//
Robot_IoT ESP32Biped;
Ticker Timer_Bateria;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Configurar  la comunicación Serial a 9600 baudios
  Serial.begin(9600);
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Configurar el robot ESP32Biped
  ESP32Biped.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Conectar a Blynk con SSID y Contraseña de la red Wi-Fi
  Blynk.begin(BLYNK_AUTH_TOKEN, "Taller robotica", ".*89LuisUnivLM");
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Configurar el timer a 60000ms
  Timer_Bateria.attach_ms(60000, program_Battery);
  //-------------------------------------------------//
}

void loop() {
}
//-------------------------------------------------//
//Función donde Notifica cuando el dispositivo, como un ESP32, se ha conectado correctamente al servidor de Blynk
BLYNK_CONNECTED() {
  //Blynk actualiza el valor actual del pin virtual V9,V14 cuando se conecte al servidor de Blynk
  Blynk.syncVirtual(V9, V14);
}
//-------------------------------------------------//

void program_Battery() {

  Serial.print("Voltaje batería=");
  Serial.println(ESP32Biped.voltage_Read());
  Blynk.virtualWrite(V16, ESP32Biped.voltage_Read());

  Serial.print("Nivel de batería=");
  Serial.println(ESP32Biped.battery(2.8358));
  Blynk.virtualWrite(V9, ESP32Biped.battery(2.8358));
}
