#include "person.h"

Person::Person() : firstName("None"), lastName("None"), dOB(0, 0, 0) {}
Person::Person(const string& f, const string& l, const Date& d) : firstName(f), lastName(l), dOB(d) {}
Person::Person(const Person& p) : dOB(p.dOB.day, p.dOB.month, p.dOB.year)
{
	firstName = p.firstName;
	lastName = p.lastName;
}
Person::~Person() {}
string Person::getFirstName() const { return firstName; }
string Person::getLastName() const { return lastName; }
Date Person::getDOB() const { return dOB; }
void Person::setFirstName(const string& f) { firstName = f; }
void Person::setLastName(const string& l) { lastName = l; }
void Person::setDOB(const Date& d) { dOB.day = d.day; dOB.month = d.month; dOB.year = d.year; }
bool Person::operator==(const Person& p) const
{
	if (firstName == p.firstName && lastName == p.lastName && dOB.day == p.dOB.day && dOB.month == p.dOB.month && dOB.year == p.dOB.year)
		return true;
	else
		return false;
}
void Person::printInfo(ostream& out) const
{
	out << "Full Name = " << firstName << " " << lastName << endl;
	out << "Date of birth (d-m-y) = " << dOB.day << "-" << dOB.month << "-" << dOB.year << endl;
}
ostream& operator<< (ostream& out, const Person& p)
{
	p.printInfo(out);
	return out;
}