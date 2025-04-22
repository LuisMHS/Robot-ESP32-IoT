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
#ifndef _Robot_IoT_h
#define _Robot_IoT_h
//-------------------------------------------------//

//-------------------------------------------------//
#include <Arduino.h>
#include <ESP32Servo.h>
#include <Notas.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <Ticker.h>
#include <Adafruit_LEDBackpack.h>
#include "Matrix/Matrix_16x8.h"
#include <Preferences.h>
//-------------------------------------------------//

//-------------------------------------------------//
#define configMAX_PRIORITIES 25
//-------------------------------------------------//

//-------------------------------------------------//
class Robot_IoT : public Notas,public Ticker,public Adafruit_8x16matrix{

  private:
    //-------------------------------------------------//
    byte _leftLeg, _rightLeg, _leftFoot, _rightFoot, _buzzer, _trigger, _echo, _led1, _led2;
    int _angleLeftLeg, _angleRightLeg, _angleLeftFoot, _angleRightFoot;
	byte _touch;
	byte _bat;
	byte _potentiometer;
	int _count1=0;
    int _count2=0;
	byte _notas;   
    int _trims;
    volatile unsigned long _previousMillis, _currentMillis;
    int _angle;	
    //-------------------------------------------------//
	
  public:
    using Notas::begin; 
	using Adafruit_8x16matrix::begin;
	using Adafruit_8x16matrix::setBrightness;
	using Adafruit_8x16matrix::clear;
	using Adafruit_8x16matrix::writeDisplay;
	//-------------------------------------------------//
    Servo _ServoLeftLeg, _ServoRightLeg, _ServoLeftFoot, _ServoRightFoot;
    //-------------------------------------------------//
    Preferences _preferences;
    //-------------------------------------------------//
    Robot_IoT();
	Robot_IoT(byte pines[]);	
    void initial_Position();
	void angle_Read_NVS();
	void standby_Mode();
    void begin();
    void angle_LeftLeg(int angle);
    void angle_RightLeg(int angle);
    void angle_LeftFoot(int angle);
    void angle_RightFoot(int angle);
    float ultrasound();
	int touch_Read();
	bool touch(int data);
	void led1(bool estate);
	void led2(bool estate);  
	void save_Angle();  
    void walk_Forward(int delayTime);
    void walk_Backward(int delayTime);
    void turn_Left(int delayTime);
    void turn_Right(int delayTime);   
    float battery(float alfa);
	float voltage_Read();	
	void move_Servos(byte leftLeg, byte rightLeg, byte leftFoot, byte rightFoot);	
};
#endif
//-------------------------------------------------//
