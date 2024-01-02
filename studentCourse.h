#pragma once
#include "course.h"

class StudentCourse : public Course
{
private:
	char letterGrade;
public:
	StudentCourse();
	StudentCourse(const string& n, const int& h, const char& l);
	StudentCourse(const StudentCourse& s);
	StudentCourse(const Course& c);

	virtual ~StudentCourse();

	char getLetterGrade() const;
	void setLetterGrade(const char& grade);

	virtual void printInfo(ostream&) const;

	friend ostream& operator<< (ostream& out, const StudentCourse& s);
};