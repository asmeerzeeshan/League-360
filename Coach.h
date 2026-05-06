#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Coach : public Person
{
private :
	string role; //e.g., Head Coach, Assistant Coach
	int teamID; //-1 means no team
	int trophiesWon;

public:
	Coach(int C_id, string cName, int C_age, string C_nationality, string role, int teamID = -1, int trophiesWon = 0); //teamID defaults to -1 for coaches not currently assigned to a team

	//GETTERS

	string getRole() const;
	int getTeamID() const;
	int getTrophiesWon() const;
	void displayInfo() const override;

	//SETTERS
	void setRole(const string& role);
	void setTeamID(int id);
	void setTrophiesWon(int trophies);

	//Destructor

	virtual ~Coach();
};
