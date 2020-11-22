#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

template<class T>
void printVector(std::vector<T> vector)
{
	std::cout << "\t";
	for (auto& t : vector)
	{
		std::cout << t << "\t";
	}
	std::cout << std::endl;
}

template<class T>
std::vector<T> slicing(std::vector<T> const& v, int x, int y)
{
	auto first = v.begin() + x;
	auto last = v.begin() + y + 1;

	std::vector<T> vector(first, last);

	return vector;
}

bool alphabeticalCompare(std::string lhs, std::string rhs) { return lhs < rhs; }

bool negativeNumeralCompare(double val) { return val < 0; }

bool isOdd(double val) { return (unsigned long)val & 1; }

int main()
{
	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	std::cout << "====================================> Alphabetical sort and splicing: " << std::endl;

	// wat is een origineel kopie? Bedoel je nou het originiele object (a.k.a originele array), of een kopie van het originele object?
	// Ik heb het maar geintrepeteerd zoals het staat gescrheven, excuus als ik het verkeerd heb begrepen.
	std::vector<std::string> coloursCOPY(colours.size());
	std::copy(colours.begin(), colours.end(), coloursCOPY.begin());

	std::cout << "Colours BEFORE sort: ";
	printVector(coloursCOPY);

	std::cout << "Colours AFTER sort: ";
	std::sort(coloursCOPY.begin(), coloursCOPY.end(), alphabeticalCompare);
	printVector(coloursCOPY);

	std::cout << std::endl;

	// Get index of element "purple". Than copy the elements to 2 different arrays.
	int elementIndex = 0;
	std::vector<std::string>::iterator it = std::find(coloursCOPY.begin(), coloursCOPY.end(), "purple");
	if (it != coloursCOPY.end())
	{
		elementIndex = std::distance(coloursCOPY.begin(), it);
		std::cout << "Element " << "'purple'" << " found at index: " << elementIndex << std::endl;
	}
	else
	{
		std::cout << "Element NOT found!" << std::endl;
	}

	std::cout << std::endl;

	std::vector<std::string> coloursBeforePurple(elementIndex);
	std::vector<std::string> coloursAfterPurple(sizeof(coloursCOPY.size() - elementIndex - 1));

	std::copy(coloursCOPY.begin(), coloursCOPY.begin() + elementIndex, coloursBeforePurple.begin());
	std::copy(coloursCOPY.begin() + elementIndex + 1, coloursCOPY.end(), coloursAfterPurple.begin());

	std::cout << "Colours BEFORE purple: ";
	printVector(coloursBeforePurple);

	std::cout << "Colours AFTER purple: ";
	printVector(coloursAfterPurple);

	std::cout << "\n====================================> Uppercasing: " << std::endl;
	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		// 2) alle elementen UPPERCASE te maken.

		std::vector<std::string> coloursCOPY(colours.size());
		std::copy(colours.begin(), colours.end(), coloursCOPY.begin());

		for (auto& t : coloursCOPY)
		{
			std::for_each(t.begin(), t.end(), [](char& c) {c = std::toupper(static_cast<unsigned char>(c)); });
		}

		printVector(coloursCOPY);
	}

	std::cout << "\n====================================> Removing Doubles: " << std::endl;
	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		// 3) alle dubbele te verwijderen

		std::vector<std::string> coloursCOPY(colours.size());
		std::copy(colours.begin(), colours.end(), coloursCOPY.begin());

		std::sort(coloursCOPY.begin(), coloursCOPY.end(), alphabeticalCompare);
		std::unique(coloursCOPY.begin(), coloursCOPY.end());

		printVector(coloursCOPY);
	}

	std::cout << "\n====================================> Removing Negative Numbers: " << std::endl;
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		// 1) alle negatieve elementen te verwijderen

		std::vector<double> numbersCOPY(numbers.size());
		std::copy(numbers.begin(), numbers.end(), numbersCOPY.begin());
		numbersCOPY.erase(std::remove_if(numbersCOPY.begin(), numbersCOPY.end(), negativeNumeralCompare), numbersCOPY.end());

		printVector(numbersCOPY);
	}

	std::cout << "\n====================================> Removing Odd Numbers: " << std::endl;
	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		// 2) voor alle elementen te bepalen of ze even of oneven zijn

		// Alleen bepalen? ik neem aan verwijderen aangezien de vorige opdracht.
		std::vector<double> numbersCOPY(numbers.size());
		std::copy(numbers.begin(), numbers.end(), numbersCOPY.begin());
		numbersCOPY.erase(std::remove_if(numbersCOPY.begin(), numbersCOPY.end(), isOdd), numbersCOPY.end());

		printVector(numbersCOPY);
	}

	std::cout << "\n====================================> Calculating the Sum, Average and Product of all the Numbers: " << std::endl;
	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		// 3) de som, het gemiddelde, en het product van alle getallen te berekenen

		double sum = 0.0;
		double average = 0.0;
		double product = 1;

		for (auto& it : numbers)
		{
			sum += it;
		}
		std::cout << "Sum of numbers: " << sum << std::endl;

		average = sum / numbers.size();
		std::cout << "Average of numbers: " << average << std::endl;

		for (auto& it : numbers)
		{
			product *= it;
		}
		std::cout << "Product of numbers: " << product << std::endl;

	}

	return 0;
}
