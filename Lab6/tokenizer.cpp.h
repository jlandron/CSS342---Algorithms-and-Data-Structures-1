template <class NumericType>
bool Tokenizer<NumericType>::getChar( char &ch ) {
  char tmp;

  // skip blanks
  while ( in.get( tmp ) && tmp == ' ' );

  // read a char 
  if ( in.good( ) && tmp != '\n'&& tmp != '\0' ) {
    ch = tmp;
    return true; // if it is not a delimiter
  }
  else
    return false; // if it's a delimitter
}

template <class NumericType>
Token<NumericType> Tokenizer<NumericType>::getToken( ) {

  char ch;
  NumericType theValue;

  if ( getChar( ch ) == true ) {
    switch( ch ) {
    case '(': return (prevToken = OPAREN);
    case ')': return (prevToken = CPAREN);

    case '!': 
      if ( getChar( ch ) == true && ch == '=' )
	      return (prevToken = NOTEQUAL);
      in.putback( ch );

      cerr << "no negation allowed" << endl;
      return (prevToken = EOL);

    case '*': return (prevToken = MULT);

    case '/': return (prevToken = DIV);

    case '%': return (prevToken = MODULUS);

    case '+': return (prevToken = PLUS);

    case '-': return (prevToken = MINUS);

    case '<': 
      if ( getChar( ch ) == true ) {
        switch( ch ) {
        case '<': return (prevToken = SHIFT_L);
        case '=': return (prevToken = LE);
        default:
          in.putback( ch );
	        return (prevToken = LT);
	      }
      }
      in.putback( ch );
      return (prevToken = LT);

    case '>':
      if ( getChar( ch ) == true ) {
        switch( ch ) {
        case '>': return (prevToken = SHIFT_R);
        case '=': return (prevToken = GE);
        default:
	        in.putback( ch );
	        return (prevToken = GT);
	      }
      }
      in.putback( ch );
      return (prevToken = GT);

    case '&': 
      if ( getChar( ch ) == true && ch == '&' )
	      return (prevToken = LOG_AND);
      in.putback( ch );
      return (prevToken = BIT_AND);

    case '^': return (prevToken = BIT_EOR);

    case '|': 
      if ( getChar( ch ) == true && ch == '|' )
	      return (prevToken = LOG_OR);
      in.putback( ch );
      return (prevToken = BIT_IOR);

    case '=': 
      if ( getChar( ch ) == true && ch == '=' )
	      return (prevToken = EQUAL);
      in.putback( ch );
      //cerr << "no assignment allowed" << endl;
      return (prevToken = ASSIGN);
      
    default:
      in.putback( ch );
      if ( !( in >> theValue ) ) {
	      cerr << "Parse error" << endl;
	      return (prevToken = EOL);
      }
      prevToken = VALUE;
      return Token<NumericType>( VALUE, theValue );
    }
  }
  return (prevToken = EOL);
}