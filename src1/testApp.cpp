#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    for (int i = 0 ; i <= 1024 ; i++){ // set and Zero graph
     graph [i] = 0;
     }
      kp = 0 ;
      ki = 0 ;
      kd = 0 ;


     arduino.connect("COM5");//remeber! change this to the proper port
     ofAddListener(arduino.EInitialized, this, &testApp::arduinoSetup);
     isArduinoSet = false;// this flag is set false until the Arduino is setup


now = 0 ;
Setpoint = 127;
Setpoint1 = 137;
PWM = 0;
pvar = false;
ivar = false;
dvar = false;
zero = false;
PIDon = false;
DEAD = false;
Pause = true;
OnOffctr =false;
point = 0;
ofBackground (50,50,50);
ofTrueTypeFont::setGlobalDpi(72);
	verdana14.loadFont("verdana.ttf", 9, true, true);
	verdana14.setLineHeight(18.0f);
	verdana14.setLetterSpacing(1.037);
	    verdana14.drawString("Font Example - use keyboard to type", 30, 35);


isready = false ;
}

//--------------------------------------------------------------
void testApp::update(){

    sprintf(T1Str, "Time: %G", now);
    sprintf(dtStr, "dt: %G", (double)(timeChange));
    sprintf(KpStr, "Kp: %G", kp);
    sprintf(KiStr, "Ki: %G", ki);
    sprintf(KdStr, "Kd: %G", kd);
    sprintf(SetStr, "Set Point: %i", (int)(Setpoint));
    sprintf(PWMStr, "PWM: %i", (int)(PWM));
    sprintf(PWMoutStr, "Output: %i", (int)(Fout));
    sprintf(EpStr, "Ep: %i", (int)(Ep));
    sprintf(EiStr, "Ei: %i", (int)(errSum));
    sprintf(EdStr, "Ed: %i", (int)(Ed));
    sprintf(ErrStr, "Error: %i", (int)(error));
  if (Pause){
  arduino.update();
    if (isArduinoSet){ // do not run  this code untill arduino is operating
        //if (OnOffctr)
          //   testApp::arduinoLoop();// preform the arduino style code
        if (PIDon ||OnOffctr || DEAD)
         testApp::arduinoLoop();// preform the arduino style code
        else{

           arduino.sendPwm(3,PWM);
           Input = (arduino.getAnalog(0)/4.0);
     }



setpoint = 266 - Setpoint;
setpoint1 = 266 - Setpoint1;

 graph [point] =  Input;//- serial.readByte();
 flushline = 10+ point ;

 point++;
 if (point == 1024 )
        point = 0;
        output = 0;

}
}
}










void testApp::arduinoSetup(const int & version) {
  ofRemoveListener(arduino.EInitialized, this, &testApp::arduinoSetup);

  arduino.sendAnalogPinReporting(0, ARD_ANALOG);// turn on anolog pin0
  arduino.sendDigitalPinMode(3, ARD_PWM);
  arduino.sendPwm(3,0);
  lastTime = 0 ;
  error = 0;
  dErr = 0;
  errSum = 0 ;
  lastErr = 0;//arduino.getAnalog(0)/4.0;
  isArduinoSet = true;// inform the rest of the program that arduino is ready
}//end void testApp::arduinoSetup(



void testApp::reset(){

      kp = 0 ;
      ki = 0 ;
      kd = 0;
      pvar = false;
      Setpoint = 127;
      ivar = false;
      dvar = false;
      point= 0;
      zero1();
      }
      void testApp::appClear(){
    for (int i = 0 ; i <= 1024 ; i++){

     graph [i] = 0;
     }

point= 0;
      }
void testApp::zero1(){
  Output = 0;
  timeChange = 0;
  lastTime =0 ;
  lastErr =0;
  now= 0;
  t1.tv_usec =0;
  arduino.sendPwm(3,0);
  PWM=0;
   lastTime = 0 ;
  errSum = 0 ;
  lastErr = arduino.getAnalog(0)/4.0;
 appClear();
  point= 0;
//  sleep (1);
}
