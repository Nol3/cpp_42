/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:46:02 by alcarden          #+#    #+#             */
/*   Updated: 2025/03/01 19:01:29 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "+ operator : " << (b + d) << std::endl;
	std::cout << "- operator : " << (b - c) << std::endl;
	std::cout << "* operator : " << (b * c) << std::endl;

	if (c < b)
		std::cout << "c lower than b" << std::endl;
	else
		std::cout << "c greater than b" << std::endl;
	if (b == d)
		std::cout << "b equal d" << std::endl;
	else
		std::cout << "b different d" << std::endl;
	std::cout << a << " " << ++a << std::endl;
	std::cout << Fixed::min(b, c) << std::endl;
	std::cout << Fixed::max(b, c) << std::endl;
	return 0;
	}
/* 	{
 	Fixed a;
 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

 	std::cout << a << std::endl;
 	std::cout << ++a << std::endl;
 	std::cout << a << std::endl;
 	std::cout << a++ << std::endl;
 	std::cout << a << std::endl;

 	std::cout << b << std::endl;
	
 	std::cout << Fixed::max( a, b ) << std::endl;
 	return 0;
	} */
}
