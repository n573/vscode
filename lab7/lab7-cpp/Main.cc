#include <iostream>
#include <string>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Duck.h"

int main(){
  Dog* d1 = new Dog("watson", "like a cow");
  d1->getName();

  Animal* a1 = new Cat("stacy", "pink");
  a1->getSound();

  Duck* duck1 = new Duck("speckly");
  duck1->getColor();
  delete d1;
  delete a1;
  delete duck1;
}
