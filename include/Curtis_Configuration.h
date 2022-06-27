/********************************************************************************/
/*   Author  : Ahmed Farag  & Wajih                                             */
/*   Date    : 18/05/2022                                                       */
/*   Version : V02                                                              */
/********************************************************************************/

#ifndef CURTIS_CONFIGURATION_H
#define CURTIS_CONFIGURATION_H

// Inputs pins
#define POTENTIOMETER_PIN_NUMBER 22

// Remote control parameters

#define RC_FW_CH_NUM 0
#define RC_RV_CH_NUM 0

#define RC_FW_UPPER_LIMIT 1722
#define RC_DEFAULT_LIMIT 1002
#define RC_RV_LOWER_LIMIT 283

// Transistors Pin number

// Forward motor driver parameters

#define THROTTLE_FORWARD_PIN 2
#define THROTTLE_MIN_PWM 60
#define THROTTLE_MAX_PWM 60

#define RC_THROTTLE_MIN_READINGS 1002
#define RC_THROTTLE_MAX_READINGS 1722

// REVERSE motor driver parameters

#define THROTTLE_REVERSE_PIN 2
#define REVERSE_DIRECTION_SWITCH 11
#define THROTTLE_MIN_PWM_REVERSE 60
#define THROTTLE_MAX_PWM_REVERSE 60

#define RC_THROTTLE_MIN_READINGS_REVERSE 282
#define RC_THROTTLE_MAX_READINGS_REVERSE 1002

void Steering_Init();
void Curtis_Forward(int Throttle_Pin_num, int Potentiometer_Readings, int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM, int Throttle_Max_PWM);
void Curtis_Reverse(int Throttle_Pin_num, int Potentiometer_Readings, int Throttle_Min_Readings, int Throttle_Max_Readings, int Throttle_Min_PWM, int Throttle_Max_PWM, int Reverse_Switch_Pin);
void Steering_RC(int RC_Readings);


#endif