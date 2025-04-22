/*
   @file: ESP32_Ultrasonido_Move.ino
   @author: Luis Miguel Hernandez Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------------------------------------------//

//----------------------Header---------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//

//--------------------Variables--------------------//
bool walk_F = 1;
bool walk_B = 0;
int distancia = 10;
bool estado_led1 = 1;
bool estado_led2 = 0;
//-------------------------------------------------//

//----------------------Objeto---------------------//
Robot_IoT ESP32Biped;
//-------------------------------------------------//

//-----------Declaracion de una función------------//
void Biped_Leds(void *pvParameters);
//-------------------------------------------------//

void setup() {

  Serial.begin(9600);
  ESP32Biped.begin();
  //ESP32Biped.attach_ms(250, program_Leds);
  ESP32Biped.attach_ms(100, program_distancia);
  // Crear una tarea en el núcleo 1
  xTaskCreate(Biped_Leds, "Biped Leds", 2048, NULL, 5, NULL);
}

void loop() {
  if (walk_F) {
    ESP32Biped.standby_Mode();
  }

  if (walk_B) {
    ESP32Biped.walk_Backward(5);
  }
  if (distancia < 10 && distancia >= 0) {
    walk_F = 0;
    walk_B = 1;
  }
  if (distancia >= 10 && distancia < 200) {
    walk_F = 1;
    walk_B = 0;
  }
}
void Biped_Leds(void *pvParameters) {
  ESP32Biped.begin();
  while (true) {
    ESP32Biped.led1(1);
    ESP32Biped.led2(0);
    delay(150);
    ESP32Biped.led1(0);
    ESP32Biped.led2(1);
    delay(150);
  }
}

void program_distancia() {
  distancia = ESP32Biped.ultrasound();
  Serial.println(distancia);
}
