/**@auther Joshua Landron
 * CSS342 Algorithms and Data Structures
 * edited from "Objects and Classes Lecture by Professor Munehiro Fukuda"
 */
#ifndef RAT2_H
#define RAT2_H
#include <iostream>

using namespace std;

class Rational{
    friend ostream& operator<<(ostream& output, const Rational & r);
    friend istream& operator>>(istream& input, Rational & r);
    public:
        Rational(int = 0, int = 1); //default values if nothing passed
        Rational operator+(const Rational &);
        Rational operator-(const Rational &);
        Rational operator*(const Rational &);
        Rational operator*(int);
        Rational operator/(const Rational &);

        bool operator>(const Rational &) const;
        bool operator==(const Rational &) const;
        bool operator>=(const Rational &) const;
        bool operator<(const Rational &) const;
        bool operator<=(const Rational &) const;
        bool operator!=(const Rational &) const;

        Rational & operator+=(const Rational &);
        Rational & operator-=(const Rational &);
        Rational & operator*=(const Rational &);
        Rational & operator/=(const Rational &);
    private:
        int numerator;
        int denominator;
        void reduce();
        int ratGCF(int, int);
};

#endif