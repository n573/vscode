#ifndef DUCK_H
#define DUCK_H
#include <iostream>
#include "Animal.h"
#include <string>

class Duck : public Animal{
 public:
  Duck();
  Duck(std::string color);
  Duck(const Duck& d);
  virtual ~Duck();
  void getColor();
  void getSound();
};
#endif
