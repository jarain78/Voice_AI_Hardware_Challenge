#include <ArduinoJson.h>
#include <PID_v1.h>

#define LOOPTIME                      100   

// Motor Right
//-----------------------------------------------------------------
int mr_EL_Start_Stop = 23; //EL
int mr_Signal_hall = 3; // Signal - Hall sensor
int mr_ZF_Direction = 22; // ZF
int mr_VR_speed = 9;  //VR

// Motor Left
//-----------------------------------------------------------------
int ml_EL_Start_Stop = 25; //EL
int ml_Signal_hall = 2; // Signal - Hall sensor
int ml_ZF_Direction = 24; // ZF
int ml_VR_speed = 8;  //VR


//#######################################
//#######################################
/*int pos_left = 0;
  int pos_right = 0;*/
int steps = 0;
int speed1 = 20;
String direction1;

// Odometry Values
float w_1_a = 0;
float w_1_b  = 0;
float w_2_a = 0;
float w_2_b = 0;

byte channelAmount = 10; // PPM Channel count
volatile byte pulseCounter = 0;
unsigned long blankTime = 2100;
volatile unsigned long *rawValues = NULL;
volatile unsigned long *validValues = NULL;
volatile unsigned long microsAtLastPulse = 0;

// JSON
DynamicJsonDocument doc(1024);
DynamicJsonDocument doc1(1024);
JsonObject obj1 = doc1.as<JsonObject>();
String output = " ";

// Ultra sonic Sensors
float center_distance = 0.0;
float left_distance = 0.0;
float right_distance = 0.0;

// PID
double speed_req_left = 0;                    //Desired speed for left wheel in m/s
double speed_act_left = 0;                    //Actual speed for left wheel in m/s
double speed_cmd_left = 0;                    //Command speed for left wheel in m/s

double speed_req_right = 0;                   //Desired speed for right wheel in m/s
double speed_act_right = 0;                   //Actual speed for right wheel in m/s
double speed_cmd_right = 0;                   //Command speed for right wheel in m/s

const double max_speed = 0.4;                 //Max speed in m/s

int PWM_leftMotor = 0;                     //PWM command for left motor
int PWM_rightMotor = 0;                    //PWM command for right motor

// PID Parameters
const double PID_left_param[] = { 0, 0, 0.1 }; //Respectively Kp, Ki and Kd for left motor PID
const double PID_right_param[] = { 0, 0, 0.1 }; //Respectively Kp, Ki and Kd for right motor PID

volatile float pos_left = 0;       //Left motor encoder position
volatile float pos_right = 0;      //Right motor encoder position

PID PID_leftMotor(&speed_act_left, &speed_cmd_left, &speed_req_left, PID_left_param[0], PID_left_param[1], PID_left_param[2], DIRECT);          //Setting up the PID for left motor
PID PID_rightMotor(&speed_act_right, &speed_cmd_right, &speed_req_right, PID_right_param[0], PID_right_param[1], PID_right_param[2], DIRECT);   //Setting up the PID for right motor

unsigned long lastMilli = 0;
const double radius = 1.7018;                   //Wheel radius, in m
const double wheelbase = 0.2;               //Wheelbase, in m

double linear_speed_x = 0;
double angula_speed_z = 0;

int motor_direction_L = LOW;
int motor_direction_R = LOW;
int motor_stop = LOW;
