#include "Player.h"
#include <iostream>
using namespace std;



//CONSTRUCTOR

Player::Player(Person* person, string position, int jerseyNumber, int teamID): personInfo(person), position(position), jerseyNumber(jerseyNumber), 
teamID(teamID), goalsScored(0), assists(0), appearances(0) //Initialize goals, assists, appearances to 0 and the rest with the provided values
{
    if (person == nullptr)
    {
        cout << "Error: Player must have a valid Person." << endl;
        isValid = false;
    }
}

//GETTERS

Person* Player::getPerson()const 
{
	return personInfo;
}

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

//Display player info

void Player::displayInfo() const
{
    if (personInfo == nullptr) {
        cout << "No such player exists" << endl;
        return;
    }

    cout << "----- PLAYER INFO -----" << endl;

    cout << "Name: " << personInfo->getName() << endl;
    cout << "Age: " << personInfo->getAge() << endl;
    cout << "Nationality: " << personInfo->getNationality() << endl;
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