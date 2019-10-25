// A simple main to exercise Evaluator class.
#include <iostream>
#include "evaluator.h"

using namespace std;

int main( ) {
  string str;
  int a = 0;
  int b = 0;
  int c = 0;
  while ( getline( cin, str ) ) {
    Evaluator<int> e( str );
    e.setA(a);
    e.setB(b);
    e.setC(c);
    cout << e.getValue( ) << endl;
    a = e.getA();
    b = e.getB();
    c = e.getC();
  }
  
  return 0;
}