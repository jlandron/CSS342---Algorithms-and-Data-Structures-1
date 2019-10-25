#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <math.h>        // for pow( )
#include <sstream>       // for stringstream
#include <vector>        // for vector
#include "tokenizer.h"

using namespace std;

// PREC_TABLE matches order of TokenType enumeration.
struct Precedence {
  int inputSymbol;
  int topOfStack;
};

template <class NumericType>
class Evaluator {
 public:
  Evaluator( const string &s ) : str( s ) { // constructor receives an exp
    opStack.push_back( EOL );

    PREC_TABLE[0].inputSymbol = 0;      // EOL
    PREC_TABLE[0].topOfStack =  -1;
    PREC_TABLE[1].inputSymbol = 0;      // VALUE
    PREC_TABLE[1].topOfStack =  0;
    PREC_TABLE[2].inputSymbol = 100;    // OPAREN 
    PREC_TABLE[2].topOfStack =  0;
    PREC_TABLE[3].inputSymbol = 99;     // CPAREN
    PREC_TABLE[3].topOfStack =  0;

    PREC_TABLE[4].inputSymbol = 23;     // NOT
    PREC_TABLE[4].topOfStack = 24;      // 
    PREC_TABLE[5].inputSymbol = 23;     // BIT_COMP
    PREC_TABLE[5].topOfStack = 24;      //
    PREC_TABLE[6].inputSymbol = 23;     // UN_MINUS  reserved for PROG 6
    PREC_TABLE[6].topOfStack = 24;      //
    PREC_TABLE[7].inputSymbol = 23;     // UN_PLUS   reserved for PROG 6
    PREC_TABLE[7].topOfStack = 24;      //

    PREC_TABLE[8].inputSymbol = 21;     // MULT
    PREC_TABLE[8].topOfStack =  22;
    PREC_TABLE[9].inputSymbol = 21;     // DIV
    PREC_TABLE[9].topOfStack =  22;
    PREC_TABLE[10].inputSymbol = 21;    // MOD
    PREC_TABLE[10].topOfStack =  22;

    PREC_TABLE[11].inputSymbol = 19;    // PLUS
    PREC_TABLE[11].topOfStack =  20;
    PREC_TABLE[12].inputSymbol = 19;    // MINUS
    PREC_TABLE[12].topOfStack =  20;

    PREC_TABLE[13].inputSymbol = 15;    // SHIFT_L 
    PREC_TABLE[13].topOfStack =  16;
    PREC_TABLE[14].inputSymbol = 15;    // SHIFT_R
    PREC_TABLE[14].topOfStack =  16;

    PREC_TABLE[15].inputSymbol = 15;    // LT
    PREC_TABLE[15].topOfStack =  16;
    PREC_TABLE[16].inputSymbol = 15;    // LE
    PREC_TABLE[16].topOfStack =  16;
    PREC_TABLE[17].inputSymbol = 15;    // GT
    PREC_TABLE[17].topOfStack =  16;
    PREC_TABLE[18].inputSymbol = 15;    // GE
    PREC_TABLE[18].topOfStack =  16;

    PREC_TABLE[19].inputSymbol = 13;    // EQUAL
    PREC_TABLE[19].topOfStack =  14;
    PREC_TABLE[20].inputSymbol = 13;    // NOTEQUAL
    PREC_TABLE[20].topOfStack =  14;

    PREC_TABLE[21].inputSymbol = 11;    // BIT_AND
    PREC_TABLE[21].topOfStack =  12;

    PREC_TABLE[22].inputSymbol = 9;    // BIT_EOR
    PREC_TABLE[22].topOfStack =  10; 

    PREC_TABLE[23].inputSymbol = 7;    // BIT_IOR
    PREC_TABLE[23].topOfStack =  8; 

    PREC_TABLE[24].inputSymbol = 5;    // LOG_AND
    PREC_TABLE[24].topOfStack =  6; 

    PREC_TABLE[25].inputSymbol = 3;    // LOG_OR
    PREC_TABLE[25].topOfStack =  4; 

    PREC_TABLE[26].inputSymbol = 1;    //ASSIGN
    PREC_TABLE[26].topOfStack = 2;

    var_a = 0;
    var_b = 0;
    var_c = 0;
  }
    
  NumericType getValue( );                  // Do the evaluation
  NumericType getA();
  NumericType getB();
  NumericType getC();
  void setA(NumericType);
  void setB(NumericType);
  void setC(NumericType);

 private:
  Precedence PREC_TABLE[27];                // precedence table
  vector<TokenType> opStack;                // Operator stack for conversion
  vector<NumericType> postFixStack;         // Postfix machine stack
  istringstream str;                        // The character stream

  vector<char> postFixVarStack;      //PostFix stack for Variables
  NumericType var_a;
  NumericType var_b;
  NumericType var_c;

  // Internal routines
  NumericType getTop( );                    // Get top of postfix stack
  void arithmeticOp(TokenType topOp);
  void binaryOp( TokenType topOp );       //process a binary operator
  void assignVar(NumericType &rhs);
  void unaryOp( TokenType topOp );        // Process a unary operator
  void processToken( const Token<NumericType> &lastToken );
};

#include "evaluator.cpp.h"
#endif