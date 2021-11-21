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
    bool operator>(Fixed& val);
    bool operator<(Fixed& val);
    bool operator>=(Fixed& val);
    bool operator<=(Fixed& val);
    bool operator!=(Fixed& val);
    bool operator==(Fixed& val);
    Fixed& operator+(const Fixed& val);
    Fixed& operator-(const Fixed& val);
    Fixed& operator*(const Fixed& val);
    Fixed& operator/(const Fixed& val);
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    int getRawBits() const;
    void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& o, const Fixed& val);