#include <string>
#include <iostream>
using namespace std;

#include "securityStudent.h"

SecurityStudent::SecurityStudent()
{
}

SecurityStudent::SecurityStudent(string sID, string fName, string lName, string eMail, int age, int* nDays, Degree d) : Student(sID, fName, lName, eMail, age, nDays)
{
	degree = d;
}

Degree SecurityStudent::GetDegree()
{
	return degree;
}

void SecurityStudent::Print()
{
	cout << "Student ID: " << GetStudentID() << "   ";
	cout << "Student Full Name: " << GetFirstName() << " " << GetLastName() << "   ";
	cout << "Student Age: " << GetStudentAge() << "   ";
	cout << "Number of Days to Complete Course: {" << GetNumDays()[0] << ", " << GetNumDays()[1] << ", " << GetNumDays()[2] << "}" << "   ";
	cout << "Degree Program: Security" << endl;
}