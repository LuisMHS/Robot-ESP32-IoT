/*
   @Sketch: Tema2_millis_LEDs.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------------------------------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//

//-------------------------------------------------//
//Creación de variables globales
unsigned long tp = 0;  //Tiempo pasado Rango: 0 a 4,294,967,295
unsigned long ta = 0;  //Tiempo actual
unsigned long t = 0;   //Tiempo trasncurrido
int tiempo = 450;      //tiempo de 450ms
bool state = false;
//-------------------------------------------------//

//-------------------------------------------------//
//Creación de un Objeto
Robot_IoT ESP32Biped;
//-------------------------------------------------//

void setup() {  //Función que se ejecutara una sola vez
  //-------------------------------------------------//
  //Inicializar el ESP32Biped
  ESP32Biped.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Inicializar la comunicación con el Monitor Serie del software del Arduino a 9600 bits por segundo
  Serial.begin(9600);
  //-------------------------------------------------//
  //Medición del tiempo pasado
  tp = millis();
  //-------------------------------------------------//
}

void loop() {  //Función que se ejecuta continuamente en un bucle infinito
  //-------------------------------------------------//
  //Encender y apagar el LED1 y LED2 del robot ESP32Biped cada 450ms sin pausas
  //-------------------------------------------------//
  ta = millis();  //Medición del tiempo actual
  t = (ta - tp);  //Aplicación del operador aritmético resta
  //Uso del if y operadores de compracíon
  if (t >= tiempo) {
    //Uso del operador boleano NOT
    state = !(state);
    ESP32Biped.led2(state);
    ESP32Biped.led1(state);
    tp = ta;  //Asignación del valor ta a la variable tp
  }
  //-------------------------------------------------//
}
