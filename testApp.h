#pragma once
#include <sys/time.h>
#include "ofMain.h"
//#include <ctime>
class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed  (int key);

		void reset();
		void appClear();
        void zero1();


        timeval t1 ;
        int flushline ;
        unsigned char graph [1025];
        int point ,PWM ;
        int setpoint;
        int setpoint1;
        int output;
        bool isready;
        bool pvar,ivar,dvar,zero,PIDon , DEAD , DEADctr ,Pause;

        void arduinoSetup(const int & version);//Arduino equivalent setup function
        void arduinoLoop();// Arduino equivalent loop function
		  //ofSerial serial ;
		bool isArduinoSet;// flag to know when Arduino is conected and configured
        ofArduino arduino; // the Arduino object
        double lastTime;
        int SampleTime;
float Input, Output, emaLast, Setpoint, Setpoint1;
float errSum, lastErr;
float kp  , ki , kd;
float Ep ,Ei ,Ed;
long double now ;
long double timeChange;
float error;
float dErr;
float analogPin0; // pin8 data container
//float IN;
int Fout , input , lastinput;
ofTrueTypeFont	verdana14;
bool OnOffctr;
char T1Str[20];
char T2Str[20];
char dtStr[20];
char KpStr[20];
char KiStr[20];
char KdStr[20];
char SetStr[20];
char PWMStr[20];
char EpStr[20];
char EiStr[20];
char EdStr[20];
char ErrStr[20];
char PWMoutStr[20];

};
