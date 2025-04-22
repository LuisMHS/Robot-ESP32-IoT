/*
   @Sketch: Tema1_Generar_Voltaje.ino
   @author: Luis Miguel Hernández Samaniego
   Arduino: 2.3.6
   @version ESP32: 3.2
*/
//-------------------------------------------------//
//Incluir el archivo Robot_IoT.h de la librería RobotESP32IoT
#include <Robot_IoT.h>
//-------------------------------------------------//

//-------------------------------------------------//
//Creación de variables globales
String txt = "Voltaje de calibración:";  //Asignar un texto o cadena de caracteres a la variable txt
int tiempo = 400;                        //Variable tiempo RANGO:-2,147,483,648 a 2,147,483,647
unsigned long t = 0;                     //Rango: 0 a 4,294,967,295
float factor = 2.8358;                   //Es de 4 byte y permite trabajar numeros con 6 a 7 decimales, incluido el decimal
//-------------------------------------------------//

//-------------------------------------------------//
//Creación de un Objeto
Robot_IoT ESP32Biped;
//-------------------------------------------------//

//Función que se ejecutara una sola vez
void setup() {
  //-------------------------------------------------//
  //Inicializar el ESP32Biped
  ESP32Biped.begin();
  //-------------------------------------------------//

  //-------------------------------------------------//
  //Inicializar la comunicación con el Monitor Serie del software del Arduino a 9600 bits por segundo
  Serial.begin(9600);
  //-------------------------------------------------//
}
//Función que se ejecuta continuamente en un bucle infinito
void loop() {
  //-------------------------------------------------//
  Serial.println("Mi primer programa ESP32Biped 2025");
  Serial.print("Nombre:");
  Serial.println("Luis");
  //-------------------------------------------------//
  t = millis();  // Medir el tiempo en la línea 44 en milisegundos
  Serial.print("Tiempo: en la línea 44:");
  Serial.println(t);
  //-------------------------------------------------//
  //Creación de variable local en la función loop
  float voltaje = (ESP32Biped.voltage_Read() * factor);
  Serial.print(txt);
  Serial.println(voltaje);  //Lectura de voltaje en el pin 35
  //-------------------------------------------------//
  delay(tiempo);  //Generar una pausa de 400ms
  //-------------------------------------------------//
}
