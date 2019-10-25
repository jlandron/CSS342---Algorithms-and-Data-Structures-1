// Gosper member function definitions
#include "Gosper.h"

//------------------------- Gosper Arrowhead ----------------------------
Gosper::Gosper( float initX, float initY, float initAngle ) 
  : Turtle( initX, initY, initAngle ) {
}
//------------------------------ leftCurve ----------------------------------
/**
 *@desc Right curve function calls istelf and right curve recursivly
 *@param int curve level, float line length
 *@return none
 *@provided outputs a .ps file with the drawing.
 **/
void Gosper::leftCurve( int level, float d ) {
  if ( level > 1 ) {
    leftCurve(level - 1, d);
    turn(120);
    rightCurve(level - 1, d);
    turn(120);
    rightCurve(level - 1, d);
    turn(-60);
    leftCurve(level - 1, d);
    turn(-60);
    leftCurve(level - 1, d);
    turn(60);
    leftCurve(level - 1, d);
    rightCurve(level - 1, d);
  }
  //create the level 1 left curve 
  else{
    draw(d);
    turn(60);
    draw(d);
    turn(120);
    draw(d);
    turn(-60);
    draw(d);
    turn(-120);
    draw(d);
    draw(d);
    turn(-60);
    draw(d);
  } 
}
//------------------------------ rightCurve ---------------------------------
/**
 *@desc Right curve function calls istelf and right curve recursively
 *@param int curve level, float line length
 *@return none
 *@provided outputs a .ps file with the drawing.
 **/
void Gosper::rightCurve( int level, float d ) {
  if ( level > 1 ) {
    turn(-60);
    leftCurve(level - 1, d);
    turn(120);
    rightCurve(level - 1, d);
    rightCurve(level - 1, d);
    turn(120);
    rightCurve(level - 1, d);
    turn(60);
    leftCurve(level - 1, d);
    turn(-60);
    leftCurve(level - 1, d);
    rightCurve(level - 1, d);
  }
  //create the level 1 right curve 
  else{
    turn(-60);
    draw(d);
    turn(60);
    draw(d);
    draw(d);
    turn(120);
    draw(d);
    turn(60);
    draw(d);
    turn(-120);
    draw(d);
    turn(-60);
    draw(d);
  }
}