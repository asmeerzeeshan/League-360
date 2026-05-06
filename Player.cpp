#include "Player.h"
#include <iostream>
#include <stdexcept> //For throw and catch exception handling
using namespace std;



//CONSTRUCTOR

Player::Player(int id, string Pname, int P_age, string Pnationality, string pos, int jerseyNum, int tID, int Pappearance) 
    : Person(id, Pname, P_age, Pnationality) , 
    position(pos), 
    jerseyNumber(jerseyNum),
    teamID(tID),          
    goalsScored(0),       
    assists(0),           
    appearances(Pappearance)
{
    if (Pname.empty())
        throw invalid_argument("Player name cannot be empty.");
    if (P_age <= 0 || P_age > 100)
        throw invalid_argument("Invalid age.");
    if (jerseyNum <= 0)
        throw invalid_argument("Jersey number must be above 0.");
}  


//GETTERS



string Player::getPosition() const 
{
    return position;
}

int Player::getJerseyNumber() const 
{
    return jerseyNumber;
}

int Player::getGoalsScored() const 
{
    return goalsScored;
}

int Player::getAssists() const 
{
    return assists;
}

int Player::getTeamID() const
{
    return teamID;
}

int Player::getAppearances() const 
{
    return appearances;
}

//SETTERS

void Player::setPosition(const string& pos)  //const string& to avoid unnecessary copying
{
    position = pos;
}

void Player::setJerseyNumber(int num)
{
    if (num <= 0)
    {
        cout << "Invalid jersey number, need a number above 0" << endl;
        return;
    }
    jerseyNumber = num;
}

void Player::setGoalsScored(int goals) 
{
    goalsScored = goals;
}

void Player::setAssists(int a) 
{
    assists = a;
}

void Player::setTeamID(int id) 
{
    teamID = id;
}

void Player::setAppearances(int apps) 
{
    appearances = apps;
}

//OTHER METHODS

void Player::addGoal() 
{
    goalsScored++;
}

void Player::addAssist() 
{
    assists++;
}

void Player::addAppearance() 
{
    appearances++;
}

bool Player::isInTeam() const
{
    return teamID != -1;
}

//Display player info

void Player::displayInfo() const 
{

    cout << "----- PLAYER INFO -----" << endl;

    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Nationality: " << getNationality() << endl;
    cout << "Position: " << position << endl;
    cout << "Jersey Number: " << jerseyNumber << endl;
    cout << "Goals: " << goalsScored << endl;
    cout << "Assists: " << assists << endl;
    cout << "Appearances: " << appearances << endl;

    if (teamID == -1)
        cout << "Team: Free Agent" << endl;
    else
        cout << "Team ID: " << teamID << endl << endl;
}

Player::~Player() {}