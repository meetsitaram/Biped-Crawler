/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <math.h>
#include "utils.h"
#include "biped.h"

#include "walking_style1.h"
#include "walking_style2.h"

WalkingStyle2 style;

void setInitialServoPositions() {
  setServoPosition(servoN10, initThetaN10);
  setServoPosition(servoN20, initThetaN20);

  setServoPosition(servoN11, initThetaN11);
  setServoPosition(servoN21, initThetaN21);

  setServoPosition(servoN12, initThetaN12);
  setServoPosition(servoN22, initThetaN22);
  
}

void setup() {
  
  Serial.begin(9600);
  Serial.println("16 channel, dual shield, Servo test!");

  setupPwm();

  setInitialServoPositions();

  for(int t=15; t>0; t--) {
    Serial.print("Starting in "); Serial.print(t); Serial.println(" seconds");
    delay(1000);
  }

  style.setDownRightLegServoPositions(L_MAX, servoN11, servoN12);  

  yield();
}

void loop() {

  // initialCallibrate(servoN10);
  // delay(2000);
  // return;

  
  int speed = 1 ;
  style.continueWalking(1);

}
