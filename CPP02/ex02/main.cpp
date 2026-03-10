#include <iostream>

#include "Fixed.hpp"

#include <iostream>

#include "Fixed.hpp"  // Replace with the actual filename if different

using std::cout;
using std::endl;

void testArithmetic() {
    Fixed a(3.5f);
    Fixed b(2);

    cout << "\n--- Arithmetic Tests ---" << endl;
    cout << "a + b = " << (a + b).toFloat() << endl;
    cout << "a - b = " << (a - b).toFloat() << endl;
    cout << "a * b = " << (a * b).toFloat() << endl;
    cout << "a / b = " << (a / b).toFloat() << endl;
}

void testComparison() {
    Fixed a(3.5f);
    Fixed b(2.5f);

    cout << "\n--- Comparison Tests ---" << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
}

void testIncrementDecrement() {
    Fixed a(1.0f);

    cout << "\n--- Increment/Decrement Tests ---" << endl;
    cout << "Original a: " << a.toFloat() << endl;

    cout << "Pre-increment: " << (++a).toFloat() << endl;
    cout << "Post-increment: " << (a++).toFloat() << " (after: " << a.toFloat() << ")" << endl;

    cout << "Pre-decrement: " << (--a).toFloat() << endl;
    cout << "Post-decrement: " << (a--).toFloat() << " (after: " << a.toFloat() << ")" << endl;
}

void testMinMax() {
    Fixed a(4.0f);
    Fixed b(2.0f);
    const Fixed c(1.0f);
    const Fixed d(3.0f);

    cout << "\n--- Min/Max Tests ---" << endl;
    cout << "min(a, b): " << Fixed::min(a, b).toFloat() << endl;
    cout << "max(a, b): " << Fixed::max(a, b).toFloat() << endl;
    cout << "min(c, d): " << Fixed::min(c, d).toFloat() << endl;
    cout << "max(c, d): " << Fixed::max(c, d).toFloat() << endl;
}

int main() {
    testArithmetic();
    testComparison();
    testIncrementDecrement();
    testMinMax();

    return 0;
}