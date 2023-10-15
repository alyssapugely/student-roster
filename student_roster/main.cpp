#include "roster.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    //  Prints out the course title, programming language used, my WGU student ID, and my name
    cout << "Course: Scripting and Programming - Applications - C867\n" << "Programming Language Used: C++\n" << "Student ID: 010556075\n" << "Name: Alyssa Pugely" << std::endl << std::endl;

    // Creates an instance of the Roster class using default constructor
    Roster classRoster;

    // Variable to hold roster array size 
    const int numberOfStudents = 5;

    // Student data to parse
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Alyssa,Pugely,apugely@wgu.edu,28,55,38,44,SOFTWARE"
    };

    // Parses each row in studentData and adds each student to classRoster
    for (int i = 0; i < numberOfStudents; i++) classRoster.parse(studentData[i]);


    // Displays all students
    cout << "Displaying all students in roster:" << std::endl;
    classRoster.printAll();
    cout << std::endl;

    // Displays all invalid emails
    cout << "Displaying all invalid emails:" << std::endl;
    classRoster.printInvalidEmails();
    cout << std::endl;

    // Displays average days in three courses for each student in roster
    cout << "Displaying average number of days spent in three courses per student:" << std::endl;
    for (int i = 0; i < numberOfStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << std::endl;

    // Displays all students in Software degree program
    cout << "Displaying all students in Software degree program:" << std::endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << std::endl;

    // Removes student with ID A3 from roster
    cout << "Removing student A3 from roster:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    // Displays all students
    cout << "Displaying all students in roster:" << std::endl;
    classRoster.printAll();
    cout << std::endl;

    // Attempts to remove student with ID A3 from roster again
    cout << "Removing student A3 from roster:" << std::endl;
    classRoster.remove("A3");
    cout << std::endl;

    system("pause");
    return 0;
}