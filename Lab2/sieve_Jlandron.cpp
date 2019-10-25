#include <iostream>
#include <vector>
#include <math.h>
#include <sys/time.h>
#include <fstream>
using namespace std;

int sieve( int n, vector<int> &primes ) {
  int cost = 0;
  bool arr[n + 1];

  // array initialization (all true)
  for ( int i = 0; i < n; i++ ){
    arr[i] = true;
  }
  // implement sieve here
  // every time you perform: array[j] = false;
  for(int i = 2; i * i <= n; i++){
    if(arr[i] == true){
      for(int j = i*2; j <= n; j+= i){
        arr[j] = false;
        cost++;
      }
    }
    
  }
  

  // collect all prime numbers      
  for ( int i = 0; i < n; i++ ){
    if (arr[i] == true){
      primes.push_back( i );
    }
  }
  return cost;
}

main( ) {
  int n = 0;
  struct timeval startTime, endTime;

  ofstream outfile ("sieve.dat");

  while ( n < 2 ) {
    cout << "Enter n ";
    cin >> n;
  }

  char printOption = 'n';
  cout << "print all primes (y|n)? ";
  cin >> printOption;

  for ( int i = 2; i <= n; i++ ) {
    gettimeofday( &startTime, NULL );

    vector<int> primes;
    int cost = sieve( i, primes );

    gettimeofday( &endTime, NULL );
    cout << "primes[1.." << i << "] took " << cost
	 << " sweeping operations...time required = " 
	 << ( endTime.tv_sec - startTime.tv_sec ) * 100000 +
            ( endTime.tv_usec - startTime.tv_usec ) << endl;
    outfile << i << " " << cost << endl;
    if ( printOption == 'y' ) {
      cout << "all primes = ";
      for ( int j = 0; j < primes.size( ); j++ )
	cout << primes[j] << " ";
      cout << endl;
    }

    cerr << i << " " << cost << endl;
  }
  outfile.close();
}

