#include "Fraction.h"

#include <fstream>
#include <iostream>
#include <string>


const std::string FILE_NAME = "FractionList.txt";


int main() {

	//Create, read, display and reduce fractions from the file
	FractionList List{};
	List.ReadFile(FILE_NAME);
	List.DisplayList();
	List = List.ReduceList();

	//Find and display sum of fractions stored in FractionList object
	Fraction Sum{};
	Sum = List.ListTotal();
	std::cout << "The total sum of all fractions from the list is: " << std::endl;
	Sum.DisplayInfo();

	//Calculate and display -F6-((F1 + F2)*F3-F4)/F5
	Fraction ResultingFraction{};
	ResultingFraction = -(List.F(6)) - ((List.F(1) + List.F(2)) * List.F(3) - List.F(4)) / List.F(5);
	std::cout << "The result of -F6-((F1 + F2)*F3-F4)/F5 is: " << std::endl;
	ResultingFraction.DisplayInfo();

	return 0;
}