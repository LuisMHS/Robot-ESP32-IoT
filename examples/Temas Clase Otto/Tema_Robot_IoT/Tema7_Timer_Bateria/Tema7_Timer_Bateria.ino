/*
   @Sketch: Tema7_Timer_Bateria.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------------------------------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//

//---------------------Objeto----------------------//
Robot_IoT ESP32biped;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Configurar la PC comunicación serial a 9600 baud
  Serial.begin(9600);
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Configurar el robot ESP32biped
  ESP32biped.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Configurar el timer cada 70000ms para que se ejecute la función  program_Battery
  ESP32biped.attach_ms(700, program_Battery);
  //-------------------------------------------------//
}

void loop() {
}
// Función program_Battery para medir el voltaje y monitorear la batería
void program_Battery() {
  Serial.print("Voltaje en el pin D35=");
  Serial.println(ESP32biped.voltage_Read());
  Serial.print("Voltaje en la batería=");
  Serial.println(ESP32biped.battery(3.1645));
}