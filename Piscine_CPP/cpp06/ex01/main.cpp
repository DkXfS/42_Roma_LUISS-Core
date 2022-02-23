#include <iostream>
#include <string>

struct Data{
    std::string info;
    char spc;
};

uintptr_t serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}

int main(){
    Data dat;
    uintptr_t temp;
    Data *datPtr;

    dat.info = "This is fine. Really...";
    dat.spc = 'w';
    
    std::cout << "Data.info= " << dat.info << std::endl;
    std::cout << "Data.spc= " << dat.spc << std::endl << std::endl;
    std::cout << "(Data*) &Data= " << &dat << std::endl << std::endl;

    std::cout << "-------------------------" << std::endl;
    std::cout << "-------SERIALIZING-------" << std::endl;
    std::cout << "-------------------------" << std::endl << std::endl;

    temp = serialize(&dat);
    std::cout << "(uintptr_t) temp= " << temp << std::endl << std::endl;

    std::cout << "-------------------------" << std::endl;
    std::cout << "------DESERIALIZING------" << std::endl;
    std::cout << "-------------------------" << std::endl << std::endl;

    datPtr = deserialize(temp);
    std::cout << "(Data*) datPtr= " << datPtr << std::endl << std::endl;
    std::cout << "datPtr->info= " << datPtr->info << std::endl;
    std::cout << "datPtr->spc= " << datPtr->spc << std::endl;
}