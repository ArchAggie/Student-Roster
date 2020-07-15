#pragma once
#ifndef SECURITYSTUDENT_H_
#define SECURITYSTUDENT_H_

#include <string>
#include <iostream>
using namespace std;

#include "student.h"

class SecurityStudent : public Student
{
public:
	SecurityStudent();

	SecurityStudent(string, string, string, string, int, int*, Degree);

	Degree GetDegree() override;

	void Print() override;

private:
	Degree degree;
};

#endif