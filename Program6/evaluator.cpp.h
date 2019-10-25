#include "evaluator.h"
// Public routine that performs the evaluation. Examines the postfix machine
// to see if a single result is left and if so, return it; otherwise prints
// error.
template<class NumericType>
NumericType Evaluator<NumericType>::getValue( ) {

  Tokenizer<NumericType> tok( str );
  Token<NumericType> lastToken;
  
  do {
    lastToken = tok.getToken( );
    processToken( lastToken );
  } while ( lastToken.getType( ) != EOL );
  if ( postFixStack.empty( ) ) {
    cerr << "Missing operand!!" << endl;
    return 0;
  }
  NumericType theResult = postFixStack.back( );
  postFixStack.pop_back( );
  //postFixVarStack.pop_back( );
  if ( !postFixStack.empty( ) )
    cerr << "Warning: missing operators!" << endl;
  
  return theResult;
}
//Public member functions to set and get variable values and retain them over
//the entire run of the program. 
template<class NumericType>
NumericType Evaluator<NumericType>::getA(){
  return var_a;
}
template<class NumericType>
NumericType Evaluator<NumericType>::getB(){
  return var_b;
}
template<class NumericType>
NumericType Evaluator<NumericType>::getC(){
  return var_c;
}
template<class NumericType>
void Evaluator<NumericType>::setA(NumericType a){
	var_a = a;
}
template<class NumericType>
void Evaluator<NumericType>::setB(NumericType b){
	var_b = b;
}
template<class NumericType>
void Evaluator<NumericType>::setC(NumericType c){
	var_c = c;
}
// After token is read, use operator precedence parsing algorithm to process
// it; missing opening parentheses are detected here.
template<class NumericType>
void Evaluator<NumericType>::
processToken( const Token<NumericType> &lastToken ) {
  TokenType topOp;
  TokenType lastType = lastToken.getType( );

  switch( lastType ) {
  case VALUE:
    postFixStack.push_back( lastToken.getValue( ) );
    postFixVarStack.push_back( ' ' );
    return;
    
  case VAR_A:
    postFixStack.push_back( var_a );
    postFixVarStack.push_back( 'a' );
    return;

  case VAR_B:
    postFixStack.push_back( var_b );
    postFixVarStack.push_back( 'b' );
    return;

  case VAR_C:
    postFixStack.push_back( var_c );
    postFixVarStack.push_back( 'c' );
    return;

  case CPAREN:
    while( ( topOp = opStack.back( ) ) != OPAREN &&
	   topOp != EOL )
      arithmeticOp( topOp );
    if ( topOp == OPAREN )
      opStack.pop_back( ); // get rid of opening parethesis
    else
      cerr << "Missing open parenthesis" << endl;
    break;
  
  default: // general operator case
    while ( PREC_TABLE[ lastType ].inputSymbol <= 
	    PREC_TABLE[ topOp = opStack.back( ) ].topOfStack )
      arithmeticOp( topOp );
    if ( lastToken.getType( ) != EOL )
      opStack.push_back( lastType );
    break;
  }
}
template<class NumericType>
void Evaluator<NumericType>::arithmeticOp(TokenType topOp){
  if(topOp == UN_MINUS || topOp == UN_PLUS ||
		topOp == NOT || topOp == BIT_COMP ){
    unaryOp(topOp);
  }else{
    binaryOp(topOp);
  }
}
// Process an operator by taking two items off the postfix stack, applying
// the operator, and pushing the result.
// Print error if missing closing parenthesis or division by 0.
template<class NumericType>
void Evaluator<NumericType>::binaryOp( TokenType topOp ) {
  if ( topOp == OPAREN ) {
    cerr << "Unbalanced parenthesis" << endl;
    opStack.pop_back( );
    return;
  }
  NumericType rhs = getTop( );
  NumericType lhs = getTop( );
  //original operator
  if (topOp == PLUS) {
	  postFixStack.push_back(lhs + rhs);
  }
  else if (topOp == MINUS) {
	  postFixStack.push_back(lhs - rhs);
  }
  else if (topOp == MULT) {
	  postFixStack.push_back(lhs * rhs);
  }
  else if ( topOp == DIV ) {
    if ( rhs != 0 ){
      postFixStack.push_back( lhs / rhs );
    }
    else {
      cerr << "Division by zero" << endl;
      postFixStack.push_back( lhs );
    }
  }
  //extra operators
  else if ( topOp == MODULUS ){
    postFixStack.push_back( lhs % rhs );
  }
  else if ( topOp == SHIFT_L ){
    postFixStack.push_back( lhs << rhs );
  }
  else if ( topOp == SHIFT_R ){
    postFixStack.push_back( lhs >> rhs );
  }
  else if ( topOp == LT ){
    postFixStack.push_back( lhs < rhs );
  }
  else if ( topOp == GT ){
    postFixStack.push_back( lhs > rhs );
  }
  else if ( topOp == LE ){
    postFixStack.push_back( lhs <= rhs );
  }
  else if ( topOp == GE ){
    postFixStack.push_back( lhs >= rhs );
  }
  else if ( topOp == EQUAL ){
    postFixStack.push_back( lhs == rhs );
  }
  else if ( topOp == NOTEQUAL ){
    postFixStack.push_back( lhs != rhs );
  }
  else if ( topOp == BIT_AND ){
    postFixStack.push_back( lhs & rhs );
  }
  else if ( topOp == BIT_IOR ){
    postFixStack.push_back( lhs | rhs );
  }
  else if ( topOp == LOG_AND ){
    postFixStack.push_back( lhs && rhs );
  }
  else if ( topOp == LOG_OR ){
    postFixStack.push_back( lhs || rhs );
  }
  else if (topOp == BIT_EOR) {
	  postFixStack.push_back(pow(lhs,rhs));
  }
  else if ( topOp == ASSIGN ){
    postFixStack.push_back( lhs = rhs );
	assignVar(rhs);
	postFixVarStack.pop_back();
  }
  opStack.pop_back( );
}
//Function made to simplify the assignment of variables. 
//uses the setter functions
template<class NumericType>
void Evaluator<NumericType>::assignVar(const NumericType &rhs)
{
  //empties the varStack of spaces until the next variable
	while (postFixVarStack.back() == ' ') { 
		postFixVarStack.pop_back();
	}
	if (postFixVarStack.back() == 'a') {
		setA(rhs);
	}
	else if (postFixVarStack.back() == 'b') {
		setB(rhs);
	}
	else if (postFixVarStack.back() == 'c') {
		setC(rhs);
	}
	else {
		cerr << "No such Variable" << endl;
	}
}
//unary operator
template<class NumericType>
void Evaluator<NumericType>::unaryOp( TokenType topOp ) {
  NumericType operand = getTop();
  if ( topOp == UN_MINUS ){
    postFixStack.push_back( -operand );
  }
  else if ( topOp == UN_PLUS ){
    postFixStack.push_back( +operand );
  }
  else if ( topOp == NOT ){
    postFixStack.push_back( !operand );
  }
  else if ( topOp == BIT_COMP ){
    postFixStack.push_back( ~operand );
  }
  
  opStack.pop_back( );
}
// top and pop the postfix machine stack; return the result.
// If the stack is empty, print an error message.
template<class NumericType>
NumericType Evaluator<NumericType>::getTop( ) {
  if ( postFixStack.empty( ) ) {
    cerr << "Missing operand" << endl;
    return 0;
  }
  NumericType tmp = postFixStack.back( );
  postFixStack.pop_back( );
  return tmp;
}