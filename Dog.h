#ifndef DOG_H
#define DOG_H
#include "Pet.h"
#include <string>
#include <iostream>
using namespace std;
class Dog:public Pet{
public:
  Dog(string);
  Dog(string, string, string);
  ~Dog();
  string printPetMood();
  void saveGame();
  void nextHour();

  void feed();
  void play();
  void sleep();
};
#endif