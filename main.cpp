#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#include "Pet.h"
#include "Dog.h"
#include "Squirrel.h"
#include "Bird.h"
//function to print the rules of the game

void printRules()
{
cout << " _                                    _       _     _ " << endl;
cout << "| |                                  | |     | |   (_)" << endl;
cout << "| |_ __ _ _ __ ___   __ _  __ _  ___ | |_ ___| |__  _ " << endl;
cout << "| __/ _` | '_ ` _ \\ / _` |/ _` |/ _ \\| __/ __| '_ \\| |" << endl;
cout << "| || (_| | | | | | | (_| | (_| | (_) | || (__| | | | |" << endl;
cout << " \\__\\__,_|_| |_| |_|\\__,_|\\__, |\\___/ \\__\\___|_| |_|_|" << endl;
cout << "                           __/ |                      " << endl;
cout << "                          |___/                       " << endl;

    cout << "******************************************************************************************************************************" <<endl << endl;
    cout << "Welcome to Tamagotchi!!!" << endl << endl;
    cout << "In this game, you will be taking care of your virtual pet that needs your love and attention to stay healthy and happy." << endl << endl;
    cout << "Your pet will need to be fed regularly to keep its hunger level under control. If your pet's hunger level gets too high,\n"
        <<"it will become unhappy and may become sick if not properly cared for." << endl << endl;
    cout << "Your pet also needs to sleep regularly to maintain its energy level. If your pet's energy level drops too low,\n"
        <<"it will become tired and less responsive to your actions." << endl << endl;
    cout << "To keep your pet entertained and mentally stimulated, you can play games with it.\n"
        <<"This will help keep your pet's mood up and prevent boredom." << endl << endl;
    cout << "Remember, taking care of a pet is a big responsibility, and neglecting your pet's needs could result in serious consequences.\n"
        <<"Do your best to keep your pet happy and healthy, and enjoy spending time with your new friend!!!" << endl << endl;
    cout << "******************************************************************************************************************************" <<endl << endl;
}

int askLoadGame()//function asking to choose between new game and load profile
{
    int option;
    cout<<"Let's get started! Would you like to start a new game or load profile?"<<endl;
    cout<<"Press 1 to start a new game."<<endl;
    cout<<"Press 2 to load your saved profile."<<endl<<endl; 
  cout<<"******************************************************************************************************************************"<<endl<<endl;
    cin>>option;
    cout<<endl; 
  cout<<"******************************************************************************************************************************"<<endl<<endl;
    return option;
}

