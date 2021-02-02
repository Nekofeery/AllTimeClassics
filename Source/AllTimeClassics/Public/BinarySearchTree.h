// Created by Nekofeery Jan 2021

#pragma once

#include "CoreMinimal.h"

template<typename T>
struct Node
{
public:
	T Value;
	Node<T>* LeftChild;
	Node<T>* RightChild;
	Node<T>* Parent;
};

/**
 * A templated implementation of a binary search tree
 * @note Remember to implement comparison and equality operators if you want to use this with custom types
 */
template<typename T>
class ALLTIMECLASSICS_API BinarySearchTree
{
	Node<T>* Root;
public:
	BinarySearchTree(Node<T>* FirstNode) { Root = FirstNode; };
	~BinarySearchTree() { delete Root; };
public:
	/**
	* Insert a node
	* @param CurrentNode - The root of the subtree in which the node will be inserted 
	* @param NewNode - The node to insert
	*/
	bool Insert(Node<T>* CurrentNode, Node<T>* NewNode);
	/**
	* Remove the node with a given value
	* @param CurrentNode - The root of the subtree from which the value will be removed
	* @param Value - The value to remove
	*/
	bool Remove(Node<T>* CurrentNode, T Value);
public:
	/** 
	* Search for a given value
	* @param CurrentNode - The root of the subtree to search
	* @param Value - The value to search
	*/
	Node<T>* Search(Node<T>* CurrentNode, T Value);
	// Find the minimum value in the current subtree 
	Node<T>* FindMinimum(Node<T>* CurrentNode);
	// Find the maximum value in the current subtree
	Node<T>* FindMaximum(Node<T>* CurrentNode);
	// Traverse the current subtree by inorder and print the value of each visited node
	void TraverseInorder(Node<T>* CurrentNode);
};
