#pragma once
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>{
    public:
    typedef typename std::stack<T>::container_type::iterator iterator;

    MutantStack(): std::stack<T>() {}
    virtual ~MutantStack(){}
    MutantStack(MutantStack const & og): std::stack<T>(og){}
    MutantStack(std::stack<T> const & og): std::stack<T>(og){}
    MutantStack& operator=(MutantStack const & og){
        if(this != &og)
            *this = og;
            //this->c = og.c;
        return *this;
    }
    iterator begin() { return this->c.begin();}
    iterator end() { return this->c.end();}
};