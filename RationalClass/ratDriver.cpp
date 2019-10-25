/**@auther Joshua Landron
 * CSS342 Algorithms and Data Structures
 * edited from "Objects and Classes Lecture by Professor Munehiro Fukuda"
 */
#include <iostream>
#include "rat2.h"

using namespace std;

int main(){
    Rational x(-2,6), y(-14,-16), z;

    cout << x << " + " << y;
    z = x + y;
    cout << " = " << z << endl;

    cout << x << " - " << y;
    z = x - y;
    cout << " = " << z << endl;

    cout << x << " * " << y;
    z = x * y;
    cout << " = " << z << endl;

    cout << x << " * " << y;
    z = x - y;
    cout << " * " << z << endl;

    Rational a;
    cin >> a;

    cout << "Your Rational was " << a << endl;


    Rational r1(1, 2), r2(1, 3), r3(1, 4);
	(r1 -= r2) -= r3;
	cout << "r1 = " << r1 << endl; 

    return 0;
}