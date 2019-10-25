/**@auther Joshua Landron
 * CSS342 Algorithms and Data Structures
 * edited from "La 1: Objects and Classes, by Professor Munehiro Fukuda"
 */
#include <iostream>
#include "Weight.h"
/**
 *@desc Default constructor
 *@param int, int
 *@return Weight object
**/
Weight::Weight(int lb, int oz){
    m_Pounds = lb;
    m_Ounces = oz;
    updateWeight();
}
/**
 *@desc overload constructor that casts the passed floats to int values
 *@param float, float
 *@return Weight object
**/
Weight::Weight(float lb, float oz){
    m_Pounds = (int)lb;
    m_Ounces = (int)oz;
    updateWeight();
}
/**
 *@desc overload constructor that casts the passed doubles to int values
 *@param double, double
 *@return Weight object
**/
Weight::Weight(double lb, double oz){
    m_Pounds = (int)lb;
    m_Ounces = (int)oz;
    updateWeight();
}
//-----------iostream overloads--------------
/**
 *@desc (<<) operator
 *@param ostream&, const Weight&
 *@return ostream&
**/
ostream& operator<<(ostream& output, const Weight & w){
    if(w.m_Pounds == 0 && w.m_Ounces == 0){
        output << "0 oz";
    }
    else{  
        if(w.m_Pounds == 1 || w.m_Pounds == -1){
            output << w.m_Pounds << " lb ";
        }else if(w.m_Pounds != 0){
            output << w.m_Pounds << " lbs ";
        }
        if(w.m_Ounces == 1 || w.m_Ounces == -1){
            output << w.m_Ounces << " oz ";
        }else if(w.m_Ounces != 0){
            output << w.m_Ounces << " ozs ";
        }
    }
    return output;
}
/**
 *@desc (>>) operator
 *@param istream&, Weight&
 *@return istream&
**/
istream& operator>>(istream& input, Weight & w){
    double lb, oz;
    input >> lb;
    w.m_Pounds = (int)lb;
    input >> oz;
    w.m_Ounces = (int)oz;
    w.updateWeight();
    return input;
}
int Weight::getPounds(){
    return m_Pounds;
}
int Weight::getOnces(){
    return m_Ounces;
}
//------------math operators---------------
/**
 *@desc (+) operator
 *@param Weight
 *@return Weight
 *@required adding to weight abjects is only defined as adding two weight objects together
**/
Weight Weight::operator+(Weight other){
    Weight result;
    result.m_Ounces = this->m_Ounces + other.m_Ounces;
    result.m_Pounds = this->m_Pounds + other.m_Pounds;
    result.updateWeight();
    return result;
}
/**
 *@desc (-) operator
 *@param Weight
 *@return Weight
 *@required subtracting from weight abjects is only defined as subtracing two weight objects
**/
Weight Weight::operator-(Weight other){
    Weight result;
    result.m_Ounces = this->m_Ounces - other.m_Ounces;
    result.m_Pounds = this->m_Pounds - other.m_Pounds;
    result.updateWeight();
    return result;
}
/**
 *@desc (/) operator
 *@param Weight
 *@return double (The ratio of two weight objects)
**/
double Weight::operator/(Weight other){
    double result;
    int ouncesThis = this->m_Ounces + (16 * this->m_Pounds);
    int ouncesOther = other.m_Ounces + (16 * other.m_Pounds);
    if(ouncesOther == 0){
        cout << "DIVISION BY ZERO!!!" << endl;
    }
    result = ((double)ouncesThis / (double)ouncesOther);
    return result;
}
/**
 *@desc (/) operator
 *@param double
 *@return Weight
**/
Weight Weight::operator/(double num){
    Weight result;
    if(num == 0){
        cout << "DIVISION BY ZERO!!!" << endl;
    }
    result.m_Ounces = (this->m_Ounces + (16 * this->m_Pounds)) / num;
    result.updateWeight();
    return result;
}
/**
 *@desc (*) operator
 *@param Weight
 *@return Weight
**/
Weight Weight::operator*(Weight other){
    Weight result;
    int ouncesThis = this->m_Ounces + (16 * this->m_Pounds);
    int ouncesOther = other.m_Ounces + (16 * other.m_Pounds);
    result.m_Ounces = (ouncesThis * ouncesOther);
    result.updateWeight();
    return result;
}
/**
 *@desc (*) operator
 *@param double
 *@return Weight
**/
Weight Weight::operator*(double num){
    Weight result;
    result.m_Ounces = this->m_Ounces * num;
    result.m_Pounds = this->m_Pounds * num;
    result.updateWeight();
    return result;
}
//-----------increment operators--------------
/**
 *@desc (+=) operator
 *@param Weight
 *@return Weight&
 *@required adding to weight abjects is only defined as adding two weight objects together
**/
Weight & Weight::operator+=(Weight other){
    this->m_Ounces = this->m_Ounces + other.m_Ounces;
    this->m_Pounds = this->m_Pounds + other.m_Pounds;
    return *this;
}
/**
 *@desc (-=) operator
 *@param Weight
 *@return Weight&
 *@required subtracting from weight abjects is only defined as subtracing two weight objects
**/
Weight & Weight::operator-=(Weight other){
    this->m_Ounces = this->m_Ounces - other.m_Ounces;
    this->m_Pounds = this->m_Pounds - other.m_Pounds;
    return *this;
}
/**
 *@desc (/=) operator
 *@param double
 *@return Weight&
**/
Weight & Weight::operator/=(double num){
    if(num == 0){
        cout << "DIVISION BY ZERO!!!" << endl;
    }
    this->m_Ounces = (this->m_Ounces + (16 * this->m_Pounds)) / num;
    this->m_Pounds = 0;
    updateWeight();
    return *this;
}
/**
 *@desc (*=) operator
 *@param Weight
 *@return Weight&
**/
Weight & Weight::operator*=(Weight other){
    int ouncesThis = this->m_Ounces + (16 * this->m_Pounds);
    int ouncesOther = other.m_Ounces + (16 * other.m_Pounds);
    m_Pounds = 0;
    updateWeight();
    return *this;
}
/**
 *@desc (*=) operator
 *@param double
 *@return Weight
**/
Weight & Weight::operator*=(double num){
    this->m_Ounces = (this->m_Ounces + (16 * this->m_Pounds)) * num;
    this->m_Pounds = 0;
    updateWeight();
    return *this;
}
//------------comparison operators-------------
/**
 *@desc (==) operator
 *@param Weight
 *@return bool
**/
bool Weight::operator==(Weight other){
    if(this->m_Ounces == other.m_Ounces && 
        this->m_Pounds == other.m_Pounds){
        return true;
    }
    return false;
}
/**
 *@desc (!=) operator
 *@param Weight
 *@return bool
**/
bool Weight::operator!=(Weight other){
    return(!(*this == other));
}
/**
 *@desc (<) operator
 *@param Weight
 *@return bool
**/
bool Weight::operator<(Weight other){
    if(this->m_Pounds < other.m_Pounds){
        return true;
    }else if(this->m_Pounds == other.m_Pounds && 
            this->m_Ounces < other.m_Ounces){
        return true;
    }
    return false;
}
/**
 *@desc (<=) operator
 *@param Weight
 *@return bool
**/
bool Weight::operator<=(Weight other){
    return(*this < other || *this == other);
}
/**
 *@desc (>) operator
 *@param Weight
 *@return bool
**/
bool Weight::operator>(Weight other){
    if(this->m_Pounds > other.m_Pounds){
        return true;
    }else if(this->m_Pounds == other.m_Pounds && this->m_Ounces > other.m_Ounces){
        return true;
    }
    return false;
}/**
 *@desc (>=) operator
 *@param Weight
 *@return bool
**/
bool Weight::operator>=(Weight other){
    return(*this > other || *this == other);
}
//------------Unary operators------------
/**
 *@desc (-) operator
 *@param none
 *@return Weight
**/
Weight Weight::operator-(){
    Weight result;
    result.m_Ounces = -(this->m_Ounces);
    result.m_Pounds = -(this->m_Pounds);
    return result;
}
/**
 *@desc (++) operator
 *@param none
 *@return Weight
**/
Weight Weight::operator++(){
    Weight result;
    result.m_Ounces = this->m_Ounces + 1;
    result.m_Pounds = this->m_Pounds;
    result.updateWeight();
    return result;
}
//--------------utility functions-------------
/**
 *@desc updateWeight 
 *reduces the weight such that the value of ounces is never more than 16
 *also ensures that a weight object is eiher all positive or all negative
 *this function is private and directly modifies the object it is in
 *@param none
 *@return void
**/
void Weight::updateWeight(){
    if(this->m_Pounds >= 0 && this->m_Ounces >= 0){
        while(this->m_Ounces >= 16){
            this->m_Ounces = this->m_Ounces - 16;
            this->m_Pounds++;
        }
    }else if(this->m_Pounds <= 0 && this->m_Ounces <= 0){
        while(this->m_Ounces < -16){
            this->m_Ounces = this->m_Ounces + 16;
            this->m_Pounds--;
        }
    }else{
        this->m_Ounces = this->m_Ounces + (16 * this->m_Pounds);
        this->m_Pounds = 0;
        updateWeight();
    }
}