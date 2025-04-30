/*
   @Sketch: Robot_App_IoT.ino
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
bool adelante = 0;
bool atras = 0;
bool izquierda = 0;
bool derecha = 0;
bool _walk_Forward = 0;
bool _walk_Backward = 0;
bool _turn_Right = 0;
bool _turn_Left = 0;
unsigned int selector = 0;
bool enable = 1;
int velocidad = 5;
// Crear un arreglo de mensajes aleatorios
const char* mensajes[] = {
  "Hola soy ESP32Biped ESP32",
  "¡Saludos desde ESP32Biped!",
  "¡Toque recibido!",
  "Bienvenido al mundo de ESP32Biped",
  "ESP32Biped te saluda con un toque"
};
//-------------------------------------------------//

//----------------------Objeto---------------------//
Robot_IoT ESP32Biped;
BlynkTimer Timer_Biped;
BlynkTimer Timer_Ultrasonido;
BlynkTimer Timer_Touch;
BlynkTimer Timer_Bateria;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Configurar la comunicación serial a 9600 baudios
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

  Timer_Biped.setInterval(1, program_Biped);
  Timer_Ultrasonido.setInterval(60000, program_distance);
  Timer_Touch.setInterval(10, program_touch);
  Timer_Bateria.setInterval(70000, program_Bateria);
  //-------------------------------------------------//
}

void loop() {
  //-------------------------------------------------//
  //Conexión activa del ESP32 con el servidor Blynk
  Blynk.run();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Inicicar el timer
  Timer_Biped.run();
  Timer_Ultrasonido.run();
  Timer_Touch.run();
  Timer_Bateria.run();
  //-------------------------------------------------//
}

//-------------------------------------------------//
//Función donde Notifica cuando el dispositivo, como un ESP32, se ha conectado correctamente al servidor de Blynk
BLYNK_CONNECTED() {
  //Blynk actualiza el valor actual del pin virtual V0, V1 cuando se conecte al servidor de Blynk
  Blynk.syncVirtual(V0, V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13);
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
BLYNK_WRITE(V10) {
  adelante = param.asInt();
}
//-------------------------------------------------//

//-------------------------------------------------//
BLYNK_WRITE(V11) {
  atras = param.asInt();
}
//-------------------------------------------------//

//-------------------------------------------------//
BLYNK_WRITE(V12) {
  izquierda = param.asInt();
}
//-------------------------------------------------//

//-------------------------------------------------//
BLYNK_WRITE(V13) {
  derecha = param.asInt();
}
//-------------------------------------------------//

//-------------------------------------------------//
BLYNK_WRITE(V14) {
  velocidad = param.asInt();
}
//-------------------------------------------------//

//-------------------------------------------------//
void program_Biped() {
  //-------------------------------------------------//
  if (adelante) {
    ESP32Biped.walk_Forward(velocidad);
    _walk_Forward = 1;
  } else {
    if (_walk_Forward) {
      ESP32Biped.standby_Mode();
      _walk_Forward = 0;
    }
  }
  //-------------------------------------------------//

  //-------------------------------------------------//
  if (atras) {
    ESP32Biped.walk_Backward(velocidad);
    _walk_Backward = 1;
  } else {
    if (_walk_Backward) {
      ESP32Biped.standby_Mode();
      _walk_Backward = 0;
    }
  }
  //-------------------------------------------------//

  //-------------------------------------------------//
  if (derecha) {
    ESP32Biped.turn_Right(velocidad);
    _turn_Right = 1;
  } else {
    if (_turn_Right) {
      ESP32Biped.standby_Mode();
      _turn_Right = 0;
    }
  }
  //-------------------------------------------------//

  //-------------------------------------------------//
  if (izquierda) {
    ESP32Biped.turn_Left(velocidad);
    _turn_Left = 1;
  } else {
    if (_turn_Left) {
      ESP32Biped.standby_Mode();
      _turn_Left = 0;
    }
  }
  //-------------------------------------------------//
}
//-------------------------------------------------//
void program_distance() {
  Blynk.virtualWrite(V7, ESP32Biped.ultrasound());
}

void program_touch() {
  if (ESP32Biped.touch(50) && (enable == 1)) {
    // Generar un índice aleatorio para elegir un mensaje
    int indice = random(0, 5);  // Selecciona un índice aleatorio entre 0 y 4
    Blynk.virtualWrite(V8, mensajes[indice]);
    // Desactivar la variable enable para evitar que el mensaje se repita
    enable = 0;
  } else {
    // Si el toque ya fue detectado y el mensaje fue enviado, restablecer enable
    enable = 1;
  }
}
void program_Bateria() {
  Blynk.virtualWrite(V9, ESP32Biped.battery(2.8358));
}
