#include "iter.hpp"
#include <string>
#include <stdlib.h>

int main(){
    std::string s[9] = {"elem 1", "elem 2", "elem 3", "elem 4", "elem 5", "elem 6", "elem 7", "elem 8", "elem 9"};
    int i[5] = {67, 564, 23, 99, 2578};

    iter<std::string, void>(s, 9, fun);
    std::cout << std::endl;
    iter<int, void>(i, 5, fun);
}