#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <algorithm>

int generateNumber(void)
{
	return (std::rand() % 100000);
}

std::vector<int> createRandomVector(unsigned int nb)
{
  srand(time(0));
	std::vector<int> vec(nb);

	std::generate(vec.begin(), vec.end(), generateNumber);
	// std::cout << "vector generated:" << std::endl;
	// for (unsigned int i = 0; i < nb; ++i)
  //   std::cout << vec[i] << std::endl;
	// std::cout << std::endl;
	return (vec);
}



int main(){
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << "Span contents: " << std::endl
            << 6 << std::endl
            << 3 << std::endl
            << 17 << std::endl
            << 9 << std::endl
            << 11 << std::endl
            << std::endl;
  std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl<< std::endl;

  std::cout << std::endl << "...:::::::: Extra Tests ::::::::..." << std::endl;
  try {sp.addNumber(99);}
  catch (std::exception &e) {std::cout << e.what() << std::endl;}

  {
    std::cout << std::endl << "_- 10 Random elements -_" << std::endl;

    std::vector<int> vec_tmp(createRandomVector(10));
    Span sp2(vec_tmp.begin(), vec_tmp.end());

    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
  }
  {
    std::cout << std::endl << "_- 10,000 Random elements -_" << std::endl;

    std::vector<int> vec_tmp(createRandomVector(10000));
    Span sp2(vec_tmp.begin(), vec_tmp.end());

    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
  }
  {
    std::cout << std::endl << "_- 20,000 Random elements -_" << std::endl;

    std::vector<int> vec_tmp(createRandomVector(20000));
    Span sp2(vec_tmp.begin(), vec_tmp.end());

    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
  }
  {
    std::cout << std::endl << "_- 1 Random element -_" << std::endl;

    std::vector<int> vec_tmp(createRandomVector(1));
    Span sp2(vec_tmp.begin(), vec_tmp.end());

    try {std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;}
    catch(std::exception& e) {std::cout << e.what() << std::endl;}
    try {std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;}
    catch(std::exception& e) {std::cout << e.what() << std::endl;}
  }
  {
    std::cout << std::endl << "_- 2 Random elements -_" << std::endl;

    std::vector<int> vec_tmp(createRandomVector(2));
    Span sp2(vec_tmp.begin(), vec_tmp.end());

    try {std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;}
    catch(std::exception& e) {std::cout << e.what() << std::endl;}
    try {std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;}
    catch(std::exception& e) {std::cout << e.what() << std::endl;}
  }
  {
    std::cout << std::endl << "_- 0 Random elements -_" << std::endl;

    std::vector<int> vec_tmp(createRandomVector(0));
    Span sp2(vec_tmp.begin(), vec_tmp.end());

    try {std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;}
    catch(std::exception& e) {std::cout << e.what() << std::endl;}
    try {std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;}
    catch(std::exception& e) {std::cout << e.what() << std::endl;}
  }
  {
    std::cout << std::endl << "_- Ranged AddNumber fail case -_" << std::endl;

    std::vector<int> vec_tmp(createRandomVector(20));
    Span sp2(19);
    try{sp2.addNumber(vec_tmp.begin(), vec_tmp.end());}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}

    try{std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}
    try{std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}
  }
  {
    std::cout << std::endl << "_- Ranged AddNumber success case -_" << std::endl;

    std::vector<int> vec_tmp(createRandomVector(20));
    Span sp2(20);
    try{sp2.addNumber(vec_tmp.begin(), vec_tmp.end());}
    catch(std::exception &e) {std::cout << e.what() << std::endl;}

    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;
  }
  return 0;
}