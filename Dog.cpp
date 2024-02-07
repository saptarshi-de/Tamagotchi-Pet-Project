#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#include "Dog.h"
#include "Pet.h"
Dog::Dog(string uname):Pet(uname){}
//sets the initial values of member variables unique to dog
Dog::Dog(string uname,string tclass, string pName):Pet(uname,tclass,pName)
{
    setHungry(25);
    setEnergy(80);
    setBored(25);
}
Dog::~Dog(){}
//prints the mood of the dog unique to it
string Dog::printPetMood()
{
    stringstream ss;
    if(getHungry()<=20)
    {
        ss<<"The food looks delicious but I'm too full to eat.\n"<<endl;
    }
    else if(getHungry()>20 && getHungry()<=40)
    {
        ss<<"If offered, I won't hate to chew on some bones.\n"<<endl;
    }
    else if(getHungry()>40 && getHungry()<=60)
    {
        ss<<"I'm starting to feel hungry. Would love to munch on some chicken.\n"<<endl;
    }
    else if(getHungry()>60 && getHungry()<=80)
    {
        ss<<"I'm really hungry! I could really go for some juicy beef right now.\n"<<endl;
    }
    else
    {
        ss<<"I'm starving! Please feed me something right away! Anything works.\n"<<endl;
    }
    if(getBored()<=20)
    {
        ss<<"I'm feeling great and grateful to have you as my owner!\n"<<endl;
    }
    else if(getBored()>20 && getBored()<=40)
    {
        ss<<"Do you wanna check out my learning abilities? Try training me.\n"<<endl;
    }
    else if(getBored()>40 && getBored()<=60)
    {
        ss<<"I'm in the mood for some fresh air. Can we go out for a walk?\n"<<endl;
    }
    else if(getBored()>60 && getBored()<=80)
    {
        ss<<"I feel useless. Can we play a game together?\n"<<endl;
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
       ss<<"I'm feeling a bit tired, maybe a nap on the couch will help.\n"<<endl;
    }
    else if(getEnergy()>=20 && getEnergy()<40)
    {
        ss<<"I'm really exhausted, can I sleep with you for a bit?\n"<<endl;
    }
    else
    {
        ss<<"I'm completely drained and might faint. Please help me rest.\n"<<endl;
    }
    ss<<endl;
    return(Pet::printPetMood()+ss.str());
}
//writes into the file of dog type
void Dog::saveGame()
{
    Pet::saveGame();
    ofstream fout;
    fout.open((Pet::getUserName())+".txt");
    fout<<"Dog"<<endl;
    fout<<Pet::getPetName()<<endl;
    fout<<Pet::getHungry()<<endl;
    fout<<Pet::getEnergy()<<endl;
    fout<<Pet::getBored()<<endl;
    fout<<Pet::getMood()<<endl;
    fout.close();
    cout<<"\n\tProfile saved successfully"<<endl<<endl;
}
//randomly updates the values of member variables unique to dog
void Dog::nextHour()
{
    int r;
    srand(time(NULL));
    r=rand()%10+1;
    updateHungry(r);
    updateEnergy(-r);
    updateBored(r);
    updateMood();
    Pet::nextHour();
}

//menu options to feed dog unique to it
void Dog::feed()
{
    int num;
    bool flag=true;
    cout<<"\nWhich food would you like to feed your pet?"<<endl;
    while(flag)
    {
        cout<<"\t1. Chicken bones and Pedigree combo meal"<<endl;
        cout<<"\t2. Chicken"<<endl;
        cout<<"\t3. Beef"<<endl;
        cin>>num;
        cout<<endl;
        if(num==1)
        {
            cout<<"Mmm! The bones have the correct combination of softness and crunch. So nice of you"<<endl<<endl;
            updateHungry(5);
            flag=false;
        }
        else if(num==2)
        {
            cout<<"Wow, the chicken is delicious! Thank you for the wholesome plate."<<endl<<endl;
            updateHungry(10);
            flag=false;
        }
        else if(num==3)
        {
            cout<<"Yum! I love beef! Thank you for the wonderful meal."<<endl<<endl;
            updateHungry(15);
            flag=false;
        }
        else
        {
            cout<<"You have entered the wrong option. Please try again."<<endl<<endl;
        }
    }
}
//menu options to play with dog unique to it
void Dog::play()
{
    int num;
    bool flag=true;
    cout<<"\nHow would you loke to spend time with your dog?"<<endl;
    while(flag)
    {
        cout<<"\t1. Train the dog to smile for selfies"<<endl;
        cout<<"\t2. Go for a riverside walk"<<endl;
        cout<<"\t3. Play fetch"<<endl;
        cin>>num;
        cout<<endl;
        if(num==1)
        {
            cout<<"Let's learn to smile to look cuter in photos!"<<endl<<endl;
            updateBored(5);
            flag=false;
        }
        else if(num==2)
        {
            cout<<"The river is full of fresh air! I would love to walk with you."<<endl<<endl;
            updateBored(10);
            flag=false;
        }
        else if(num==3)
        {
            cout<<"I'm pretty sure I'm faster than the frisbee! Let's see. Wohoo!"<<endl<<endl;
            updateBored(15);
            flag=false;
        }
        else
        {
            cout<<"Invalid option, please choose a number from the menu options."<<endl<<endl;
        }
    }
}
//menu options to put the dog to sleep unique to it   
void Dog::sleep()
{
    int num;
    bool flag=true;
    cout<<"\nHow do you want to put the dog to have rest?"<<endl;
    while(flag)
    {
        cout<<"\t1. Take a power nap" <<endl;
        cout<<"\t2. Relax on the couch"<<endl;
        cout<<"\t3. Give it a head massage" <<endl;
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
            cout<<"I'm going to relax on the couch." <<endl<<endl;
            updateEnergy(10);
            flag=false;
        }
        else if(num==3)
        {
            cout<<"The head massage feels awesome. I'm going to sleep." <<endl<<endl;
            updateEnergy(15);
            flag=false;
        }
        else
        {
            cout<<"Invalid option. Please choose again." <<endl<<endl;
        }
    }
}