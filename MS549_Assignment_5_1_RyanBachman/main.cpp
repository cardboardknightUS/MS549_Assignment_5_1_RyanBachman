/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 5.1 - Project - Binary Search Tree
	main.cpp
*/

#include "functions.h"
#include "bst.h"

// Allows you to use iostream statements without the use of std::.
using namespace std;

// This assignment will be using doubly linked lists to create a stack and queue, allow inserts, deletions of top of stack or front of queue, deletion of searched items and printing.
// There will also be a troubleshooting section for timing insertions and deletions for stacks and queues.
int main()
{
	bool programLoop = true; // Set a variable for looping the program.
	BinarySearchTree bst;

	// Begin FULL program loop...
	while (programLoop == true)
	{
		int menuChoice;

		mainMenu(); // Output main menu to the user.

		cout << "Please select a menu item (1 through 7): ";
		cin >> menuChoice; // Get input from the user for going through the main menu.
		cout << endl;

		if (menuChoice == 1) // Add a value to the BST...
		{
			int userInput;

			cout << "Please enter a value to add to the BST: ";
			cin >> userInput;
			cout << endl;

			if (!bst.contains(userInput)) // Check if the user us adding an existing value to the BST...
			{
				bst.addNode(userInput); // Add the users input value to the BST.
				cout << userInput << " has been added to the BST!" << endl;
			}
			else
			{
				cout << "This value already exists in the BST!" << endl;
			}
		}
		else if (menuChoice == 2) // Remove a value from the BST...
		{
			if (!bst.isEmpty()) // Check if the user is trying to remove a node from an empty queue.
			{
				int userInput;

				cout << "Please enter a value to remove to the BST: ";
				cin >> userInput;
				cout << endl;

				if (bst.contains(userInput)) // Check if the user input value exists in the BST...
				{
					bst.removeNode(userInput);
				}
				else // If not, output a message letting the user know.
				{
					cout << "This value is not tied to any node in the BST!" << endl;
				}
			}
			else // If empty, output a message to the user letting them know.
			{
				cout << "The BST is empty, there is no need to remove anything!" << endl;
			}
		}
		else if (menuChoice == 3) // Find the maximum value in the BST...
		{
			bst.findMax();
		}
		else if (menuChoice == 4) // Traverse the BST in order...
		{
			bst.inOrderTraverse();
		}
		else if (menuChoice == 5) // Search for a specific value in the BST...
		{
			int userInput;

			cout << "Please enter a value to remove to the BST: ";
			cin >> userInput;
			cout << endl;

			bst.findNode(userInput);
		}
		else if (menuChoice == 6)
		{
			// BEGIN TESTING PROTOCOLS FOR ADDING N ELEMENTS TO THE BST AND RETURN TIMING DETAILS.
			// BST INSERTS
			// BST TIMING FOR 100 ELEMENTS
			BinarySearchTree bst100;

			cout << "Inserting 100 elements into the BST..." << endl;

			// Get the start time to get algorithm time calculations.
			chrono::high_resolution_clock::time_point startTime = getStartTime();

			// Loop through the BST 100 times.
			for (int i = 0; i < 100; i++)
			{
				bst100.addNode(rand() % 100);
			}

			// Get the end time to get algorithm time calculations.
			chrono::high_resolution_clock::time_point endTime = getEndTime();

			cout << "100 elements inserted into the BST..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> bstInsertTime100 = elapsedTime(startTime, endTime);

			// STACK TIMING FOR 1,000 ELEMENTS
			BinarySearchTree bst1000;

			cout << "\nInserting 1,000 elements into the BST..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the BST 100 times.
			for (int i = 0; i < 1000; i++)
			{
				bst1000.addNode(rand() % 1000);
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "1,000 elements inserted into the BST..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> bstInsertTime1000 = elapsedTime(startTime, endTime);

			// BST TIMING FOR 10,000 ELEMENTS
			BinarySearchTree bst10000;

			cout << "\nInserting 10,000 elements into the BST..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the BST 10,000 times.
			for (int i = 0; i < 10000; i++)
			{
				bst10000.addNode(rand() % 10000);
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "10,000 elements inserted into the BST..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> bstInsertTime10000 = elapsedTime(startTime, endTime);

			// BST TIMING FOR 100,000 ELEMENTS
			BinarySearchTree bst100000;

			cout << "\nInserting 10,000 elements into the BST..." << endl;

			// Get the start time to get algorithm time calculations.
			startTime = getStartTime();

			// Loop through the BST 100,000 times.
			for (int i = 0; i < 100000; i++)
			{
				bst100000.addNode(rand() % 100000);
			}

			// Get the end time to get algorithm time calculations.
			endTime = getEndTime();

			cout << "100,000 elements inserted into the BST..." << endl;

			// Print out elapsed time to the user.
			chrono::duration<double> bstInsertTime100000 = elapsedTime(startTime, endTime);
			// END OF BST INSERTS

			getResults(bstInsertTime100, bstInsertTime1000, bstInsertTime10000, bstInsertTime100000);
		}
		else if (menuChoice == 7)
		{
			return 0;
		}
		else
		{
			cout << "Please enter a valid number from 1 to 7.\n" << endl;
		}
	} // ... End FULL program loop.

	cout << "\n" << endl;
	system("pause");
	return 0;
}