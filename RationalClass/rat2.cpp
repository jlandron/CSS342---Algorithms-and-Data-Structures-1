/**@auther Joshua Landron
 * CSS342 Algorithms and Data Structures
 * edited from "Objects and Classes Lecture by Professor Munehiro Fukuda"
 * Description: A Rational is a fraction that is in its simplest form.
 */
#include <iostream>
#include "rat2.h"

using namespace std;
/**
 *@desc Constructor
 *@param int, int
 *@return none
**/
Rational::Rational(int n, int d) : numerator(n < 0 ? -n : n), denominator(d < 0 ? -d : d){
    reduce();
}
/**
 *@desc (<<) overload operator
 *@param ostream&, Rational&
 *@return ostream&
**/
ostream& operator<<(ostream& output, const Rational & r){
    if(r.denominator == 0){
        output << "DIVIDE BY ZERO ERROR!!!" << endl;
    }else if(r.numerator == 0){
        output << 0;
    }else if(r.denominator == 1){
        output << r.numerator;
    }else{
        output << r.numerator << "/" << r.denominator;
    }return output;
}
/**
 *@desc (>>) operator overload
 *@param istream&, Rational&
 *@return istream&
**/
istream& operator>>(istream& input, Rational & r){
    cout << "Enter the numerator: ";
    input >> r.numerator;
    cout << "Enter the Denominator :";
    input >> r.denominator;
    if(r.denominator == 0){
        cout << "DIVIDE BY ZERO!!!" << endl;
        r.denominator = 1;
    }
    r.reduce();
    return input;
}
/**
 *@desc (+) operator overload
 *@param const Rational&
 *@return Rational
**/
Rational Rational::operator+(const Rational & other){
    Rational t;
    t.numerator = numerator * other.denominator + denominator * other.numerator;
    t.denominator = denominator * other.denominator;
    t.reduce();
    return t;
}
/**
 *@desc (-) operator overload
 *@param const Rational&
 *@return Rational
**/
Rational Rational::operator-(const Rational & other){
    Rational t;
    t.numerator = numerator * other.denominator - denominator * other.numerator;
    t.denominator = denominator * other.denominator;
    t.reduce();
    return t;
}
/**
 *@desc (*) operator overload
 *@param const Rational&
 *@return Rational
**/
Rational Rational::operator*(const Rational & other){
    Rational t;
    t.numerator = numerator * other.numerator;
    t.denominator = denominator * other.denominator;
    t.reduce();
    return t;
}
/**
 *@desc (*) operator overload
 *@param int
 *@return Rational
**/
Rational Rational::operator*(int num){
    Rational t;
    t.numerator = numerator * num;
    t.denominator = denominator;
    t.reduce();
    return t;
}
/**
 *@desc (/) operator overload
 *@param const Rational&
 *@return Rational
**/
Rational Rational::operator/(const Rational & other){
    Rational t;
    t.numerator = numerator * other.denominator;
    t.denominator = denominator * other.numerator;
    t.reduce();
    return t;
}
/**
 *@desc (/) operator overload
 *@param int
 *@return Rational
**/
// Rational Rational::operator/(int num){
//     Rational t;
//     if(num == 0){
//         cout << "DIVIDE BY ZERO!!!" << endl;
//     }
//     t.numerator = numerator;
//     t.denominator = denominator * num;
//     t.reduce();
//     return t;
// }
/**
 *@desc (>) operator overload
 *@param const Rational&
 *@return boolean
**/
bool Rational::operator>(const Rational & other) const{
    return float(numerator/denominator) > 
           float(other.numerator/other.denominator);
}
/**
 *@desc (>) operator overload
 *@param const Rational&
 *@return boolean
**/
bool Rational::operator==(const Rational & other) const{
    return (numerator == other.numerator && 
            denominator == other.denominator);
}
/**
 *@desc (>=) operator overload
 *@param const Rational&
 *@return boolean
**/
bool Rational::operator>=(const Rational & other) const{
    return (*this > other || *this == other);
}
/**
 *@desc (<) operator overload
 *@param const Rational&
 *@return boolean
**/
bool Rational::operator<(const Rational & other) const{
    return !(*this > other);
}
/**
 *@desc (<=) operator overload
 *@param const Rational&
 *@return boolean
**/
bool Rational::operator<=(const Rational & other) const{
    return (*this < other || *this == other);
}
/**
 *@desc (!=) operator overload
 *@param const Rational&
 *@return boolean
**/
bool Rational::operator!=(const Rational & other) const{
    return !(*this == other);
}
/**
 *@desc (+=) operator overload
 *@param const Rational&
 *@return Rational&
**/
Rational& Rational::operator+=(const Rational & other){
    numerator = numerator * other.denominator + denominator * other.numerator;
    denominator = denominator * other.denominator;
    reduce();
    return *this;
}
/**
 *@desc (-=) operator overload
 *@param const Rational&
 *@return Rational&
**/
Rational& Rational::operator-=(const Rational & other){
    numerator = numerator * other.denominator - denominator * other.numerator;
    denominator = denominator * other.denominator;
    reduce();
    return *this;
}
/**
 *@desc (*=) operator overload
 *@param const Rational&
 *@return Rational&
**/
Rational& Rational::operator*=(const Rational & other){
    numerator = numerator * other.numerator;
    denominator = denominator * other.denominator;
    return *this;
}
/**
 *@desc (/=) operator overload
 *@param const Rational&
 *@return Rational&
**/
Rational& Rational::operator/=(const Rational & other){
    numerator = numerator * other.denominator;
    denominator = denominator * other.numerator;
    return *this;
}
/**
 *@desc private utility function used to reduce fractions each time they might change
 *@param none
 *@return none
**/
void Rational::reduce(){
    int n = numerator < 0 ? -numerator : numerator;
    int gcf = ratGCF(n, denominator);
    numerator = numerator / gcf;
    denominator = denominator / gcf;
}
/**
 *@desc private utility function used by reduce()
 * This method uses a version of the Euclidian algorithm to find GCF
 *@param none
 *@return none
**/
int Rational::ratGCF(int n, int d){
    int temp;
    while(d != 0){
        temp = d;
        d = n % d;
        n = temp;
    }
    return n;
}