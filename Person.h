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
    virtual void displayInfo() const = 0;

    void setName(const string& name);
    void setAge(int age);
    void setNationality(const string& nat);

 

    virtual ~Person();
};