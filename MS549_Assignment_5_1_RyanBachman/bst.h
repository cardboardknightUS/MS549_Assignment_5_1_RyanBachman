/*
	Ryan Bachman
	University of Advancing Technology
	MS549 - Data Structures and Testing
	Fall 2024, Grad 2

	Assignment 5.1 - Project - Binary Search Tree
	bst.h
*/

#pragma once
#include <iostream>

#ifndef BST_H
#define BST_H

// Allows you to use iostream statements without the use of std::.
using namespace std;

// Create a node class that will be leveraged to manipulate nodes in the binary search tree.
struct Node
{
	int data;
	Node* left;
	Node* right;

	Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Create a Binary Search Tree class using a Node struct.
class BinarySearchTree
{
public:
	BinarySearchTree() : root(nullptr) {}

	void addNode(int val);
	void removeNode(int val);
	int findMax();
	void inOrderTraverse();
	bool findNode(int val);
	bool contains(int value);
	bool isEmpty();

private:
	Node* root;

	void addNode(Node*& node, int val);
	Node* removeNode(Node* node, int val);
	Node* findMin(Node* node);
	void inOrderTraverse(Node* node);
	bool findNode(Node* node, int value);
	bool contains(Node* node, int value);
};
#endif