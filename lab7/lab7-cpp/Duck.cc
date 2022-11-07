#include <iostream>
#include "Duck.h"
#include <string>

Duck::Duck() : Animal(){
  std::cout<<"quacky constructy\n";
}

Duck::Duck(std::string color) : Animal(color){
  std::cout<<"ducky quackers2\n";
}

Duck::~Duck(){
  std::cout<<"Duck dstroyyyyyyy\n";
}

void Duck::getColor(){
  std::cout<<"duck color: "<<this->color<<"\n";
}

void Duck::getSound(){
  std::cout<<"ducky go quacky\n";
}
