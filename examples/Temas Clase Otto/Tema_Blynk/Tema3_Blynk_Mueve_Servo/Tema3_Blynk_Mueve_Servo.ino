/*
   @Sketch: Tema3_Robot_Mueve_Servo.ino
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
  //Blynk actualiza el valor actual del pin virtual V2, V3, V4, V5 cuando se conecte al servidor de Blynk
  Blynk.syncVirtual(V2, V3, V4, V5);
}
//-------------------------------------------------//

//-------------------------------------------------//
// Función que se ejecuta cuando hay un cambio en el valor del pin virtual V2
BLYNK_WRITE(V2) {  // Pierna izquierda
  // Obtener el valor numérico del pin virtual V2 con param.asInt()
  // Asignar el valor obtenido a la función angle_LeftLeg para mover el ángulo de la pierna izquierda
  ESP32Biped.angle_LeftLeg(param.asInt());
  // Serial.println(param.asInt());
}
//-------------------------------------------------//

//-------------------------------------------------//
//Función que se ejecuta cuando hay un cambio en el valor de un pin virtual V3
BLYNK_WRITE(V3) {  //Pierna derecha
  // Obtener el valor numérico del pin virtual V3 con param.asInt()
  // Asignar el valor obtenido a la función angle_RightLeg para mover el ángulo de la pierna derecha
  ESP32Biped.angle_RightLeg(param.asInt());
}
//-------------------------------------------------//

//-------------------------------------------------//
//Función que se ejecuta cuando hay un cambio en el valor de un pin virtual V4
BLYNK_WRITE(V4) {  //Pie Izquierdo
  // Obtener el valor numérico del pin virtual V4 con param.asInt()
  // Asignar el valor obtenido a la función angle_LegFoot para mover el ángulo de la pie izquierda
  ESP32Biped.angle_LeftFoot(param.asInt());
}
//-------------------------------------------------//

//-------------------------------------------------//
//Función que se ejecuta cuando hay un cambio en el valor de un pin virtual V5
BLYNK_WRITE(V5) {  //Pie Derecho
  // Obtener el valor numérico del pin virtual V5 con param.asInt()
  // Asignar el valor obtenido a la función angle_LegFoot para mover el ángulo de la pie derecho
  ESP32Biped.angle_RightFoot(param.asInt());
}
//-------------------------------------------------//
