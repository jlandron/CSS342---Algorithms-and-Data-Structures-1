#include "longint.h"
#include <iostream>

// Constructors
LongInt::LongInt(const string str) {
    int i = 0;
    while (!(isdigit(str[i]) || str[i] == '-')) {
        i++;
    }
    if (str[i] == '-') {
        this->negative = true;
        i++;
    } else {
        this->negative = false;
    }
    for (; i < str.length(); i++) {
        if (isdigit(str[i])) {
            digits.addBack(str[i]);
        }
    }
    remove0s();
}
LongInt::LongInt(const LongInt &rhs) {
    this->negative = rhs.negative;
    this->digits = rhs.digits;
    remove0s();
}
LongInt::LongInt() {
    this->negative = false;
    this->digits.addBack('0');
}
// Destructor
LongInt::~LongInt() {
    digits.clear();  // clears all space in the heap
}
// iostream
istream &operator>>(istream &in, LongInt &rhs) {
    char ch;
    ch = in.get();
    while (ch != '\n') {
        if (isdigit(ch) || ch == '-') {
            if (ch == '-' && rhs.negative == false) {
                rhs.negative = true;
                ch = in.get();
            }
            rhs.digits.addBack(ch);
        }
        ch = in.get();
    }
    rhs.remove0s();
    return in;
}
ostream &operator<<(ostream &out, const LongInt &rhs) {
    Deque<char> tmp = rhs.digits;
    if (rhs.negative) {
        out << '-';
    }
    while (!(tmp.isEmpty())) {
        out << tmp.removeFront();
    }
    return out;
}

// Arithmetic binary operators
// slide 28
LongInt LongInt::operator+(const LongInt &rhs) const {
    // positive lhs + negative rhs means ans = lhs - rhs.
    if (!this->negative && rhs.negative) {  // rhs only negative
        LongInt tmp;
        tmp.digits = rhs.digits;  // positive version of rhs
        tmp.negative = false;
        return (*this - tmp);
    }
    // negative lhs + positive rhs means ans = rhs - lhs.
    else if (this->negative && !rhs.negative) {  // lhs only negative
        LongInt tmp;
        tmp.digits = this->digits;  // positive version of lhs
        tmp.negative = false;
        return (rhs - tmp);
    }
    // negative lhs + negative rhs means ans = -(lhs + rhs). Apply operator+ and
    // thereafter set a negative sign.
    LongInt *res = new LongInt;            // new LongInt to return
    if (this->negative && rhs.negative) {  // both negative
        res->negative = true;
    }
    // positive lhs + positive rhs means ans = lhs + rhs.
    Deque<char> left = this->digits;
    Deque<char> right = rhs.digits;
    res->digits.clear();
    int sum;
    int carry = 0;
    while (!(left.isEmpty()) && !(right.isEmpty())) {
        sum = ((left.getBack() - '0') + (right.getBack() - '0') + carry) % 10;
        carry =
            ((left.removeBack() - '0') + (right.removeBack() - '0') + carry) /
            10;
        res->digits.addFront(sum + '0');
    }
    while (!(left.isEmpty())) {
        res->digits.addFront((((left.getBack() - '0') + carry) % 10) + '0');
        carry = ((left.removeBack() - '0') + carry) / 10;
    }
    while (!(right.isEmpty())) {
        res->digits.addFront((((right.getBack() - '0') + carry) % 10) + '0');
        carry = ((right.removeBack() - '0') + carry) / 10;
    }
    if (carry > 0) {
        res->digits.addFront(carry + '0');
    }
    res->remove0s();
    return *res;
}

