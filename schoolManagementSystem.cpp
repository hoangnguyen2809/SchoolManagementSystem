#include "schoolManagementSystem.h"

SchoolManagementSystem::SchoolManagementSystem() : S(), C() {}

int SchoolManagementSystem::getNumberOfRegisteredStudents() const
{
	return (int)S.size();
}

int SchoolManagementSystem::getNumberOfCoursesOffered() const
{
	return (int)C.size();
}

Student SchoolManagementSystem::getStudent(const int& studentIndex) const
{
	assert(studentIndex >= 0 && studentIndex < (int)S.size());
	return S[studentIndex];
}

Course SchoolManagementSystem::getCourse(const int& courseIndex) const
{
	assert(courseIndex >= 0 && courseIndex < (int)C.size());
	return C[courseIndex];
}

void SchoolManagementSystem::addCourse(const Course& course)
{
	bool available = false;
	int size = C.size();
	for (int i = 0; i < size; i++)
		if (C[i] == course)
			available = true;
	if (!available)
		C.push_back(course);
	else
		return;
}

void SchoolManagementSystem::removeCourse(const int& courseIndex)
{
	assert(courseIndex >= 0 && courseIndex < (int)C.size());
	for (int i = 0; i < (int)S.size(); i++)
		S[i].withdraw(getCourse(courseIndex));
	C.erase(C.begin() + courseIndex);
}

int SchoolManagementSystem::searchCourse(const string& courseName) const
{
	int index = -1;
	for (int i = 0; i < (int)C.size(); i++)
		if (C[i].getCourseName() == courseName)
			index = i;
	return index;
}

void SchoolManagementSystem::printAllCourses() const
{
	for (int i = 0; i < (int)C.size(); i++)
		cout << C[i] << endl;
}

void SchoolManagementSystem::registerStudent(const Person& person)
{
	bool registered = false;
	for (int i = 0; i < (int)S.size(); i++)
	{
		Person student(S[i].getFirstName(), S[i].getLastName(), S[i].getDOB());
		if (student == person)
			registered = true;
	}
	if (!registered)
	{
		Student newStudent(person);
		S.push_back(newStudent);
	}
}

void SchoolManagementSystem::removeStudent(const int& studentIndex)
{
	int size = S.size();
	assert(studentIndex >= 0 && studentIndex < size);
	S.erase(S.begin() + studentIndex);
}

void SchoolManagementSystem::enrolStudent(const int& studentIndex, const int& courseIndex)
{
	assert(studentIndex >= 0 && studentIndex < (int)S.size());
	assert(courseIndex >= 0 && courseIndex < (int)C.size());
	S[studentIndex].enrol(getCourse(courseIndex));
}

void SchoolManagementSystem::withdrawStudent(const int& studentIndex, const int& courseIndex)
{
	assert(studentIndex >= 0 && studentIndex < (int)S.size());
	assert(courseIndex >= 0 && courseIndex < (int)C.size());
	S[studentIndex].withdraw(getCourse(courseIndex));
}

void SchoolManagementSystem::assignLetterGrade(const int& studentIndex, const int& courseIndex, const char& letterGrade)
{
	assert(studentIndex >= 0 && studentIndex < (int)S.size());
	assert(courseIndex >= 0 && courseIndex < (int)C.size());
	S[studentIndex].assignLetterGrade(getCourse(courseIndex), letterGrade);
}

Student SchoolManagementSystem::getTopStudent() const
{
	double max = 0;
	int index = 0;
	if (S.size() == 0)
		return Student();
	else
		for (int i = 0; i < (int)S.size(); i++)
			if (S[i].getGPA() > max)
			{
				max = S[i].getGPA();
				index = i;
			}
	return S[index];
}

int SchoolManagementSystem::searchStudent(const string& firstName, const string& lastName) const
{
	int index = -1;
	for (int i = 0; i < (int)S.size(); i++)
		if (S[i].getFirstName() == firstName && S[i].getLastName() == lastName)
			index = i;
	return index;
}

void SchoolManagementSystem::printAllStudents() const
{
	for (int i = 0; i < (int)S.size(); i++)
		cout << S[i] << endl;
}

Person SchoolManagementSystem::generateRandomPerson()
{
	int year = rand() % 5 + 1998;
	int month = rand() % 12 + 1;
	int day = rand() % 30 + 1;

	string firstName = "";
	firstName += rand() % 26 + 65;
	for (int i = 1; i < 10; i++)
		firstName += rand() % 26 + 97;
	string lastName = "";
	lastName += rand() % 26 + 65;
	for (int i = 1; i < 10; i++)
		lastName += rand() % 26 + 97;

	Date dOB(day, month, year);
	Person person(firstName, lastName, dOB);
	return person;
}

char SchoolManagementSystem::generateRandomLetterGrade()
{
	int x = rand() % 11;
	char grade;
	switch (x)
	{
	case 0:
		grade = 'A';
		break;
	case 1:
	case 2:
		grade = 'B';
		break;
	case 3:
	case 4:
	case 5:
		grade = 'C';
		break;
	case 6:
	case 7:
		grade = 'D';
		break;
	case 8:
	case 9:
	case 10:
		grade = 'F';
		break;
	}
	return grade;
}