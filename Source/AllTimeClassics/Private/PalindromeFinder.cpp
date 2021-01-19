// Created by Nekofeery Jan 2021


#include "PalindromeFinder.h"

bool PalindromeFinder::IsPalindrome(FString Word)
{
	// Step through the word from both directions 
	bool bIsPalindrome = IsPalindrome(Word, 0, Word.Len());
	if (bIsPalindrome)
	{
		UE_LOG(LogTemp, Display, TEXT("%s is a palindrome."), *Word);
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("%s is no palindrome."), *Word);
		return false;
	}
}

bool PalindromeFinder::IsPalindrome(FString Word, int FirstIndex, int LastIndex)
{
	// We checked every char and did not return yet, so this must be a palindrome
	if (FirstIndex >= LastIndex)
	{
		return true;
	}
	// Both chars are equal, continue
	else if (Word[FirstIndex] == Word[LastIndex])
	{
		return IsPalindrome(Word, FirstIndex++, LastIndex--);
	}
	// Chars are not equal, this is no palindrome
	else
	{
		return false;
	}
}