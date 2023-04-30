#pragma once
#include <iostream>
#include <string>

#include "student.h"

using namespace std;

class Roster {

private:
	string DegreeProgramString;
	string stringDat;
	int i;
	int rosterPosition = 0;
	int dayOne, dayTwo, dayThree;
	double dayAvg;

	Student* classRosterArray[5];

public:
	~Roster();

	void add(string studentID, string firstName, string lastName, string emailAddr, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, string DegProgramString);
	void remove(string studentID);

	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();

	void parse(string studentData);

};

