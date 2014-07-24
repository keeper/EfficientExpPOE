#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

map<const int, const char*> zones;          //Variable that saves the zones mob level and name
string input = "";                          //Variable that saves user's last input
int charLevel = 0;                          //Variable that saves the characters level
int EficientLower = 0;                      //Variable that saves the lowest level with 100% exp efficiency
int EficientUpper = 0;                      //Variable that saves the highest level with 100% exp efficiency

int getLevel()
{
    cout << "Enter character level" << endl;
    cin >> input;

    for(unsigned int i = 0; i < input.length(); i++){
        int ascii = input.c_str()[i];

        int zero = '0';
        if(ascii < zero || ascii > zero+9){
            return 0;
        }
    }

    return 1;
}

int init(int argc, char *argv[])
{
    //data initialization
    zones.insert(make_pair(7, "Normal Ledge"));
    zones.insert(make_pair(37, "Cruel Ledge"));
    zones.insert(make_pair(53, "Merciless Ledge"));
    zones.insert(make_pair(26, "Normal City of Sarn"));
    zones.insert(make_pair(46, "Cruel City of Sarn"));
    zones.insert(make_pair(61, "Merciless City of Sarn"));
    zones.insert(make_pair(32, "Normal Docks"));
    zones.insert(make_pair(50, "Cruel Docks"));
    zones.insert(make_pair(62, "Merciless Docks"));
    zones.insert(make_pair(34, "Normal Lunaris 3"));
    zones.insert(make_pair(52, "Cruel Lunaris 3"));
    zones.insert(make_pair(66, "Merciless Lunaris 3"));
    zones.insert(make_pair(66, "66 Maps"));
    zones.insert(make_pair(67, "67 Maps"));
    zones.insert(make_pair(68, "68 Maps"));
    zones.insert(make_pair(69, "69 Maps"));
    zones.insert(make_pair(70, "70 Maps"));
    zones.insert(make_pair(71, "71 Maps"));
    zones.insert(make_pair(72, "72 Maps"));
    zones.insert(make_pair(73, "73 Maps"));
    zones.insert(make_pair(74, "74 Maps"));
    zones.insert(make_pair(75, "75 Maps"));
    zones.insert(make_pair(76, "76 Maps"));
    zones.insert(make_pair(77, "77 Maps"));
    zones.insert(make_pair(78, "78 Maps"));

    if(argc != 2){
        if(getLevel()){
            charLevel = atoi(input.c_str());
        } else {
            cout << "Bad Input, closing program" << endl;
            return 0;
        }
    } else {
        charLevel = atoi(argv[1]);                              //if using console parameter it's not a regular user
    }

    return 1;
}

void calculate()
{
    int x = charLevel >> 4;
    int Safemargin = 3 + x;

    EficientLower = charLevel - Safemargin;
    EficientUpper = charLevel + Safemargin;

    cout << "100% exp from " << EficientLower << " to " << EficientUpper << endl;
}

void checkZones()
{
    cout << "That includes the following zones:" << endl;
    for(int i = EficientLower; i <= EficientUpper; i++){
        map<const int, const char *>::iterator zone = zones.find(i);  //goes trough the hole map returns zones.end() zone if none is found

        if(zone != zones.end()){
            cout << "\t" << zone->second << endl;
        }
    }
}

void showMenu()
{
    cout << endl;
    cout << "+ to add a level" << endl;
    cout << "anything else to exit" << endl;
}

void levelUp()
{
    cin >> input;
    charLevel++;

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Level: "<< charLevel << endl;
}

int main (int argc, char *argv[])
{
    if(init(argc, argv)){                   //Initializes the program, uses the 1st parameter has character level or ask's for it
        do{
            calculate();                    //Calculates the lowest and highest levels of efficient exp
            checkZones();                   //Checks if the zones are in the interval and output's them
            showMenu();                     //displays the options the program gives to the user
            levelUp();                      //Levels up the character and displays it's new level

        } while(input.c_str()[0] == '+');   //Repeat's until something other than +(to level up) is inputed
    }

    return 0;                               //ends the program
}
