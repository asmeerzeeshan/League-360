#include"Team.h"
#include <iostream>
using namespace std;

//CONSTRUCTOR

Team::Team(int id, string name, string formationn, string stadium, Coach* c) : teamID(id),
teamName(name),
formation(formationn),
homeStadium(stadium),
coach(c),
wins(0),
draws(0),
losses(0),
goalsFor(0),
goalsAgainst(0)
{
	if (name.empty())
	{
		throw invalid_argument("Team name cannot be empty.");
	}

	if (formationn.empty())
	{
		throw invalid_argument("Formation cannot be empty.");
	}

	if (stadium.empty())
	{
		throw invalid_argument("Home stadium cannot be empty.");
	}

	if (c == nullptr)
	{
		throw invalid_argument("How will u win w/o a coach dumbo");
	}
}

//GETTERS

int Team:: getTeamID() const
{
	return teamID;
}

string Team:: getTeamName() const
{
	return teamName;
}

string Team:: getFormation() const
{
	return formation;
}

string Team:: getHomeStadium() const
{
	return homeStadium;
}

int Team:: getWins() const
{
	return wins;
}

int Team:: getDraws() const
{
	return draws;
}

int Team:: getLosses() const
{
	return losses;
}

int Team:: getGoalsFor() const
{
	return goalsFor;
}

int Team:: getGoalsAgainst() const
{
	return goalsAgainst;
}

Coach* Team:: getCoach() const
{
	return coach;
}

int Team:: getPoints() const
{
	return wins * 3 + draws;
}

int Team:: getGoalDiff() const
{
	return goalsFor - goalsAgainst;
}

int Team:: getMatchesPlayed() const
{
	return wins + draws + losses;
}

//SETTERS

void Team:: setTeamName(const string& name)
{
	teamName = name;
}

void Team:: setFormation(const string& formationn)
{
	formation = formationn;
}

void Team:: setHomeStadium(const string& stadium)
{
	homeStadium = stadium;
}

void Team:: setCoach(Coach* c)
{
	coach = c;
}

//Other Methods regarding team and player management

void Team::addPlayer(Player* p) // adds a player to the team
{

	if (p == nullptr)
	{
		throw invalid_argument("Cannot add a null player to the team.");
	}

	for (Player* existingPlayer : players) // goes through the vector of players 
	{
		if (existingPlayer->getID() == p->getID()) // checks if the player being added has the same ID as any existing player in the team
		{
			throw invalid_argument("Player with this ID already exists in the team."); // if a player with the same ID is found, an exception is thrown to prevent adding a duplicate player to the team
		}
	}
	players.push_back(p); // if no duplicate player is found, the new player is added to the team's vector array thingy by pushing it back into the players vector. Pushing back means adding it to the end of the vector.
}


void Team::removePlayer(int ID)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getID() == ID)
		{
			players.erase(players.begin() + i); // removes the player at index i from the players vector
			return; 
		}
	}
}

Player* Team::findPlayer(int ID) const
{
	for (Player* p : players)
	{
		if (p->getID() == ID)
		{
			return p; // returns a pointer to the player who matched the ID
		}
	}
	return nullptr; // returns nullptr if no player with the specified ID is found in the team
}

void Team::recordResult(int gf, int ga)
{
	goalsFor += gf;
	goalsAgainst += ga;

	if (gf > ga)
		wins++;
	else if (gf == ga)
		draws++;
	else
		losses++;
}

void Team::displayInfo() const
{
	cout << "----- TEAM INFO -----" << endl;
	cout << "Name: " << getTeamName() << endl;
	cout << "Stadium: " << getHomeStadium() << endl;
	cout << "Formation: " << getFormation() << endl;
	cout << "Coach: " << (coach ? coach->getName() : "No coach") << endl;  
	cout << "Matches Played: " << getMatchesPlayed() << endl;  
	cout << "Wins: " << getWins() << endl;
	cout << "Draws: " << getDraws() << endl;
	cout << "Losses: " << getLosses() << endl;
	cout << "Goals For: " << getGoalsFor() << endl;
	cout << "Goals Against: " << getGoalsAgainst() << endl;
	cout << "Goal Difference: " << getGoalDiff() << endl;  
	cout << "Points: " << getPoints() << endl;  
}

void Team::displaySquad() const
{
	cout << "----- SQUAD -----" << endl;
	for (int i = 0; i < players.size(); i++) // iterates through the vector of players in the team
	{
		players[i]->displayInfo(); // calls the displayInfo() method for each player,which is a virtual function that will call the displayInfo() method of the player 
	}
}