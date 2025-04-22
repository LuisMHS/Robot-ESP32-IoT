/*
   @Sketch: Tema3_Timer_HC_SR04.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------------------------------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
#include <Ticker.h>
//-------------------------------------------------//
//-------------------------------------------------//
//Variable
float distancia;
//-------------------------------------------------//

//-------------------------------------------------//
//Creación de un Objeto
Robot_IoT ESP32Biped;
Ticker timer;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Inicializar el ESP32Biped
  ESP32Biped.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Inicializar la comunicación con el Monitor Serie del software del Arduino a 9600 bits por segundo
  Serial.begin(9600);
  //-------------------------------------------------//

  //-------------------------------------------------//
  timer.attach_ms(200, program_distance);
  //-------------------------------------------------//
}

void loop() {
  //-------------------------------------------------//
  //Si la distancia es mayor a 20cm y menor igual a 80cm, enceder los leds, en caso contrario a pagar los leds
  //-------------------------------------------------//
  //Uso del if-else
  if ((distancia > 20) && (distancia <= 80)) {  //Operadores de compración y operadores booleanos
    //Leds encendidos
    ESP32Biped.led1(1);
    ESP32Biped.led2(1);
  } else {
    //Leds apagados
    ESP32Biped.led1(0);
    ESP32Biped.led2(0);
  }
}
//-------------------------------------------------//
void program_distance() {
  distancia = ESP32Biped.ultrasound();  //Asignar el valor medido del ultrasonido a la variable distancia
  Serial.print("Distancia:");
  Serial.print(distancia);
  Serial.println("cm");
}
//-------------------------------------------------//
