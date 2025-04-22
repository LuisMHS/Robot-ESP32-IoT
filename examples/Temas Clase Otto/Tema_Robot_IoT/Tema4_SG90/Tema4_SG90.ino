/*
   @Sketch: Tema4_SG90.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------------------------------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//

//-------------------------------------------------//
//Creación de variables
byte angle = 90;  //Variable ángulo
//-------------------------------------------------//

//-------------------------------------------------//
//Creación de un objeto
Robot_IoT ESP32Biped;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Inicializar la PC comunicación serial
  Serial.begin(9600);
  //Inicializar el ESP32Biped
  ESP32Biped.begin();
  //-------------------------------------------------//
}

void loop() {
  //-------------------------------------------------//
  //Mover la pierna y pie del ESP32BipedIoT en un ángulo de 50° a 130°
  for (angle = 50; angle <= 130; angle++) {
    ESP32Biped.angle_LeftLeg(angle);
    ESP32Biped.angle_RightLeg(angle);
    ESP32Biped.angle_LeftFoot(angle);
    ESP32Biped.angle_RightFoot(angle);
    delay(15);  //Pausa de 15 ms
  }
  //-------------------------------------------------//

  //-------------------------------------------------//
  delay(1000);  //Pausa de 1000 ms
  //-------------------------------------------------//
  //Mover la pierna y el pie del ESP32BipedIoT en un ángulo de 130° a 50°
  //-------------------------------------------------//
  for (angle = 130; angle >= 50; angle--) {
    ESP32Biped.move_Servos(angle, angle, angle, angle);
    delay(15);  //Pausa de 15 ms
  }
  delay(1000);  //Pausa de 1000 ms
  //-------------------------------------------------//
}
