/*
 ***********************************************************************
 * Librería RobotESP32IoT
 * Copyright (C) 2025 Luis
 
 * Este programa es software libre: puedes redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General de GNU publicada
 * por la Fundación para el Software Libre, ya sea la versión 3 de la
 * Licencia, o (a tu elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; ni siquiera la garantía implícita de
 * COMERCIABILIDAD o ADECUACIÓN A UN PROPÓSITO PARTICULAR.
 * Consulta la Licencia Pública General de GNU para más detalles.
 *
 * Deberías haber recibido una copia de la Licencia Pública General de GNU
 * junto con este programa. Si no, consulta <https://www.gnu.org/licenses/>.
  
 ***********************************************************************
   @file: Robot ESP32 IoT  
   @author:
   -Luis Miguel Hernandez Samaniego
   Agradecimiento:
   Librería desarrollado con ayuda de ChatGPT
   Agradecimientos en la participación de los codigos de movimientos
   y creacion Matrix_16x8.h
   @author:
   -Milagros de la Cruz Quispe 
   Arduino: 2.2.1
   @version  V0.0.1
   @date  2024-01-05
   Agradecimientos: 
   Libreria OttoDIYLib
   Libreria ESP32Servo
   Libreria EEPROM
   Libreria Melody
   Actualización:
   -@author:Luis Miguel Hernández Samaniego
   Arduino: 2.3.2
   @version  V0.0.2
   @date  2024-07-26   
   -@author:Luis Miguel Hernández Samaniego 
   Se actualizo para trabajar la creacion de objeto sin parametros
   Arduino: 2.3.4
   ESP32:3.1.1
   @version  V0.0.3
   @date  2025-03-09 
   -@author:Luis Miguel Hernández Samaniego 
   Se actualizo para utilizar las funciones necesarias 
   Arduino: 2.3.6
   ESP32:3.2
   @version  V0.0.4
   @date  2025-04-20   
***********************************************************************
*/
//-------------------------------------------------//
#include "Robot_IoT.h"
//-------------------------------------------------//

