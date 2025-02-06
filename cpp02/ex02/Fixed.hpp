/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:45:33 by alcarden          #+#    #+#             */
/*   Updated: 2025/02/06 13:45:34 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
 # define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        int _value;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(int const value);
        Fixed(float const value);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);

        Fixed & operator = (const Fixed &fixed);

        bool operator > (const Fixed &fixed);
        bool operator < (const Fixed &fixed);
        bool operator >= (const Fixed &fixed);
        bool operator <= (const Fixed &fixed);
        bool operator == (const Fixed &fixed);
        bool operator != (const Fixed &fixed);

        Fixed operator + (const Fixed &fixed);
        Fixed operator - (const Fixed &fixed);
        Fixed operator * (const Fixed &fixed);
        Fixed operator / (const Fixed &fixed);
        Fixed & operator ++ (void);
        Fixed & operator -- (void);
        Fixed operator ++ (int);
        Fixed operator -- (int);
};

std::ostream & operator << (std::ostream &out, const Fixed &fixed);

#endif
