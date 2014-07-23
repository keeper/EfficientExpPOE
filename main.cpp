#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int NORM_LEDGE = 7;                         //Zones Levels
int CRUE_LEDGE = 37;
int MERC_LEDGE = 53;
int NORM_SARN = 26;
int CRUE_SARN = 46;
int MERC_SARN = 61;
int NORM_DOCKS = 32;
int CRUE_DOCKS = 50;
int MERC_DOCKS = 62;
int NORM_LNRS3 = 34;
int CRUE_LNRS3 = 52;
int MERC_LNRS3 = 66;
int MAPS_66 = 66;
int MAPS_67 = 67;
int MAPS_68 = 68;
int MAPS_69 = 69;
int MAPS_70 = 70;
int MAPS_71 = 71;
int MAPS_72 = 72;
int MAPS_73 = 73;
int MAPS_74 = 74;
int MAPS_75 = 75;
int MAPS_76 = 76;
int MAPS_77 = 77;
int MAPS_78 = 78;

string input = "";                          //Variable that saves user's last input
int charLevel = 0;                          //Variable that saves the characters level
int EficientLower = 0;                      //Variable that saves the lowest level with 100% exp efficiency
int EficientUpper = 0;                      //Variable that saves the highest level with 100% exp efficiency

void init(int argc, char *argv[])
{
    if(argc != 2){
        cout << "Enter character level" << endl;
        cin >> input;
        charLevel = atoi(input.c_str());
    } else {
        charLevel = atoi(argv[1]);
    }
}

void calculate()
{
    int x = (int)charLevel/16;
    int Safemargin = 3 + x;

    EficientLower = charLevel - Safemargin;
    EficientUpper = charLevel + Safemargin;

    cout << "100% exp from " << EficientLower << " to " << EficientUpper << endl;
}

void checkZones()
{
    cout << "That includes the following zones:" << endl;
    for(int i = EficientLower; i <= EficientUpper; i++){
        if(i == NORM_LEDGE){
            cout << "\tNormal Ledge" << endl;
        }
        if(i == CRUE_LEDGE){
            cout << "\tCruel Ledge" << endl;
        }
        if(i == MERC_LEDGE){
            cout << "\tMerciless Ledge" << endl;
        }

        if(i == NORM_SARN){
            cout << "\tNormal City of Sarn" << endl;
        }
        if(i == CRUE_SARN){
            cout << "\tCruel City of Sarn" << endl;
        }
        if(i == MERC_SARN){
            cout << "\tMerciless City of Sarn" << endl;
        }

        if(i == NORM_DOCKS){
            cout << "\tNormal Docks" << endl;
        }
        if(i == CRUE_DOCKS){
            cout << "\tCruel Docks" << endl;
        }
        if(i == MERC_DOCKS){
            cout << "\tMerciless Docks" << endl;
        }

        if(i == NORM_LNRS3){
            cout << "\tNormal Lunaris Temple" << endl;
        }
        if(i == CRUE_LNRS3){
            cout << "\tCruel Lunaris Temple" << endl;
        }
        if(i == MERC_LNRS3){
            cout << "\tMerciless Lunaris Temple" << endl;
        }

        if(i == MAPS_66){
            cout << "\t" << MAPS_66 << " Maps" << endl;
        }
        if(i == MAPS_67){
            cout << "\t" << MAPS_67 << " Maps" << endl;
        }
        if(i == MAPS_68){
            cout << "\t" << MAPS_68 << " Maps" << endl;
        }
        if(i == MAPS_69){
            cout << "\t" << MAPS_69 << " Maps" << endl;
        }
        if(i == MAPS_70){
            cout << "\t" << MAPS_70 << " Maps" << endl;
        }
        if(i == MAPS_71){
            cout << "\t" << MAPS_71 << " Maps" << endl;
        }
        if(i == MAPS_72){
            cout << "\t" << MAPS_72 << " Maps" << endl;
        }
        if(i == MAPS_73){
            cout << "\t" << MAPS_73 << " Maps" << endl;
        }
        if(i == MAPS_74){
            cout << "\t" << MAPS_74 << " Maps" << endl;
        }
        if(i == MAPS_75){
            cout << "\t" << MAPS_75 << " Maps" << endl;
        }
        if(i == MAPS_76){
            cout << "\t" << MAPS_76 << " Maps" << endl;
        }
        if(i == MAPS_77){
            cout << "\t" << MAPS_77 << " Maps" << endl;
        }
        if(i == MAPS_78){
            cout << "\t" << MAPS_78 << " Maps" << endl;
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
    init(argc, argv);                       //Initializes the program, uses the 1st parameter has character level or ask's for it

    do{
        calculate();                        //Calculates the lowest and highest levels of efficient exp
        checkZones();                       //Checks if the zones are in the interval and output's them
        showMenu();                         //displays the options the program gives to the user
        levelUp();                          //Levels up the character and displays it's new level

    } while(input.c_str()[0] == '+');       //Repeat's until something other than +(to level up) is inputed

    return 0;                               //ends the program
}
