/*
   @Sketch: Tema6_Touch.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/

//-------------------------------------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//

//----------------------Variable-------------------//
unsigned long t = 0;
unsigned long tp = 0;
unsigned long ta = 0;
bool touch;
//-------------------------------------------------//

//---------------------Objeto----------------------//
Robot_IoT ESPBiped;
//-------------------------------------------------//

void setup() {
  //-------------------------------------------------//
  // Configurar el robot ESPBiped
  ESPBiped.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Configurar la comunicación serial a 9600 baudios
  Serial.begin(9600);
  //-------------------------------------------------//

  //-------------------------------------------------//
  tp = millis();  //medición del tiempo pasado
  //-------------------------------------------------//
}

void loop() {
  /*
  ta = millis();                            //lectura del tiempo actual
  t = (ta - tp);                            //tiempo transcurrido
  if (t >= 100) {                           //Medir el touch cada 100ms
    Serial.println(ESPBiped.touch_Read());  //Ver los valor numerico del touch del pin D4
    tp = ta;                                //Actualizar el tiempo pasado con el tiempo actual
  }
  */
  //-------------------------------------------------//
  //Obtener el valor promedio al tocar y dejar de tocar
  touch = ESPBiped.touch(50);
  //-------------------------------------------------//

  //-------------------------------------------------//
  while (touch) {
    //Obtener el valor promedio al tocar y dejar de tocar
    touch = ESPBiped.touch(50);
    ESPBiped.walk_Forward(3);  //ESPBiped camina hacia adelante
  }
  //-------------------------------------------------//
}
