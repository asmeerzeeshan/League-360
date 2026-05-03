#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Coach
{
private :
	Person* personInfo; //aggregation of Person
	string role; //e.g., Head Coach, Assistant Coach
	int teamID; //-1 means no team
	int trophiesWon;

public:
	Coach(Person* person, string role, int teamID = -1, int trophiesWon = 0); //teamID defaults to -1 for coaches not currently assigned to a team

	Person* getPerson() const;
	string getRole() const;
	int getTeamID() const;
	int getTrophiesWon() const;
};
