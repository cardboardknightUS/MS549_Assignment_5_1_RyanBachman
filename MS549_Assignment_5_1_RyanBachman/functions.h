/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 5.1 - Project - Binary Search Tree
	functions.h
*/

#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>

// Allows you to use iostream statements without the use of std::.
using namespace std;

int mainMenu();

chrono::high_resolution_clock::time_point getStartTime();

chrono::high_resolution_clock::time_point getEndTime();

chrono::duration<double> elapsedTime(chrono::high_resolution_clock::time_point startHigh, chrono::high_resolution_clock::time_point endHigh);

void getResults(chrono::duration<double> bstInsertTime100, chrono::duration<double> bstInsertTime1000, chrono::duration<double> bstInsertTime10000, chrono::duration<double> bstInsertTime100000);