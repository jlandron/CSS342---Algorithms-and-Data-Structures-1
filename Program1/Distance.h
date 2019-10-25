/**@auther Joshua Landron
 * CSS342 Algorithms and Data Structures
 * edited from "Lab 1: Objects and Classes by Professor Munehiro Fukuda"
 */
#ifndef DISTANCE_H
#define DISTANCE_H
#include <iostream>

using namespace std;

class Distance{
    //printing operators
    friend ostream& operator<<(ostream& output, const Distance & w);
    friend istream& operator>>(istream& input, Distance & w);
    
    public:
        //a Distance object can only have int values, and uses overload constructors to ensure the
        //program doesnt fail if passed doubles of floats.
        Distance(int ft = 0, int in = 0); //default constructor
        Distance(float ft, float in); //Type conversion constructors(rounding)
        Distance(double ft, double in);
        //getters
        int getFeet();
        int getInches();
        //overloading math operators
        Distance operator+(Distance);
        Distance operator-(Distance);
        double operator/(Distance);
        Distance operator/(double);
        Distance operator*(Distance);
        Distance operator*(double);
        //increment operator
        Distance & operator+=(Distance);
        Distance & operator-=(Distance);
        Distance & operator/=(double);
        Distance & operator*=(Distance);
        Distance & operator*=(double);
        //comparison operators
        bool operator==(Distance);
        bool operator!=(Distance);
        bool operator<(Distance);
        bool operator<=(Distance);
        bool operator>(Distance);
        bool operator>=(Distance);
        //unary operators
        Distance operator-();
        Distance operator++();

    private:
        int m_Inches;
        int m_Feet;
        //utility functions

        //called whenever the values of Distance might not be stored 
        //in the correct format, i.e. Inches = 20.
        void updateDistance();
    
};
#endif