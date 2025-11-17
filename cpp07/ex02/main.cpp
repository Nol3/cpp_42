#include <iostream>
#include "Array.hpp"

int main(void)
{
	// Test 1: Empty array
	std::cout << "=== Test 1: Empty Array ===" << std::endl;
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	// Test 2: Array with n elements
	std::cout << "\n=== Test 2: Array with 5 elements ===" << std::endl;
	Array<int> arr(5);
	std::cout << "Array size: " << arr.size() << std::endl;
	std::cout << "Default initialized values: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	// Test 3: Assign values
	std::cout << "\n=== Test 3: Assign values ===" << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;
	std::cout << "Array after assignment: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	// Test 4: Copy constructor
	std::cout << "\n=== Test 4: Copy Constructor ===" << std::endl;
	Array<int> copy(arr);
	std::cout << "Original: ";
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "Copy: ";
	for (unsigned int i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	// Modify copy and check original is unchanged
	copy[0] = 999;
	std::cout << "After modifying copy[0] to 999:" << std::endl;
	std::cout << "Original[0]: " << arr[0] << std::endl;
	std::cout << "Copy[0]: " << copy[0] << std::endl;

	// Test 5: Assignment operator
	std::cout << "\n=== Test 5: Assignment Operator ===" << std::endl;
	Array<int> assigned(3);
	for (unsigned int i = 0; i < assigned.size(); i++)
		assigned[i] = 100 + i;
	std::cout << "Before assignment: ";
	for (unsigned int i = 0; i < assigned.size(); i++)
		std::cout << assigned[i] << " ";
	std::cout << std::endl;

	assigned = arr;
	std::cout << "After assigned = arr: ";
	for (unsigned int i = 0; i < assigned.size(); i++)
		std::cout << assigned[i] << " ";
	std::cout << std::endl;

	// Test 6: Out of bounds exception
	std::cout << "\n=== Test 6: Out of Bounds Exception ===" << std::endl;
	try
	{
		std::cout << "Accessing arr[10]..." << std::endl;
		std::cout << arr[10] << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Test 7: With strings
	std::cout << "\n=== Test 7: Array of Strings ===" << std::endl;
	Array<std::string> strArr(3);
	strArr[0] = "Hello";
	strArr[1] = "World";
	strArr[2] = "C++";
	std::cout << "String array: ";
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;

	return 0;
}
