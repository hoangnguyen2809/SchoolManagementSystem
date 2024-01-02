#pragma once
#include<iostream>
#include<string>

using namespace std;

class Course
{
private:
	string courseName;
	int creditHour;
public:
	Course();
	Course(const string& n, const int& h);
	Course(const Course& c);

	virtual ~Course();

	string getCourseName() const;
	int getCreditHour() const;

	void setCourseName(const string& n);
	void setCreditHour(const int& h);

	bool operator == (const Course& c) const;

	virtual void printInfo(ostream&) const;

	friend ostream& operator<< (ostream& out, const Course& c);

};
