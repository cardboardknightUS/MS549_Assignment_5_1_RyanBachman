/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 5.1 - Project - Binary Search Tree
	bst.cpp
*/

#include "bst.h"

// Allows you to use iostream statements without the use of std::.
using namespace std;

// Public version of contains that can leverage private values and functions.
bool BinarySearchTree::contains(int value)
{
	return contains(root, value);
}

// Contains does a check to see if a value is in the BST so users cannot add multiple of the same value.
bool BinarySearchTree::contains(Node* node, int value)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (value < node->data)
	{
		return contains(node->left, value);
	}
	else if (value > node->data)
	{
		return contains(node->right, value);
	}
	else
	{
		return true;
	}
}

// Basic function to return whether the BST is empty or not.
bool BinarySearchTree::isEmpty()
{
	if (root == nullptr) // If true, then the BST is empty...
	{
		return true;
	}
	else // Otherwise it's not empty and remove functionality is unlocked.
	{
		return false;
	}
}

// Public version of addNode that can leverage private values and functions.
void BinarySearchTree::addNode(int val)
{
	addNode(root, val);
}

// addNode will add a node to the Binary Search Tree and set the root if no value is added yet.
void BinarySearchTree::addNode(Node*& node, int val)
{
	if (node == nullptr) // If the root is null, add a new node with the value.
	{
		node = new Node(val);
	}
	else if (val < node->data) // If the value is less than the node it's checking, add node to the left...
	{
		addNode(node->left, val);
	}
	else // Otherwise, add the node to the right.
	{
		addNode(node->right, val);
	}
}

// Public version of removeNode that can leverage private values and functions.
void BinarySearchTree::removeNode(int val)
{
	root = removeNode(root, val);
}

// removeNode will remove a node from the Binary Search Tree and re-order the tree.
Node* BinarySearchTree::removeNode(Node* node, int val)
{
	if (node == nullptr) // If the tree is empty, return a null pointer.
	{
		return nullptr;
	}

	if (val < node->data) // If the value to be removed is less than the data in the current node...
	{
		node->left = removeNode(node->left, val); // Move to the left to find the value.
	}
	else if (val > node->data) // Otherwise if the value to be removed is more than the data in the current node...
	{
		node->right = removeNode(node->right, val); // Move to the right to find the value.
	}
	else if (val = node->data) // If the value to be removed is equal to the current node...
	{
		if (node->left == nullptr) // Remove the left node if it's left.
		{
			Node* temp = node->right;
			delete node;
			cout << val << " has been removed from the BST!" << endl;
			return temp;
		}
		else if (node->right == nullptr) // Otherwise remove the right node if it's right.
		{
			Node* temp = node->left;
			delete node;
			cout << val << " has been removed from the BST!" << endl;
			return temp;
		}

		Node* minRight = findMin(node->right);
		node->data = minRight->data;
		node->right = removeNode(node->right, minRight->data);
	}
	else
	{
		cout << val << " is not in the BST!" << endl;
	}

	return node;
}

// Finds the maximum value by consistently moving right in the tree until it gets to the maximum value.
int BinarySearchTree::findMax()
{
	Node* current = root;

	while (current->right != nullptr)
	{
		current = current->right;
	}

	cout << "The max value in the BST is " << current->data << "!" << endl;
	return current->data;
}

// Public version of inOrderTraverse that can leverage private values and functions.
void BinarySearchTree::inOrderTraverse()
{
	inOrderTraverse(root);
}

// This will traverse the tree, setting the values in order so it can output to the user in a readable, ordered format.
void BinarySearchTree::inOrderTraverse(Node* node)
{
	if (node != nullptr)
	{
		inOrderTraverse(node->left);
		cout << node->data << " ";
		inOrderTraverse(node->right);
	}
}

// Public version of findNode that can leverage private values and functions.
bool BinarySearchTree::findNode(int val)
{
	return findNode(root, val);
}

// This will search the BST to find a node that matches the value and outputs to the user if it exists.
bool BinarySearchTree::findNode(Node* node, int val)
{
	if (node == nullptr) // General logic to let the user know that the value they're looking for isn't in the BST.
	{
		cout << "That node was not found in the BST." << endl;
		return false;
	}

	if (node->data == val) // If it's found on the exact node, it will output that the value was found...
	{
		cout << "The value of " << val << " was found in the BST!";
		return true;
	}
	else if (val < node->data) // Otherwise if the value is less than the current node, traverse the tree to the left until it's found (or not found)...
	{
		return findNode(node->left, val);
	}
	else // Otherotherwise if the value is greater than the current node, traverse the tree to the right until it's found (or not found)...
	{
		return findNode(node->right, val);
	}
}

// Finds the minimum value in the BST in order to properly use the removeNode function.
Node* BinarySearchTree::findMin(Node* node)
{
	while (node->left != nullptr)
	{
		node = node->left;
	}

	return node;
}