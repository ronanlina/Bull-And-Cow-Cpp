#pragma once
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main() {

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro() {

	//game introduction

	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of ?\n";
	std::cout << std::endl;
	return;
}
//
void PlayGame()
{		
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	constexpr int32 NUMBER_OF_TURNS = 5;
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess(); 

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls << "\t";
		std::cout << "Cows = " << BullCowCount.Cows << "\t\n\n";
	}
	PrintGameSummary();
	return;
}

FText GetValidGuess() {

	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do{
		std::cout << "Try " << BCGame.GetCurrentTry()<< " of " << BCGame.GetMaxTries() << ". ";
		std::cout << "Enter your guess : ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lowercase word.\n\n";
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;

}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n) ? ";
	FText Response = "";
	getline(std::cin, Response);

	return (tolower(Response[0]) == 'y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "WELL DONE - YOU WIN!" << std::endl;
	}
	else 
	{
		std::cout << "Better luck next time!" << std::endl;
	}
}