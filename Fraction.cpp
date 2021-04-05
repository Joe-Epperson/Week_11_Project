// Joe Epperson, IV
// jee4cf@umsystem.edu
// 4/05/2021
// CS201L Lab 11

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
	try
	{
		if (num1 == 0)
		{
			throw runtime_error("Error: Cannot divide by zero");
		}
		int remainder = num2 % num1;
		if (remainder != 0)
			return getGCD(remainder, num1);
		return num1;
	}
	catch (runtime_error& e)
	{
		cout << e.what() << endl;
	}
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	try
	{
		int gcd = getGCD(numerator, denominator);
		if (gcd == 0)
		{
			throw runtime_error("Error: Cannot divide by zero");
		}
		numerator /= gcd;
		denominator /= gcd;
	}
	catch (runtime_error& e)
	{
		cout << e.what() << endl;
	}

	// Changing the values based on whether or not they are negative
	if ((numerator < 0) && (denominator < 0))
	{
		numerator *= -1;
		denominator *= -1;
	}
	else if ((denominator < 0) && (numerator >= 0))
	{
		numerator *= -1;
		denominator *= -1;
	}
}

// Defining the operator overload functions for '+' '-' '*' '/'
const Fraction Fraction::operator+(Fraction rhs)
{
	Fraction endVal;
	endVal.denominator = denominator * rhs.denominator;
	endVal.numerator = (numerator * (endVal.denominator / denominator)) + (rhs.numerator * (endVal.denominator / rhs.denominator));
	endVal.reduce();
	return endVal;
}

const Fraction Fraction::operator-(Fraction rhs)
{
	Fraction endVal;
	endVal.denominator = denominator * rhs.denominator;
	endVal.numerator = (numerator * (endVal.denominator / denominator)) - (rhs.numerator * (endVal.denominator / rhs.denominator));
	endVal.reduce();
	return endVal;
}

const Fraction Fraction::operator*(Fraction rhs)
{
	Fraction endVal;
	endVal.denominator = denominator * rhs.denominator;
	endVal.numerator = numerator * rhs.numerator;
	endVal.reduce();
	return endVal;
}

const Fraction Fraction::operator/(Fraction rhs)
{
	Fraction endVal;
	endVal.numerator = numerator * rhs.denominator;
	endVal.denominator = denominator * rhs.numerator;
	endVal.reduce();
	return endVal;
}


// Defining the bool operator overload
bool Fraction::operator==(Fraction rhs)
{
	if ((numerator == rhs.numerator) && (denominator == rhs.denominator))
	{
		return true;
	}
	return false;
}

// Defining the operator overload functions for the input stream and the output stream
ostream& operator<<(ostream& output, const Fraction& fract)
{
	output << fract.numerator << '/' << fract.denominator << endl;
	return output;
}

istream& operator>>(istream& input, Fraction& fract)
{
	char slash;
	input >> fract.numerator >> slash >> fract.denominator;
	return input;
}
