#include "Span.hpp"

Span::Span(): _n(0){}

Span::Span(const Span& og): _str(og._str), _n(og._n){}

Span::Span(unsigned int n): _n(n){}

Span::~Span(){}

void Span::addNumber(int n){
    if(_str.size() >= _n)
        throw SpanFullExc();
    _str.push_back(n);
}

unsigned int Span::longestSpan(){
    if(_str.size() < 2)
        throw SpanCalcExc();
    unsigned int span=0;

    for(std::vector<int>::iterator it = _str.begin(); it != _str.end(); it++)
        for(std::vector<int>::iterator it2 = (it+1); it2 != _str.end(); it2++){
            if(std::abs((float)*it2 - *it) > span)
                span = abs(*it2 - *it);
        }
    return span;
}

unsigned int Span::shortestSpan(){
    if(_str.size() < 2)
        throw SpanCalcExc();
    unsigned int span = UINT_MAX;

    for(std::vector<int>::iterator it = _str.begin(); it != _str.end(); it++)
        for(std::vector<int>::iterator it2 = (it+1); it2 != _str.end(); it2++){
            if(std::abs((float)*it2 - *it) < span)
                span = abs(*it2 - *it);
        }
    return span;
}

Span& Span::operator=(const Span& og){
    if(this != &og){
        _n = og._n;
        _str = og._str;
    }
    return *this;
}