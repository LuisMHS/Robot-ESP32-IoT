/*
   @file:   ESP32_Move_Melody_Leds.ino
   @author: Luis Miguel Hernandez Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//----------------------Header---------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//

//-------------------------------------------------//
//Creación de un Objeto
Robot_IoT ESP32Biped;
//-------------------------------------------------//

//-----------Declaracion de una función------------//
void Biped_Move(void *pvParameters);
void Biped_Melody(void *pvParameters);
void Biped_Leds(void *pvParameters);
//-------------------------------------------------//

//-------------------------------------------------//
void setup() {
  Serial.begin(115200);
  ESP32Biped.begin();
  xTaskCreate(Biped_Move, "Biped Move", 2048, NULL, 10, NULL);
  xTaskCreate(Biped_Melody, "Biped Melody", 2048, NULL, 24, NULL);
  xTaskCreate(Biped_Leds, "Biped Leds", 2048, NULL, 8, NULL);
}
//-------------------------------------------------//
void loop() {
}
//-------------------------------------------------//

void Biped_Move(void *pvParameters) {
  ESP32Biped.begin();
  while (true) {
    for (int i = 0; i < 5; i++) {
      ESP32Biped.angle_LeftLeg(90);
      ESP32Biped.angle_RightLeg(90);
      ESP32Biped.angle_RightFoot(90);
      ESP32Biped.angle_LeftFoot(90);
      delay(300);
      ESP32Biped.angle_LeftLeg(90);
      ESP32Biped.angle_RightLeg(90);
      ESP32Biped.angle_RightFoot(40);
      ESP32Biped.angle_LeftFoot(90);
      delay(300);
      ESP32Biped.angle_LeftLeg(90);
      ESP32Biped.angle_RightLeg(90);
      ESP32Biped.angle_RightFoot(90);
      ESP32Biped.angle_LeftFoot(140);
      delay(300);
    }
    delay(10000);
  }
}
//-------------------------------------------------//

void Biped_Melody(void *pvParameters) {
  ESP32Biped.begin();
  while (true) {
 
      ESP32Biped.sound_Dance();
      delay(2000);
    
  }
}
//-------------------------------------------------//
void Biped_Leds(void *pvParameters) {
  ESP32Biped.begin();
  while (true) {
    for (int i = 0; i < 5; i++) {
      ESP32Biped.led1(1);
      ESP32Biped.led2(0);
      delay(250);
      ESP32Biped.led1(0);
      ESP32Biped.led2(1);
      delay(250);
    }
  }
}