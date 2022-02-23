#include <algorithm>
#include <iostream>
#include <iterator>

template<typename T>
typename T::iterator easyfind(T& cntnr, int i){
    return std::find(cntnr.begin(), cntnr.end(), i);
}