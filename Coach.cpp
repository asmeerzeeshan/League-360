#include "Coach.h"
#include <iostream>
using namespace std;

Coach::Coach(int C_id, string cName, int C_age, string C_nationality, string C_Role, int C_TeamID, int C_TrophiesWon):
    Person(C_id, cName, C_age, C_nationality), 
    role(C_Role), 
    teamID(C_TeamID),
    trophiesWon(C_TrophiesWon) 
{
    
    if (cName.empty())
    {
        throw invalid_argument("Coach name cannot be empty.");
    }

    if (C_age <= 0 || C_age > 100)
    {
        throw invalid_argument("Invalid age.");
    }

    if (C_Role.empty())
    {
        throw invalid_argument("Coach role cannot be empty.");
    }

}

//GETTERS

string Coach::getRole() const 
{
    return role;
}

int Coach::getTeamID() const 
{
    return teamID;
}

int Coach::getTrophiesWon() const
{
    return trophiesWon;
}

//Setters

void Coach::setRole(const string &role)
{
    this->role = role;
}

void Coach::setTeamID(int id)
{
    teamID = id;
}

void Coach::setTrophiesWon(int trophies)
{
    trophiesWon = trophies;
}

//Other Methods
void Coach::displayInfo() const
{

    cout << "----- COACH INFO -----" << endl;

    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Nationality: " << getNationality() << endl;
    cout << "Role: " << role << endl;
    cout << "Trophies Won: " << trophiesWon << endl;

    if (teamID == -1)
        cout << "Team: Free Agent" << endl;
    else
        cout << "Team ID: " << teamID << endl << endl;
}

Coach::~Coach() {} //DESTRUCTOR