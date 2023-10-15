# student-roster

This program maintains a roster of students in various degree programs, along with data associated with each student. 
The program manipulates and organizes student data based on project requirements and displays the output to the console.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation and Usage](#installation-and-usage)
- [Development](#development)

## Introduction

This program is modeled after the prompt that I was hired as a contractor to help a university migrate an existing student system to a new platform using C++ language.  
The part of the system that I was required to develop is responsible for reading and manipulating a list of data that was provided as part of the project requirements. 
This program maintains a current roster of students within a given course.  It reads the list of students, uses function calls to manipulate data, and directs data-related 
output to the console.

## Features

- This program holds student data, including student ID, first name, last name, email address, age, an array of the number of days to complete each course, and degree program.
- This program contains functions to add and remove students to and from the roster, print a tab-seperated list of all students within the roster, calculate and print the average
  number of days each student spent in their courses, print invalid student emails, and print students by degree program.

## Prerequisites

- Install your preferred IDE with C++ support, I used [Visual Studio with C++](https://visualstudio.microsoft.com/vs/features/cplusplus/) 

## Installation and Usage

1. Ensure that you have an IDE downloaded that supports C++ (see prerequisites).
2. Clone [this repository](https://github.com/alyssapugely/student-roster)
3. Open the project in IDE with C++ support.
4. To run the program using Visual Studio on a Windows system, press ctrl + F5.

## Development

This program was developed without using third-party libraries. It contains a degree.h file to hold degree program enums, student.h and student.cpp files to create and manipulate student objects, 
roster.h and roster.cpp files to create and manipulate roster objects, and a main.cpp file to demonstrate the program's functionality.


