/*
   @Sketch: Tema4_Robot_Touch.ino
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

//-----------------Variable------------------------//
unsigned long t = 0;
unsigned long tp = 0;
unsigned long ta = 0;
bool touch;
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
  //Configurar la PC comunicación serial a 9600 baud
  Serial.begin(9600);
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Conectarce a Blynk con SSID y Contraseña de la red Wi-Fi
  Blynk.begin(BLYNK_AUTH_TOKEN, "Taller robotica", ".*89LuisUnivLM");
  //-------------------------------------------------//

  //-------------------------------------------------//
  tp = millis();  //medicion del tiempo pasado
  //-------------------------------------------------//
}

void loop() {

  //-------------------------------------------------//
  //Mantiene la conexión activa del ESP32 con el servidor Blynk
  Blynk.run();
  //-------------------------------------------------//

  ta = millis();     //lectura del tiempo actual
  t = (ta - tp);     //tiempo transcurrido
  if (t >= 40000) {  //Medir el touch cada 40000ms
    Serial.println(ESP32Biped.touch_Read());
    Blynk.virtualWrite(V8, ESP32Biped.touch_Read());
    tp = ta;  //Actualizar el tiempo pasado con el tiempo actual
  }
}
//-------------------------------------------------//
//Función donde Notifica cuando el dispositivo, como un ESP32, se ha conectado correctamente al servidor de Blynk
BLYNK_CONNECTED() {
  //Blynk actualiza el valor actual del pin virtual V8 cuando se conecte al servidor de Blynk
  Blynk.syncVirtual(V8);
}
//-------------------------------------------------//
