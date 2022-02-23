#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main(){
    int arr[] = {56, 42, 87, 16, 93};
    std::vector<int> vct;
    std::list<int> lst;
    std::deque<int> dqe;
    std::vector<int>::iterator vtr;
    std::list<int>::iterator ltr;
    std::deque<int>::iterator dtr;

    for(int i=0; i<5; i++){
        vct.push_back(arr[i]);
        lst.push_back(arr[i]);
        dqe.push_back(arr[i]);
    }
    
    std::cout << std::endl << "::::::::: VECTOR TESTS :::::::::" << std::endl;
    vtr = easyfind(vct, 42);
    if(vtr != vct.end())
        std::cout << "Element " << *vtr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    vtr = easyfind(vct, 93);
    if(vtr != vct.end())
        std::cout << "Element " << *vtr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    vtr = easyfind(vct, 56);
    if(vtr != vct.end())
        std::cout << "Element " << *vtr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    vtr = easyfind(vct, 9001);
    if(vtr != vct.end())
        std::cout << "Element " << *vtr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    
    std::cout << std::endl << "::::::::: DEQUE TESTS :::::::::" << std::endl;
    dtr = easyfind(dqe, 42);
    if(dtr != dqe.end())
        std::cout << "Element " << *dtr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    dtr = easyfind(dqe, 93);
    if(dtr != dqe.end())
        std::cout << "Element " << *dtr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    dtr = easyfind(dqe, 56);
    if(dtr != dqe.end())
        std::cout << "Element " << *dtr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    dtr = easyfind(dqe, 9001);
    if(dtr != dqe.end())
        std::cout << "Element " << *dtr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    
    std::cout << std::endl << "::::::::: LIST TESTS :::::::::" << std::endl;
    ltr = easyfind(lst, 42);
    if(ltr != lst.end())
        std::cout << "Element " << *ltr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    ltr = easyfind(lst, 93);
    if(ltr != lst.end())
        std::cout << "Element " << *ltr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    ltr = easyfind(lst, 56);
    if(ltr != lst.end())
        std::cout << "Element " << *ltr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
    ltr = easyfind(lst, 9001);
    if(ltr != lst.end())
        std::cout << "Element " << *ltr << " found" << std::endl;
    else std::cout << "Element NOT found" << std::endl;
}