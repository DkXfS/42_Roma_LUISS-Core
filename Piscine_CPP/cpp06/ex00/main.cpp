#include <cstdlib>
#include <iostream>
#include <limits>
#include <cmath>

bool isNan(char *str){
    if(str[0] == 'n' && str[1] == 'a' && str[2] == 'n' && (str[3] == '\0' || (str[3] == 'f' && str[4] == '\0')))
        return true;
    return false;
}

int isInf(char *str){
    int ret = 0;
    if(str[0] == '+'){
        str++;
        ret = 1;
    }
    else if(str[0] == '-'){
        str++;
        ret = 2;
    }
    if(str[0] == 'i' && str[1] == 'n' && str[2] == 'f' && (str[3] == '\0' || (str[3] == 'f' && str[4] == '\0'))){
        if(ret)
            return ret;
        else return 1;
    }
    else return 0;
}

std::string inputType(char *str){
    int i;
    if(isNan(str))
        return "nan";
    if((i=isInf(str))){
        if(i == 2)
            return "-inf";
        return "inf";
    }
    if((str[0] < '0' || str[0] > '9') && !str[1])
        return "char";
    i=0;
    if(str[i] == '+' || str[i] == '-')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
        i++;
    if(str[i] == '.')
        i++;
    while(str[i] >= '0' && str[i] <= '9')
        i++;
    if(!str[i] || (str[i] == 'f' && !str[i+1]))
        return "num";
    std::cout << "Error: Input must be a single character or number" << std::endl;
    return "false";
}

void charCase(double d){
    std::cout << "char: \t";
    if(d!=d || d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::infinity() ||
            d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if(!isprint(static_cast<char>(d)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
}

void intCase(double d){
    std::cout << "int: \t";
    if(d!=d || d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::infinity() ||
            d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(d) << std::endl;
}

void floatCase(double d){
    std::cout << "float: \t";
    if (d != d || d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::infinity())
        std::cout << static_cast<float>(d) << "f" << std::endl;
    else if(d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
        std::cout << "impossible" << std::endl;
    else{
        std::cout << static_cast<float>(d);
        if(modf(d, (double*)NULL) == 0.0 && d < 1000000)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void doubleCase(double d){
    std::cout << "double: ";
    if (d != d || d == -std::numeric_limits<double>::infinity() || d == std::numeric_limits<double>::infinity())
        std::cout << d << std::endl;
    else{
        std::cout << d;
        if(modf(d, (double*)NULL) == 0.0 && d < 1000000)
            std::cout << ".0";
        std::cout << std::endl;
    }
}

int main(int argc, char **argv){
    std::string type;
    double d;

    if(argc != 2){
        std::cout << "Error: One argument allowed/needed" << std::endl; 
        return 1;
    }
    if((type = inputType(argv[1])) == "false")
        return 1;
    if(type == "char")
        d = static_cast<double>(argv[1][0]);
    else
        d = strtod(argv[1], NULL);
    if(errno == ERANGE){
        std::cout << "Error: The input value is out of range of all conversion types" << std::endl;
        return 1;
    }
    charCase(d);
    intCase(d);
    floatCase(d);
    doubleCase(d);
    return 0;
}