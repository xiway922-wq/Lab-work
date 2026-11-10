#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

class Fraction{
private:
    int numerator;
    int denominator;

    void simplify();

public:
    Fraction() = delete;
    Fraction(int num, int den);
    Fraction(const Fraction& other);

    int get_numerator() const;
    int get_denominator() const;
    
    Fraction add(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;
    Fraction division(const Fraction& other) const;
    
    void print() const;
};