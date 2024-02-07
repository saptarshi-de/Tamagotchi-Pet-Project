#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#include "Bird.h"
#include "Pet.h"
Bird::Bird(string uname):Pet(uname){}
//sets the initial values of member variables unique to bird
Bird::Bird(string uname,string tclass, string pName):Pet(uname,tclass,pName)
{
    setHungry(20);
    setEnergy(80);
    setBored(20);
}
Bird::~Bird(){}
//prints the mood of the bird unique to it
string Bird::printPetMood()
{
    stringstream ss;
    if(getHungry()<=20)
    {
        ss<<"I'm too full to have anything.\n"<<endl;
    }
    else if(getHungry()>20 && getHungry()<=40)
    {
        ss<<"I'm starting to feel a little hungry. I can try munching on a pepper\n"<<endl;
    }
    else if(getHungry()>40 && getHungry()<=60)
    {
        ss<<"I'm feeling pretty hungry now. Some sunflower seeds wil be highly appreciated.\n"<<endl;
    }
    else if(getHungry()>60 && getHungry()<=80)
    {
        ss<<"I'm really hungry! Those worms look really appealing.\n"<<endl;
    }
    else
    {
        ss<<"I'm starving! Please feed me something! Anything works\n"<<endl;
    }
    if(getBored()<=20)
    {
        ss<<"I'm feeling great and ready for anything!\n"<<endl;
    }
    else if(getBored()>20 && getBored()<=40)
    {
        ss<<"The weather kinda looks nice. Can you teach me to dance?\n"<<endl;
    }
    else if(getBored()>40 && getBored()<=60)
    {
        ss<<"I'm in the mood for some fresh air. Can I complete a round of the backyard?\n"<<endl;
    }
    else if(getBored()>60 && getBored()<=80)
    {
        ss<<"I'm really in the mood of singing a song for you. May I?\n"<<endl;
    }
    else
    {
        ss<<"I'm extremely bored! Can we please play or do something fun?\n"<<endl;
    }
    if(getEnergy()>=80)
    {
        ss<<"I'm feeling super energetic and ready for anything!\n"<<endl;
    }
    else if(getEnergy()>=60 && getEnergy()<80)
    {
        ss<<"I could use a quick nap to recharge my batteries.\n"<<endl;
    }
    else if(getEnergy()>=40 && getEnergy()<60)
    {
       ss<<"I'm feeling a bit tired, maybe a head massage will help.\n"<<endl;
    }
    else if(getEnergy()>=20 && getEnergy()<40)
    {
        ss<<"I'm really exhausted, it'll be best if the surroundings are dark to help me sleep.\n"<<endl;
    }
    else
    {
        ss<<"I'm completely drained and might faint. Please help me rest.\n"<<endl;
    }
    ss<<endl;
    return(Pet::printPetMood()+ss.str());
}
//writes into the file of bird type
void Bird::saveGame()
{
    Pet::saveGame();
    ofstream fout;
    fout.open((Pet::getUserName())+".txt");
    fout<<"Bird"<<endl;
    fout<<Pet::getPetName()<<endl;
    fout<<Pet::getHungry()<<endl;
    fout<<Pet::getEnergy()<<endl;
    fout<<Pet::getBored()<<endl;
    fout<<Pet::getMood()<<endl;
    fout.close();
    cout<<"\n\tProfile saved successfully"<<endl<<endl;
}
//randomly updates the values of member variables unique to bird
void Bird::nextHour()
{
    int r;
    srand(time(NULL));
    r=rand()%8+1;
    updateHungry(-r);
    updateEnergy(-r);
    updateBored(-r);
    updateMood();
    Pet::nextHour();
}

//menu options to feed bird unique to it
void Bird::feed()
{
    int num;
    bool flag=true;
    cout<<"\nWhich food would you like to feed your pet?"<<endl;
    while(flag)
    {
        cout<<"\t1. Chilly pepper"<<endl;
        cout<<"\t2. Worms"<<endl;
        cout<<"\t3. Sunflower seeds"<<endl;
        cin>>num;
        cout<<endl;
        if(num==1)
        {
            cout<<"Yum! The pepper has an interesting flavor to it! Thanks for feeding me."<<endl<<endl;
            updateHungry(5);
            flag=false;
        }
        else if(num==2)
        {
            cout<<"Wow, I love worms! I love to devour them and maintain protein levels in  my body."<<endl<<endl;
            updateHungry(10);
            flag=false;
        }
        else if(num==3)
        {
            cout<<"Mmm, sunflower seeds are the best and so are you! Thank you for the healthy meal."<<endl<<endl;
            updateHungry(15);
            flag=false;
        }
        else
        {
            cout<<"You have entered the wrong option. Please try again."<<endl<<endl;
        }
    }
}
//menu options to play with bird unique to it
void Bird::play()
{
    int num;
    bool flag=true;
    cout<<"\nWhat would you like to do with your bird?"<<endl;
    while(flag)
    {
        cout<<"\t1. Set ot free in the backyard"<<endl;
        cout<<"\t2. Train to dance"<<endl;
        cout<<"\t3. Chirp for you"<<endl;
        cin>>num;
        cout<<endl;
        if(num==1)
        {
            cout<<"I would love to be set free for a few minutes. The freedom is amazing!"<<endl<<endl;
            updateBored(5);
            flag=false;
        }
        else if(num==2)
        {
            cout<<"I'm curious to jump to the beats of songs! Lets learn to dance."<<endl<<endl;
            updateBored(10);
            flag=false;
        }
        else if(num==3)
        {
            cout<<"I know many different tunes! I would love to sing one"<<endl<<endl;
            updateBored(15);
            flag=false;
        }
        else
        {
            cout<<"Invalid option, please choose a number from the menu options."<<endl<<endl;
        }
    }
}
//menu options to put the bird to sleep unique to it   
void Bird::sleep()
{
    int num;
    bool flag=true;
    cout<<"\nWhat do you want to do?"<<endl;
    while(flag)
    {
        cout<<"\t1. Take a quick nap" <<endl;
        cout<<"\t2. Give a head massage"<<endl;
        cout<<"\t3. Turn off the lights of the room" <<endl;
        cin>>num;
        cout<<endl;
        if(num==1)
        {
            cout<<"I'm going to take a quick nap." <<endl<<endl;
            updateEnergy(5);
            flag=false;
        }
        else if(num==2)
        {
            cout<<"You are really nice to give me a massage. It feels wonderful and I'm sleepy already!" <<endl<<endl;
            updateEnergy(10);
            flag=false;
        }
        else if(num==3)
        {
            cout<<"Dark surroundings are ideal for a sound sleep. Thank you so much" <<endl<<endl;
            updateEnergy(15);
            flag=false;
        }
        else
        {
            cout<<"Invalid option. Please choose again." <<endl<<endl;
        }
    }
}