#include <iostream>
#include "Animal.h"
#include <string>

Animal::Animal(){
    color = "";
    // sound = NULL;
  }

Animal::Animal(std::string color){
    this->color = color;
    // this->sound = sound;
  }

// void Animal::getSound(){
//  std::cout<<"Sound of Animal: "<<this->sound,,"\n" ;
// }

  void Animal::getColor(){
    std::cout<<"Color of Animal: "<<this->color<<"\n";
  }
  Animal::~Animal(){
    std::cout<<"Animal dstr\n";
  }
Animal::Animal(const Animal& a){
  this->color = a.color;
}


//void Animal::print(){
//std::cout<<"general animal here\n";
//}
