#pragma once

template<typename T>
class Array{
    unsigned int len;
    T* arr;

    class OutofBoundsIndex: public std::exception{
        virtual const char* what()const throw(){
            return "ERROR: The accessed index is out of range of the array";
        }
    };

    public:
    Array(): len(0), arr(new T[0]){}

    Array(unsigned int n): len(n), arr(new T[len]){}

    ~Array() { delete [] arr; }

    Array(const Array& a): len(a.len), arr(new T[a.len]){
        for(unsigned int i=0; i<len; i++)
            arr[i] = a[i];
    }

    Array& operator=(Array const& a){
        if(len){
            std::cout << "trigg" << std::endl;
            delete [] arr;
        }
        len = a.len;
        arr = new T[len];
        for(unsigned int i=0; i<len; i++)
            arr[i] = a[i];
        return *this;
    }

    T& operator[](unsigned int i)const{
        if(i >= len || i < 0)
            throw OutofBoundsIndex();
        return arr[i];
    }

    unsigned int size() { return len; }
};
