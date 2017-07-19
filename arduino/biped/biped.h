#ifndef BIPED_INCLUDE
#define BIPED_INCLUDE
const double femur = 11.0; // in cm
const double tibia = 11.0;
const double coxa = 2.0; 
double Z_OFFSET = 3.5;

const int L_MIN = 4;
const int L_MAX = 12;

const int servoN12 = 13;
const int servoN12Min = 180;
const int servoN12Max = 585;
const int sheildN12 = 0;
const int initThetaN12 = 180;

const int servoN11 = 14;
const int servoN11Min = 160;
const int servoN11Max = 565;
const int sheildN11 = 0;
const int initThetaN11 = 180;

const int servoN10 = 15;
const int servoN10Min = 160;
const int servoN10Max = 565;
const int sheildN10 = 0;
const int initThetaN10 = 90;

const int servoN22 = 9;
const int servoN22Min = 150;
const int servoN22Max = 555;
const int sheildN22 = 0;
const int initThetaN22 = 0;

const int servoN21 = 10;
const int servoN21Min = 140;
const int servoN21Max = 545;
const int sheildN21 = 0;
const int initThetaN21 = 0;

const int servoN20 = 11;
const int servoN20Min = 155;
const int servoN20Max = 560;
const int sheildN20 = 0;
const int initThetaN20 = 90;

// // Depending on your servo make, the pulse width min and max may vary, you 
// // want these to be as small/large as possible without hitting the hard stop
// // for max range. You'll have to tweak them as necessary to match the servos you
// // have!
// #define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

#endif