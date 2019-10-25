/**@auther Joshua Landron
 * CSS342 Algorithms and Data Structures
 * edited from "Lab 1: Objects and Classes by Professor Munehiro Fukuda"
 */
#ifndef WEIGHT_H
#define WEIGHT_H
#include <iostream>

using namespace std;

class Weight{
    //printing operators
    friend ostream& operator<<(ostream& output, const Weight & w);
    friend istream& operator>>(istream& input, Weight & w);
    
    public:
        //a weight object can only have int values, and uses overload constructors to ensure the
        //program doesnt fail if passed doubles of floats.
        Weight(int = 0, int = 0); //default constructor
        Weight(float, float); //Type conversion constructors
        Weight(double, double);
        //getters
        int getPounds();
        int getOnces();
        //overloading math operators
        Weight operator+(Weight);
        Weight operator-(Weight);
        double operator/(Weight);
        Weight operator/(double);
        Weight operator*(Weight);
        Weight operator*(double);
        //increment operator
        Weight & operator+=(Weight);
        Weight & operator-=(Weight);
        Weight & operator/=(double);
        Weight & operator*=(Weight);
        Weight & operator*=(double);
        
        //comparison operators
        bool operator==(Weight);
        bool operator!=(Weight);
        bool operator<(Weight);
        bool operator<=(Weight);
        bool operator>(Weight);
        bool operator>=(Weight);
        //unary operators
        Weight operator-();
        Weight operator++();

    private:
        int m_Ounces;
        int m_Pounds;
        //utility functions

        //called whenever the values of weight might not be stored 
        //in the correct format, i.e. ounces = 20.
        void updateWeight();
    
};
#endif