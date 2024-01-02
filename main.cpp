#include<iostream>
#include<algorithm>
#include<ctime>
#include "course.h"
#include "studentCourse.h"
#include "date.h"
#include "person.h"
#include "student.h"
#include "schoolManagementSystem.h"

using namespace std;


int main()
{
	cout << "Welcome to Phantom College School Management System" << endl;
	cout << "===================================================" << endl << endl;

	srand(1);

	//Prepare the courses offered in the school
	Course course[] = { Course("CMPT120", 2), Course("CMPT130", 3), Course("CMPT135", 4),
						  Course("MACM101", 2), Course("CALC151", 3), Course("CALC152", 4),
						  Course("MATH242", 4), Course("ECON101", 3), Course("ECON102", 4),
						  Course("ENGL100", 2), Course("HIST101", 3), Course("PHYS100", 2),
						  Course("PHYS101", 3), Course("PHYS102", 4), Course("CHEM101", 3),
						  Course("CHEM102", 4) };

	//Construct a school management system object
	SchoolManagementSystem sys;

	//Add the courses offered to the system
	for (int i = 0; i < 16; i++)      //there are 16 courses initially
		sys.addCourse(course[i]);

	//Print all courses offered in the school
	cout << "All the courses offered in the school are..." << endl;
	sys.printAllCourses();
	cout << endl << endl;

	//See if BIOL150 is offered in the school
	int courseIndex = sys.searchCourse("BIOL150");
	if (courseIndex == -1)
		cout << "BIOL150 is not offered in the school." << endl;
	else
	{
		cout << "BIOL150 is offered in the school. Details below..." << endl;
		cout << sys.getCourse(courseIndex) << endl;
	}
	cout << endl << endl;

	//Register some new students
	for (int i = 0; i < 10; i++)
		sys.registerStudent(Student(sys.generateRandomPerson()));

	//Enroll students to some courses
	for (int studentIndex = 0; studentIndex < sys.getNumberOfRegisteredStudents(); studentIndex++)
	{
		for (int i = 0; i < sys.getNumberOfCoursesOffered() / 2; i++)
		{
			int courseIndex = rand() % sys.getNumberOfCoursesOffered();
			sys.enrolStudent(studentIndex, courseIndex);
		}
	}

	//Print all the students
	cout << "All the students in the school are..." << endl;
	sys.printAllStudents();
	cout << endl << endl;

	//See if Yonas Weldeselassie is a student in the school
	int studentIndex = sys.searchStudent("Yonas", "Weldeselassie");
	if (studentIndex == -1)
		cout << "Yonas Weldeselassie is not a student in the school." << endl;
	else
	{
		cout << "Yonas Weldeselassie is a student in the school. Details below..." << endl;
		cout << sys.getStudent(studentIndex) << endl;
	}
	cout << endl << endl;

	//See if a registered student is a student in the school
	Student s = sys.getStudent(rand() % sys.getNumberOfRegisteredStudents());
	studentIndex = sys.searchStudent(s.getFirstName(), s.getLastName());
	if (studentIndex == -1)
		cout << s.getFirstName() << " " << s.getLastName() << " is not a student in the school." << endl;
	else
	{
		cout << s.getFirstName() << " " << s.getLastName() << " is a student in the school. Details below..." << endl;
		cout << sys.getStudent(studentIndex) << endl;
	}
	cout << endl << endl;

	//Remove some courses offered from the system
	int n = sys.getNumberOfCoursesOffered() / 4;
	for (int i = 0; i < n; i++)
	{
		int courseIndex = rand() % sys.getNumberOfCoursesOffered();
		sys.removeCourse(courseIndex);
	}

	//Assign letter grades to the students
	for (int studentIndex = 0; studentIndex < sys.getNumberOfRegisteredStudents(); studentIndex++)
	{
		vector<StudentCourse> v = sys.getStudent(studentIndex).getCourses();
		int n = 3 * v.size() / 4; //Assign letter grades to three fourths of the courses the student is taking
		for (int j = 0; j < n; j++)
		{
			int courseIndex = sys.searchCourse(v[j].getCourseName());
			sys.assignLetterGrade(studentIndex, courseIndex, sys.generateRandomLetterGrade());
		}
	}

	//Print all the students after they have been assigned their letter grades
	cout << "All the students in the school are..." << endl;
	sys.printAllStudents();
	cout << endl << endl;

	//Get the top student in the school
	Student top = sys.getTopStudent();
	cout << "The top student in the school is " << endl << top << endl;

	system("Pause");
	return 0;
}