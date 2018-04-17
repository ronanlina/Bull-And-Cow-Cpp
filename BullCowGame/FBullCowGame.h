#pragma once
#include<string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase		//either add 'Not_Lowercase' here or use tolower() on input
};

class FBullCowGame {
public:
	FBullCowGame();

	int32 GetMaxTries() const;	
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	bool	bGameWon;
	int32  MyCurrentTry = 1;
	FString MyHiddenWord;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString) const;
};