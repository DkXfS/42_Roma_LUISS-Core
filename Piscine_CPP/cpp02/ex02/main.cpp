#include "Fixed.hpp"

int main(void){
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed const c(Fixed(5.05f) + Fixed(2));
    Fixed const d(c);
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "c <= d : " << (c <= d) << std::endl;
    std::cout << "b <= d : " << (b <= d) << std::endl;
    std::cout << "b-c = " << b - c << std::endl;
    std::cout << "b*c = " << b * c << std::endl;
    std::cout << "c/b = " << c / b << std::endl;
    //std::cout << Fixed::max(a, b) << std::endl;
    return 0;
}