#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>

int main(){
    {
        std::cout << "::::::::::::::: MutantStack Tests :::::::::::::::" << std::endl;
        //std::cout << "-------------------------------------------------" << std::endl << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "top element: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "container size: " << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(9009);
        mstack.push(0);
        mstack.push(17);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << std::endl << ">>>>>>> mstack Elements <<<<<<<<" << std::endl;
        while (it != ite)
        {
            std::cout << *it << "   ";
            ++it;
        }
        std::cout << std::endl;

        std::stack<int> s(mstack);
        MutantStack<int> mstack2(s);
        MutantStack<int> mstack3 = mstack;

        it = mstack2.begin();
        ite = mstack2.end();
        std::cout << std::endl << ">>>>>>> mstack2 Elements <<<<<<<" << std::endl;
        while (it != ite)
        {
            std::cout << *it << "   ";
            ++it;
        }
        std::cout << std::endl;
        it = mstack3.begin();
        ite = mstack3.end();
        std::cout << std::endl << ">>>>>>> mstack3 Elements <<<<<<<" << std::endl;
        while (it != ite)
        {
            std::cout << *it << "   ";
            ++it;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << ":::::::::::::::::: List Tests :::::::::::::::::::" << std::endl;
        //std::cout << "-------------------------------------------------" << std::endl << std::endl;
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << "top element: " << lst.back() << std::endl;
        lst.pop_back();
        std::cout << "container size: " << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(9009);
        lst.push_back(0);
        lst.push_back(17);
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        ++it;
        --it;
        std::cout << std::endl << ">>>>>>> List Elements <<<<<<<<" << std::endl;
        while (it != ite)
        {
            std::cout << *it << "   ";
            ++it;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << "::::::::::::::: STRING - MutantStack Tests :::::::::::::::" << std::endl;
        //std::cout << "-------------------------------------------------" << std::endl << std::endl;
        MutantStack<std::string> mstack;
        mstack.push("Five");
        mstack.push("Seventeen");
        std::cout << "top element: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "container size: " << mstack.size() << std::endl;
        mstack.push("Three");
        mstack.push("Bartender");
        mstack.push("Grain");
        mstack.push("Low");
        mstack.push("Great");
        mstack.push("Strat");
        MutantStack<std::string>::iterator it = mstack.begin();
        MutantStack<std::string>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << std::endl << ">>>>>>> mstack Elements <<<<<<<<" << std::endl;
        while (it != ite)
        {
            std::cout << *it << "   ";
            ++it;
        }
        std::cout << std::endl;

        std::stack<std::string> s(mstack);
        MutantStack<std::string> mstack2(s);
        MutantStack<std::string> mstack3 = mstack;

        it = mstack2.begin();
        ite = mstack2.end();
        std::cout << std::endl << ">>>>>>> mstack2 Elements <<<<<<<" << std::endl;
        while (it != ite)
        {
            std::cout << *it << "   ";
            ++it;
        }
        std::cout << std::endl;
        it = mstack3.begin();
        ite = mstack3.end();
        std::cout << std::endl << ">>>>>>> mstack3 Elements <<<<<<<" << std::endl;
        while (it != ite)
        {
            std::cout << *it << "   ";
            ++it;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
    {
        std::cout << ":::::::::::::::::: STRING - List Tests :::::::::::::::::::" << std::endl;
        //std::cout << "-------------------------------------------------" << std::endl << std::endl;
        std::list<std::string> lst;
        lst.push_back("Five");
        lst.push_back("Seventeen");
        std::cout << "top element: " << lst.back() << std::endl;
        lst.pop_back();
        std::cout << "container size: " << lst.size() << std::endl;
        lst.push_back("Three");
        lst.push_back("Bartender");
        lst.push_back("Grain");
        lst.push_back("Low");
        lst.push_back("Great");
        lst.push_back("Strat");
        std::list<std::string>::iterator it = lst.begin();
        std::list<std::string>::iterator ite = lst.end();
        ++it;
        --it;
        std::cout << std::endl << ">>>>>>> List Elements <<<<<<<<" << std::endl;
        while (it != ite)
        {
            std::cout << *it << "   ";
            ++it;
        }
        std::cout << std::endl;
    }
}