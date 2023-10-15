#pragma once
#include <string>
using namespace std;

// Defines an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE, as well as a default value
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE, DEFAULT };

// String references for degree program index values
static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
