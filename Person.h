#pragma once

#include <string>
using namespace std;

class Person {

private:
   const int personID;
    string name;
    int age;
    string nationality;


public:
    Person(int id, string name, int age, string nationality);

    int getID() const;
    string getName() const;
    int getAge() const;
    string getNationality() const;

    void setName(const string& name);
    void setAge(int age);
    void setNationality(const string& nat);

    virtual void displayInfo() const = 0;
    virtual string getRole() const = 0;

    virtual ~Person();
};