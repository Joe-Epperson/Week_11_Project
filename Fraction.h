#pragma once
// Joe Epperson, IV
// 4/05/2021
// Lab 11

#include <iostream>
using namespace std;

class Fraction
{

	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

private:
	int getGCD(int num1, int num2);

	// Declaring private class variables
	int numerator;
	int denominator;

public:
	void reduce();

	// Declaring and defining a constructor for the Fraction class
	Fraction() { numerator = 0; denominator = 0; }

	// Declaring the overload operators for input and output streams
	friend ostream& operator << (ostream& output, const Fraction& fract);
	friend istream& operator >> (istream& input, Fraction& fract);

	// Declaring the overload operators for '+' '-' '*' '/'
	const Fraction operator+ (Fraction rhs);
	const Fraction operator- (Fraction rhs);
	const Fraction operator* (Fraction rhs);
	const Fraction operator/ (Fraction rhs);

	// Declaring the overload operator for the equality bool
	bool operator== (Fraction rhs);

};

