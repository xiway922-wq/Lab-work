#include "Fraction.h"
#include <cmath>

int gcd(int a, int b)
{
    int r;
    a = abs(a);
    b = abs(b);

    while(b!=0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

    Fraction::Fraction(int num, int den)
    {
        if(den==0)
        {
            throw std::invalid_argument("Denominator 0?!");
        }
        if(den<0)
        {
            num=-num;
            den=-den;
        }

        numerator = num;
        denominator = den;

        simplify();
    }
    
    Fraction::Fraction(const Fraction& other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }

    int Fraction::get_numerator() const
    {
        return numerator;
    }

    int Fraction::get_denominator() const
    {
        return denominator;
    }
    
    
    Fraction Fraction::add(const Fraction& other) const
    {
        int new_den = denominator * other.denominator;
        int new_num = numerator * other.denominator + other.numerator * denominator;
        return Fraction(new_num, new_den);
    }

    Fraction Fraction::multiply(const Fraction& other) const
    {
       int new_den = denominator * other.denominator;
       int new_num = numerator * other.numerator;
       return Fraction(new_num, new_den);
    }
    
    Fraction Fraction::division(const Fraction& other) const
    {
       int new_den = denominator * other.numerator;
       int new_num = numerator * other.denominator;
       return Fraction(new_num, new_den);
    }

void Fraction::simplify()
{
    int div = gcd(numerator, denominator);
    numerator /= div;
    denominator /= div;
}

void Fraction::print() const
{
    if(denominator==1)
    cout << numerator << "\n";
    else
    cout << numerator << "/" << denominator << "\n";
}
