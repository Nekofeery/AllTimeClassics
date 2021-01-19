// Created by Nekofeery Jan 2021


#include "BinarySearchTree.h"

template<typename T>
bool BinarySearchTree<T>::Insert(Node<T>* CurrentNode, Node<T>* NewNode)
{
	// Add greater values to the right side of the parent
	if (NewNode->Value > CurrentNode->Value)
	{
		// Add if parent is a leaf
		if (CurrentNode->RightChild == nullptr)
		{
			CurrentNode->RightChild = NewNode;
			NewNode->Parent = CurrentNode;
			return true;
		}
		// Go down in the hierarchy otherwise
		else
		{
			Insert(CurrentNode->RightChild, NewNode);
		}
	}
	// Add smaller values to the left side of the parent
	else
	{
		if (CurrentNode->LeftChild == nullptr)
		{
			CurrentNode->LeftChild = NewNode;
			NewNode->Parent = CurrentNode;
			return true;
		}
		else
		{
			Insert(CurrentNode->LeftChild, NewNode);
		}
	}
	return false;
}

template<typename T>
bool BinarySearchTree<T>::Remove(Node<T>* CurrentNode, T Value)
{
	// Value does not exist in the tree
	if (CurrentNode == nullptr)
	{
		return false;
	}
	// Value found
	else if (CurrentNode->Value == Value)
	{ 
		// Node is a leaf
		if (CurrentNode->LeftChild == nullptr && CurrentNode->RightChild == nullptr)
		{
			delete CurrentNode;
			return true;
		}
		//Node has only one child
		else if (CurrentNode->LeftChild != nullptr XOR CurrentNode->RightChild != nullptr)
		{
			// Append the child to this node's parent
			if (CurrentNode->LeftChild != nullptr)
			{
				CurrentNode->LeftChild->Parent = CurrentNode->Parent;
			}
			else
			{
				CurrentNode->RightChild->Parent = CurrentNode->Parent;
			}
			delete CurrentNode;
			return true;
		}
		// Node has two children
		else
		{
			// Find node with the smallest value and copy its value to this node
			Node<T>* InorderSuccessor = FindMinimum(CurrentNode->RightChild);
			CurrentNode->Value = InorderSuccessor->Value;
			// Delete the successor node
			delete InorderSuccessor;
			return true;
		}
	}
	// Search left subtree
	else if (Value < CurrentNode->Value)
	{
		Remove(CurrentNode->LeftChild, Value);
	}
	// Search right subtree
	else if (Value > CurrentNode->Value)
	{
		Remove(CurrentNode->RightChild, Value);
	}
}


template<typename T>
Node<T>* BinarySearchTree<T>::Search(Node<T>* CurrentNode, T Value)
{
	// Value does not exist in the tree
	if (CurrentNode == nullptr)
	{
		return nullptr;
	}
	// Value found
	else if (CurrentNode != nullptr && CurrentNode->Value == Value)
	{
		return CurrentNode;
	}
	// Search left subtree
	if (Value < CurrentNode->ValueCurrentNode)
	{
		Search(CurrentNode->LeftChild, Value);
	}
	// Search right subtree
	else if (Value > CurrentNode->ValueCurrentNode)
	{
		Search(CurrentNode->RightChild, Value);
	}
}

template<typename T>
Node<T>* BinarySearchTree<T>::FindMinimum(Node<T>* CurrentNode)
{
	// Tree is empty
	if (CurrentNode == nullptr)
	{
		return nullptr;
	}
	// Minimum found
	else if (CurrentNode->LeftChild == nullptr)
	{
		return CurrentNode;
	}
	// Search subtree
	else
	{
		FindMinimum(CurrentNode->LeftChild);
	}
}

template<typename T>
Node<T>* BinarySearchTree<T>::FindMaximum(Node<T>* CurrentNode)
{
	// Tree is empty
	if (CurrentNode == nullptr)
	{
		return nullptr;
	}
	// Maximum found
	else if (CurrentNode->RightChild == nullptr)
	{
		return CurrentNode;
	}
	// Search subtree
	else
	{
		FindMaximum(CurrentNode->RightChild);
	}
}

template<typename T>
void BinarySearchTree<T>::TraverseInorder(Node<T>* CurrentNode)
{
	if (CurrentNode != nullptr)
	{
		TraverseInorder(CurrentNode->LeftChild);
		// Be aware that printing may be more complex depending on your data type
		UE_LOG(LogTemp, Display, FText::AsNumber(CurrentNode->Value));
		TraverseInorder(CurrentNode->RightChild);
	}
}