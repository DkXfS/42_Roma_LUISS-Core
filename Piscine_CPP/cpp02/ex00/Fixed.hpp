#include <iostream>

class Fixed{
    int value;
    static int const fractional_bits;

    public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& val);
    Fixed& operator=(const Fixed& val);
    int getRawBits() const;
    void setRawBits(int const raw);
};