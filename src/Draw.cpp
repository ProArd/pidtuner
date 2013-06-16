#include "testApp.h"

void testApp::draw(){
 if (PIDon){
 ofSetColor(0,255,0);
 ofRect (35, 266, 17 ,10);
 }
 else {
     ofSetColor(255,0,0);
     ofRect (58, 266, 22 ,10);
 }

	ofSetColor(225);
	verdana14.drawString(T1Str, 400, 275);
	verdana14.drawString(T2Str, 480, 275);
	verdana14.drawString(dtStr, 480, 300);
	verdana14.drawString("PID ON|OFF", 10, 275);
	verdana14.drawString(KpStr, 35, 285);
	verdana14.drawString(KiStr, 35, 295);
	verdana14.drawString(KdStr, 35, 305);
	verdana14.drawString("P-", 10, 285);
	verdana14.drawString("I-", 10, 295);
	verdana14.drawString("D-", 10, 305);
	verdana14.drawString("Dead-", 10, 315);
	verdana14.drawString("onoff-", 10, 325);
	verdana14.drawString(SetStr, 90, 275);
	verdana14.drawString(PWMStr, 180, 275);
	verdana14.drawString(PWMoutStr, 270, 275);
	verdana14.drawString(EpStr, 600, 275);
	verdana14.drawString(EiStr, 600, 350);
	verdana14.drawString(EdStr, 600, 400);
	verdana14.drawString(ErrStr, 600, 300);



ofSetLineWidth (1);
ofSetColor(0,0,0);

for (int i = 266 ; i > 9 ; i -=32){
 ofLine(10,i,1034,i);
 ofSetLineWidth (1);
}
for (int i = 1034 ; i > 9 ; i -=32){
 ofLine(i,10,i,266);
 ofSetLineWidth (1);
}
ofSetLineWidth (2);
ofSetColor(0,0,255);   //set point line
ofLine (10 ,setpoint ,1034 ,setpoint);
if (DEAD)
ofLine (10 ,setpoint1 ,1034 ,setpoint1);
ofSetLineWidth (2);

ofSetColor(0,255,0);
for (int i = 0 ; i < 1023 ; i++){
 ofSetColor(0,255,0);
 ofLine (i+10 ,(266 - graph[i]) , i+11 , (266-graph [i+1]));
 ofSetLineWidth (2);
}
ofSetColor(255,0,0);
ofLine (10+point , 10  , 10+point , 266);

ofSetLineWidth (1);


ofFill ();
if (pvar)
    ofSetColor(255,0,0);
else
    ofSetColor(50,50,50);

    ofCircle(28 , 281 ,5);
if (ivar)
    ofSetColor(0,255,0);
else
    ofSetColor(50,50,50);

    ofCircle(28 , 291,5);
if (dvar)
    ofSetColor(0,0,255);
else
    ofSetColor(50,50,50);

ofCircle(28 , 301,5);
if (OnOffctr)
    ofSetColor(0,255,255);
else
    ofSetColor(50,50,50);
    ofCircle(28 , 311,5);
}

