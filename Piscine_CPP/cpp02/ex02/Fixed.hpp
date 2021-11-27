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
    Fixed(int const val, char c);
    float toFloat() const;
    int toInt() const;
    Fixed& operator=(const Fixed &val);
    bool operator>(const Fixed& val) const;
    bool operator<(const Fixed& val) const;
    bool operator>=(const Fixed& val) const;
    bool operator<=(const Fixed& val) const;
    bool operator!=(const Fixed& val) const;
    bool operator==(const Fixed& val) const;
    Fixed operator+(const Fixed& val) const;
    Fixed operator-(const Fixed& val) const;
    Fixed operator*(const Fixed& val) const;
    Fixed operator/(const Fixed& val) const;
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);
    int getRawBits() const;
    void setRawBits(int const raw);
    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed const & min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& o, const Fixed& val);