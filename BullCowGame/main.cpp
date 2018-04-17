#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
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
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of ?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{		
	BCGame.Reset();
	int32 CurrentTry = BCGame.GetCurrentTry();

	constexpr int32 NUMBER_OF_TURNS = 5;
	for (int32 i = 0; i < NUMBER_OF_TURNS; i++)
	{
		FText Guess = GetGuess(); 

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		std::cout << "Try #" << CurrentTry + i << "\t";

		std::cout << "Bulls = " << BullCowCount.Bulls << "\t";
		std::cout << "Cows = " << BullCowCount.Cows << "\t\n";
	}
}
//
FText GetGuess() {
	std::cout << "Enter your guess : ";
	FText Guess = "";
	getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n) ? ";
	FText Response = "";
	getline(std::cin, Response);

	return (tolower(Response[0]) == 'y');
}
