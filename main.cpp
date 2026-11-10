#include "Fraction.h"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

int main()
{
    
try {
        Fraction f1(2, 4); 
        cout << "f1 = "; f1.print();

        Fraction f2(3, -9); 
        cout << "f2 = "; f2.print();
        
        Fraction sum = f1.add(f2);
        cout << "f1 + f2 = "; sum.print();

        Fraction mult = f1.multiply(f2); 
        cout << "f1 * f2 = "; mult.print();

        Fraction div = f1.division(f2); 
        cout << "f1 / f2 = "; div.print();

        Fraction bad(5, 0);
    } 
        catch (const std::invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

}