#pragma once
#ifndef SOFTWARESTUDENT_H_
#define SOFTWARESTUDENT_H_

#include <string>
#include <iostream>
using namespace std;

#include "Student.h"

class SoftwareStudent : public Student
{
public:
	SoftwareStudent();

	SoftwareStudent(string, string, string, string, int, int*, Degree);

	Degree GetDegree() override;

	void Print() override;

private:
	Degree degree;
};

#endif