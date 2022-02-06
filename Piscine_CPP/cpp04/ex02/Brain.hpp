#include <string>
#include <iostream>
#pragma once

class Brain{
    std::string ideas[100];

    public:
    Brain();
    ~Brain();
    Brain(const Brain& og);
    Brain& operator=(const Brain& b);
};