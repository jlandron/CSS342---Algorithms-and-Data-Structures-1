#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sys/time.h>
#include "arrayOps.cpp"
#include "mergesort.cpp"                    // implement your mergesort

using namespace std;

// performance evaluation
int elapsed( timeval &startTime, timeval &endTime ) {
  return ( endTime.tv_sec - startTime.tv_sec ) * 1000000
    + ( endTime.tv_usec - startTime.tv_usec );
}

int main( int argc, char* argv[] ) {
  // verify arguments
                                                           
  if ( argc != 2 ) {
    cerr << "usage: a.out size" << endl;
    return -1;
  }

  // verify an array size
                                                       
  int size = atoi( argv[1] );
  if ( size <= 0 ) {
    cerr << "array size must be positive" << endl;
    return -1;
  }

  // array generation
                                                           
  srand( 1 );
  vector<int> items( size );
  initArray( items, size );
   cout << "initial:" << endl;   // comment out when evaluating performance only
   printArray( items, "items" ); // comment out when evaluating performance only

  // mergesort
  struct timeval startTime, endTime;
  gettimeofday( &startTime, 0 );
  mergesort( items );
  gettimeofday( &endTime, 0 );
  cout << "elapsed time: " << elapsed( startTime, endTime ) << endl;

   cout << "sorted:" << endl;    // comment out when evaluating performance only
   printArray( items, "items" ); // comment out when evaluating performance only

  return 0;
}
