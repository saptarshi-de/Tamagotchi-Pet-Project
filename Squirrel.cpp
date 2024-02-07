#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#include "Squirrel.h"
#include "Pet.h"
Squirrel::Squirrel(string uname):Pet(uname){}
//sets the initial values of member variables unique to squirrel
Squirrel::Squirrel(string uname,string tclass, string pName):Pet(uname,tclass,pName)
{
    setHungry(15);
    setEnergy(90);
    setBored(15);
}
Squirrel::~Squirrel(){}
//prints the mood of the squirrel unique to it
string Squirrel::printPetMood()
{
    stringstream ss;
    if(getHungry()<=20)
    {
        ss<<"Those nuts look delicious but I'm too full to have anything.\n"<<endl;
    }
    else if(getHungry()>20 && getHungry()<=40)
    {
        ss<<"If offered, I might have a few almonds.\n"<<endl;
    }
    else if(getHungry()>40 && getHungry()<=60)
    {
        ss<<"My stomach just started rumbling. Few hazlenuts would be amazing\n"<<endl;
    }
    else if(getHungry()>60 && getHungry()<=80)
    {
        ss<<"I'm really hungry now. PLease feed me with a bowl full of peanuts\n"<<endl;
    }
    else
    {
        ss<<"I'm starving! Please feed me with something...anything!\n"<<endl;
    }
    if(getBored()<=20)
    {
        ss<<"I'm feeling great and ready to do anything!\n"<<endl;
    }
    else if(getBored()>20 && getBored()<=40)
    {
        ss<<"I want to learn new stuff. Can you teach me how to respond to certain words?\n"<<endl;
    }
    else if(getBored()>40 && getBored()<=60)
    {
        ss<<"I am in the mood of showing you my home. Do you want to make a quick visit?\n"<<endl;
    }
    else if(getBored()>60 && getBored()<=80)
    {
        ss<<"I'm starting to get bored. Can we do something together?\n"<<endl;
    }
    else
    {
        ss<<"I'm extremely bored! Can we please play or do something fun?\n"<<endl;
    }
    if(getEnergy()>=80)
    {
        ss<<"I'm feeling super energetic and ready to do anything!\n"<<endl;
    }
    else if(getEnergy()>=60 && getEnergy()<80)
    {
        ss<<"I could use a quick nap to recharge my batteries.\n"<<endl;
    }
    else if(getEnergy()>=40 && getEnergy()<60)
    {
       ss<<"I'm feeling a bit tired, maybe a quick nap will help.\n"<<endl;
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
//writes into the file of squirrel type
void Squirrel::saveGame()
{
    Pet::saveGame();
    ofstream fout;
    fout.open((Pet::getUserName())+".txt");
    fout<<"Squirrel"<<endl;
    fout<<Pet::getPetName()<<endl;
    fout<<Pet::getHungry()<<endl;
    fout<<Pet::getEnergy()<<endl;
    fout<<Pet::getBored()<<endl;
    fout<<Pet::getMood()<<endl;
    fout.close();
    cout<<"\n\tProfile saved successfully"<<endl<<endl;
}
//randomly updates the values of member variables unique to squirrel
void Squirrel::nextHour()
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

//menu options to feed squirrel unique to it
void Squirrel::feed()
{
    int num;
    bool flag=true;
    cout<<"\nWhich food would you like to feed your pet?"<<endl;
    while(flag)
    {
        cout<<"\t1. Hazlenuts"<<endl;
        cout<<"\t2. Peanuts"<<endl;
        cout<<"\t3. Almonds"<<endl;
        cin>>num;
        cout<<endl;
        if(num==1)
        {
            cout<<"Yum! These hazlenuts are delicious! Thanks for feeding me."<<endl<<endl;
            updateHungry(5);
            flag=false;
        }
        else if(num==2)
        {
            cout<<"Wow, the peanuts are fresh! Thank you for the bowlful."<<endl<<endl;
            updateHungry(10);
            flag=false;
        }
        else if(num==3)
        {
            cout<<"Almonds are so healthy! Thank you for the wonderful meal."<<endl<<endl;
            updateHungry(15);
            flag=false;
        }
        else
        {
            cout<<"You have entered the wrong option. Please try again."<<endl<<endl;
        }
    }
}
//menu options to play with squirrel unique to it
void Squirrel::play()
{
    int num;
    bool flag=true;
    cout<<"\nWhat would you like to do with your squirrel?"<<endl;
    while(flag)
    {
        cout<<"\t1. Train new words"<<endl;
        cout<<"\t2. Visit the squirrel's family"<<endl;
        cout<<"\t3. Play tag"<<endl;
        cin>>num;
        cout<<endl;
        if(num==1)
        {
            cout<<"I'm so curious and inquisitive to learn new words! I hope I learn to respond."<<endl<<endl;
            updateBored(5);
            flag=false;
        }
        else if(num==2)
        {
            cout<<"I'm excited to have you visit my home! My family members will be thrilled to see you"<<endl<<endl;
            updateBored(10);
            flag=false;
        }
        else if(num==3)
        {
            cout<<"Playing with you is always the highlight of my day! Let's have some fun!"<<endl<<endl;
            updateBored(15);
            flag=false;
        }
        else
        {
            cout<<"Invalid option, please choose a number from the menu options."<<endl<<endl;
        }
    }
}
//menu options to put the squirrel to sleep unique to it   
void Squirrel::sleep()
{
    int num;
    bool flag=true;
    cout<<"\nWhat do you want to do?"<<endl;
    while(flag)
    {
        cout<<"\t1. Sing a lullaby to the squirrel" <<endl;
        cout<<"\t2. Relax under the shade"<<endl;
        cout<<"\t3. Cuddle" <<endl;
        cin>>num;
        cout<<endl;
        if(num==1)
        {
            cout<<"You song is so soothening. I'm going to sleep." <<endl<<endl;
            updateEnergy(5);
            flag=false;
        }
        else if(num==2)
        {
            cout<<"I'm going to relax under the cool shade of that tree." <<endl<<endl;
            updateEnergy(10);
            flag=false;
        }
        else if(num==3)
        {
            cout<<"I'm so lucky to have you. I love being cuddled as it relieves me of all my stress" <<endl<<endl;
            updateEnergy(15);
            flag=false;
        }
        else
        {
            cout<<"Invalid option. Please choose again." <<endl<<endl;
        }
    }
}