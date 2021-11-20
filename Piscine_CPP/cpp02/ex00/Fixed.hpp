#include <iostream>

class Fixed{
    int value;
    static int const fractional_bits;

    public:
    Fixed();
    ~Fixed();
    Fixed(Fixed& val);
    Fixed& operator=(Fixed& val);
    int getRawBits() const;
    void setRawBits(int const raw);
};