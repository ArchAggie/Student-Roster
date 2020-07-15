#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"


Student::Student()
{

}

Student::Student(string sID, string fName, string lName, string eMail, int age, int* nDays)
{
	studentID = sID;
	firstName = fName;
	lastName  = lName;
	emailAddress = eMail;
	studentAge = age;
	numDays[0] = nDays[0];
	numDays[1] = nDays[1];
	numDays[2] = nDays[2];
}

void Student::SetStudentID(string sID)
{
	studentID = sID;
}
void Student::SetFirstName(string fName)
{
	firstName = fName;
}
void Student::SetLastName(string lName)
{
	lastName = lName;
}
void Student::SetEmailAddress(string eMail)
{
	emailAddress = eMail;
}
void Student::SetStudentAge(int age)
{
	studentAge = age;
}
void Student::SetNumDays(int nDays0, int nDays1, int nDays2)
{
	Student::numDays[0] = nDays0;
	Student::numDays[1] = nDays1;
	Student::numDays[2] = nDays2;
}

string Student::GetStudentID()
{
	return studentID;
}
string Student::GetFirstName()
{
	return firstName;
}
string Student::GetLastName()
{
	return lastName;
}
string Student::GetEmailAddress()
{
	return emailAddress;
}
int Student::GetStudentAge()
{
	return studentAge;
}
int *Student::GetNumDays()
{
	return numDays;
}

Degree Student::GetDegree()
{
	return Degree::SOFTWARE;
}

void Student::Print()
{

}

Student::~Student()
{

}