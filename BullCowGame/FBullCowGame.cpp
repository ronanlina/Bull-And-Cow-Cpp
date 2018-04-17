#pragma once
#include<stdlib.h>
#include<map>
#include "FBullCowGame.h"

#define TMap std::map

FBullCowGame::FBullCowGame() 
{
	Reset();
}
void FBullCowGame::Reset()
{	
	const FString HIDDEN_WORD = "hey";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameWon = false;
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,5}, {4,7}, {5,9}, {6,11} };
	
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() const
{	
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{	
	return bGameWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{	
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{	
	MyCurrentTry++;

	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (Guess[i] == MyHiddenWord[i]) // or (Guess[j] == MyHiddenWord[i])
			{
				if(i == j)
				{
					BullCowCount.Bulls++;
				}
			}
			else if (Guess[i] == MyHiddenWord[j]) // <-- instead of this
			{
				BullCowCount.Cows++;
			}
		}
	}
	if (BullCowCount.Bulls == GetHiddenWordLength())
	{
		bGameWon = true;
	}
	else
	{
		bGameWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	if (Guess.length() < 2)
	{
		return true;
	}
	TMap<char, bool> LetterSeen; //setup map
	for (auto Letter : Guess)
	{
		Letter = tolower(Letter); // handle mixed case
		if (LetterSeen[Letter]) // if the letter is in the map
		{
			return false; // no isogram
		}
		else
		{
			LetterSeen[Letter] = true; // add letter to the map as seen
		}
	}
	return true;
}

bool FBullCowGame::IsLowerCase(FString Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter)) 
		{
			return false;
		}
	}
	return true;
}
