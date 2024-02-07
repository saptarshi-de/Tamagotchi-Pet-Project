#include "Pet.h"
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
//overloaded constructor loads a saved file
Pet::Pet(string uname)
{
    ifstream fin;
    fin.open(uname+".txt");
    userName=uname;
    string info;
    fin >> info;
    typeClass=info;
    fin >> info;
    petName=info;
    fin >> info;
    hungry=stoi(info);
    fin >> info;
    energy=stoi(info);
    fin >> info;
    bored=stoi(info);
    fin >> info;
    mood=info;
    fin.close();
}

//overloaded constructor that initiliases the member variables
Pet::Pet(string uname,string tclass, string pName)
{
    userName=uname;
    mood="Happy";
    typeClass=tclass;
    petName=pName;
}
//destructor
Pet::~Pet()
{
    cout<<endl;
    cout << "Thank you for playing this game and I hope you enjoyed it!" <<endl;
    cout<<"Dont forget to write down your username and use it to load your profile next time!"<<endl<<endl;
    cout<<"******************************************************************************************************************************"<<endl<<endl;
}

//function that affects all the member variables
void Pet::nextHour()
{
    if(bored<=20)
    {      
    }
    else if(bored>20 && bored<=40)
    {
        hungry+=1;
    }
    else if(bored>40 && bored<=60)
    {
        hungry+=2;
    }
    else if(bored>60 && bored<=80)
    {
        hungry+=3;
    }
    else
    {
        hungry+=4;
    }
   if(hungry<=20)
    {      
    }
    else if(hungry>20 && hungry<=40)
    {
       energy-=1;
    }
    else if(hungry>40 && hungry<=60)
    {
        energy-=2;
    }
    else if(hungry>60 && hungry<=80)
    {
        energy-=3;
    }
    else
    {
        energy-=4;
    }
    if(energy>=80)
    {      
    }
    else if(energy>=60 && energy<80)
    {
        bored+=1;
    }
    else if(energy>=40 && energy<60)
    {
        bored+=2;
    }
    else if(energy>20 && energy<=40)
    {
        bored+=3;
    }
    else
    {
        bored+=4;
    }
    adjustLevels();
}
//function that adjusts the upper and lower bounds
void Pet::adjustLevels()
{
    if(hungry>100)
    {
        hungry=100;
    }
    if(hungry<0)
    {
        hungry=0;
    }
    if(bored>100)
    {
        bored=100;
    }
    if(bored<0)
    {
        bored=0;
    }
    if(energy>100)
    {
        energy=100;
    }
    if(energy<0)
    {
        energy=0;
    }
}
//function that prints the statistics of the pet
string Pet::printWelcomeInfo()
{
    stringstream ss;
    ss << "Welcome " << userName << "! Here are the stats of your pet : "<<petName<<"\n"
         << "Hunger level: " <<hungry<<"\n"
         << "Boredom level: " <<bored<<"\n"
         << "Energy level: " <<energy<<"\n"
         << "Mood: " << mood <<endl;
    ss << endl;
    return ss.str();
}

//function that prints how the pet is doing
void Pet::printPetInfo()
{
    cout<<endl;
    if(hungry<=20) 
    {
        cout<<petName<<" is not hungry at all. It seems well-fed and satisfied!"<<endl<<endl;
    }
    else if(hungry>20 && hungry<=40)
    {
        cout<<petName<<" is feeling a bit hungry. It could use a small snack to recharge."<<endl<<endl;
    }
    else if(hungry>40 && hungry<=60)
    {
        cout<<petName<<" is quite hungry now. It needs a proper meal to fill its stomach."<<endl<<endl;
    }
    else if(hungry>60 && hungry<=80)
    {
        cout<<petName<<" is very hungry and weak. It needs to eat as soon as possible to regain its energy."<<endl<<endl;
    }
    else
    {
        cout<<petName<<" is starving to death! It is critical that you feed it immediately!"<<endl<<endl;
    }
    if(energy>=80)
    {
        cout<<petName<<" is full of energy and ready to play!"<<endl<<endl;
    }
    else if(energy>=60 && energy<80)
    {
        cout<<petName<<" is starting to feel a bit tired."<<endl<<endl;
    }
    else if(energy>=40 && energy<60)
    {
        cout<<petName<<" could use a nap." <<endl<<endl;
    }
    else if(energy>=20 && energy<40)
    {
        cout<<petName<<" is feeling quite sleep-deprived."<<endl<<endl;
    }
    else
    {
        cout<<petName<<" is completely exhausted and needs rest."<<endl<<endl;
    }
    if(bored<=20)
    {
        cout<<petName<<" is having a great time playing!"<<endl<<endl;
    }
    else if(bored>20 && bored<=40)
    {
        cout<<petName<<" could use some more excitement. Maybe try a new activity?"<<endl<<endl;
    }
    else if(bored>40 && bored<=60)
    {
        cout<<petName<<"'s mental health may be affected by the lack of stimulation. It's important to keep it entertained."<<endl<<endl;
    }
    else if(bored>60 && bored<=80)
    {
        cout<<petName<<" is extremely bored and may start to feel restless. It's time to spice things up!"<<endl<<endl;
    }
    else
    {
        cout<<petName<<" is dangerously bored and may attempt to run away. Try to engage it in some new activities!"<<endl<<endl;
    }
    cout<<endl;
}

