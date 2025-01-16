#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int _value;                         // Valor del número de punto fijo
    static const int _fractionalBits = 8; // Bits para la parte fraccionaria

public:
    Fixed(void);                        // Constructor por defecto
    Fixed(const Fixed& other);          // Constructor de copia
    Fixed& operator=(const Fixed& other); // Operador de asignación
    ~Fixed(void);                       // Destructor

    int getRawBits(void) const;         // Obtener valor raw
    void setRawBits(int const raw);     // Establecer valor raw
};

#endif