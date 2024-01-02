#pragma once
#include "student.h"
#include "course.h"
#include<cassert>
class SchoolManagementSystem
{
private:
	vector<Student> S;
	vector<Course> C;
public:
	SchoolManagementSystem();

	int getNumberOfRegisteredStudents() const;
	int getNumberOfCoursesOffered() const;

	Student getStudent(const int& studentIndex) const;
	Course getCourse(const int& courseIndex) const;

	void addCourse(const Course& course);
	void removeCourse(const int& courseIndex);

	int searchCourse(const string& courseName) const;
	void printAllCourses() const;

	void registerStudent(const Person& person);
	void removeStudent(const int& studentIndex);
	void enrolStudent(const int& studentIndex, const int& courseIndex);
	void withdrawStudent(const int& studentIndex, const int& courseIndex);
	void assignLetterGrade(const int& studentIndex, const int& courseIndex, const char& letterGrade);
	Student getTopStudent() const;

	int searchStudent(const string& firstName, const string& lastName) const;
	void printAllStudents() const;

	static Person generateRandomPerson();
	static char generateRandomLetterGrade();
};