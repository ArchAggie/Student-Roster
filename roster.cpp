#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
//#include <>

using namespace std;

//call all necessary files
#include "roster.h"
#include "student.h"
#include "degree.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
//#include ""

Roster::Roster()
{

}

void Roster::AddData(string sID, string fName, string lName, string eMail, int age, int nDays0, int nDays1, int nDays2, Degree degree)
{
	int daysInClass[] = { nDays0, nDays1, nDays2 };

	if (degree == Degree::SOFTWARE)
	{
		classRosterArray[addInteger++] = new SoftwareStudent(sID, fName, lName, eMail, age, daysInClass, degree);
	}
	if (degree == Degree::NETWORKING)
	{
		classRosterArray[addInteger++] = new NetworkStudent(sID, fName, lName, eMail, age, daysInClass, degree);
	}
	if (degree == Degree::SECURITY)
	{
		classRosterArray[addInteger++] = new SecurityStudent(sID, fName, lName, eMail, age, daysInClass, degree);
	}
}

void Roster::PrintAll()
{
	cout << "Full Student Roster:" << endl;
	for(int i = 0; i < 5; i++)
	{
		(*classRosterArray[i]).Print();
	}
	cout << endl;
}

void Roster::PrintNumDays(string studentID)
{
	for (int i = 0; i < 5; i++)
	{
		if ((*classRosterArray[i]).GetStudentID() == studentID)
		{
			int a = 0;
			a = ((*classRosterArray[i]).GetNumDays()[0] + (*classRosterArray[i]).GetNumDays()[1] + (*classRosterArray[i]).GetNumDays()[2]) / 3;

			cout << "Over three courses, the student with the ID of " << studentID << " took an average of " << a << " to complete each course." << endl;
		}
	}
	cout << endl;
}

void Roster::PrintByDegree(Degree degree)
{
	Degree findDegree = Degree::SOFTWARE;
	if (degree == NETWORKING)//remove quotes
	{
		findDegree = Degree::NETWORKING;
		cout << "All students in the Networking Degree Program: " << endl;
	}
	if (degree == SECURITY)
	{
		findDegree = Degree::SECURITY;
		cout << "All students in the Security Degree Program: " << endl;
	}
	if (degree == SOFTWARE)
	{
		findDegree = Degree::SOFTWARE;
		cout << "All students in the Software Degree Program: " << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		if (findDegree == (*classRosterArray[i]).GetDegree())
		{
			(*classRosterArray[i]).Print();
		}
	}
	cout << endl;
}

void Roster::PrintInvalidEmails()
{
	cout << "Invalid emails entered in the student roster:" << endl;
	for (int i = 0; i < 5; i++)
	{
		string charAt = "@";
		string charSpace = " ";
		string charPeriod = ".";

		bool charAtFound = true;
		bool charSpaceFound = true;
		bool charPeriodFound = true;

		string eMail = (*classRosterArray[i]).GetEmailAddress();

		if (eMail.find(charAt) == string::npos)
		{
			charAtFound = false;
		}
		if (eMail.find(charSpace) == string::npos)
		{
			charSpaceFound = false;
		}
		if (eMail.find(charPeriod) == string::npos)
		{
			charPeriodFound = false;
		}

		if (charAtFound == false || charSpaceFound == true || charPeriodFound == false)
		{
			cout << (*classRosterArray[i]).GetEmailAddress() << endl;
		}
	}
	cout << endl;
}

/*
void Roster::PrintInvalidEmails()
{
	cout << "Invalid emails entered in the student roster:" << endl;
	for (int i = 0; i < 5; i++)
	{
		bool charAt = false;
		bool charSpace = false;
		bool charPeriod = false;
		string eMail = (*classRosterArray[i]).GetEmailAddress();

		for (char &c : eMail)
		{
			if (c == '@')
			{
				charAt = true;
			}
			if (c == ' ')
			{
				charSpace = true;
			}
			if (c == '.')
			{
				charPeriod = true;
			}
		}
		if (charAt != false || charSpace != false || charPeriod != false)
		{
			cout << (*classRosterArray[i]).GetEmailAddress() << endl;
		}
	}
	cout << endl;
}
*/

void Roster::RemoveData(string studentID)
{
	bool dataRemoved = false;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			if (studentID == classRosterArray[i]->GetStudentID())
			{
				classRosterArray[i] = nullptr;
				dataRemoved = true;
			}
		}
	}
	if (dataRemoved == true)
	{
		cout << "Information for the student ID of " << studentID << " was not found in the student roster." << endl;
	}
	cout << endl;
}

int main()
{
	const string studentDataArray[] =
	{
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Brian,Parsons,bpars12@wgu.edu,28,30,42,20,SOFTWARE"
	};

	//Performance Assessment Requirement F
	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Language Used: C++" << endl;
	cout << "Student ID: 001008912" << endl;
	cout << "Student Name: Brian Parsons" << endl << endl;
	
	Roster studentRoster;

	Degree studentDegree{};

	for (int i = 0; i < 5; i++)
	{
		stringstream students(studentDataArray[i]);

		vector <string> result;

		while (students.good())
		{
			string subString;
			getline(students, subString, ',');
			result.push_back(subString);
		}
		if (result[8] == "NETWORK")
		{
			studentDegree = Degree::NETWORKING;
		}
		if (result[8] == "SECURITY")
		{
			studentDegree = Degree::SECURITY;
		}
		if (result[8] == "SOFTWARE")
		{
			studentDegree = Degree::SOFTWARE;
		}
		studentRoster.AddData(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]), stoi(result[6]), stoi(result[7]), studentDegree);
	}
	studentRoster.PrintAll();

	studentRoster.PrintInvalidEmails();

	for (int i = 0; i < 5; i++)
	{
		string studentIDArray[5];

		studentIDArray[0] = "A1";
		studentIDArray[1] = "A2";
		studentIDArray[2] = "A3";
		studentIDArray[3] = "A4";
		studentIDArray[4] = "A5";

		studentRoster.PrintNumDays(studentIDArray[i]);
	}

	studentRoster.PrintByDegree(SOFTWARE);

	studentRoster.RemoveData("A3");

	studentRoster.RemoveData("A3");
}

Roster::~Roster()
{

}