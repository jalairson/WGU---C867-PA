#pragma once
#include <string>
#include <iostream>

#include "degree.h"

using namespace std;

//D1
class Student {

private:
	
	string studentID;
	string firstName;
	string lastName;
	string emailAddr;
	int age;
	int days1, days2, days3;
	int daysToComplete[3]{ 1, 1, 1 };
	string daysVal;
	DegreeProgram DegProgram;
	string DegProgramString;

public:

	//D2

	void SetStudentID(string ID);
	string GetStudentID();

	void SetFirstName(string FNAME);
	string GetFirstName();

	void SetLastName(string LNAME);
	string GetLastName();

	void SetEmailAddr(string EMAIL);
	string GetEmailAddr();

	void SetAge(int age);
	int GetAge();

	void SetDaysToComplete(int days1, int days2, int days3);
	int GetDaysToComplete();

	int GetDays1();
	int GetDays2();
	int GetDays3();

	void SetDegreeProgram(string DEGPROG);
	string GetDegreeProgram();

	void Print();

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddr, int age, int days1, int days2, int days3, string DegProgramString);

	bool checkEmail();
};

