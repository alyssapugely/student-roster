#pragma once
#include "student.h"
#include <string>
using namespace std;


class Roster
{
	// Instance variables that define objects of the Roster class
public:
	// Creates variable to designate the nunber of student objects the below array will hold
	const static int numberOfStudents = 5;
	// Creates roster array to hold student objects
	Student* classRosterArray[numberOfStudents];
	// Sets last index to matching integer and not one greater than index
	int lastIndex = -1;

public:
	// Destructor for a Roster object 
	~Roster();
	// Parses set of comma delimited strings into individual string objects
	void parse(string row);
	// Creates Student object from variables passed as parameter and adds student to roster 
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	// Removes student from roster based on ID input as parameter
	void remove(string studentID);
	// Prints a tab-separated list of all student data 
	void printAll();
	// Prints students average number of days in the three courses, based on ID input as parameter
	void printAverageDaysInCourse(string studentID);
	// Verifies student email addresses and displays all invalid email addresses to the user
	void printInvalidEmails();
	// Prints out student information for a degree program specified by an enumerated type
	void printByDegreeProgram(DegreeProgram degreeProgram);
};

