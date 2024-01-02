#include "course.h"

Course::Course()
{
	courseName = "None";
	creditHour = 0;
}
Course::Course(const string& n, const int& h)
{
	courseName = n;
	creditHour = h;
}
Course::Course(const Course& c)
{
	courseName = c.courseName;
	creditHour = c.creditHour;
}
Course::~Course() {}
string Course::getCourseName() const { return courseName; }
int Course::getCreditHour() const { return creditHour; }
void Course::setCourseName(const string& n) { courseName = n; }
void Course::setCreditHour(const int& h) { creditHour = h; }
bool Course::operator == (const Course& c) const
{
	if (courseName == c.courseName && creditHour == c.creditHour)
		return true;
	else
		return false;
}
void Course::printInfo(ostream& out) const
{
	out << "Course Name = " << courseName << endl;
	out << "Credit Hours = " << creditHour << endl;
}
ostream& operator<<(ostream& out, const Course& c)
{
	c.printInfo(out);
	return out;
}