//function checking if the file in the name of the user already exists when being loaded
string loadGame(string _uname)
{
    ifstream ifile;
    string type;
    ifile.open(_uname+".txt");
    if(!ifile)
    {
        return "";
    }
    ifile>>type;
    ifile.close();
    return type;
}
void printOptionsToChoose(){
  cout << "*************************************************************************************************************"<<endl;
  cout << "Please choose from the following menu options:" << endl;
  cout << "Enter 1 to ask the admin for a hint"<< endl;
  cout << "Enter 2 to see how your pet is feeling" << endl;
  cout << "Enter 3 to feed your pet" << endl;
  cout << "Enter 4 to play with your pet" << endl;
  cout << "Enter 5 to put your pet to sleep" << endl;
  cout << "Enter q to quit the game" << endl;
}
bool checkName(string name)//function checking if the username entered follows the rules specified
{
    bool correct=true;
    if(name.length()>0 && name.length()<=10)
    {
        for(int i=0;i<name.length();i++)
        {
            if(isalnum(name[i]))
            {
                correct=true;
            }
            else
            {
                correct=false;
            }
            if(correct==false)
            {
                break;
            }
        }
        if(correct==false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool checkNameUser(string name)
{
    ifstream ifile;
    ifile.open(name+".txt");
    if(ifile)
    {
        return true;
    }
    ifile.close();
    return false;
}

string createName()
{
    string uname;
    bool correct=true, exist;
    cout<<"It's time to create your username!!!"<<endl;
    cout<<"Please keep in mind the following rules:"<<endl;
    cout<<" 1) The name cannot be longer than 10 characters"<<endl;
    cout<<" 2) Only letters and numbers are allowed"<<endl<<endl;   
cout<<"******************************************************************************************************************************"<<endl<<endl;
    cin>>uname;
    correct=checkName(uname);
    exist=checkNameUser(uname);
    while(correct==false)
    {
        cout<<"Please keep in mind the following rules to re-enter the name:"<<endl;
        cout<<" 1) The name cannot be longer than 10 characters"<<endl;
        cout<<" 2) Only letters and numbers are allowed"<<endl;
      cout<<"******************************************************************************************************************************"<<endl<<endl;
        cin>>uname;
        correct=checkName(uname);
    }  
    while(exist)
    {
        cout<<"The user already exists"<<endl;
        cout<<"Please keep in mind the following rules to re-enter the name:"<<endl;
        cout<<" 1) The name cannot be longer than 10 characters"<<endl;
        cout<<" 2) Only letters and numbers are allowed"<<endl;
      cout<<"******************************************************************************************************************************"<<endl<<endl;
        cin>>uname;
        exist=checkNameUser(uname);
    }
    return uname;
}

int newAnimalChoice(){
    cout<< "Which pet do you want to have?" << endl;
    cout<< "OPTION 1 - A LOYAL DOG 🥹" << endl;
    cout<< endl;
    cout<<  "     _=," << endl;
    cout<<  " o_/6 /#\\ " << endl;
    cout<<  " \\__ |##/" << endl;
    cout<<  "  ='|--\\ " << endl;
    cout<<  "   /   #'-. " << endl;
    cout<<  "   \\#|_   _'-. /" << endl;
    cout<<  "    |/ \\_( # |" << endl;
    cout<<  "   C/ ,--___/" << endl;
  
    cout << endl;
    cout<< "OPTION 2 - A PLAYFUL SQUIRREL 🤓"<< endl;
    cout << endl;
    cout<<" ,;;:;," << endl;
    cout<<"   ;;;;;" << endl;
    cout<<" ,:;;:;    ,'=." << endl;
    cout<<" ;:;:;  .='' ,'_\\" << endl;
    cout<<"  :;:;,/  ,__:=@" << endl;
    cout<<"   ';;:;  =./)_" << endl;
    cout<<"    `'=\_  )_'`" << endl;
    cout<<"       ``'''`" << endl;

    cout<< endl;
    cout<< "OPTION 3 - AN ENERGETIC BIRD 🤠" << endl;
    cout<< endl;
    cout<<"               /" << endl;
    cout<<"\\             / /"<< endl;
    cout<<" \\\\\\' ,      / //"<< endl;
    cout<<"  \\\\\\//,   _/ //,"<< endl;
    cout<<"   \\_-//' /  //<,"<< endl;
    cout<<"     \\ ///  >  \\\\\\`__/_"<< endl;
    cout<<"     /,)-^>> _\\` \\\\\\" << endl;
    cout<<"     (/   \\\\ //\\\\"<< endl;
    cout<<"         // _//\\\\\\\\"<< endl;
    cout<<"       ((` (("<< endl;
    cout << endl;
    cout << "*************************************************************************************************************"<<endl;
    int petnum;
    cin >> petnum;
    return petnum;
}

int main()
{
    Pet* player=nullptr;                   //pointer of Pet type
    bool playGame=true;
    bool flagForLoad=true;
    string user,pname;
    char escape;
    printRules();
    int optionToLoad=askLoadGame();
    if(optionToLoad==1)                    //when user chooses to create a new profile
    {
        string newPlayerName=createName();
        int animalChoice=newAnimalChoice();
        switch(animalChoice)
        {
            case 1:
                cout<<"Enter the name of your dog"<<endl;
                cin>>pname;
                player= new Dog(newPlayerName,"Dog",pname);
                break;
            case 2:
                cout<<"Enter the name of your squirrel"<<endl;
                cin>>pname;
                player= new Squirrel(newPlayerName,"Squirrel",pname);
                break;
            case 3:
                cout<<"Enter the name of your bird"<<endl;
                cin>>pname;
                player= new Bird(newPlayerName,"Bird",pname);
                break;
            default:
                cout<<"You entered the wrong option. Start again!"<<endl;
                exit(1);
                break;
        }
    }
    else if(optionToLoad==2)              //when user chooses to load a saved profile
    {
        while(flagForLoad)
        {
            cout<<"Enter your username"<<endl;
            cin>>user;
            if(loadGame(user)=="Dog")
            {
                player= new Dog(user);
                flagForLoad=false;
            }
            else if(loadGame(user)=="Squirrel")
            {
                player= new Squirrel(user);
                flagForLoad=false;
            }
            else if(loadGame(user)=="Bird")
            {
                player= new Bird(user);
                flagForLoad=false;
            }
            else if(user=="Q" || user == "q")
            {
                cout<<"Game exited. Start the game again!"<<endl;
                exit(1);
            }
            else
            {
                cout<<"User does not exist. Try again or enter Q in the next prompt to start again."<<endl<<endl;
            }
        }
    } 
    else                     //when the user enters a wrong menu option
    {
        cout<<"You entered the wrong option. Start again!"<<endl<<endl;
        exit(1);
    }
    cout<<endl;
  cout<<"******************************************************************************************************************************"<<endl<<endl;
    cout << player->printWelcomeInfo();
    while(playGame)                   //game loop
    {
        char optionChoice;
        printOptionsToChoose();
        cin>>optionChoice;
        switch(optionChoice)
        {
            case '1':
                player->printPetInfo();
                player->nextHour();
                break;
            case '2':
                cout << player->printPetMood();
                player->nextHour();
                break;

            case '3':
                player->feed();
                player->nextHour();
                break;
            case '4':
                player->play();
                player->nextHour();
                break;
            case '5':
                player->sleep();
                player->nextHour();
                break;
            case 'Q':
            case 'q':
                
                player->saveGame();
                playGame=false;
                break;
            default:
                cout<<"Invalid entry. Try again."<<endl<<endl;
                break;
        }
        player->seeStats();
        if(player->gameover())        
        {
            player->saveGame();
            break;
        }
        else                         //generates a warning if the pet's levels reach an extreme
        {
            player->generateWarning();      
            continue;
        }
    }
    delete player; 
    return 0;
}