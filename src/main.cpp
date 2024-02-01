#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

void PlayBullCowGame(int MAX_TURNS, int WORD_LENGTH);
std::string Introduction(int MAX_TURNS, int WORD_LENGTH);
void AsciiArt();
std::string DetermineWord();
std::string RanWord(int n);
int rand();
std::string GetGuess(int MAX_TURNS, int turn);
bool CheckIfGuessIsCorrect(std::string WORD, std::string Guess);
bool CheckIfGuessIsValid(std::string Guess, int WORD_LENGTH);
bool CheckIfGuessIsIsogram(std::string Guess);
int NumberOfBulls(std::string WORD, std::string Guess, int WORD_LENGTH);
int NumberOfCows(std::string WORD, std::string Guess, int WORD_LENGTH, int Bulls);
bool AskToPlayAgain();

//main is run by BullCowGame
int main()
{
	for (int bWantsToPlayAgain = true; bWantsToPlayAgain == 1;)
	{
		int constexpr MAX_TURNS = 8;
		int constexpr WORD_LENGTH = 5;
		PlayBullCowGame(MAX_TURNS, WORD_LENGTH);
		bWantsToPlayAgain = AskToPlayAgain();
	}
	return 0;
}




//runs the functions of the BullCowGame
void PlayBullCowGame(int MAX_TURNS, int WORD_LENGTH)
{
	std::string WORD = Introduction(MAX_TURNS, WORD_LENGTH);
	for (int turn = 1; turn <= MAX_TURNS; turn++)
	{
	label:
		std::string Guess = GetGuess(MAX_TURNS, turn);
		if (CheckIfGuessIsCorrect(WORD, Guess) == true)
		{
			std::cout << "Bullseye!!  The word was '" << WORD << "' - You win!\n";
			break;
		}
		if (CheckIfGuessIsValid(Guess, WORD_LENGTH) == false)
		{
			goto label;
		}
		if (turn == MAX_TURNS)
		{
			std::cout << "Nahh, that one's not right either.\n";
			std::cout << "The word was " << WORD << "!  Looks like you couldn't guess it within " << WORD_LENGTH << " tries.\n";
			break;
		}
		int Bulls = NumberOfBulls(WORD, Guess, WORD_LENGTH);
		int Cows = NumberOfCows(WORD, Guess, WORD_LENGTH, Bulls);

		if (turn <= 10)
		{
			//repeat the guess back to the player
			std::cout << "Not quite!  Your guess '" << Guess << "' had " << Bulls << " Bull(s) and " << Cows << " Cow(s).\n";
			std::cout << std::endl;
		}
	}
	return;
}

//introduce the game and determine the word being used.
std::string Introduction(int MAX_TURNS, int WORD_LENGTH)
{
	std::string WORD = DetermineWord();
	std::cout << std::endl;
	std::cout << std::endl;
	AsciiArt();
	std::cout << "\t Welcome to Bulls and Cows, a fun word game!\n";
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "First, there are some things you should know..\n";
	std::cout << "1.) An isogram is a word with no repeating letters.\n";
	std::cout << "2.) A \'Bull\' is when you guess a correct letter in the correct place.\n";
	std::cout << "3.) A \'Cow\' is when you guess a correct letter in the incorrect place.\n";
	std::cout << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of within " << MAX_TURNS << " turns?\n";
	std::cout << std::endl;
	return WORD;
}

//draws bull & cow ascii image
void AsciiArt()
{
	std::cout << "\t            .--.            .-~;                 \n";
	std::cout << "\t  .--------/\\/  \"-.      .-\"  \\/\\--------.  \n";
	std::cout << "\t /|    DAT     \\--\"      \"--/   DAT      |\\  \n";
	std::cout << "\t `|  \\  COW |  / .--------. \\  | BULL /  |'    \n";
	std::cout << "\t   \\ /uu.----\\ | |WELCOME!| | /-----,.\\ /     \n";
	std::cout << "\t   |/        |/  '--------'  \\|        \\|      \n";
	return;
}

//determine the word being used
std::string DetermineWord()
{
	//generate a random number from 1 - 10
	int n = rand() % 10;
	std::string WORD = "";
	WORD = RanWord(n);
	return WORD;
}

//uses RNG to determine the word choice
std::string RanWord(int n)
{
	std::string WORD = "";
	if (n == 0)
	{
		WORD = "worst";
	}
	else if (n == 1)
	{
		WORD = "curse";
	}
	else if (n == 2)
	{
		WORD = "first";
	}
	else if (n == 3)
	{
		WORD = "brick";
	}
	else if (n == 4)
	{
		WORD = "jocks";
	}
	else if (n == 5)
	{
		WORD = "bacon";
	}
	else if (n == 6)
	{
		WORD = "break";
	}
	else if (n == 7)
	{
		WORD = "fable";
	}
	else if (n == 8)
	{
		WORD = "ocean";
	}
	else if (n == 9)
	{
		WORD = "radio";
	}
	return WORD;
}

//random number generator
int rand()
{
	int RNG = (time(0));
	return RNG;
}

//get a guess from the player
std::string GetGuess(int MAX_TURNS, int turn)
{
	std::cout << " Turn (" << turn << '/' << MAX_TURNS << ") What is your Guess? - ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

//if the player's guess isn't a 5 letter isogram, return false
bool CheckIfGuessIsValid(std::string Guess, int WORD_LENGTH)
{
	if (Guess.size() != WORD_LENGTH)
	{
		std::cout << "That guess isn't a 5 letter word.\n";
		std::cout << std::endl;
		return false;
	}
	else if (CheckIfGuessIsIsogram(Guess) != true)
	{
		std::cout << "That guess isn't an isogram.\n";
		std::cout << std::endl;
		return false;
	}
	else return true;
}

//if the player's guess is correct, return true
bool CheckIfGuessIsCorrect(std::string WORD, std::string Guess)
{
	if (WORD == Guess)
	{
		return true;
	}
	else return false;
}

//if the player's guess is correct, return true
bool CheckIfGuessIsIsogram(std::string Guess)
{
	int length = Guess.length();

	//changes each letter of the guess to lowercase
	for (int cha = 0; cha <  length; cha++)
	{
		Guess[cha] = tolower(Guess[cha]);
		continue;
	}

	//change the string to a list of intergers in alphabetical order
	std::sort(Guess.begin(), Guess.end());

	//checks for letters that repeat
	for (int cha = 0; cha < length; cha++)
	{
		if (Guess[cha] == Guess[cha + 1])
		{
			return false;
		}
	}
	return true;
}

//determine the number of bulls of the player's guess
int NumberOfBulls(std::string WORD, std::string Guess, int WORD_LENGTH)
{
	int Bulls = 0;
	for (int cha = 0; cha < WORD_LENGTH; cha++)
	{
		if (Guess[cha] == WORD[cha])
		{
			Bulls++;
		}
	}
	return Bulls;
}

//determine the number of cows in the player's guess
int NumberOfCows(std::string WORD, std::string Guess, int WORD_LENGTH, int Bulls)
{
	int Cows = 0;
	for (int i = 0; i < WORD_LENGTH; i++)
	{
		for (int x = 0; x < WORD_LENGTH; x++)
		{
			if (WORD[i] == Guess[x])
			{
				Cows++;
			}
		}
	}
	return Cows - Bulls;
}

//ask the player if they'd like to play again
bool AskToPlayAgain()
{
	std::cout << std::endl;
	std::cout << " Would you like to play again?(y/n) - ";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	return (Response[0] == 'y') || (Response[0] == 'Y');
}