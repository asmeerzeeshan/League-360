#include <iostream>
#include "Person.h"
using namespace std;


Person::Person(int id, string name, int age, string nationality) : personID(id)
{
	this->name = name;
	this->age = age;
	this->nationality = nationality;
}

int Person::getID() const
{
	return personID;
}	

int Person::getAge() const
{
	return age;
}

string Person::getName() const
{
	return name;
}

string Person::getNationality() const
{
	return nationality;
}

void Person::setName(const string& name)
{
	if (name.empty())
	{
		cout << "Name cannot be empty." << endl;
		return;
	}
	this->name = name;
}

void Person::setAge(int age)
{
	if (age <= 0 || age > 100)
	{
		cout << "Invalid age. Age must be between 1 and 100." << endl;
		return;
	}
	this->age = age;
}

void Person::setNationality(const string& nat)
{
	if (nat.empty())
	{
		cout << "Nationality cannot be empty." << endl;
		return;
	}
	this->nationality = nat;
}

Person::~Person() {}