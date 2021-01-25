// Created by Nekofeery Jan 2021

#pragma once

#include "CoreMinimal.h"

/**
 * Different algorithms for array sorting
 */
template<typename T>
class ALLTIMECLASSICS_API ArraySorting
{
public:
	/**
	* Insertion sort
	* @param Array - The array to sort
	* @note Worst case time complexity is O(n²); useful for already mostly ordered arrays
	*/
	void InsertionSort(TArray<T> Array);
};
