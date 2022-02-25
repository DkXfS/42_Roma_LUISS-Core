#include <iostream>
#include "Array.hpp"
#include <time.h>
#include <stdlib.h>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        if(numbers[67] != tmp [67])
            std::cerr << "assignment operator not functioning as intended !!" << std::endl;
        if(test[67] != tmp [67])
            std::cerr << "Copy constructor not functioning as intended !!" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    std::cout << std::endl << "//////////// Extra Tests \\\\\\\\\\\\\\\\\\\\\\\\" << std::endl << std::endl;
    {
        Array<int> arr1(10);
        Array<int> arr2(20);
        Array<int> arr3;

        arr3 = arr1;

        try
        {
            arr3[12] = 42;
            std::cout << "arr1[12] = " << arr1[12] << std::endl;
            std::cout << "arr3[12] = " << arr3[12] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        arr3 = arr2;

        try
        {
            arr3[12] = 42;
            std::cout << "arr2[12] = " << arr2[12] << std::endl;
            std::cout << "arr3[12] = " << arr3[12] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        Array<float> arr1(10);
        Array<float> arr2(20);
        Array<float> arr3;

        arr3 = arr1;

        try
        {
            arr3[12] = 42.42f;
            std::cout << "arr1[12] = " << arr1[12] << std::endl;
            std::cout << "arr3[12] = " << arr3[12] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }

        arr3 = arr2;

        try
        {
            arr3[12] = 42.42f;
            std::cout << "arr2[12] = " << arr2[12] << std::endl;
            std::cout << "arr3[12] = " << arr3[12] << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}