//-------------------------------------------------//
Robot_IoT::Robot_IoT(byte pines[]):Notas(pines[10]),Ticker(),Adafruit_8x16matrix(){
  //-------------------------------------------------//  
	_leftLeg = pines[0];
	_rightLeg = pines[1];
	_leftFoot = pines[2];
	_rightFoot = pines[3];
	_trigger = pines[4];
	_echo = pines[5];
	_led1 = pines[6];
	_led2 = pines[7];
	_bat=pines[8];
	_touch=pines[9];	
    _notas=pines[10];	
	//Para mover los servomotores millis
	_previousMillis = millis();
	_angle = 0;		
}
//-------------------------------------------------//
Robot_IoT::Robot_IoT():Notas(14),Ticker(),Adafruit_8x16matrix() {
	//revisar
 	_leftLeg = 17;
	_rightLeg =18;
	_leftFoot =16;
	_rightFoot =5;
	_trigger =27 ;
	_echo =26 ;
	_led1 = 12;
	_led2 = 13;
	_bat=35;
	_touch=4;
    _notas=14;		
	//Para mover los servomotores millis
	_previousMillis = millis();
	_angle = 0;	
  
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::angle_Read_NVS(){
	
   _preferences.begin("Angulos", true);
   _angleLeftLeg=_preferences.getInt("LeftLeg",90);
   _angleRightLeg=_preferences.getInt("RightLeg",90);
   _angleLeftFoot=_preferences.getInt("LeftFoot",90);
   _angleRightFoot=_preferences.getInt("RightFoot",90);
   _preferences.end();
     
}


//-------------------------------------------------//
void Robot_IoT::initial_Position() {
    //Posicion Inicial
	_ServoLeftLeg.write(_angleLeftLeg);
	_ServoRightLeg.write(_angleRightLeg);
	_ServoLeftFoot.write(_angleLeftFoot);
	_ServoRightFoot.write(_angleRightFoot);  	  	
    //-------------------------------------------------//
}
//-------------------------------------------------//
void Robot_IoT::standby_Mode(){
	angle_Read_NVS();
	initial_Position();
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::begin() {
  
   angle_Read_NVS();
  _ServoLeftLeg.attach(_leftLeg);
  _ServoRightLeg.attach(_rightLeg);
  _ServoLeftFoot.attach(_leftFoot);
  _ServoRightFoot.attach(_rightFoot);
   initial_Position();
   Notas::begin();
   pinMode(_trigger, OUTPUT);
   pinMode(_echo, INPUT); 
   pinMode(_led1, OUTPUT);
   pinMode(_led2, OUTPUT);
   pinMode(2,OUTPUT);
   Adafruit_8x16matrix::begin(0x70);  // address Matrix
   Adafruit_8x16matrix::setBrightness(5);
   Adafruit_8x16matrix::clear();
   Adafruit_8x16matrix::writeDisplay();
  
}

//-------------------------------------------------//
void Robot_IoT::angle_LeftLeg(int angle) {
  //Serial.println(angle);
  _angleLeftLeg=angle;
  _ServoLeftLeg.write(angle);
  
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::angle_RightLeg(int angle) {
	
    //Serial.println(angle);
  _angleRightLeg=angle;
  _ServoRightLeg.write(angle);

}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::angle_LeftFoot(int angle) {
    //Serial.println(angle);
_angleLeftFoot=angle;
  _ServoLeftFoot.write(angle);  
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::angle_RightFoot(int angle) {
  _angleRightFoot=angle;
   //hysiSerial.println(_rightFoot);
  _ServoRightFoot.write(angle);

}
//-------------------------------------------------//

//-------------------------------------------------//
float Robot_IoT::ultrasound() {
  long duration, distance;
  digitalWrite(_trigger, 0);
  delayMicroseconds(2);
  digitalWrite(_trigger, 1);
  delayMicroseconds(10);
  digitalWrite(_trigger, 0);
  duration = pulseIn(_echo, 1);
  distance = (duration*0.0343) / (2.0);
  return distance;
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::led1(bool estate) {
  digitalWrite(_led1, estate);    
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::led2(bool estate) {
  digitalWrite(_led2, estate);    
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::save_Angle() {
	_preferences.begin("Angulos", false);
    _preferences.putInt("LeftLeg", _angleLeftLeg);
	_preferences.putInt("RightLeg", _angleRightLeg);
	_preferences.putInt("LeftFoot", _angleLeftFoot);
	_preferences.putInt("RightFoot", _angleRightFoot);
    _preferences.end(); 
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::walk_Forward(int delayTime) {

int frequency=1; 
  _currentMillis = millis();

  if ((_currentMillis - _previousMillis) >= delayTime) {
    _previousMillis = _currentMillis;
    _angle++;
    float posPD  = (25 * sin(radians(_angle )*frequency) + _angleRightFoot);
    float posPI  = (25 * sin(radians(_angle )*frequency) + _angleLeftFoot);
    float posPRD = (45 * cos(radians(_angle )*frequency) + _angleRightLeg);
    float posPRI = (45 * cos(radians(_angle )*frequency) + _angleLeftLeg);
    //Serial.println(posPD);
     _ServoLeftLeg.write(posPRI);
    _ServoRightLeg.write(posPRD);
    _ServoLeftFoot.write(posPI);
    _ServoRightFoot.write(posPD);

    if (_angle >= 360) {
      _angle = -1;
    }
  }
}
//-------------------------------------------------//


//-------------------------------------------------//
void Robot_IoT::walk_Backward(int delayTime) {
int frequency=1;
  _currentMillis = millis();
  if ((_currentMillis - _previousMillis) >= delayTime) {
    _previousMillis = _currentMillis;
    _angle++;
    float posPD  = ( 25 * sin(radians(_angle )*frequency) +  _angleRightFoot);
    float posPI  = ( 25 * sin(radians(_angle )*frequency) +  _angleLeftFoot);
    float posPRD = (-45 * cos(radians(_angle )*frequency) +  _angleRightLeg);
    float posPRI = (-45 * cos(radians(_angle )*frequency) +  _angleLeftLeg);
    //Serial.println(posPD);
    _ServoLeftLeg.write(posPRI);
    _ServoRightLeg.write(posPRD);
    _ServoLeftFoot.write(posPI);
    _ServoRightFoot.write(posPD);

    if (_angle >= 360) {
      _angle = -1;
    }
  }
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::turn_Left(int delayTime) {
 int frequency=1;
  _currentMillis = millis();
  if ((_currentMillis - _previousMillis) >= delayTime) {
    _previousMillis = _currentMillis;
    _angle++;
    float posPD =  (30 * sin(radians(_angle ) * frequency) +  _angleRightFoot);
    float posPI =  (14 * sin(radians(_angle ) * frequency) +  _angleLeftFoot);
    float posPRD = (14 * cos(radians(_angle ) * frequency) +  _angleRightLeg);
    float posPRI = (50 * cos(radians(_angle ) * frequency) +  _angleLeftLeg);
    //Serial.println(posPD);
    _ServoLeftLeg.write(posPRI);
    _ServoRightLeg.write(posPRD);
    _ServoLeftFoot.write(posPI);
    _ServoRightFoot.write(posPD);
	
    if (_angle >= 360) {
      _angle = -1;
    }
  }
}
//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::turn_Right(int delayTime) {
   int frequency=1;
  _currentMillis = millis();
  if ((_currentMillis - _previousMillis) >= delayTime) {
    _previousMillis = _currentMillis;
    _angle++;
    float posPD =  (30 * sin(radians(_angle )*frequency) +  _angleRightFoot);
    float posPI =  (14 * sin(radians(_angle )*frequency) +  _angleLeftFoot);
    float posPRD = (50 * cos(radians(_angle )*frequency) +  _angleRightLeg);
    float posPRI = (14 * cos(radians(_angle )*frequency) +  _angleLeftLeg);
    //Serial.println(posPD);
    _ServoLeftLeg.write(posPRI);
    _ServoRightLeg.write(posPRD);
    _ServoLeftFoot.write(posPI);
    _ServoRightFoot.write(posPD);

    if (_angle >= 360) {
      _angle = -1;
    }
  }
}

//-------------------------------------------------//

//-------------------------------------------------//
int Robot_IoT::touch_Read(){
	return touchRead(_touch);
}
//-------------------------------------------------//

//-------------------------------------------------//
bool Robot_IoT::touch(int data){		  
	int touchdetected=touchRead(_touch);	
    //Serial.println(touchdetected);	
	if((touchdetected>=0) && (touchdetected<data)){

		return 1;		
	}else{
		return 0;
		
    }	
}
//-------------------------------------------------//
float Robot_IoT::battery(float alfa){

 float battery_Charge = (voltage_Read()*alfa);
 battery_Charge=((41.666667)*(battery_Charge-6)); 
 return battery_Charge;
}

//-------------------------------------------------//

//-------------------------------------------------//
void Robot_IoT::move_Servos(byte leftLeg, byte rightLeg, byte leftFoot, byte rightFoot) {
   _ServoLeftLeg.write(leftLeg);
   _ServoRightLeg.write(rightLeg);
   _ServoLeftFoot.write(leftFoot);
   _ServoRightFoot.write(rightFoot);
}
//-------------------------------------------------//

//-------------------------------------------------//
float Robot_IoT::voltage_Read(){
return (float)((3.3*analogRead(_bat))/(4095.0));
}
//-------------------------------------------------//