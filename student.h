#pragma once
#include "course.h"
#include<vector>
#include "studentCourse.h"
#include "person.h"
class Student : public Person
{
private:
	vector<StudentCourse> coursesEnrolled;
public:
	Student();
	Student(const string& f, const string& l, const Date& d, const vector<StudentCourse> c);
	Student(const Student& s);
	Student(const Person& p);

	virtual ~Student();

	vector<StudentCourse> getCourses();

	double getGPA() const;
	void enrol(const Course&);
	void withdraw(const Course&);
	void assignLetterGrade(const Course&, const char&);
	bool operator>(const Student&) const;

	virtual void printInfo(ostream& out) const;

	friend ostream& operator<< (ostream& out, const Student& student);
};