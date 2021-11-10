#include "Karen.hpp"

int main(int argc, char** argv){
    Karen crazyKaren;

    if(argc > 2)
        std::cout << "< Multiple arguments received. Only the first argument will be considered >" << std::endl << std::endl;
    if(argc < 2)
        std::cout << "< A karen comment level is required >" << std::endl;
    else
        crazyKaren.complain(argv[1]);
}