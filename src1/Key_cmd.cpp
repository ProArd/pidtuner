
#include "testApp.h"

void testApp::keyPressed(int key){
  switch (key){
    case ' ':
        Pause = !Pause;
        break;
    case 'p':
        pvar = !pvar;
        break;
    case 'i':
        ivar = !ivar;
        break;
    case 'd':
        dvar = !dvar;
        break;
    case 'q':
        kp -= .01;
        break;
    case 'Q':
        kp += .01;
        break;
    case 'w':
        ki -= .01;
        break;
    case 'W':
        ki += .01;
        break;
    case 'e':
        kd -= .01;
        break;
    case 'E':
        kd += .01;
        break;
    case 'm':
        PWM --;
        break;
    case 'M':
        PWM++;
        break;
    case 'r':
        reset();
        break;
    case 'c':
        appClear();
        break;
    case 'z':
        zero1();
        break;
    case 's':
        Setpoint--;
        break;
    case 'S':
        Setpoint++;
        break;
    case 'a':
        Setpoint1--;
        break;
    case 'A':
        Setpoint1++;
        break;
    case 'o':
        PIDon = !PIDon;
        break;
    case 'y':
        OnOffctr = !OnOffctr;
        break;
    case 'h':
        DEAD = !DEAD;
        break;
  }


}
