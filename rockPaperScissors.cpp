#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstddef>
using namespace std;
int rand();

int main()
{
	cout << "How many games of rock, paper, scissors would you like to play?" << endl;

	double numberOfPlays;
	string input;
	int Default = 2;
	int  valid = 0;
	while (valid == 0)
	{
		cin >> input;

		size_t found = input.find_first_not_of("123456789.-");
		if (found != string::npos)
		{
			cout << "Please use Arabic numberals." << endl;
			valid = 0;
		}
		else
		{
			numberOfPlays = stod(input);


			int numberOfPlaysIntTest = numberOfPlays;

			if (numberOfPlays <= 0)
			{
				cout << "You cannot play a negative number of games. Please enter a positive whole number." << endl;
				valid = 0;
			}
			else if (numberOfPlays != numberOfPlaysIntTest)
			{
				valid = 0;
				cout << "You cannot play a fraction of a game. No decimals. Please enter a positive whole number." << endl;
			}
			else
			{
				valid = 1;
			}
		}
	}

		srand(time(NULL));

		double playerScore = 0;
		double computerScore = 0;

		for (int x = 0; x < numberOfPlays; x++)
		{
			cout << "rock, paper, scissors" << endl;
			int a = 10 + rand() % 46;
			//cout << a << endl;
			int computerChoice;
			string playerInput;
			int playerChoice;

			if (a < 25)
			{
				computerChoice = 1;
			}
			else if (a <= 40)
			{
				computerChoice = 2;
			}
			else if (a > 40)
			{
				computerChoice = 3;
			}

			cin >> playerInput;
			int playerInputValid = 0;
			if (playerInput == "rock" || playerInput == "paper" || playerInput == "scissors" || playerInput == "three")
			{
				playerInputValid = 1;
			}
			else
			{
				cout << "Your selection was not valid. Please choose 'rock' 'paper' or 'scissors'" << endl;
				playerInputValid = 0;
			}

			if (playerInputValid == 1)
			{
				if (playerInput == "rock")
				{
					playerChoice = 1;
				}
				else if (playerInput == "paper")
				{
					playerChoice = 2;
				}
				else if (playerInput == "scissors")
				{
					playerChoice = 3;
				}
				else if (playerInput == "three")
				{
					cout << "Death by Tide pod." << endl;
					abort();
				}

				if (playerChoice == computerChoice)
				{
					playerScore = playerScore + 0.5;
					computerScore = computerScore + 0.5;

					cout << "Computer also chose " << playerInput << ". You tie. Player: " << playerScore << " Computer: " << computerScore << endl;
				}
				else if (playerChoice == 1)
				{
					if (computerChoice == 2)
					{
						computerScore = computerScore + 1;

						cout << "Computer chose paper. You lose. Player: " << playerScore << " Computer: " << computerScore << endl;

					}
					else if (computerChoice == 3)
					{
						playerScore = playerScore + 1;

						cout << "Computer chose scissors. You win. Player: " << playerScore << " Computer: " << computerScore << endl;
					}
				}
				else if (playerChoice == 2)
				{
					if (computerChoice == 1)
					{
						playerScore = playerScore + 1;
						cout << "Computer chose rock. You win. Player: " << playerScore << " Computer: " << computerScore << endl;
					}
					else if (computerChoice == 3)
					{
						computerScore = computerScore + 1;
						cout << "Computer chose scissors. You lose. Player: " << playerScore << " Computer: " << computerScore << endl;
					}


				}
				else if (playerChoice == 3)
				{
					if (computerChoice == 2)
					{
						playerScore = playerScore + 1;
						cout << "Computer chose paper. You win. Player: " << playerScore << " Computer: " << computerScore << endl;
					}
					else if (computerChoice == 1)
					{
						computerScore = computerScore + 1;
						cout << "Computer chose rock. You lose. Player: " << playerScore << " Computer: " << computerScore << endl;
					}
				}
			}
			else
			{
				numberOfPlays = numberOfPlays + 1;
			}
		}

		if (computerScore == playerScore)
		{
			cout << "Final score: TIE" << endl;
		}
		else if (computerScore < playerScore)

		{
			cout << "Final score: VICTORY!\nCongratulations on your 100% luck-based win." << endl;
		}
		else if (computerScore > playerScore)
		{
			cout << "Final score: DEFEAT!\nBetter luck next time." << endl;
		}
	}
