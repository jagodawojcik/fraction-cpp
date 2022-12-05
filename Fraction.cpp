#include "Fraction.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


// Calculate greatest common divisor of two integers
int gcdFinder(int numerator, int denominator);


Fraction Fraction::ReduceFraction() {
	int cDivisor{1};
	int numerator{m_numerator}, denominator{m_denominator};
	
	cDivisor = gcdFinder(numerator, denominator);

	numerator = numerator / cDivisor; 
	denominator = denominator / cDivisor;

	Fraction reducedFraction;
	reducedFraction = Fraction(numerator, denominator);
	
	return reducedFraction;
};

void Fraction::DisplayInitial() const {
	if (m_numerator < 0 && m_denominator < 0)
		std::cout << "Initial: ";
	else if (m_numerator < 0 || m_denominator < 0)
		std::cout << "Initial: -";
	else
		std::cout << "Initial: ";
		
	std::cout << abs(m_numerator) << "/" << abs(m_denominator) << std::endl;
};

void Fraction::DisplayMixed() const {
	int reminder{ 0 };
	int result{ 0 };
	
	reminder = m_numerator % m_denominator;
	result = m_numerator/m_denominator;
	
	if (m_numerator < 0 && m_denominator < 0)
		std::cout << "Mixed: ";
	else if (m_numerator < 0 || m_denominator < 0)
		std::cout << "Mixed: -";
	else
		std::cout << "Mixed: ";

	if (result == 0) 
		std::cout << abs(m_numerator) << '/' << abs(m_denominator) << std::endl;
	else if (reminder == 0)
		std::cout << abs(result) << std::endl;
	else 
		std::cout << abs(result) << ' ' << abs(reminder) << '/' << abs(m_denominator) << std::endl;
};

void Fraction::DisplayReal() const {
	std::cout << "Real: " << float(m_numerator) / m_denominator << std::endl;
};

void Fraction::DisplayInfo() {

	Fraction ReducedFraction{};

	DisplayInitial();
	ReducedFraction = ReduceFraction();
	std::cout << "Reduced ";
	ReducedFraction.DisplayInitial();
	ReducedFraction.DisplayMixed();
	DisplayReal();
	std::cout << std::endl;
};

Fraction Fraction::operator+(const Fraction& frac) const {
	
	short int newNumerator{0}, newDenominator{1};

	newNumerator = (m_numerator * frac.m_denominator) + (frac.m_numerator * m_denominator);
	newDenominator = m_denominator * frac.m_denominator;

	return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator-(const Fraction& frac) const {
	long newNumerator{ 0 }, newDenominator{ 1 };

	newNumerator = (m_numerator * frac.m_denominator) - (frac.m_numerator * m_denominator);
	newDenominator = m_denominator * frac.m_denominator;

	return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(const Fraction& frac) const {
	return Fraction(m_numerator*frac.m_numerator, m_denominator*frac.m_denominator);
}

Fraction Fraction::operator/(const Fraction& frac) const {
	return Fraction(m_numerator * frac.m_denominator, m_denominator * frac.m_numerator);
}

int gcdFinder(int numerator, int denominator) {
	if (denominator == 0)
		return numerator;
	// else do nothing

	return gcdFinder(denominator, numerator % denominator);
}

void FractionList::ReadFile(std::string fileName) {

	std::ifstream inputFile(fileName);
	if (!inputFile.fail()) {

		std::string Numerator, Denominator;
		Fraction existingFraction;

		while (inputFile >> Numerator) {
			existingFraction.SetNumerator(stoi(Numerator));
			inputFile >> Denominator;
			existingFraction.SetDenominator(stoi(Denominator));
			m_list.push_back(existingFraction);
		}
	}
	// else do nothing

	std::cout << "Number of Fractions read from a file: " << m_list.size() << std::endl;
};

FractionList FractionList::ReduceList() {
	FractionList newList;

	for (uint8_t i = 0; i < m_list.size(); i++) {
		newList.m_list.push_back(m_list[i].ReduceFraction());
	}

	return newList;
};

void FractionList::DisplayList() {

	for (uint8_t i = 0; i < m_list.size(); i++) {
		std::cout << "Fraction " << unsigned(i) + 1 << " from the list: " << std::endl;
		m_list[i].DisplayInfo();
	}
};

Fraction FractionList::ListTotal() {
	
	Fraction Sum;
	
	for (uint8_t i = 0; i < m_list.size(); i++) {
		Sum = Sum + m_list[i]; 
	} 
	
	return Sum; 
};

