/*
   @file:   Robot_Touch_Move
   @author: Luis Miguel Hernandez Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/

//----------------------Header---------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
#include <BluetoothSerial.h>
//-------------------------------------------------//

//-------------------------------------------------//
String device_Name = "ESP32Biped";
bool walk = 0;  //Indicador de caminar al inicio cero
unsigned long tp = 0;
unsigned long ta = 0;
unsigned long t = 0;
//-------------------------------------------------//

//----------------------Objeto---------------------//
Robot_IoT ESP32Biped;
BluetoothSerial SerialBT;

//-----------Declaracion de una función------------//
void ESP32Leds(void *pvParameters);
//-------------------------------------------------//

void setup() {
//-------------------------------------------------//
//Inicializar el ESP32Biped
//Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth no está habilitado
#endif

//-------------------------------------------------//
//Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
#error El perfil de puerto serie para Bluetooth no está disponible o no está habilitado.
#endif
  SerialBT.begin(device_Name);
  Serial.begin(9600);
  ESP32Biped.begin();
  // Crear una tarea en el núcleo 0
  xTaskCreate(ESP32Leds, "ESP32_Leds", 2048, NULL, 1, NULL);
}
//-------------------------------------------------//
void loop() {
  SerialBT.println(ESP32Biped.touch_Read());
  delay(80);
  if (ESP32Biped.touch(29)) {
    walk = 1;
    ESP32Biped.sound_Happy();
    tp = millis();
    while (walk) {
      ta = millis();
      t = ta - tp;
      ESP32Biped.walk_Forward(5);
      if (t >= 5000) {
        tp = ta;
        walk = 0;
        ESP32Biped.standby_Mode();
      }
    }
  }
}
//-------------------------------------------------//
void ESP32Leds(void *pvParameters) {
  ESP32Biped.begin();
  while (true) {
    ESP32Biped.led1(1);
    ESP32Biped.led2(0);
    delay(200);
    ESP32Biped.led1(0);
    ESP32Biped.led2(1);
    delay(200);
  }
}
//-------------------------------------------------//