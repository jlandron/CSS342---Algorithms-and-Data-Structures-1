// Gosper Class 
#ifndef GOSPER_H
#define GOSPER_H

#include "Turtle.h"
#include <iostream>
#include <math.h>
using namespace std;
//---------------------------------------------------------------------------
// Gosper class uses Turtle graphics: a tool to draw lines 
//   by the following three actions:
//   -- draw: draw a line by a given distance and move to the destination
//   -- move: simply move by a given distance without drawing a line
//   -- turn: turn left by a given angle
//
// Assumptions:
//   -- all Turtle functions will work in this inheritance
//   -- all parameters and data members are float.
//   -- Outputs are in postscript format.
//---------------------------------------------------------------------------
class Gosper : Turtle {
public:
  Gosper( float initX=0.0, float initY=0.0, float initAngle=0.0 );
  void leftCurve( int l, float d );  //draw a level-l left curve with dist d
  void rightCurve( int l, float d ); //draw a level-l right curve with dist d
};
#endif
