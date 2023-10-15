#pragma once
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

class Student
{
public:
	// Constant that defines the number of variables in the daysInCourseArraySize array
	const static int daysInCourseArraySize = 3;
private:
	// Instance variables that define objects of the Student class
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysInCourseArraySize];
	DegreeProgram degreeProgram;
public:
	// Parameterless constructor for a Student object
	Student();
	// Full constructor for a Student object
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
	// Destructor for a Student object 
	~Student();

	// Getters (aka accessors) for instance variables of the Student class
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	// Setters (aka mutators) for instance variables of the Student class
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	// Prints specific student's data
	void print();
};

