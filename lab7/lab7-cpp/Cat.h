#ifndef CAT_H
#define CAT_H
#include <iostream>
#include "Animal.h"
#include <string>

class Cat : public Animal{

 private:
  std::string name;

 public:
  Cat();
  Cat(std::string name, std::string color);
  virtual ~Cat();
  Cat(const Cat& c);
  void getColor();
  void getName();
  void getSound();

};
#endif
