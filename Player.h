#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Player
{
private:
	bool isValid = true;
	Person* personInfo; //aggregation of Person
	string position;
	int jerseyNumber;
	int goalsScored;
	int assists;
	int teamID; //-1 means no team
	int appearances;

public:

	Player(Person* person, string position, int jerseyNumber, int teamID);


	Person* getPerson() const;
	string getPosition() const;
	int getJerseyNumber() const;
	int getGoalsScored() const;
	int getAssists() const;
	int getTeamID() const;
	int getAppearances() const;

	void setPosition(const string& pos);
	void setJerseyNumber(int num);
	void setGoalsScored(int goals);
	void setAssists(int a);
	void setTeamID(int id);
	void setAppearances(int app);


	void displayInfo() const;
	void addGoal();
	void addAssist();
	void addAppearance();

};