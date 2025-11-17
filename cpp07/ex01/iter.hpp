#ifndef ITER_HPP
#define ITER_HPP

// Template function that applies a function to every element of an array
// Supports both const and non-const arrays and function parameters

template<typename T>
void iter(T* array, const int length, void (*func)(T&))
{
	for (int i = 0; i < length; i++)
		func(array[i]);
}

template<typename T>
void iter(T* array, const int length, void (*func)(const T&))
{
	for (int i = 0; i < length; i++)
		func(array[i]);
}

#endif
