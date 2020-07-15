#pragma once
#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
using namespace std;

#include "degree.h"

class Student
{


public:

	Student();

	Student(string, string, string, string, int, int*);

	//Accessors
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetStudentAge();
	int *GetNumDays();

	//Mutators
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmailAddress(string emailAddress);
	void SetStudentAge(int studentAge);
	void SetNumDays(int numDays0, int numDays1, int numDays2);

	virtual void Print();

	virtual Degree GetDegree();


	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int numDays[3];
};

#endif