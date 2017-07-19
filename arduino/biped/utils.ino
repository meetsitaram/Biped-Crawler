#include "biped.h"
#include "utils.h"
#include <math.h>

//const int degreeStepSize = 2.25;

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
Adafruit_PWMServoDriver pwm2 = Adafruit_PWMServoDriver(0x41);

void setupPwm() {
  pwm.begin();
  pwm2.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  pwm2.setPWMFreq(60);    
}

void initialCallibrate(int servoNum) {
   pwm.setPWM(servoNum, 0, 170); 
   delay(2000);
   pwm.setPWM(servoNum, 0, 575); 
   delay(5000);
}

double getAlpha(int L, int servoLift) {
  double z = Z_OFFSET + servoLift;
  double alpha1 = acos(z/L);
  double alpha2 = acos( (pow(femur,2) + pow(L,2) - pow(tibia,2)) / (2.0*femur*L) );

  double alpha = 180*(alpha1 + alpha2) / M_PI;
  if (alpha == NAN)  {
    return 0;
  }
  return alpha;
}

double getBeta(int L, int servoLift) {
  if (L > femur + tibia) {
    return 0;
  }
  double beta = (180.0/M_PI)*acos( ( pow(L,2) - pow(femur,2) - pow(tibia, 2) )/(2.0*femur*tibia) );
  return beta;
}


void setServoPosition(int servoNum, int theta) {

  if (theta < 0 || theta > 180) {
    Serial.println("invalid theta:" + theta);
    return;
  }

  int shieldNum = 0;
  int servoMin = -1;
  int servoMax = -1;
  switch(servoNum) {
    case servoN10:
      servoMin = servoN10Min;
      servoMax = servoN10Max;
      shieldNum = 0;
      break;  
    case servoN11:
      servoMin = servoN11Min;
      servoMax = servoN11Max;
      shieldNum = 0;
      break;  
    case servoN12:
      servoMin = servoN12Min;
      servoMax = servoN12Max;
      shieldNum = 0;
      break;  
    case servoN20:
      servoMin = servoN20Min;
      servoMax = servoN20Max;
      shieldNum = 0;
      break;  
    case servoN21:
      servoMin = servoN21Min;
      servoMax = servoN21Max;
      shieldNum = 0;
      break; 
    case servoN22:
      servoMin = servoN22Min;
      servoMax = servoN22Max;
      shieldNum = 0;
      break;   

    default:
      Serial.println("invalid servo:" + servoNum );
      return;                                
  }

  if (servoMin < 0 || servoMax < 0) {
    Serial.println("invalid servo:" + servoNum);
    return;
  }

  double degreeStepSize = (servoMax - servoMin ) / 180.0;
  double pulseLength = servoMin + degreeStepSize*theta;
  if(shieldNum == 0) {
    pwm.setPWM(servoNum, 0, pulseLength);
  } else {
    pwm2.setPWM(servoNum, 0, pulseLength);
  }
  
}
