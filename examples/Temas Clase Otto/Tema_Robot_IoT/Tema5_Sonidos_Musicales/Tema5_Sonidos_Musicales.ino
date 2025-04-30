/*
   @Sketch: Tema5_Sonidos_Musicales.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------------------------------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//

//-------------------------------------------------//
//Creación de variable
char selector = ' ';
//-------------------------------------------------//

//-------------------------------------//
//Creación de un objeto ESPBiped
Robot_IoT ESPBiped;
//-------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Inicializar el ESPBiped
  ESPBiped.begin();
  //Inicializar la comunicación serial
  Serial.begin(9600);
  //-------------------------------------------------//
}
void loop() {
  //-------------------------------------------------//
  //Si Serial.available es 1 leer la comunicación serial
  if (Serial.available() > 0) {
    selector = Serial.read();  //La variable selector almacenara un char enviado desde el monitor serie
  }
  //-------------------------------------------------//

  //-------------------------------------------------//
  Serial.println(selector);  //Imprimir la variable selector
  //-------------------------------------------------//

  //-------------------------------------------------//
  // Si selector toma un carácter desde '0' a '4', ejecutar el caso elegido con switch
  switch (selector) {
    case '0':
      ESPBiped.sound_Disconnection();  //Sonido de desconexión
      break;                            //Salir del caso '0' y evaluar la siguiente variable selector
    case '1':
      ESPBiped.sound_Connection();  //Sonido de conexión
      break;
    case '2':
      ESPBiped.sound_Happy_Birthday();  //Sonido de feliz cumpleaños
      break;
    case '3':
      ESPBiped.sound_Christmas_Music();  //Sonido de Navidad
      break;
    case '4':
      ESPBiped.sound_Star_Wars();  //Sonido de desconexión
      break;
    case '5':
      ESPBiped.sound_Dance();  //Sonido de Dance
      break;
    case '6':
      ESPBiped.sound_Happy();  //Sonido de felicidad
      break;
    case '7':
      ESPBiped.sound_BillieJean();  //Sonido de BillieJean
      break;
    case '8':
      ESPBiped.sound_Conquest_of_Paradise();  //Sonido de Conquest of Paradise
      break;
    default:
      break;
  }
  delay(100);  //Pausa de 100 ms
}
//-------------------------------------------------//
