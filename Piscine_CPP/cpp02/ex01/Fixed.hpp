#include <iostream>
#include <cmath>

class Fixed{
    int value;
    static int const fractional_bits;

    public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& val);
    Fixed(int const val);
    Fixed(float const val);
    float toFloat() const;
    int toInt() const;
    Fixed& operator=(const Fixed &val);
    int getRawBits() const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& o, const Fixed& val);