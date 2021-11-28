#include "Fixed.hpp"

int main(void){
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed const c(Fixed(5.05f) + Fixed(2));
    Fixed const d(c);
    std::cout << "a \t= " << a << std::endl;
    std::cout << "++a \t= " << ++a << std::endl;
    std::cout << "a \t= " << a << std::endl;
    std::cout << "a++ \t= " << a++ << std::endl;
    std::cout << "a-- \t= " << a-- << std::endl;
    std::cout << "a \t= " << a << std::endl;
    std::cout << "b \t= " << b << std::endl;
    std::cout << "c \t= " << c << std::endl;
    std::cout << "d \t= " << d << std::endl;
    std::cout << "c <= d \t: " << (c <= d) << std::endl;
    std::cout << "b <= d \t: " << (b <= d) << std::endl;
    std::cout << "b-c \t= " << b - c << std::endl;
    std::cout << "b*c \t= " << b * c << std::endl;
    std::cout << "c/b \t= " << c / b << std::endl;
    std::cout << "max(c, b) = " << Fixed::max(c, b) << std::endl;
    return 0;
}