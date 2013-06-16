#include "testApp.h"


void testApp::arduinoLoop() {
    Sleep(100);
Input = (arduino.getAnalog(0)/4.0);
if (PIDon){
   //Setpoint = (arduino.getAnalog(5)/4.0);


   /*How long since we last calculated*/
   gettimeofday(&t1, NULL);
   now  = t1.tv_usec / 100000.0;

   if (now> lastTime)
   timeChange = (now - lastTime);
   if (now < lastTime)
   timeChange = (lastTime- now);
   if(timeChange>= .01)
   {

   /*Compute all the working error variables*/


   dErr = (error - lastErr) / 1;

   /*Compute PID Output*/
   if  (pvar == false)
        Ep = 0;
        else{
           error = Setpoint - Input;
            Ep = (kp * error);
   }
     if (ivar == false)
        Ei = 0 ;
     else{
         errSum += error *1;
        Ei = (ki * errSum);
     }
     if (dvar == false)
        Ed = 0 ;
     else{
         dErr = (Input - lastinput) / 1;
        Ed = (kd * dErr);
     }


   Fout= Ep + Ei + Ed;
if (Fout > 255)
  Fout = 255;
if (Fout < 0 )
  Fout = 0;

   /*Remember some variables for next time*/
   lastErr = error;
   lastTime = now;
   lastinput = Input;

      //analogPin0 = arduino.getAnalog(0)/1023.0; // anolog read A0

           if (zero)
     Fout = 0;
      else
      arduino.sendPwm(3,Fout);
   }
}

   if (OnOffctr){
     if (Input > Setpoint) {
        Fout -= 2;
     }
     if (Input < Setpoint) {
        Fout += 10;


     }


           if (zero)
     Fout = 0;
      else
      arduino.sendPwm(3,Fout);

   }
if (DEAD){
        if (Input > Setpoint1)
            DEADctr = false;

        if (Input < Setpoint)
            DEADctr = true;
        if (DEADctr)
        Fout += 10;
        if (!DEADctr)
            Fout -= 2;

      if (zero)
      Fout = 0;
      else
      arduino.sendPwm(3,Fout);

   }


 // arduino.update();// get any changes that the Arduino might have
}// end void testApp::arduinoLoop()

