#ifndef BIRD_H
#define BIRD_H
#include "Pet.h"
#include <string>
#include <iostream>
using namespace std;
class Bird:public Pet{
public:
  Bird(string);
  Bird(string, string, string);
  ~Bird();
  string printPetMood();
  void saveGame();
  void nextHour();

  void feed();
  void play();
  void sleep();
};
#endif