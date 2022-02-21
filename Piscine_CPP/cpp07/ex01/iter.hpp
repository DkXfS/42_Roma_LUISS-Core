#include <iostream>

template<typename T, typename U>
void iter(T* arr, int len, U (*f)(T)){
    int i=0;
    while(i<len)
        f(arr[i++]);
}

template<typename T>
void fun(T smt){
    std::cout << smt << std::endl;
}