//function that prints the mood of the pet
string Pet::printPetMood()
{
    int avg=(hungry+(100-energy)+bored)/3;
    stringstream ss;
    ss<<endl;
    if(avg<20)
    {
        ss<<petName<<" is happy and enjoying life."<<endl;
        mood="Very Happy";
    }
    else if(avg>=20 && avg<35)
    {
        ss<<petName<<" is feeling good."<<endl;
        mood="Good";
    }
    else if(avg>=35 && avg<50)
    {
        ss<<petName<<" is feeling just ok."<<endl;
        mood="Satisfied";
    }
    else if(avg>=50 && avg<70)
    {
        ss<<petName<<" is feeling down."<<endl;
        mood="Sad";
    }
    else
    {
        mood="Miserable";
        ss<<petName<<" is feeling very down and needs extra love and attention."<<endl;
    }
    string moodInfo="\nOverall, your pet mood is: "+mood+"\n\nLets hear what your pet has to say:\n";
    ss<<moodInfo;
    return ss.str();
}
//function that prints the following message
void Pet::saveGame()
{
    cout<<"Saving game....."<<endl;
}
//function that checks if the game is over
bool Pet::gameover()
{
    if(hungry==100 || bored==100 || energy==0)
    {
        cout << "GAME OVER!!! Your pet is dead."<<endl;
        return true;
    }
    return false;
}
//function that generates a warning
void Pet::generateWarning()
{
    if(hungry>90 || bored>90 || energy<10)
    {
        cout << "WARNING: YOUR PET IS IN A SERIOUS PROBLEM. IT IS NEARING ITS DEATH. PLEASE SAVE IT!!!"<<endl<<endl;
    }
}

//function that updates hunger of the pet
void Pet::updateHungry(int h)
{
    hungry-=h;
    adjustLevels();
}
//function that updates boredom of the pet
void Pet::updateBored(int b)
{
    bored-=b;
    adjustLevels();
}
//function that updates energy of the pet
void Pet::updateEnergy(int e)
{
    energy+=e;
    adjustLevels();
}
//function that updates the mood of the pet
void Pet::updateMood()
{
    int avg=(hungry+bored+(100-energy))/3;
    if(avg<20)
    {
        mood="Happy";
    }
    else if(avg>=20 && avg<35)
    {
        mood="Good";
    }
    else if(avg>=35 && avg<50)
    {
        mood="Satisfied";
    }
    else if(avg>=50 && avg<70)
    {
        mood="Sad";
    }
    else
    {
        mood="Miserable";
    }
}
//function that displays the stats of the pet
void Pet::seeStats()
{
    cout << "Here are the stats of your pet: "<<petName<<"\n"
         << "Hunger level: " <<hungry<<"\n"
         << "Boredom level: " <<bored<<"\n"
         << "Energy level: " <<energy<<"\n"
         << "Mood: " << mood <<endl;
    cout<<endl;
}
//function that returns the username
string Pet::getUserName()
{
    return userName;
}
//function that returns the pet name
string Pet::getPetName()
{
    return petName;
}
//function that returns the hunger
int Pet::getHungry()
{
    return hungry;
}
//function that returns the boredom
int Pet::getBored()
{
    return bored;
}
//function that returns energy
int Pet::getEnergy()
{
    return energy;
}
//function that returns the mood
string Pet::getMood()
{
    return mood;
}
//function that sets the value of hungry
void Pet::setHungry(int h)
{
    hungry=h;
}
//function that sets the value of bored
void Pet::setBored(int b)
{
    bored=b;
}
//function that sets the value of energy
void Pet::setEnergy(int e)
{
    energy=e;
}