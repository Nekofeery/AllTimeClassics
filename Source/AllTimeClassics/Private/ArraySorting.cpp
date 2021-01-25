// Created by Nekofeery Jan 2021


#include "ArraySorting.h"

template<typename T>
void ArraySorting<T>::InsertionSort(TArray<T> Array)
{
	// The value we are currently comparing to
	int Key;
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