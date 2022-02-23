#include <exception>
#include <iterator>
#include <vector>
#include <cmath>

class Span{
    std::vector<int> _str;
    unsigned int _n;
    Span();

    class SpanFullExc: public std::exception{
        const char* what()const throw(){
            return "!! Error: Reached max number of elements !!";
        }
    };
    class SpanCalcExc: public std::exception{
        const char* what()const throw(){
            return "!! Error: Span can't be calculated. Not enough numbers !!";
        }
    };

    public:
    Span(unsigned int n);
    Span(const Span& og);
    ~Span();
    Span& operator=(const Span& og);
    void addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    template <typename itr>
    Span(itr beg, itr end): _str(std::vector<int>(beg, end)), _n(_str.size()){}
};