/*
   @Sketch: Tema5_Robot_Sonido_Musicales.ino
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

//------------------Variable-----------------------//
int selector = 0;
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

//-------------------------------------------------//
//Función donde Notifica cuando el dispositivo, como un ESP32, se ha conectado correctamente al servidor de Blynk
BLYNK_CONNECTED() {
  //Blynk actualiza el valor actual del pin virtual V6 cuando se conecte al servidor de Blynk
  Blynk.syncVirtual(V6);
}
//-------------------------------------------------//

//-------------------------------------------------//
// Función que se ejecuta cuando hay un cambio en el valor del pin virtual V0
BLYNK_WRITE(V6) {  // Selector
                   // Obtener el valor numérico del pin virtual V6 con param.asInt()
                   // Asignar el valor obtenido a la variable selector para selecionar el sonido que desea escuchar
  selector = param.asInt();
  // Serial.println(param.asInt());
  //-------------------------------------------------//
  // Si selector toma un carácter desde '0' a '8', ejecutar el caso elegido con switch
  switch (selector) {
    case 0:
      ESP32Biped.sound_Disconnection();  //Sonido de desconexión
      break;                            //Salir del caso '0' y evaluar la siguiente variable selector
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
      ESP32Biped.sound_Star_Wars();  //Sonido de desconexión
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