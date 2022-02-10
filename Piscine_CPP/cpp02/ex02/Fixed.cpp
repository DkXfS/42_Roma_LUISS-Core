#include "Fixed.hpp"

int const Fixed::fractional_bits= 8;

Fixed::Fixed(): value(0){
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& val): value(val.getRawBits()){
    //std::cout << "Copy constructor called" << std::endl;
    //this->value = val.value;
}

Fixed::Fixed(int const val): value(val << fractional_bits){
    //std::cout << "Int constructor called" << std::endl;
    //this->value = val << fractional_bits;
}

Fixed::Fixed(int const val, char c): value(val){
    (void)c;
    //std::cout << "Value copy constructor called" << std::endl;
    //this->value = val; 
}

Fixed::Fixed(float const val): value(roundf(val * (1<<8))){
    //std::cout << "Float constructor called" << std::endl;
    //this->value = roundf(val * (1<<8));
}

Fixed::~Fixed(){
    //std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& val){
    //std::cout << "Assignation operator called" << std::endl;
    this->value = val.getRawBits();
    return *this;
}

int Fixed::getRawBits() const{
    //std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw){
    //std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

int Fixed::toInt() const{
    return this->value >> 8;
}

float Fixed::toFloat() const{
    return (float)(this->value / (float)(1<<8));
}

bool Fixed::operator>(const Fixed& val) const{
    return this->value > val.value;
}

bool Fixed::operator<(const Fixed& val) const{
    return this->value < val.value;
}

bool Fixed::operator>=(const Fixed& val) const{
    return this->value >= val.value;
}

bool Fixed::operator<=(const Fixed& val) const{
    return this->value <= val.value;
}

bool Fixed::operator==(const Fixed& val) const{
    return this->value == val.value;
}

bool Fixed::operator!=(const Fixed& val) const{
    return !this->operator==(val);
}

Fixed Fixed::operator+(const Fixed& val) const{
    return Fixed(this->value + val.value, 'x');
}

Fixed Fixed::operator-(const Fixed& val) const{
    return Fixed(this->value - val.value, 'x');
}

Fixed Fixed::operator*(const Fixed& val) const{
    return Fixed((this->value * val.value) >> 8, 'x');
}

Fixed Fixed::operator/(const Fixed& val) const{
    float a = this->toFloat(), b = val.toFloat();
    return Fixed(a/b);
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

Fixed& Fixed::min(Fixed &a, Fixed &b){
    return (a < b) ? a : b;
}

Fixed const & Fixed::min(const Fixed &a, const Fixed &b){
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b){
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b){
    return (a > b) ? a : b;
}