#pragma once
#include<string>
#include<iostream>
#include "date.h"
using namespace std;

class Person
{
private:
	string firstName;
	string lastName;
	Date dOB;
public:
	Person();
	Person(const string& f, const string& l, const Date& d);
	Person(const Person& p);

	virtual ~Person();

	string getFirstName() const;
	string getLastName() const;
	Date getDOB() const;

	void setFirstName(const string& f);
	void setLastName(const string& l);
	void setDOB(const Date& d);

	bool operator == (const Person& p) const;

	virtual void printInfo(ostream&) const;

	friend ostream& operator<< (ostream& out, const Person& p);

};