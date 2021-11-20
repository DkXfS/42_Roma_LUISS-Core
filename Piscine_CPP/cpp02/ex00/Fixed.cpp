#include "Fixed.hpp"

int const Fixed::fractional_bits= 8;

Fixed::Fixed(): value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& val){
    std::cout << "Copy constructor called" << std::endl;
    this->value = val.value;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed &val){
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