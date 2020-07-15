#pragma once
#ifndef NETWORKSTUDENT_H_
#define NETWORKSTUDENT_H_

#include <string>
#include <iostream>
using namespace std;

#include "student.h"

class NetworkStudent : public Student 
{
public:
	NetworkStudent();

	NetworkStudent(string, string, string, string, int, int*, Degree);

	Degree GetDegree() override;

	void Print() override;

private:
	Degree degree;
};

#endif