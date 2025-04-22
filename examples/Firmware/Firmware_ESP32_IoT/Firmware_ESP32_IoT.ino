/*
   @Sketch: Firmware_ESP32_IoT.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------Firmware configuration--------------//
#define BLYNK_TEMPLATE_ID "TMPL2r7IFosMh"
#define BLYNK_TEMPLATE_NAME "Firmware Robot"
#define BLYNK_AUTH_TOKEN "7K-YYk2PXU8FlewMRREr3nSI0zzJx_0F"
//-------------------------------------------------//

//----------------------Header---------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
//Incluir el archivo BlynkSimpleEsp32.h de la librería Blynk
#include <BlynkSimpleEsp32.h>
#include <Robot_IoT.h>
//-------------------------------------------------//

//------------------Variable-----------------------//
unsigned int selector = 0;
//-------------------------------------------------//

//----------------------Objeto---------------------//
Robot_IoT ESP32Biped;
BlynkTimer Timer_Ultrasonido;
BlynkTimer Timer_Touch;
BlynkTimer Timer_Voltaje;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Configurar la PC comunicación serial a 9600 baud
  Serial.begin(9600);
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Configurar el robot ESP32Biped
  ESP32Biped.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Conectarce a Blynk con SSID y Contraseña de la red Wi-Fi
  Blynk.begin(BLYNK_AUTH_TOKEN, "Taller robotica", ".*89LuisUnivLM");
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Configurar el timer
  Timer_Ultrasonido.setInterval(70000, program_distance);
  Timer_Touch.setInterval(70000, program_touch);
  Timer_Voltaje.setInterval(70000, program_Voltaje);
  //-------------------------------------------------//
}

void loop() {
  //-------------------------------------------------//
  //Conexión activa del ESP32 con el servidor Blynk
  Blynk.run();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Inicicar el timer
  Timer_Ultrasonido.run();
  Timer_Touch.run();
  Timer_Voltaje.run();
  //-------------------------------------------------//
}

//-------------------------------------------------//
//Función donde Notifica cuando el dispositivo, como un ESP32, se ha conectado correctamente al servidor de Blynk
BLYNK_CONNECTED() {
  //Blynk actualiza el valor actual del pin virtual V0, V1 cuando se conecte al servidor de Blynk
  Blynk.syncVirtual(V0, V1, V2, V3, V4, V5, V6, V7, V8, V9);
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

//-------------------------------------------------//
// Función que se ejecuta cuando hay un cambio en el valor del pin virtual V6
BLYNK_WRITE(V6) {  // selector
  selector = param.asInt();
  // Serial.println(param.asInt());
  //-------------------------------------------------//
  // Si selector toma un carácter desde '0' a '8', ejecutar el caso elegido con switch
  switch (selector) {
    case 0:
      ESP32Biped.sound_Disconnection();  //Sonido de desconexión
      break;                             //Salir del caso '0' y evaluar la siguiente variable selector
    case 1:
      ESP32Biped.sound_Connection();  //Sonido de conexión
      break;
    case 2:
      ESP32Biped.sound_Happy_Birthday();  //Sonido de feliz cumpleaños
      break;
    case 3:
      ESP32Biped.sound_Christmas_Music();  //Sonido de Navidad
      break;
    case 4:
      ESP32Biped.sound_Star_Wars();  //Sonido de guerra de galaxias
      break;
    case 5:
      ESP32Biped.sound_Dance();  //Sonido de Dance
      break;
    case 6:
      ESP32Biped.sound_Happy();  //Sonido de felicidad
      break;
    case 7:
      ESP32Biped.sound_BillieJean();  //Sonido de BillieJean
      break;
    case 8:
      ESP32Biped.sound_Conquest_of_Paradise();  //Sonido de Conquest of Paradise
      break;
    default:
      break;
  }
}
//-------------------------------------------------//
//-------------------------------------------------//
//Función que se ejecuta cuando hay un cambio en el valor de un pin virtual V11
BLYNK_WRITE(V11) {  //Guardar ángulo
  if (param.asInt()) {
    ESP32Biped.save_Angle();
    Blynk.virtualWrite(V11, 0);
  }
}
//-------------------------------------------------//


//-------------------------------------------------//
void program_distance() {
  Blynk.virtualWrite(V7, ESP32Biped.ultrasound());
}
void program_touch() {
  Blynk.virtualWrite(V8, ESP32Biped.touch_Read());
}
void program_Voltaje() {
  Blynk.virtualWrite(V9, ESP32Biped.voltage_Read());
}