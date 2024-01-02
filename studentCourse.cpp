#include "studentCourse.h"

StudentCourse::StudentCourse() : Course(), letterGrade('N') {}
StudentCourse::StudentCourse(const string& n, const int& h, const char& l) : Course(n, h), letterGrade(l) {}
StudentCourse::StudentCourse(const StudentCourse& s) : Course(s), letterGrade(s.letterGrade) {}
StudentCourse::StudentCourse(const Course& c) : Course(c), letterGrade('N') {}
StudentCourse::~StudentCourse() {}
char StudentCourse::getLetterGrade() const { return letterGrade; }
void StudentCourse::setLetterGrade(const char& grade) { letterGrade = grade; }
void StudentCourse::printInfo(ostream& out) const
{
	this->Course::printInfo(out);
	out << endl;
	out << "Letter Grade = " << this->getLetterGrade() << endl;
}
ostream& operator<< (ostream& out, const StudentCourse& s)
{
	s.printInfo(out);
	return out;
}