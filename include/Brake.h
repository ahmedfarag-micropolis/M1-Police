#ifndef Brake_h
#define Brake_h

//Cytron
#define Brake_Dir 26    //Cytron 1 Dir 1
#define Brake_PWM 25    //Cytron 1 PWM 1
#define Brake_Pot 23

#define Brake_Motor_Speed_PWM 250

#define RC_Throttle_Zero   1002
#define RC_Throttle_Max    1722
#define RC_Throttle_Min    283

#define App_Throttle_Zero   0
#define App_Throttle_Max    100

#define Pot_Brake_Limit     300
#define Pot_Release_Limit   100


void Brake_init();
// void Brake_Control(int Throttle_Value);
void Brake_Control_App(int Throttle_Value);
void Brake_Control_RC(int Throttle_Value);
void Brake_Control_Serial();
void EMERGENCY_Brake(int EB1, int EB2, int EB3, int EB4,  int Throttle);




void Brake_Control_Serial();





#endif