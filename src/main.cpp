#include <Arduino.h>
// #include <ROS_Serial.h>
#include <DriveMotor.h>
#include <Brake.h>
#include <Light_Siren.h>
#include <Drone_Launch.h>
#include <Curtis_Configuration.h>
#include "SBUS.h"

#define Steering_RC_CH 0
#define Throttle_RC_CH 2
#define Drone_CH 4
#define Front_Light_CH 5
#define Siren12_CH 6
#define Steering_Enable 8
#define Siren_Light_CH 9
#define Siren3_CH 10
/**
 * Drone Launch
 *
 */
// serial port 1
SBUS x8r(Serial1);

// channel, fail safe, and lost frames data
uint16_t channels[16];
bool failSafe;
bool lostFrame;

void setup()
{
  Serial.begin(115200);
  // ROS_Init();
  // Drive_Init();
  Brake_init();
  Steering_Init();

  // Light_Init();
  // Siren_Init();
  // Drone_Launch_Init();

  x8r.begin();
}

void loop()
{
  if (x8r.read(&channels[0], &failSafe, &lostFrame))
    ;

  int Throttle_RC = channels[Throttle_RC_CH];
  // Serial.println(Throttle_RC);
  int RC_Readings = channels[RC_FW_CH_NUM];

  int EM_Brake1 = channels[8];
  int EM_Brake2 = channels[9];
  int EM_Brake3 = channels[10];
  int EM_Brake4 = channels[11];
// if(!failSafe){

  EMERGENCY_Brake(EM_Brake1, EM_Brake2, EM_Brake3, EM_Brake4, Throttle_RC);
  // Brake_Control_RC(Throttle_RC);
  // Drive_RC(Throttle_RC);
  Steering_RC(RC_Readings);
//}
// else{
  // Brake_Control_RC(Drive_RC_Zero);
  // Drive_RC(Drive_RC_Zero);
  // Steering_RC(Drive_RC_Zero);

//}
  // int Steering_RC = channels[Steering_RC_CH];
  // int Front_Light_RC = channels[Front_Light_CH];
  // int Siren_Light_RC = channels[Siren_Light_CH];
  // int Siren_12_RC = channels[Siren12_CH];
  // int Siren_3_RC = channels[Siren3_CH];
  // EMERGENCY_Brake(EM_Brake1, EM_Brake2, EM_Brake3, EM_Brake4, Throttle_RC);

  //  Light_RC( Front_Light_RC, Siren_Light_RC,Throttle_RC_CH );
  // Siren_RC(Siren12_CH, Siren3_CH);

  //---------------- App ---------------------
  // Drive_APP(G_Throttle_Msg, G_Direction_Msg);
  // Brake_Control_App(G_Throttle_Msg);
  // Light_App(G_Full_Light, G_Head_Light, G_Siren_Light_Msg, G_Direction_Msg);
  // Siren_App(G_Siren1_Msg, G_Siren2_Msg, G_Siren3_Msg);
  // Drone_Control_App(G_Drone_Launch_Msg);

  //  Brake_Control_Serial();

  // nh.spinOnce();
  // delayMicroseconds(1);
}