#include <iostream>
#include <string>

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "String Address :\t\t" << &str << std::endl << "String Address from pointer :\t" << stringPTR << std::endl\
                << "String Address from reference :\t" << &stringREF << std::endl;
    std::cout << "String through Pointer :\t" << *stringPTR << std::endl << "String through Reference :\t" << stringREF << std::endl;
}