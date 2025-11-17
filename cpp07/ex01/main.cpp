#include <iostream>
#include "iter.hpp"

// Test function for non-const reference
void printInt(int& x)
{
	std::cout << x << std::endl;
}

// Test function for const reference
void printConstInt(const int& x)
{
	std::cout << x << " ";
}

// Test function for non-const reference with strings
void printString(std::string& s)
{
	std::cout << s << " ";
}

// Test function to increment integers
void increment(int& x)
{
	x++;
}

int main(void)
{
	// Test with integers
	int arr[] = {1, 2, 3, 4, 5};
	int length = 5;

	std::cout << "Original array: ";
	::iter(arr, length, printConstInt);
	std::cout << std::endl;

	std::cout << "After increment: ";
	::iter(arr, length, increment);
	::iter(arr, length, printConstInt);
	std::cout << std::endl;

	// Test with strings
	std::string strArr[] = {"hello", "world", "test"};
	std::cout << "String array: ";
	::iter(strArr, 3, printString);
	std::cout << std::endl;

	return 0;
}