LongInt LongInt::operator-(const LongInt &rhs) const {
    // positive lhs - negative rhs means ans = lhs + rhs. You should call
    // operator+.
    if (!this->negative && rhs.negative) {
        LongInt tmp;
        tmp.digits = rhs.digits;
        tmp.negative = false;
        return (*this + tmp);
    }
    // negative lhs - positive rhs means ans = -(lhs + rhs). This corresponds to
    // the 4th case of operator+. make temp negative LongInt and do addition
    else if (this->negative && !rhs.negative) {
        LongInt tmp;
        tmp.digits = rhs.digits;  // convert to double negative addition
        tmp.negative = true;
        return (*this + tmp);
    }
    LongInt *res = new LongInt;
    Deque<char> left;
    Deque<char> right;
    int diff;
    int borrow = 0;
    // negative lhs - negative rhs means ans = rhs - lhs.
    LongInt tempL = *this;  // check if ABS(left) < ABS(right)
    tempL.negative = false;
    LongInt tempR = rhs;
    tempR.negative = false;
    if (this->negative && rhs.negative) {  // both negative
        if (tempL < tempR) {               // check ABS(left) < ABS(right)
            left = rhs.digits;
            right = this->digits;  // if true, result is positive, swap left and
                                   // right
            res->negative = false;
        } else {
            left = this->digits;  // else, result is negative, do not swap
            right = rhs.digits;
            res->negative = true;
        }
    } else if (!this->negative && !rhs.negative) {  // both positive
        if (tempL < tempR) {  // check ABS(left) < ABS(right)
            left = rhs.digits;
            right = this->digits;  // if true, result is negative, swap left and
                                   // right
            res->negative = true;
        } else {
            left = this->digits;  // else, result is negative, do not swap
            right = rhs.digits;
            res->negative = false;
        }
    }
    // positive lhs - positive rhs means ans = lhs - rhs.
    // check if left is smaller than right (i.e. 10 - 100)
    res->digits.clear();
    // implement subtraction
    while (!(left.isEmpty()) && !(right.isEmpty())) {
        int l = (left.removeBack() - '0') - borrow;
        int r = (right.removeBack() - '0');
        if (l < r) {
            borrow = 1;
        } else {
            borrow = 0;
        }
        diff = ((l - r) + (borrow * 10));
        res->digits.addFront(diff + '0');
    }
    while (!(left.isEmpty())) {
        int rem = ((left.removeBack() - '0') - borrow);
        if (rem < 0) {
            rem += 10;
        } else {
            borrow = 0;
        }
        res->digits.addFront(rem + '0');
    }
    while (!(right.isEmpty())) {
        int rem = ((right.removeBack() - '0') - borrow);
        if (rem < 0) {
            rem += 10;
        } else {
            borrow = 0;
        }
        res->digits.addFront(rem + '0');
        borrow = 0;
    }
    res->remove0s();
    return *res;
}
// assignment operators
// deep copy operator
const LongInt &LongInt::operator=(const LongInt &rhs) {
    this->negative = rhs.negative;
    this->digits = rhs.digits;
    return *this;
}
// Logical binary operators
// compare digits at front
bool LongInt::operator<(const LongInt &rhs) const {
    if (this->negative && rhs.negative) {  // check sign, if both negative
        LongInt left = *this;              // create new positive longInts
        left.negative = false;  // compare opposite (i.e. -1000 < -100 is true)
        LongInt right = rhs;    // compare 100 < 1000
        right.negative = false;
        return (right < left);
    } else if (this->negative && !rhs.negative) {
        return true;
    } else if (!this->negative && rhs.negative) {
        return false;
    }
    int thisSize = 0;
    int thatSize = 0;
    Deque<char> tmp = this->digits;
    for (; !tmp.isEmpty(); tmp.removeBack()) {
        thisSize++;
    }
    tmp = rhs.digits;
    for (; !tmp.isEmpty(); tmp.removeBack()) {
        thatSize++;
    }
    if (thisSize < thatSize) {  // check size
        return false;
    }
    // check each digit from high to low
    Deque<char> left = this->digits;
    Deque<char> right = rhs.digits;
    while (!(left.isEmpty()) && !(right.isEmpty())) {
        if (left.removeFront() > right.removeFront()) {
            return false;
        }
    }
    return true;
}
bool LongInt::operator<=(const LongInt &rhs) const {
    return (*this < rhs || *this == rhs);
}
bool LongInt::operator>(const LongInt &rhs) const { return (!(*this < rhs)); }
bool LongInt::operator>=(const LongInt &rhs) const {
    return (*this > rhs || *this == rhs);
}
bool LongInt::operator==(const LongInt &rhs) const {
    if (this->negative != rhs.negative) {
        return false;
    }
    Deque<char> left = this->digits;
    Deque<char> right = rhs.digits;
    while (!(left.isEmpty()) && !(right.isEmpty())) {
        if (left.removeBack() != right.removeBack()) {
            return false;
        }
    }
    if (left.isEmpty() && right.isEmpty()) {
        return true;
    }
    return false;
}
bool LongInt::operator!=(const LongInt &rhs) const { return !(*this == rhs); }
// helpers
void LongInt::remove0s() {
    while (!digits.isEmpty() && digits.getFront() == '0') {
        digits.removeFront();
        if (digits.getBack() == '0' && digits.getFront() == '0') {
            this->negative = false;
        }
    }
    if (digits.isEmpty()) {
        digits.addBack('0');
        this->negative = false;
    }
}
int LongInt::getSize(const LongInt &temp) {
    int size = 0;
    Deque<char> tmp = temp.digits;
    for (; !tmp.isEmpty(); tmp.removeBack()) {
        size++;
    }
    return size;
}