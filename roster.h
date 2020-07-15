#pragma once
#ifndef ROSTER_H_
#define ROSTER_H_

#include "student.h"
#include <array>

class Roster
{
public:
	Roster();

	virtual ~Roster();

	void PrintAll();
	void AddData(string sID, string fName, string lName, string eMail, int age, int nDays0, int nDays1, int nDays2, Degree degree);
	void RemoveData(string studentID);
	void PrintByDegree(Degree degree);
	void PrintNumDays(string);
	void PrintInvalidEmails();

	int addInteger = 0;

private:
	Student* classRosterArray[5];
};

#endif