#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _value;                         	// Valor del número de punto fijo
    static const int _fractionalBits = 8; 	// Bits para la parte fraccionaria

public:
    Fixed(void);                        	//defecto
    Fixed(const Fixed& other);          	//copia
    Fixed& operator=(const Fixed& other); 	//Operador de asignación
    ~Fixed(void);                       	//Destructor

    Fixed(const int value);       	        // Constructor de int
    Fixed(const float value);     	        // Constructor de float
    int getRawBits(void) const;         	// Obtener valor raw
    void setRawBits(int const raw);     	// Establecer valor raw
	float toFloat(void) const;			    // Convertir a float
	int toInt(void) const;				    // Convertir a int

    // Añadir esta declaración para poder tener el overload de "<<" como función amiga:
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif