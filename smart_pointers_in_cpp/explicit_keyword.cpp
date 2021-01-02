//explicit keyword in cpp
// Link for Reference:
// https://www.geeksforgeeks.org/g-fact-93/
// https://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-mean

/*
NOTES:
In C++, if a class has a constructor which can be called with a single argument,
then this constructor becomes conversion constructor because such a constructor
allows conversion of the single argument to the class being constructed.
We can avoid such implicit conversions as these may lead to unexpected results.
We can make the constructor explicit with the help of explicit keyword.
*/

#include <iostream>

using namespace std;

class Complex
{
private:
	double real;
	double imag;

public:
	// Default constructor
	explicit Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

	// A method to compare two Complex numbers
	bool operator== (Complex rhs) {
	return (real == rhs.real && imag == rhs.imag)? true : false;
	}
};

int main()
{
	// a Complex object
	Complex com1(3.0, 0.0);

	if (com1 == (Complex)3.0) // You need to explicitly typecast the object type because Complex constructor is declared explicit
	cout << "Same";
	else
	cout << "Not Same";
	return 0;
}
