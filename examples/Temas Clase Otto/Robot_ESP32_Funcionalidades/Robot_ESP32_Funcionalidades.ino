// --- PINES DE CONEXIÓN CON EL ROBOT ESP32 IOT --- //
// ------------------------------------------------ //

/***********************************************
 * Left Leg Servo  = TX2 --> 17 
 * Right Leg Servo = D18 --> 18 
 * Left Foot Servo = RX2 --> 16 
 * Right Foot Servo= D5  --> 5 
 * Trig            = D27 --> 27  
 * Echo            = D26 --> 26 
 * LED1 Right      = D12 --> 12 
 * LED2 Left       = D13 --> 13  
 * Batery          = D35 --> 35  
 * Touch           = D4  --> 4  
 * Buzzer          = D14 --> 14 
 **********************************************/

/******************Header**********************/
#include <Robot_IoT.h>
/**********************************************/

/*******************Objeto*********************/
Robot_IoT ESP32Biped;
/**********************************************/

void setup() {
  /*******Configurar el robot ESP32Biped*********/
  ESP32Biped.begin();
  /**********************************************/
}

void loop() {
  /**********************************************/
  ESP32Biped.standby_Mode();
  // ESP32Biped, entra en modo de espera y quédate parado.
  /**********************************************/
  ESP32Biped.angle_LeftLeg(90);
  // ESP32Biped, mueve la pierna izquierda a un ángulo de 90°.
  /**********************************************/
  ESP32Biped.angle_RightLeg(90);
  // ESP32Biped, mueve la pierna derecha a un ángulo de 90°.
  /**********************************************/
  ESP32Biped.angle_LeftFoot(90);
  // ESP32Biped, mueve el pie izquierdo a un ángulo de 90°.
  /**********************************************/
  ESP32Biped.angle_RightFoot(90);
  // ESP32Biped, mueve el pie derecho a un ángulo de 90°.
  /**********************************************/
  ESP32Biped.ultrasound();
  // ESP32Biped, mide la distancia en centímetros.
  /**********************************************/
  ESP32Biped.touch_Read();
  // ESP32Biped, mide el valor numérico cuando tocas el pin D4 del ESP32 con los dedos.
  /**********************************************/
  ESP32Biped.touch(75);
  // ESP32Biped, detecta el contacto en el pin táctil D4 del ESP32 y envía 1 si se toca y 0 si no hay contacto.
  /**********************************************/
  ESP32Biped.led1(1);
  // ESP32Biped, enciende el led1 del lado derecho al recibir 1 y apágalo al recibir 0.
  /**********************************************/
  ESP32Biped.led2(0);
  // ESP32Biped, enciende el led2 del lado izquierdo al recibir 1 y apágalo al recibir 0.
  /**********************************************/
  ESP32Biped.save_Angle();
  // ESP32Biped, guarda los ángulos en la memoria flash de la ESP32.
  /**********************************************/
  ESP32Biped.walk_Forward(3);
  // ESP32Biped, camina hacia adelante a un ritmo de 3ms.
  /**********************************************/
  ESP32Biped.walk_Backward(3);
  // ESP32Biped, camina hacia atrás a un ritmo de 3ms.
  /**********************************************/
  ESP32Biped.turn_Left(3);
  // ESP32Biped, gira hacia la izquierda a un ritmo de 3ms.
  /**********************************************/
  ESP32Biped.turn_Right(3);
  // ESP32Biped, gira hacia la derecha a un ritmo de 3ms.
  /**********************************************/
  ESP32Biped.battery(3.2258);
  // ESP32Biped, mide el porcentaje de tu batería.
  /**********************************************/
  ESP32Biped.voltage_Read();
  // ESP32Biped, mide el voltaje en el pin D35.
  // Nota: El rango de lectura de voltaje es de 0 a 3.3V.
  /**********************************************/
  ESP32Biped.move_Servos(90, 90, 90, 90);
  // ESP32Biped, mueve la pierna izquierda, la pierna derecha, el pie izquierdo y el pie derecho a un ángulo de 90°.
  /**********************************************/
  ESP32Biped.attach_ms(40000, distancia);
  // ESP32Biped, configura tu temporizador a 40000 milisegundos para ejecutar la funcionalidad "distancia"
  // Nota: Puedes ejecutar cualquier otra funcionalidad asignándole un nombre distinto a "distancia".
  /**********************************************/
  ESP32Biped.detach();
  // ESP32Biped, desactiva tu temporizador (por ejemplo, el temporizador "distancia" que ha sido previamente configurado).
  /**********************************************/
  ESP32Biped.note("Sol", 500);
  // ESP32Biped, Reproduce una nota musical Sol en la cuarta octava (Sol4) con una duración de 500ms.
  // para las 7 octavas completas, se escribe asi: (de La0 a Do8).
  // Nota: Las notas musicales de la cuarta octava se representan con nombres (Do, RE, Mi, Fa, Sol, La, Si).
  // Se omite el número 4 porque se asume que todas las notas hacen referencia a la cuarta octava.
  /**********************************************/
  /**********************************************/
  /**********************************************/
  ESP32Biped.sound_Connection();
  // ESP32Biped, Reproduce un sonido de conexión.
  /**********************************************/
  ESP32Biped.sound_Disconnection();
  // ESP32Biped, Reproduce un sonido de desconexíon
  /**********************************************/
  ESP32Biped.sound_Happy_Birthday();
  // ESP32Biped, Reproduce un sonido de feliz cumpleaños
  /**********************************************/
  ESP32Biped.sound_Noche_paz();
  // ESP32Biped, Reproduce un sonido de noche de paz.
  /**********************************************/
  ESP32Biped.sound_Christmas_Music();
  // ESP32Biped, Reproduce un sonido navideño.
  /**********************************************/
  ESP32Biped.sound_BillieJean();
  // ESP32Biped, Reproduce un sonido inspirado en la canción "Billie Jean" de Michael Jackson.
  /**********************************************/
  ESP32Biped.sound_Dance();
  // ESP32Biped, Reproduce un sonido alegre y rítmico.
  /**********************************************/
  ESP32Biped.sound_Greeting();
  // ESP32Biped, Reproduce un sonido como un saludo o bienvenida.
  /**********************************************/
  ESP32Biped.sound_Happy();
  // ESP32Biped, Reproduce un sonido que expresa felicidad o alegría.
  /**********************************************/
  ESP32Biped.sound_Sad();
  // ESP32Biped, Reproduce un sonido que transmite tristeza o melancolía.
  /**********************************************/
  ESP32Biped.sound_Surprise();
  // ESP32Biped, Reproduce un sonido que expresa sorpresa o asombro.
  /**********************************************/
  ESP32Biped.sound_Angry();
  // ESP32Biped, Reproduce un sonido que refleja enojo o irritación.
  /**********************************************/
  ESP32Biped.sound_Fear();
  // ESP32Biped, Reproduce un sonido que transmite miedo.
  /**********************************************/
  ESP32Biped.sound_Love();
  // ESP32Biped, Reproduce un sonido que expresa amor.
  /**********************************************/
  ESP32Biped.sound_Happ();
  // ESP32Biped, Reproduce un sonido alegre.
  /**********************************************/
  ESP32Biped.sound_Conquest_of_Paradise();
  // ESP32Biped, Reproduce un sonido inspirado en la famosa melodía "Conquest of Paradise" de Vangelis.
  /**********************************************/
}
/**********************************************/
//Funcion distancia para monitoriar el sensor ultrasonido HC-RS04 cada 60segundos
void distancia() {
  ESP32Biped.ultrasound();
}
/**********************************************/