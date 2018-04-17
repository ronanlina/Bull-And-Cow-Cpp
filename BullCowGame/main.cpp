#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

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

	//game int32roduction

	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of ?\n";
	std::cout << std::endl;
	return;
}
//
void PlayGame()
{		
	BCGame.Reset();
	int32 CurrentTry = BCGame.GetCurrentTry();

	constexpr int32 NUMBER_OF_TURNS = 5;
	for (int32 i = 0; i < NUMBER_OF_TURNS; i++)
	{
		FText Guess = GetValidGuess(); 

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Try #" << CurrentTry + i << "\t";

		std::cout << "Bulls = " << BullCowCount.Bulls << "\t";
		std::cout << "Cows = " << BullCowCount.Cows << "\t\n";
	}
}

FText GetValidGuess() {

	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do{
		std::cout << "Enter your guess : ";
		FText Guess = "";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lowercase word.\n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);

}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n) ? ";
	FText Response = "";
	getline(std::cin, Response);

	return (tolower(Response[0]) == 'y');
}
