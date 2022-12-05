#pragma once

#include <iostream>
#include <vector>
#include <cassert>

// Class to create and manage Fraction objects
class Fraction {

public:
	Fraction(int newNumerator = 0, int newDenominator = 1) : m_numerator(newNumerator), m_denominator(newDenominator) { assert(newDenominator != 0); };
	~Fraction() = default;

	// Return numerator
	int GetNumerator() const { return m_numerator; }; 

	// Return denominator
	int GetDenominator() const { return m_denominator; };

	// Set numerator
	void SetNumerator(int newNumerator) { m_numerator = newNumerator; };

	// Set denominator
	void SetDenominator(int newDenominator) { assert(newDenominator != 0); m_denominator = newDenominator; };

	// Reduce Fraction initial form to lowest terms
	Fraction ReduceFraction();

	// Display Fraction in initial form
	void DisplayInitial() const;
	
	// Simplify fraction to a mixed form if possible and Display mixed form
	void DisplayMixed() const;
	
	// Display a result as a decimal number
	void DisplayReal() const;

	// Display initial, reduced, mixed and decimal forms of a Fraction object
	void DisplayInfo();

	// Binary operators for addition, substraction, multiplication and division of Fraction objects
	Fraction operator+(const Fraction& frac) const;
	Fraction operator-(const Fraction& frac) const;
	Fraction operator*(const Fraction& frac) const;
	Fraction operator/(const Fraction& frac) const;
	
	// Unary operator, returns opposite Fraction
	Fraction operator-() const { return Fraction(-m_numerator, m_denominator); }


private:
	int m_numerator;
	int m_denominator;

};


// Class to store Fraction objects in a vector object
class FractionList {

public:
	FractionList() = default;
	~FractionList() = default;

	// Read Fractions from a file and saves as a FractionList vector object, takes file name as an argument
	void ReadFile(const std::string fileName);

	// Reduce FractionList to the lowest terms
	FractionList ReduceList();

	// Display each Fraction from a list in initial, reduced, mixed and decimal forms
	void DisplayList();

	// Access a specific element from a FractionList
	Fraction F(uint8_t i) const { return m_list[i - 1]; };

	// Add all the Fraction objects stored in a list and display and return a resulting sum as a Fraction obj
	Fraction ListTotal();

private:
	std::vector <Fraction> m_list;
};