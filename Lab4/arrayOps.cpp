#include <vector>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

//initalize random array with new seed using ctime
void initArray( vector<int> &array, int randMax ) {
  int size = array.size( );
  srand(time(NULL));
  for ( int i = 0; i < size; ) {
    int tmp = ( randMax == -1 ) ? rand( ) : rand( ) % randMax;
    bool hit = false;
    for ( int j = 0; j < i; j++ ) {
      if ( array[j] == tmp ) {
        hit = true;
        break;
      }
    }
    if ( hit )
      continue;
    array[i] = tmp;
    i++;
  }
}

void printArray( vector<int> &array, char arrayName[] ) {
  int size = array.size( );

  for ( int i = 0; i < size; i++ )
    cout << arrayName << "[" << i << "] = " << array[i] << endl;
}
