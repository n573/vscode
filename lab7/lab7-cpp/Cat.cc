#include <iostream>
#include "Cat.h"
#include <string>

Cat::Cat() : Animal(){
  std::cout<<"Cat CONSTRRRRR\n";
  this->name = "";
}

Cat::Cat(std::string name, std::string color) : Animal(color){
  std::cout<<"CAT CONSTRRRRRRRRRRRRRR2\n";
  this->name = name;
}

Cat::~Cat(){
  std::cout<<"Cat dstrrrrr\n";
}

Cat::Cat(const Cat& c) : Animal(c){
  this->name = c.name;
}

void Cat::getColor(){
  std::cout<<"cat colourio: "<<this->color<<"\n";
}

void Cat :: getName(){
  std::cout<<"cat nameooooouououou: "<<this->name<<"\n";
}

void Cat::getSound(){
  std::cout<<"cat sound goes nya\n";
}
