#ifndef WHATEVER_HPP
#define WHATEVER_HPP

// Template function to swap two values
template<typename T>
void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// Template function to return the minimum of two values
// If equal, returns the second one
template<typename T>
T min(const T& a, const T& b)
{
	if (b < a)
		return b;
	return a;
}

// Template function to return the maximum of two values
// If equal, returns the second one
template<typename T>
T max(const T& a, const T& b)
{
	if (b > a)
		return b;
	return a;
}

#endif
