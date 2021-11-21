#include "Fixed.hpp"

int const Fixed::fractional_bits= 8;

Fixed::Fixed(): value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& val){
    std::cout << "Copy constructor called" << std::endl;
    this->value = val.value;
}

Fixed::Fixed(int const val){
    std::cout << "Int constructor called" << std::endl;
    this->value = val << 8;
}

Fixed::Fixed(float const val){
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(val * (1<<8));
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& val){
    std::cout << "Assignation operator called" << std::endl;
    this->value = val.value;
    return *this;
}

int Fixed::getRawBits() const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

int Fixed::toInt() const{
    return this->value >> 8;
}

float Fixed::toFloat() const{
    return (float)(this->value / (float)(1<<8));
}

bool Fixed::operator>(Fixed& val){
    return this->value > val.value;
}

bool Fixed::operator<(Fixed& val){
    return this->value < val.value;
}

bool Fixed::operator>=(Fixed& val){
    return this->value >= val.value;
}

bool Fixed::operator<=(Fixed& val){
    return this->value <= val.value;
}

bool Fixed::operator==(Fixed& val){
    return this->value == val.value;
}

bool Fixed::operator!=(Fixed& val){
    return !this->operator==(val);
}

Fixed& Fixed::operator+(const Fixed& val){
    this->value += val.value;
    return *this;
}

Fixed& Fixed::operator-(const Fixed& val){
    this->value -= val.value;
    return *this;
}

Fixed& Fixed::operator*(const Fixed& val){
    this->value = (this->value * val.value) >> 8;
    return *this;
}

Fixed& Fixed::operator/(const Fixed& val){
    this->value /= val.value;
    return *this;
}

Fixed& Fixed::operator++(){
    this->value += 1;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp = *this;
    this->value += 1;
    return temp;
}

Fixed& Fixed::operator--(){
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed temp = *this;
    this->value -= 1;
    return temp;
}
std::ostream& operator<<(std::ostream& o, const Fixed& val){
    o << val.toFloat();
    return o;
}