#ifndef PET_H
#define PET_H
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class Pet {
public:
  Pet(string);
  Pet(string, string, string);
  virtual ~Pet();
  virtual void nextHour();
  virtual string printWelcomeInfo();
  virtual void saveGame();
  void printPetInfo();
  virtual string printPetMood();
  bool gameover();
  virtual void generateWarning();
  void adjustLevels();
  // void setname(string);
  void updateHungry(int);
  void updateEnergy(int);
  void updateBored(int);
  void updateMood();
  void seeStats();

  string getUserName();
  string getPetName();
  int getHungry();
  int getEnergy();
  int getBored();
  string getMood();
  
  void setEnergy(int);
  void setBored(int);
  void setHungry(int);


  virtual void feed() = 0;
  virtual void play() = 0;
  virtual void sleep() = 0;
  // virtual void petInfo() = 0;
private:
  int hungry, energy, bored;
  string userName, petName, mood, typeClass;
};
#endif