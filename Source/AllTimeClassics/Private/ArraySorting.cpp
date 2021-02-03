// Created by Nekofeery Jan 2021


#include "ArraySorting.h"

template<typename T>
void ArraySorting<T>::InsertionSort(TArray<T> Array)
{
	// The value we are currently comparing to
	int Key;
	// The number of elements
	int Size = Array.Num();
	for (int i = 1; i < Size; i++)
	{
		Key = Array[i];
		for (int j = i; j > 0; j--)
		{
			// We found the right spot for the current element
			if (Array[j - 1] < Key)
			{
				Array[j] = Key;
				break;
			}
			// We are still shifting elements to the right
			else
			{
				Array[j] = Array[j - 1];
			}
		}
	}
}

template<typename T>
void ArraySorting<T>::SelectionSort(TArray<T> Array)
{
	// The index of the smallest value found in the unsorted part of the array
	int MinimumIndex = 0;
	// The number of elements
	int Size = Array.Num();
	// Temporary variable for swapping values
	int Temp = 0;
	for (int i = 0; i < Size - 1; i++)
	{
		MinimumIndex = i;
		// Go through the unsorted part
		for (int j = i + 1; j < Size; j++)
		{
			// A smaller value was found
			if (Array[j] < Array[MinimumIndex])
			{
				MinimumIndex = j;
			}
		}
		// Swap the smallest value with the first
		Temp = Array[MinimumIndex];
		Array[MinimumIndex] = Array[i];
		Array[i] = Temp;
	}
}