#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	int i;
	Roster classRoster;

	cout << "Course: C867 - Scripting and Programming Applications" << endl
		<< "Language: C++" << endl << "Student ID#: 009965674" << endl << "Name: Jeremiah Lairson" << endl << endl;



	const string studentData[5] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jeremiah,Lairson,jlairs5@wgu.edu,29,30,20,10,SOFTWARE" };

	for (i = 0; i < 5; ++i) {
		classRoster.parse(studentData[i]);
	}

	classRoster.printAll();

	cout << endl;
	
	classRoster.printInvalidEmails();

	cout << endl;
	

	for (i = 0; i < 5; ++i) {
		classRoster.printAverageDaysInCourse(string studentID);
	}



	cout << endl;
	
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << endl;

	classRoster.remove("A3");

	cout << endl;

	classRoster.printAll();

	cout << endl;

	classRoster.remove("A3");
	
	return 0;
}