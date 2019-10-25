/**@auther Joshua Landron
 * CSS342 Algorithms and Data Structures
 * edited from "Program 1: Objects and Classes, by Professor Munehiro Fukuda"
 */
#include <iostream>
#include "Distance.h"
/**
 *@desc Default constructor
 *@param int, int
 *@return Distance object
**/
Distance::Distance(int ft, int in) : m_Feet(ft), m_Inches(in) {
    updateDistance();
}
/**
 *@desc overload constructor that casts the passed floats to int values
 *by rounding instead of truncation
 *@param float, float
 *@return Distance object
**/
Distance::Distance(float ft, float in){
    m_Feet = (int)(ft + 0.5);
    m_Inches = (int)(in + 0.5);
    updateDistance();
}
/**
 *@desc overload constructor that casts the passed doubles to int values
 *by rounding instead of truncation
 *@param double, double
 *@return Distance object
**/
Distance::Distance(double ft, double in){
    m_Feet = (int)(ft + 0.5);
    m_Inches = (int)(in + 0.5);
    updateDistance();
}
//-----------iostream overloads--------------
/**
 *@desc (<<) operator
 *@param ostream&, const Distance&
 *@return ostream&
**/
ostream& operator<<(ostream& output, const Distance & w){
    if(w.m_Feet == 0 && w.m_Inches == 0){
        output << "0 inch";
    }
    else{  
        if(w.m_Feet == 1 || w.m_Feet == -1){
            output << w.m_Feet << " foot ";
        }else if(w.m_Feet != 0){
            output << w.m_Feet << " feet ";
        }
        if(w.m_Inches == 1 || w.m_Inches == -1){
            output << w.m_Inches << " inch ";
        }else if(w.m_Inches != 0){
            output << w.m_Inches << " inches ";
        }
    }
    return output;
}
/**
 *@desc (>>) operator
 *@param istream&, Distance&
 *@return istream&
**/
istream& operator>>(istream& input, Distance & w){
    double ft, in;
    input >> ft;
    w.m_Feet = (int)ft;
    input >> in;
    w.m_Inches = (int)in;
    w.updateDistance();
    return input;
}
int Distance::getFeet(){
    return this->m_Feet;
}
int Distance::getInches(){
    return this->m_Inches;
}
//------------math operators---------------
/**
 *@desc (+) operator
 *@param Distance
 *@return Distance
 *@required adding to Distance abjects is only defined as adding two Distance objects together
**/
Distance Distance::operator+(Distance other){
    Distance result;
    result.m_Inches = this->m_Inches + other.m_Inches;
    result.m_Feet = this->m_Feet + other.m_Feet;
    result.updateDistance();
    return result;
}
/**
 *@desc (-) operator
 *@param Distance
 *@return Distance
 *@required subtracting from Distance abjects is only defined as subtracing two Distance objects
**/
Distance Distance::operator-(Distance other){
    Distance result;
    result.m_Inches = this->m_Inches - other.m_Inches;
    result.m_Feet = this->m_Feet - other.m_Feet;
    result.updateDistance();
    return result;
}
/**
 *@desc (/) operator
 *@param Distance
 *@return double (The ratio of two Distance objects)
**/
double Distance::operator/(Distance other){
    double result;
    int InchesThis = this->m_Inches + (12 * this->m_Feet);
    int InchesOther = other.m_Inches + (12 * other.m_Feet);
    if(InchesOther == 0){
        cout << "DIVISION BY ZERO!!!" << endl;
    }
    result = ((double)InchesThis / (double)InchesOther);
    return result;
}
/**
 *@desc (/) operator
 *@param double
 *@return Distance
**/
Distance Distance::operator/(double num){
    Distance result;
    if(num == 0){
        cout << "DIVISION BY ZERO!!!" << endl;
    }
    result.m_Inches = (this->m_Inches + (12 * this->m_Feet)) / num;
    result.updateDistance();
    return result;
}
/**
 *@desc (*) operator
 *@param Distance
 *@return Distance
**/
Distance Distance::operator*(Distance other){
    Distance result;
    int InchesThis = this->m_Inches + (12 * this->m_Feet);
    int InchesOther = other.m_Inches + (12 * other.m_Feet);
    result.m_Inches = (InchesThis * InchesOther);
    result.updateDistance();
    return result;
}
/**
 *@desc (*) operator
 *@param double
 *@return Distance
**/
Distance Distance::operator*(double num){
    Distance result;
    result.m_Inches = this->m_Inches * num;
    result.m_Feet = this->m_Feet * num;
    result.updateDistance();
    return result;
}
//-----------increment operators--------------
/**
 *@desc (+=) operator
 *@param Distance
 *@return Distance&
 *@required adding to Distance abjects is only defined as adding two Distance objects together
**/
Distance & Distance::operator+=(Distance other){
    this->m_Inches = this->m_Inches + other.m_Inches;
    this->m_Feet = this->m_Feet + other.m_Feet;
    return *this;
}
/**
 *@desc (-=) operator
 *@param Distance
 *@return Distance&
 *@required subtracting from Distance abjects is only defined as subtracing two Distance objects
**/
Distance & Distance::operator-=(Distance other){
    this->m_Inches = this->m_Inches - other.m_Inches;
    this->m_Feet = this->m_Feet - other.m_Feet;
    return *this;
}
/**
 *@desc (/=) operator
 *@param double
 *@return Distance&
**/
Distance & Distance::operator/=(double num){
    if(num == 0){
        cout << "DIVISION BY ZERO!!!" << endl;
    }
    this->m_Inches = (this->m_Inches + (12 * this->m_Feet)) / num;
    this->m_Feet = 0;
    updateDistance();
    return *this;
}
/**
 *@desc (*=) operator
 *@param Distance
 *@return Distance&
**/
Distance & Distance::operator*=(Distance other){
    int InchesThis = this->m_Inches + (12 * this->m_Feet);
    int InchesOther = other.m_Inches + (12 * other.m_Feet);
    m_Feet = 0;
    updateDistance();
    return *this;
}
/**
 *@desc (*=) operator
 *@param double
 *@return Distance
**/
Distance & Distance::operator*=(double num){
    this->m_Inches = (this->m_Inches + (12 * this->m_Feet)) * num;
    this->m_Feet = 0;
    updateDistance();
    return *this;
}
//------------comparison operators-------------
/**
 *@desc (==) operator
 *@param Distance
 *@return bool
**/
bool Distance::operator==(Distance other){
    if(this->m_Inches == other.m_Inches && 
        this->m_Feet == other.m_Feet){
        return true;
    }
    return false;
}
/**
 *@desc (!=) operator
 *@param Distance
 *@return bool
**/
bool Distance::operator!=(Distance other){
    return(!(*this == other));
}
/**
 *@desc (<) operator
 *@param Distance
 *@return bool
**/
bool Distance::operator<(Distance other){
    if(this->m_Feet < other.m_Feet){
        return true;
    }else if(this->m_Feet == other.m_Feet && 
            this->m_Inches < other.m_Inches){
        return true;
    }
    return false;
}
/**
 *@desc (<=) operator
 *@param Distance
 *@return bool
**/
bool Distance::operator<=(Distance other){
    return(*this < other || *this == other);
}
/**
 *@desc (>) operator
 *@param Distance
 *@return bool
**/
bool Distance::operator>(Distance other){
    if(this->m_Feet > other.m_Feet){
        return true;
    }else if(this->m_Feet == other.m_Feet && this->m_Inches > other.m_Inches){
        return true;
    }
    return false;
}/**
 *@desc (>=) operator
 *@param Distance
 *@return bool
**/
bool Distance::operator>=(Distance other){
    return(*this > other || *this == other);
}
//------------Unary operators------------
/**
 *@desc (-) operator
 *@param none
 *@return Distance
**/
Distance Distance::operator-(){
    Distance result;
    result.m_Inches = -(this->m_Inches);
    result.m_Feet = -(this->m_Feet);
    return result;
}
/**
 *@desc (++) operator
 *@param none
 *@return Distance
**/
Distance Distance::operator++(){
    Distance result;
    result.m_Inches = this->m_Inches + 1;
    result.m_Feet = this->m_Feet;
    result.updateDistance();
    return result;
}
//--------------utility functions-------------
/**
 *@desc updateDistance 
 *reduces the Distance such that the value of Inches is never more than 12
 *also ensures that a Distance object is eiher all positive or all negative
 *this function is private and directly modifies the object it is in
 *@param none
 *@return void
**/
void Distance::updateDistance(){
    if(this->m_Feet >= 0 && this->m_Inches >= 0){
        while(this->m_Inches >= 12){
            this->m_Inches = this->m_Inches - 12;
            this->m_Feet++;
        }
    }else if(this->m_Feet <= 0 && this->m_Inches <= 0){
        while(this->m_Inches < -12){
            this->m_Inches = this->m_Inches + 12;
            this->m_Feet--;
        }
    }else{
        this->m_Inches = this->m_Inches + (12 * this->m_Feet);
        this->m_Feet = 0;
        updateDistance();
    }
}