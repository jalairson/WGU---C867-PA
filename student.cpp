#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "student.h"

using namespace std;



Student::Student() {
	studentID = -1;
	firstName = "unknown";
	lastName = "unknown";
	emailAddr = "unknown";
	age = -1;
	daysToComplete[3];
	DegProgram = DegreeProgram::SOFTWARE;
}

	Student::Student(string ID, string FNAME, string LNAME, string EMAIL, int AGE, int days1, int days2, int days3, string DegProgramString) {
		SetStudentID(ID);
		SetFirstName(FNAME);
		SetLastName(LNAME);
		SetEmailAddr(EMAIL);
		SetAge(AGE);
		SetDaysToComplete(days1, days2, days3);
		SetDegreeProgram(DegProgramString);
	}

void Student::SetStudentID(string ID) {

	studentID = ID;

}

string Student::GetStudentID() {
	return studentID;
}

void Student::SetFirstName(string FNAME) {

	firstName = FNAME;

}

string Student::GetFirstName() {
	return firstName;
}

void Student::SetLastName(string LNAME) {

	lastName = LNAME;

}

string Student::GetLastName() {
	return lastName;
}

void Student::SetEmailAddr(string EMAIL) {

	emailAddr = EMAIL;

}

string Student::GetEmailAddr() {
	return emailAddr;
}

void Student::SetAge(int AGE) {

	age = AGE;

}

int Student::GetAge() {
	return age;
}

void Student::SetDaysToComplete(int days1, int days2, int days3) {
	daysToComplete[0] = days1;
	daysToComplete[1] = days2;
	daysToComplete[2] = days3;
	this->days1 = days1;
	this->days2 = days2;
	this->days3 = days3;
}

int Student::GetDays1() {
	return days1;
}
int Student::GetDays2() {
	return days2;
}
int Student::GetDays3() {
	return days3;
}
void Student::SetDegreeProgram(string DegProgramString) {
	if (DegProgramString == "SECURITY") {
		DegProgram = DegreeProgram::SECURITY;
	}
	if (DegProgramString == "NETWORK") {
		DegProgram = DegreeProgram::NETWORK;
	}
	if (DegProgramString == "SOFTWARE") {
		DegProgram = DegreeProgram::SOFTWARE;
	}

}

string Student::GetDegreeProgram() {
	if (DegProgram == DegreeProgram::SECURITY) {
		return "Security";
	}
	if (DegProgram == DegreeProgram::NETWORK) {
		return "Network";
	}
	if (DegProgram == DegreeProgram::SOFTWARE) {
		return "Software";
	}
	else {
		return "I don't know what happened here...";
	}

}

void Student::Print() {

	cout << GetStudentID() << '\t' << "First Name: ";
	cout << GetFirstName() << '\t' << "Last Name: ";
	cout << GetLastName() << '\t' << "Age: ";
	cout << GetAge() << '\t' << "daysInCourse: {";
	cout << GetDays1() << "," << GetDays2() << "," << GetDays3() << "}";
	cout << '\t' << "Degree Program: " << GetDegreeProgram() << ". ";

}

bool Student::checkEmail() {
	if (emailAddr.find("@") == string::npos) {
		return true;
	}
	if (emailAddr.find(".") == string::npos) {
		return true;
	}
	if (emailAddr.find(" ") != string::npos) {
		return true;
	}
	else {
		return false;
	}
}