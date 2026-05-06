#pragma once
#include "Player.h"
#include "Coach.h"
#include <vector>
#include <string>
using namespace std;

class Team
{
private:
	string teamName;
	int teamID;
	vector<Player*> players;
	Coach* coach;// Pointer to a coach, not an object to allow for team to get deleted and coach to still exist
	string formation; //e.g., 4-4-2, 3-5-2
	string homeStadium;

	int wins;
	int draws;
	int losses;
	int goalsFor;
	int goalsAgainst;

public:
	Team(int id, string name, string formationn, string stadium, Coach* c);

	//GETTERS
	
	int getTeamID() const;
	string getTeamName() const;
	string getFormation() const;
	string getHomeStadium() const;
	int getWins() const;
	int getDraws() const;
	int getLosses() const;
	int getGoalsFor() const;
	int getGoalsAgainst() const;
	Coach* getCoach() const;
	int getPoints() const;       // calculated: wins*3 + draws
	int getGoalDiff() const;     // calculated: goalsFor - goalsAgainst
	int getMatchesPlayed() const; // calculated: wins + draws + losses

	//SETTERS
	void setTeamName(const string& name);
	void setFormation(const string& formation);
	void setHomeStadium(const string& stadium);
	void setCoach(Coach* c);

	//Other Methods regarding team and player management

	void addPlayer(Player* p);
	void removePlayer(int playerID);
	Player* findPlayer(int playerID) const; //const added so it does not amend or modify the

	// Match result
	void recordResult(int gf, int ga); // auto calculates W/D/L

	//Display

	void displayInfo() const;
	void displaySquad() const;

};