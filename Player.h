#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Player : public Person  // ← inherit
{
private:
    string position;
    int jerseyNumber;
    int goalsScored;
    int assists;
    int teamID;
    int appearances;

public:
    Player(int id, string Pname, int P_age, string Pnationality,string pos, int jerseyNumber, int tID, int Pappearence);

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

    void displayInfo() const override;  // ← override pure virtual function from person clas
    void addGoal();
    void addAssist();
    void addAppearance();
    bool isInTeam() const;
    virtual ~Player();
};