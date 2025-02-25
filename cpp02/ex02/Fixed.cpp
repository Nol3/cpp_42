/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:45:10 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/06 13:45:12 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractionalBits;
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    _value = (int)roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    if (this != &fixed)
        _value = fixed.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator = (const Fixed &fixed)
{
    std::cout << "Copy operator called" << std::endl;
    if (this != &fixed)
        _value = fixed.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(int const raw)
{
    _value = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_value >> _fractionalBits);
}

bool Fixed::operator > (const Fixed &fixed)
{
    return (_value > fixed.getRawBits());
}

bool Fixed::operator < (const Fixed &fixed)
{
    return (_value < fixed.getRawBits());
}

bool Fixed::operator >= (const Fixed &fixed)
{
    return (_value >= fixed.getRawBits());
}

bool Fixed::operator <= (const Fixed &fixed)
{
    return (_value <= fixed.getRawBits());
}

bool Fixed::operator == (const Fixed &fixed)
{
    return (_value == fixed.getRawBits());
}

bool Fixed::operator != (const Fixed &fixed)
{
    return (_value != fixed.getRawBits());
}

Fixed Fixed::operator + (const Fixed &fixed)
{
    return (Fixed(toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator - (const Fixed &fixed)
{
    return (Fixed(toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator * (const Fixed &fixed)
{
    return (Fixed(toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator / (const Fixed &fixed)
{
    return (Fixed(toFloat() / fixed.toFloat()));
}

Fixed & Fixed::operator ++ (void)
{
    _value++;
    return (*this);
}

Fixed & Fixed::operator -- (void)
{
    _value--;
    return (*this);
}

Fixed & Fixed::operator++(void) {
	_value += 1; // Incrementar por el valor más pequeño representable
	return *this;
}

Fixed & Fixed::operator--(void) {
	_value -= 1; // Decrementar por el valor más pequeño representable
	return *this;
}

Fixed Fixed::operator ++ (int)
{
    Fixed tmp(*this);
    operator++();
    return (tmp);
}

Fixed Fixed::operator -- (int)
{
    Fixed tmp(*this);
    operator--();
    return (tmp);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    if(a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b)
{
    if(a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    if(a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed const & Fixed::min(Fixed const &a, Fixed const &b)
{
    if(a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}
