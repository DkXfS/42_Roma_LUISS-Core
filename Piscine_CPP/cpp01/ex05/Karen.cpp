#include "Karen.hpp"

Karen::Karen(){
    this->complaintLevels[0]="DEBUG";
    this->complaintLevels[1]="INFO";
    this->complaintLevels[2]="WARNING";
    this->complaintLevels[3]="ERROR";

    this->complaintFuncts[0]=&Karen::debug;
    this->complaintFuncts[1]=&Karen::info;
    this->complaintFuncts[2]=&Karen::warning;
    this->complaintFuncts[3]=&Karen::error;
}

void Karen::debug(){
    std::cout << std::endl << "[DEBUG] :\nI love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info(){
    std::cout << std::endl << "[INFO] :\nI cannot believe adding extra bacon cost more money. You don't put enough!\nIf you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(){
    std::cout << std::endl << "[WARNING] :\nI think I deserve to have some extra bacon for free.\nI've been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(){
    std::cout << std::endl << "[ERROR] :\nThis is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::complain(std::string level){
    int i=0;

    while(i<4){
        if(!level.compare(this->complaintLevels[i])){
            (this->*complaintFuncts[i])();
            break;
        }
        i++;
    }
    if(i>3)
        std::cout << std::endl << "< non existent karen comment level >" << std::endl;
}