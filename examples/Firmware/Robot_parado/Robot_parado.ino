/*
   @Sketch: Robot_parado.ino
   @Author: Luis Miguel Hernández Samaniego
   @Arduino: 2.3.8
   @Version ESP32: 3.1.1
   @Fecha: 12/03/2026 
   @Placa: ESP32 WROOM genérico
   @Version código:0.0.1
*/

//----------------------Header---------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//

//------------------Variable-----------------------//
bool estado = 0;
//-------------------------------------------------//

//-------------------Objeto------------------------//
Robot_IoT bot;
Ticker SG90, LED;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Configurar la comunicación serial a 9600 baudios
  Serial.begin(9600);
  //Configurar le pin del led azul de la placa ESP32
  pinMode(2, OUTPUT);
  //-------------------------------------------------//
  //Configurar el bot
  bot.begin();
  //-------------------------------------------------//
  //Movimiento para que el robot este parado
  bot.angle_LeftLeg(90);
  bot.angle_RightLeg(90);
  bot.angle_LeftFoot(90);
  bot.angle_RightFoot(90);
  bot.save_Angle();
  //-------------------------------------------------//
  //Configurar el timer para el micro servo SG90
  SG90.attach(2, program_servo);
  //-------------------------------------------------//
  //Configurar el timer para el encedido de LED azul
  LED.attach_ms(400, program_LED);
  //-------------------------------------------------//
}

void loop() {
}
//-------------------------------------------------//
void program_servo() {
  //Movimiento para que el robot este parado
  bot.angle_LeftLeg(90);
  bot.angle_RightLeg(90);
  bot.angle_LeftFoot(90);
  bot.angle_RightFoot(90);
}
//-------------------------------------------------//
void program_LED() {
  estado = !estado;
  digitalWrite(2, estado);
}
//-------------------------------------------------//
