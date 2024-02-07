#ifndef SQUIRREL_H
#define SQUIRREL_H
#include "Pet.h"
#include <string>
#include <iostream>
using namespace std;
class Squirrel:public Pet{
public:
  Squirrel(string);
  Squirrel(string, string, string);
  ~Squirrel();
  string printPetMood();
  void saveGame();
  void nextHour();

  void feed();
  void play();
  void sleep();
};
#endif