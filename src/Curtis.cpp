/********************************************************************************/
/*   Author  : Ahmed Farag  & Wajih                                             */
/*   Date    : 18/05/2022                                                       */
/*   Version : V02                                                              */
/********************************************************************************/
#include <Arduino.h>
#include <Curtis_Configuration.h>
#include "SBUS.h"

// Intitialization function
void Steering_Init()
{
  // Set the PWM pin for the throttle to output
  pinMode(THROTTLE_FORWARD_PIN, OUTPUT);
  // Set the Reverse switch pin  to output
  pinMode(REVERSE_DIRECTION_SWITCH, OUTPUT);
  // Set Reverse pin to low
  digitalWrite(REVERSE_DIRECTION_SWITCH, LOW);
}

// Stering function without feedback
void Steering_RC(int RC_Readings)
{

  if ((RC_Readings >= 1004) && (RC_Readings <= 1722))
  {
    // Serial.print("Right: ");
    Curtis_Forward(RC_Readings, THROTTLE_FORWARD_PIN, RC_THROTTLE_MIN_READINGS, RC_THROTTLE_MAX_READINGS, THROTTLE_MIN_PWM, THROTTLE_MAX_PWM);
  }

  if ((RC_Readings > 1000) && (RC_Readings < 1004))
  {

    analogWrite(THROTTLE_FORWARD_PIN, 1);
    digitalWrite(REVERSE_DIRECTION_SWITCH, LOW);
  }

  if ((RC_Readings >= 282) && (RC_Readings <= 1000))
  {

    // Serial.print("Left: ");
    Curtis_Reverse(RC_Readings, THROTTLE_REVERSE_PIN, RC_THROTTLE_MIN_READINGS_REVERSE, RC_THROTTLE_MAX_READINGS_REVERSE, THROTTLE_MIN_PWM_REVERSE, THROTTLE_MAX_PWM_REVERSE, REVERSE_DIRECTION_SWITCH);
  }
}

// Function to move the motor forward with PWM maped from Potentiometer values
void Curtis_Forward(int Potentiometer_Readings, int Throttle_Pin, int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM, int Throttle_Max_PWM)
{
  int Throttle_PWM_Value = map(Potentiometer_Readings, Throttle_Min_Readings, Throttle_Max_Readings, Throttle_Min_PWM, Throttle_Max_PWM);
  // Serial.print("Forward PWM ");
  // Serial.println(Throttle_PWM_Value);

  digitalWrite(REVERSE_DIRECTION_SWITCH, LOW);
  // digitalWrite(FORWARD_DIRECTION_SWITCH, HIGH);
  analogWrite(Throttle_Pin, Throttle_PWM_Value);
}

// Function to move the motor backward with PWM maped from Potentiometer values
void Curtis_Reverse(int Potentiometer_Readings, int Throttle_Pin, int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM, int Throttle_Max_PWM, int Reverse_Switch_Pin)
{
  // Set reverse switch on

  int Throttle_PWM_Value_Rev = map(Potentiometer_Readings, Throttle_Min_Readings, Throttle_Max_Readings, Throttle_Min_PWM, Throttle_Max_PWM);
  // Serial.print("Reverse PWM ");
  // Serial.println(Throttle_PWM_Value_Rev);

  digitalWrite(REVERSE_DIRECTION_SWITCH, HIGH);
  analogWrite(Throttle_Pin, Throttle_PWM_Value_Rev);
}
