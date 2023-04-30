#include <iostream>
#include <string>

#include "roster.h"

using namespace std;



void Roster::add(string studentID, string firstName, string lastName, string emailAddr, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, string DegProgramString) {

	Student* tempStudent = new Student(studentID, firstName, lastName, emailAddr, age, daysToComplete1, daysToComplete2, daysToComplete3, DegProgramString);
	classRosterArray[rosterPosition] = tempStudent;
	rosterPosition++;

}

void Roster::remove(string studentID) {

	cout << "Removing student (" << studentID << ") from student roster:" << endl;

	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i] == NULL) {
			cout << endl;
			cout << "INVALID STUDENT ID: " << studentID << endl;
		}
		else {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = NULL;
			}
		}
	}

}

void Roster::printAll() {

	cout << "Displaying all student information:" << endl;

	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->Print();
			cout << endl;
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	cout << "Displaying student average days to complete courses:" << endl;

	for (i = 0; i < 5; ++i) {
		if (classRosterArray[i] != NULL) {
			if (classRosterArray[i]->GetStudentID() == studentID) {

				int IDNO = i;

				dayOne = classRosterArray[IDNO]->GetDays1();
				dayTwo = classRosterArray[IDNO]->GetDays2();
				dayThree = classRosterArray[IDNO]->GetDays3();

				dayAvg = (dayOne + dayTwo + dayThree) / 3;

				cout << "Student ID: " << classRosterArray[IDNO]->GetStudentID() << ", average days in course is: " << dayAvg << endl;
			}
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram DegProgram) {

	cout << "Displaying student information by specified degree Program (";

	if (DegProgram == DegreeProgram::SECURITY) {
		DegreeProgramString = "Security";
	}
	if (DegProgram == DegreeProgram::NETWORK) {
		DegreeProgramString = "Network";
	}
	if (DegProgram == DegreeProgram::SOFTWARE) {
		DegreeProgramString = "Software";
	}

	cout << DegreeProgramString << ")" << endl;

	for (i = 0; i < 5; ++i) {

		if (classRosterArray[i] == NULL) {}
		else if (classRosterArray[i]->GetDegreeProgram() == DegreeProgramString) {
			classRosterArray[i]->Print();
			cout << endl;
		}

	}

}

void Roster::printInvalidEmails() {
	cout << "Displaying invalid student emails: " << endl;
	for (i = 0; i < 5 ; i++) {
		if (classRosterArray[i]->checkEmail() == true) {
			cout << classRosterArray[i]->GetEmailAddr() << endl;
		}
	}
}


void Roster::parse(string stringDat) {

		size_t rhs = stringDat.find(",");
		string studentID = stringDat.substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = stringDat.find(",", lhs);
		string firstName = stringDat.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = stringDat.find(",", lhs);
		string lastName = stringDat.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = stringDat.find(",", lhs);
		string emailAddr = stringDat.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = stringDat.find(",", lhs);
		int age = stoi(stringDat.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = stringDat.find(",", lhs);
		int daysToComplete1 = stoi(stringDat.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = stringDat.find(",", lhs);
		int daysToComplete2 = stoi(stringDat.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = stringDat.find(",", lhs);
		int daysToComplete3 = stoi(stringDat.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = stringDat.find(",", lhs);
		string DegProgramString = stringDat.substr(lhs, rhs - lhs);

		add(studentID, firstName, lastName, emailAddr, age, daysToComplete1, daysToComplete2, daysToComplete3, DegProgramString);

}

Roster::~Roster() {

	cout << endl;
	cout << "Calling destructor for class Roster - - " << endl << endl;

	for (i = 0; i < 5; ++i) {

		if (classRosterArray[i] == NULL) {}

		else {
			cout << "Removing student information for student (ID - " << classRosterArray[i]->GetStudentID() << ")" << endl;
			delete classRosterArray[i];
			classRosterArray[i] = NULL;
			cout << "Student Information on line " << (i + 1) << " erased." << endl << endl;
		}
	}
}