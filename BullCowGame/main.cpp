#include <iostream>
#include <string>

void PrintIntro();
void PlayGame();
std::string GetGuessAndPrintBack();

int main() {

	PrintIntro();
	PlayGame();

	return 0;
}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;
	for (size_t i = 0; i < NUMBER_OF_TURNS; i++)
	{
		GetGuessAndPrintBack();
	}
}

void PrintIntro() {

	//game introduction
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thingking of ?\n";
	std::cout << std::endl;
	return;
}

std::string GetGuessAndPrintBack() {
	std::cout << "Enter your guess : ";
	std::string Guess = "";
	getline(std::cin, Guess);

	std::cout << "Your guess was : " << Guess << std::endl << std::endl;

	return Guess;
}