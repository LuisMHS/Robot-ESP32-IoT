//-------------------------------------------------//
/*
   @Sketch: Tema8_Flash.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------------------------------------------//

//----------------------Header---------------------//
//Incluir el archivo Preferences.h
#include <Preferences.h>
//-------------------------------------------------//

//----------------------Variable-------------------//
int angleLeftLeg;
int angleRightLeg;
int angleLeftFoot;
int angleRightFoot;
//-------------------------------------------------//

//---------------------Objeto----------------------//
Preferences preferences;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  //Configurar la PC comunicación serial a 9600 baud
  Serial.begin(115200);
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Obtener los ángulos guardados
  preferences.begin("Angulos", false);
  angleLeftLeg = preferences.getInt("LeftLeg", 90);
  angleRightLeg = preferences.getInt("RightLeg", 90);
  angleLeftFoot = preferences.getInt("LeftFoot", 90);
  angleRightFoot = preferences.getInt("RightFoot", 90);
  preferences.end();
  //-------------------------------------------------//
}

void loop() {
  //-------------------------------------------------//
  //Ángulos guardados
  Serial.println(angleLeftLeg);
  Serial.println(angleRightLeg);
  Serial.println(angleLeftFoot);
  Serial.println(angleRightFoot);
  delay(500);
  //-------------------------------------------------//
}
