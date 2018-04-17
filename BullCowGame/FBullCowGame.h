#pragma once
#include<string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();

	int32 GetMaxTries() const;	
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString);

	FBullCowCount SubmitGuess(FString);

private:
	int32  MyCurrentTry = 1;
	int32 MyMaxTries = 5;
	FString MyHiddenWord;
	bool IsIsogram(FString);
};