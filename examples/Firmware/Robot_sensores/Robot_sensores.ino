/*
   @Sketch: Robot_sensores.ino
   @Author: Luis Miguel Hernández Samaniego
   @Arduino: 2.3.8
   @Version ESP32: 3.1.1
   @Fecha: 12/03/2026 
   @Placa: ESP32 WROOM genérico
   @Version código:0.0.1
*/
//********No conectar los micro servo SG90*********//

//----------------------Header---------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//
//------------------Variable-----------------------//
bool estado = 0;
//-------------------------------------------------//

//-------------------Objeto------------------------//
Robot_IoT bot;
Ticker Sensor, LEDs;
//-------------------------------------------------//

//-------------------------------------------------//
void bot_Zumbador(void *pvParameters);
//-------------------------------------------------//
void setup() {
  //-------------------------------------------------//
  //Configurar la comunicación serial a 9600 baudios
  Serial.begin(9600);
  //-------------------------------------------------//
  //Configurar el bot
  bot.begin();
  //-------------------------------------------------//
  //Configurar el timer para la batería y monitoreo de la distancia
  Sensor.attach_ms(200, program_Sensor);
  //Configurar el timer para el encedido de los LEDs
  LEDs.attach_ms(400, program_LEDs);
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Configurar la tarea bot_Zumbador
  xTaskCreate(bot_Zumbador, "bot_Zumbador", 2048, NULL, 24, NULL);
  //-------------------------------------------------//
}

void loop() {
}

void bot_Zumbador(void *pvParameters) {
  //-------------------------------------------------//
  // Configurar el bot
  bot.begin();
  //-------------------------------------------------//
  int i = 0;
  while (1) {
    switch (i) {
      case 0:
        bot.sound_Disconnection();  //Sonido de desconexión
        break;                      //Salir del caso '0' y evaluar la siguiente variable i
      case 1:
        bot.sound_Connection();  //Sonido de conexión
        break;
      case 2:
        bot.sound_Happy_Birthday();  //Sonido de feliz cumpleaños
        break;
      case 3:
        bot.sound_Christmas_Music();  //Sonido de Navidad
        break;
      case 4:
        bot.sound_Star_Wars();  //Sonido de guerra de galaxias
        break;
      case 5:
        bot.sound_Dance();  //Sonido de Dance
        break;
      case 6:
        bot.sound_Happy();  //Sonido de felicidad
        break;
      case 7:
        bot.sound_BillieJean();  //Sonido de BillieJean
        break;
      case 8:
        bot.sound_Conquest_of_Paradise();  //Sonido de Conquest of Paradise
        break;
      default:
        break;
    }
    delay(10);
    if (i > 8) {
      //Volver a repetir los sonidos desde el inicio
      i = 0;
    }
    i++;
  }
}
//-------------------------------------------------//
void program_Sensor() {
  Serial.print("Distancia=");
  Serial.print(bot.ultrasound());
  Serial.print(" cm -- ");
  Serial.print("Voltaje=");
  Serial.print(bot.voltage_Read());
  Serial.println(" V");
}
//-------------------------------------------------//

//-------------------------------------------------//
void program_LEDs() {
  bot.led1(estado);
  estado = !estado;
  bot.led2(estado);
}
//-------------------------------------------------//

