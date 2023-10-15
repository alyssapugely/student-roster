#include "roster.h"
#include <string>
using namespace std;

// Parses set of comma delimited strings into individual string objects
void Roster::parse(string studentInformation) {
	// Sets initial value of degreeProgram to default
	DegreeProgram degreeProgram = DEFAULT;

	// Uses the last string character in studentInformation to determine degreeProgram value
	if (studentInformation.back() == 'Y') degreeProgram = SECURITY;
	else if (studentInformation.back() == 'K') degreeProgram = NETWORK;
	else if (studentInformation.back() == 'E') degreeProgram = SOFTWARE;

	// Locates the index of the first comma in studentInformation
	int right = studentInformation.find(",");
	// Extracts the first substring in front of the comma in studentInformation
	string studentID = studentInformation.substr(0, right);

	// Locates starting point of next substring
	int left = right + 1;
	right = studentInformation.find(",", left);
	// Extracts the second substring in studentInformation
	string firstName = studentInformation.substr(left, right - left);

	left = right + 1;
	right = studentInformation.find(",", left);
	// Extracts the third substring in studentInformation
	string lastName = studentInformation.substr(left, right - left);

	left = right + 1;
	right = studentInformation.find(",", left);
	// Extracts the fourth substring in studentInformation
	string emailAddress = studentInformation.substr(left, right - left);

	left = right + 1;
	right = studentInformation.find(",", left);
	// Extracts the fifth substring in studentInformation and converts it to integer
	int age = stoi(studentInformation.substr(left, right - left));

	left = right + 1;
	right = studentInformation.find(",", left);
	// Extracts the sixth substring in studentInformation and converts it to integer
	int daysInCourse1 = stoi(studentInformation.substr(left, right - left));

	left = right + 1;
	right = studentInformation.find(",", left);
	// Extracts the seventh substring in studentInformation and converts it to integer
	int daysInCourse2 = stoi(studentInformation.substr(left, right - left));

	left = right + 1;
	right = studentInformation.find(",", left);
	// Extracts the eigth substring in studentInformation and converts it to integer
	int daysInCourse3 = stoi(studentInformation.substr(left, right - left));

	// Creates Student object from variables passed as parameter
	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// Creates Student object from variables passed as parameter and adds student to roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	// Put days in array to use in Student object constructor
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	// Adds new Student object to roster array
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
}

// Removes student from the roster by student ID
void Roster::remove(string studentID)
{
	bool studentIDMatch = false;
	// Iterates through roster array
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		// If ID input as parameter matches ID of student at current index
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			// Set boolean to true
			studentIDMatch = true;
			// If the index of the current student does not equal its own index, it is swapped with the last student 
			if (i < numberOfStudents - 1)
			{
				// Declares pointer to Student object and assigns it the value of the student at the current index
				Student* tempStudent = classRosterArray[i];
				// Student at current index is set to last index in array
				classRosterArray[i] = classRosterArray[numberOfStudents - 1];
				// Student at last index in array is assigned to pointer (students are swapped)
				classRosterArray[numberOfStudents - 1] = tempStudent;
			}
			// Last student in roster array is no longer visible
			Roster::lastIndex--;
		}
	}
	// Prints message if student was successfully removed from roster
	if (studentIDMatch)
	{
		cout << "Student " << studentID << " successfully removed from roster." << std::endl;
	}
	// Prints message if student was not removed 
	else cout << "Student " << studentID << " is not in roster, so could not be removed." << std::endl;
}


// Prints a tab-separated list of all student data
void Roster::printAll()
{
	// Iterates through roster array and prints data for each student in array
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

// Prints a student’s average number of days in the three courses
void Roster::printAverageDaysInCourse(string studentID)
{
	// Iterates through roster array
	for (int i = 0; i <= Roster::lastIndex; i++) {
		// If ID input as parameter matches ID of student at current index
		if (Roster::classRosterArray[i]->getStudentID() == studentID) {
			// Save the array of days in courses for that student 
			int* daysArray = classRosterArray[i]->getDays();
			// Calculate the sum of the three days values
			int totalDays = daysArray[0] + daysArray[1] + daysArray[2];
			// Calculate the average of the days
			double averageDays = static_cast<double>(totalDays) / 3.0;
			// Prints the student’s average number of days in the three courses
			cout << "Average number of days for student " << classRosterArray[i]->getStudentID() << ": " << averageDays << std::endl;
		}
	}
}

// Verifies student email addresses and prints all invalid email addresses
void Roster::printInvalidEmails()
{
	bool invalidEmail = false;
	// Iterates through roster array
	for (int i = 0; i <= Roster::lastIndex; i++) {
		// Gets the email address of the student at the current index
		string emailAddress = (classRosterArray[i]->getEmailAddress());
		// If the email address has an invalid format, prints the email address
		if ((emailAddress.find("@") == string::npos) || (emailAddress.find(".") == string::npos) || (emailAddress.find(" ") != string::npos))
		{
			invalidEmail = true;
			cout << "Student " << classRosterArray[i]->getStudentID() << " has invalid email: " << emailAddress << std::endl;
		}
	}
	// Prints message if all email addresses have a valid format
	if (!invalidEmail) cout << "All email addresses are valid" << std::endl;
}


// Prints all students within the degree program passed as a parameter
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	// Iterates through roster array
	for (int i = 0; i <= Roster::lastIndex; i++) {
		// If students's degree program matches the program input as a parameter, the student is printed
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			Roster::classRosterArray[i]->print();
		}
	}
}

// Destructor for Roster class
Roster::~Roster()
{
	cout << "Destructor called!" << std::endl;
	// Iterates through roster and deletes each student at current index until all student are deleted
	for (int i = 0; i < numberOfStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	cout << "Dynamically allocated memory has been successfully released!" << std::endl;
}