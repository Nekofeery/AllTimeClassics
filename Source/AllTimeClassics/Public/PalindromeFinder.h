// Created by Nekofeery Jan 2021

#pragma once

#include "CoreMinimal.h"

/**
 * Find palindromes in string words (i.e. words that can be read forwards and backwards) 
 */
class ALLTIMECLASSICS_API PalindromeFinder
{
public:
	// Check if a given string is a palindrome
	bool IsPalindrome(FString Word);
private:
	bool IsPalindrome(FString Word, int FirstIndex, int LastIndex);
};
