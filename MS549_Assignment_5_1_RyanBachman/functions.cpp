/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 5.1 - Project - Binary Search Tree
	functions.cpp
*/

#include "functions.h"
#include "bst.h"

// Allows you to use iostream statements without the use of std::.
using namespace std;

// Outputs the main menu options to the user using only cout.
int mainMenu()
{
	cout << "\n\nRyan Bachman's Assignment 5.1 Project" << endl;
	cout << "1: Add a Node" << endl;
	cout << "2: Remove a Node" << endl;
	cout << "3: Find Maximum Node Value" << endl;
	cout << "4: Traverse the BST In Order" << endl;
	cout << "5: Find Specific Node" << endl;
	cout << "6: Testing" << endl;
	cout << "7: Exit Program" << endl;

	return 0;
}

// Get the time when the function is called for start time.
chrono::high_resolution_clock::time_point getStartTime()
{
	// Code for a HIGH RESOLUTION timing.
	auto startHigh = chrono::high_resolution_clock::now();

	return startHigh;
}

// Get the time when the function is called for end time.
chrono::high_resolution_clock::time_point getEndTime()
{
	// Code for a HIGH RESOLUTION timing.
	auto endHigh = chrono::high_resolution_clock::now();

	return endHigh;
}

// Calculate the time elapsed between getStartTime() and getEndTime() so this can be reused anywhere.
chrono::duration<double> elapsedTime(chrono::high_resolution_clock::time_point startHigh, chrono::high_resolution_clock::time_point endHigh)
{
	chrono::duration<double> elapsedHighRes = endHigh - startHigh;

	cout << fixed << setprecision(5) << "The operation took " << elapsedHighRes.count() << " seconds.\n" << endl;

	return elapsedHighRes;
}

void getResults(chrono::duration<double> bstInsertTime100, chrono::duration<double> bstInsertTime1000, chrono::duration<double> bstInsertTime10000, chrono::duration<double> bstInsertTime100000)
{
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           R   E   S   U   L   T   S                                          |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| Additions            | 100                 | 1,000             | 10,000             | 100,000                |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "| Insert Runtime       | " << bstInsertTime100.count() << "             | " << bstInsertTime1000.count() << "           | " << bstInsertTime10000.count() << "            | " << bstInsertTime100000.count() << "                |" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}