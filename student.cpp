#include "student.h"

Student::Student() : Person(), coursesEnrolled() {}
Student::Student(const string& f, const string& l, const Date& d, const vector<StudentCourse> c) : Person(f, l, d), coursesEnrolled(c) {}
Student::Student(const Student& s) : Person(s), coursesEnrolled(s.coursesEnrolled) {}
Student::Student(const Person& p) : Person(p), coursesEnrolled() {}
Student::~Student() {}
vector<StudentCourse> Student::getCourses() { return coursesEnrolled; }
double Student::getGPA() const
{
	int size = coursesEnrolled.size();
	double totalCreditPoint = 0.0, credHours = 0.0, mark = 0.0;
	for (int i = 0; i < size; i++)
	{
		if (coursesEnrolled[i].getLetterGrade() != 'N')
		{
			credHours += coursesEnrolled[i].getCreditHour();
			if (coursesEnrolled[i].getLetterGrade() == 'A')
			{
				mark = 4 * coursesEnrolled[i].getCreditHour();
				totalCreditPoint += mark;
			}
			else if (coursesEnrolled[i].getLetterGrade() == 'B')
			{
				mark = 3 * coursesEnrolled[i].getCreditHour();
				totalCreditPoint += mark;
			}
			else if (coursesEnrolled[i].getLetterGrade() == 'C')
			{
				mark = 2 * coursesEnrolled[i].getCreditHour();
				totalCreditPoint += mark;
			}
			else if (coursesEnrolled[i].getLetterGrade() == 'D')
			{
				mark = 1 * coursesEnrolled[i].getCreditHour();
				totalCreditPoint += mark;
			}
			else if (coursesEnrolled[i].getLetterGrade() == 'F')
			{
				mark = 0 * coursesEnrolled[i].getCreditHour();
				totalCreditPoint += mark;
			}
		}
	}
	if (credHours == 0.0)
		return credHours;
	else
		return totalCreditPoint / credHours;
}
void Student::enrol(const Course& c)
{
	StudentCourse course = c;
	bool ans = false;
	for (int i = 0; i < (int)coursesEnrolled.size(); i++)
		if (coursesEnrolled[i] == course)
			ans = true;
	if (ans = true)
		coursesEnrolled.push_back(course);
}
void Student::withdraw(const Course& c)
{
	StudentCourse course = c;
	bool ans = true;
	for (int i = 0; i < (int)coursesEnrolled.size(); i++)
		if (coursesEnrolled[i] == course)
		{
			ans = false;
			coursesEnrolled.erase(coursesEnrolled.begin() + i);
		}
}
void Student::assignLetterGrade(const Course& c, const char& grade)
{
	int size = coursesEnrolled.size();
	StudentCourse course = c;
	for (int i = 0; i < size; i++)
		if (coursesEnrolled[i].getCourseName() == c.getCourseName())
			coursesEnrolled[i].setLetterGrade(grade);
}
bool Student::operator>(const Student& student) const
{
	if (this->getGPA() > student.getGPA())
		return true;
	else
		return false;
}
void Student::printInfo(ostream& out) const
{
	this->Person::printInfo(out);
	out << endl;
	out << "Courses taken or enrolled in..." << endl;

	for (int i = 0; i < (int)coursesEnrolled.size(); i++)
	{
		out << "Course Name = " << coursesEnrolled[i].getCourseName() << endl;
		out << "Credit Hours = " << coursesEnrolled[i].getCreditHour() << endl;
		out << "Letter Grade = " << coursesEnrolled[i].getLetterGrade() << endl << endl;
	}

	out << endl;
	out << "GPA = " << this->getGPA() << endl;
	out << endl;
}
ostream& operator <<(ostream& out, const Student& s)
{
	s.printInfo(out);
	return out;
}