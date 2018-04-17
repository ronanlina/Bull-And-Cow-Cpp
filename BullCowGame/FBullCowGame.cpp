#include<stdlib.h>
#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() 
{
	Reset();
}
void FBullCowGame::Reset()
{	
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
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
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{	
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
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

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
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

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess)
{
	/*for (int i = 0; i < Guess.length(); i++)
	{
		for (int j = 0; j < Guess.length(); j++)
		{
			if (Guess[i] == Guess[j])
			{
				return false;
			}
		}
	}*/

	return true;
}
