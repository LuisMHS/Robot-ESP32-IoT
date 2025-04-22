/*
   @Sketch: Tema7_Completar_Robot_App.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------Firmware configuration--------------//
#define _ _ _ _ _ _ _ _ _ _ "_ _ _ _ _ _ _ _ _"
#define BLYNK_TEMPLATE_NAME "_ _ _ _ _ _ _ _ _"
#define _ _ _ _ _ _ _ _ _ "_ _ _ _ _ _ _ _ _"
//-------------------------------------------------//

//--------------------_-Header---------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
//Incluir el archivo BlynkSimpleEsp32.h de la librería Blynk
#include <_ _ _ _ _ _ _ _ _.h>
#include <_ _ _ _ _ _ _ _ _.h>
//-------------------------------------------------//

//------------------Variable-----------------------//
bool _ _ _ _ _ _ _ _ _ = 0;
bool atras = 0;
bool izquierda = 0;
bool derecha = 0;
bool _ _ _ _ _ _ _ _ _ = 0;
bool walk_Backward = 0;
bool turn_Right = 0;
bool turn_Left = 0;
unsigned int _ _ _ _ _ _ _ _ _ = 0;
bool enable = 1;
int _ _ _ _ _ _ _ _ _ = 5;
// Crear un arreglo de mensajes aleatorios
const char* mensajes[] = {
  "Hola soy ESP32 un robot bipedo",
  _ _ _ _ _ _ _ _ _,
  "¡Toque recibido!",
  "Bienvenido al mundo",
  "ESP32Biped te saluda con un toque"
};
//-------------------------------------------------//

//----------------------Objeto---------------------//
Robot_IoT _ _ _ _ _ _ _ _ _;
BlynkTimer Timer_Robot;
_ _ _ _ _ _ _ _ _ Timer_Ultrasonido;
_ _ _ _ _ _ _ _ _ Timer_Touch;
BlynkTimer Timer_Bateria;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Configurar la PC comunicación serial a 9600 baud
  Serial._ _ _ _ _ _ _ _ _(9600);
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Configurar el robot ESP32Biped
  _ _ _ _ _ _ _ _ _.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Conectarce a Blynk con SSID y Contraseña de la red Wi-Fi
  _ _ _ _ _ _ _ _ _.begin(BLYNK_AUTH_TOKEN, "Taller robotica", ".*89LuisUnivLM");
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Configurar el timer

  Timer_Robot.setInterval(1, program_ESP32Biped);
  Timer_Ultrasonido._ _ _ _ _ _ _ _ _(60000, program_distance);
  Timer_Touch.setInterval(10, program_touch);
  Timer_Bateria.setInterval(70000, program_Bateria);
  //-------------------------------------------------//
}

void loop() {
  //-------------------------------------------------//
  //Conexión activa del ESP32 con el servidor Blynk
  _ _ _ _ _ _ _ _ _.run();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Inicicar el timer
  Timer_Robot.run();
  Timer_Ultrasonido.run();
  Timer_Touch.run();
  Timer_Bateria.run();
  //-------------------------------------------------//
}

//-------------------------------------------------//
//Función donde Notifica cuando el dispositivo, como un ESP32, se ha conectado correctamente al servidor de Blynk
BLYNK_CONNECTED() {
  //Blynk actualiza el valor actual del pin virtual V0, V1 cuando se conecte al servidor de Blynk
  _ _ _ _ _ _ _ _ _.syncVirtual(V0, V1, V2, V3, V4, V5, V6, V7, V8, V9, V10, V11, V12, V13);
}
//-------------------------------------------------//

//-------------------------------------------------//
// Función que se ejecuta cuando hay un cambio en el valor del pin virtual V0
BLYNK_WRITE(V0) {  // Led1 en el lado derecho
  // Encender o apagar el led1 según el valor recibido por el param.asInt()
  _ _ _ _ _ _ _ _ _.led1(param.asInt());
}
//-------------------------------------------------//

//-------------------------------------------------//
// Función que se ejecuta cuando hay un cambio en el valor del pin virtual V1
BLYNK_WRITE(_ _ _ _ _ _ _ _ _) {  // Led2 en el lado izquierdo
  // Encender o apagar el led2 según el valor recibido por el param.asInt()
  _ _ _ _ _ _ _ _ _.led2(param.asInt());
}
//-------------------------------------------------//

//-------------------------------------------------//
// Función que se ejecuta cuando hay un cambio en el valor del pin virtual V2
BLYNK_WRITE(V2) {  // Pierna izquierda
  // Obtener el valor numérico del pin virtual V2 con param.asInt()
  // Asignar el valor obtenido a la función angle_LeftLeg para mover el ángulo de la pierna izquierda
  _ _ _ _ _ _ _ _ _.angle_LeftLeg(param.asInt());
  // Serial.println(param.asInt());
}
//-------------------------------------------------//

//-------------------------------------------------//
//Función que se ejecuta cuando hay un cambio en el valor de un pin virtual V3
BLYNK_WRITE(V3) {  //Pierna derecha
  // Obtener el valor numérico del pin virtual V3 con param.asInt()
  // Asignar el valor obtenido a la función angle_RightLeg para mover el ángulo de la pierna derecha
  _ _ _ _ _ _ _ _ _.angle_RightLeg(param.asInt());
}
//-------------------------------------------------//

//-------------------------------------------------//
//Función que se ejecuta cuando hay un cambio en el valor de un pin virtual V4
BLYNK_WRITE(V4) {  //Pie Izquierdo
  // Obtener el valor numérico del pin virtual V4 con param.asInt()
  // Asignar el valor obtenido a la función angle_LegFoot para mover el ángulo de la pie izquierda
  _ _ _ _ _ _ _ _ _.angle_LeftFoot(param.asInt());
}
//-------------------------------------------------//

//-------------------------------------------------//
//Función que se ejecuta cuando hay un cambio en el valor de un pin virtual V5
BLYNK_WRITE(V5) {  //Pie Derecho
  // Obtener el valor numérico del pin virtual V5 con param.asInt()
  // Asignar el valor obtenido a la función angle_LegFoot para mover el ángulo de la pie derecho
  _ _ _ _ _ _ _ _ _.angle_RightFoot(param.asInt());
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
      _ _ _ _ _ _ _ _ _.sound_Disconnection();  //Sonido de desconexión
      break;                                    //Salir del caso '0' y evaluar la siguiente variable selector
    case 1:
      _ _ _ _ _ _ _ _ _.sound_Connection();  //Sonido de conexión
      break;
    case 2:
      _ _ _ _ _ _ _ _ _.sound_Happy_Birthday();  //Sonido de feliz cumpleaños
      break;
    case 3:
      _ _ _ _ _ _ _ _ _.sound_Christmas_Music();  //Sonido de Navidad
      break;
    case 4:
      _ _ _ _ _ _ _ _ _.sound_Star_Wars();  //Sonido de guerra de galaxias
      break;
    case 5:
      _ _ _ _ _ _ _ _ _.sound_Dance();  //Sonido de Dance
      break;
    case 6:
      _ _ _ _ _ _ _ _ _.sound_Happy();  //Sonido de felicidad
      break;
    case 7:
      _ _ _ _ _ _ _ _ _.sound_BillieJean();  //Sonido de BillieJean
      break;
    case 8:
      _ _ _ _ _ _ _ _ _.sound_Conquest_of_Paradise();  //Sonido de Conquest of Paradise
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
  atras = _ _ _ _ _ _ _ _ _;
}
//-------------------------------------------------//

//-------------------------------------------------//
BLYNK_WRITE(V12) {
  izquierda = param.asInt();
}
//-------------------------------------------------//

//-------------------------------------------------//
BLYNK_WRITE(V13) {
  derecha = _ _ _ _ _ _ _ _ _;
}
//-------------------------------------------------//

//-------------------------------------------------//
BLYNK_WRITE(V14) {
  velocidad = param.asInt();
}
//-------------------------------------------------//

//-------------------------------------------------//
void program_ESP32Biped() {
  //-------------------------------------------------//
  if (adelante) {
    _ _ _ _ _ _ _ _ _.walk_Forward(velocidad);
    walk_Forward = 1;
  } else {
    if (walk_Forward) {
      _ _ _ _ _ _ _ _ _.standby_Mode();
      walk_Forward = 0;
    }
  }
  //-------------------------------------------------//

  //-------------------------------------------------//
  if (atras) {
    _ _ _ _ _ _ _ _ _.walk_Backward(velocidad);
    walk_Backward = 1;
  } else {
    if (walk_Backward) {
      _ _ _ _ _ _ _ _ _.standby_Mode();
      walk_Backward = 0;
    }
  }
  //-------------------------------------------------//

  //-------------------------------------------------//
  if (derecha) {
    _ _ _ _ _ _ _ _ _.turn_Right(velocidad);
    turn_Right = 1;
  } else {
    if (turn_Right) {
      _ _ _ _ _ _ _ _ _.standby_Mode();
      turn_Right = 0;
    }
  }
  //-------------------------------------------------//

  //-------------------------------------------------//
  if (izquierda) {
    _ _ _ _ _ _ _ _ _.turn_Left(velocidad);
    turn_Left = 1;
  } else {
    if (turn_Left) {
      _ _ _ _ _ _ _ _ _.standby_Mode();
      turn_Left = 0;
    }
  }
  //-------------------------------------------------//
}
//-------------------------------------------------//
void program_distance() {
  _ _ _ _ _ _ _ _ _.virtualWrite(V7, _ _ _ _ _ _ _ _ _.ultrasound());
}

void program_touch() {
  if (_ _ _ _ _ _ _ _ _.touch(50) && enable == 1) {
    // Generar un índice aleatorio para elegir un mensaje
    int indice = random(0, 5);  // Selecciona un índice aleatorio entre 0 y 4
    _ _ _ _ _ _ _ _ _.virtualWrite(V8, mensajes[indice]);
    // Desactivar la variable enable para evitar que el mensaje se repita
    enable = 0;
  } else {
    // Si el toque ya fue detectado y el mensaje fue enviado, restablecer enable
    enable = 1;
  }
}
void program_Bateria() {
  _ _ _ _ _ _ _ _ _.virtualWrite(V9, _ _ _ _ _ _ _ _ _.battery(2.8358));
}
