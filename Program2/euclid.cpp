#include <vector>
#include <math.h>
#include <iostream>
#include <sys/time.h>
#include <fstream>
using namespace std;
/**
 *@desc method that produces the most costly set of operations 
 *  in finding the greatest commen denoninator
 *@param int, vector<int>
 *@return int
 *@required takes an in that is the upper bound to calculate possiblilities
 *@provided provides the largest number of modulus operations in the range
 *  as well as saving the specific numbers and modulo that produced that operation 
**/
int euclid(int n, vector<int> &numsSaved) {
    int maxCost = 0;
    int maxA;
    int maxB;
    int maxMod;
    //iterate through all possible combinations
    //use temp values and later add to vector for access
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int cost = 0;
            int A = i;              //number that will become the modulus
            int B = j;              //number that will go to zero
            int temp;               //holding value
            //euclids method using a while loop
            while(B != 0){
                temp = B;
                B = A % B;
                A = temp;
                cost++;
            }
            //check if this round of euclids method is the most costly
            if(cost > maxCost){
                maxMod = A;
                maxA = i;
                maxB = j;
                maxCost = cost;
            }
        }
    }
    //saves the set adn modulo of the most costly operation in a vector
    numsSaved.push_back(maxMod);
    numsSaved.push_back(maxA);
    numsSaved.push_back(maxB);
    return maxCost;
}

int main( ) {
    int n = 0;
    struct timeval startTime, endTime;
    //ofstream outfile("euclid.dat");

    while ( n < 8 ) {
        cout << "Enter a number greater than 8: ";
        cin >> n;
    }

    for ( int i = 8; i <= n; i++ ) {
        gettimeofday( &startTime, NULL );
        //numsSaved will have the values of Max modulus operations at [0]
        //and the max numbers at [1] and [2]
        vector<int> numsSaved;
        int cost = euclid( i, numsSaved );

        gettimeofday( &endTime, NULL );
        //calculate time passed
        int time = ( endTime.tv_sec - startTime.tv_sec ) * 1000000 +
                ( endTime.tv_usec - startTime.tv_usec );

        cout << "At i = " << i << " gcd( " << numsSaved[1] << ", " 
            << numsSaved[2] << ") = " << numsSaved[0] << " took " 
            << cost << " modulus operations...time required = " 
            << time << endl;

        //send value to file
        //outfile << i << " " << cost << endl;
        cerr << i << " " << cost << endl;
        //clear the vector
        numsSaved.pop_back();
        numsSaved.pop_back();
        numsSaved.pop_back();
    }
    //outfile.close();
    return 0;
}

