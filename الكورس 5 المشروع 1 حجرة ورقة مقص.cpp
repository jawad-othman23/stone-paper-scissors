// الكورس 5 المشروع 1 حجرة ورقة مقص.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum enGameChoice { Stone = 1 , Paper = 2 , Scissors = 3};
enum enWinner {Player = 1 , Computer = 2  , Draw = 3};

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;


};

struct stGameResult
{

	short GameRounds = 0;
	short PlayerWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string  WinnerName = "";


};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;

} 

string WinnerName(enWinner Winner)
{
	string arrWinnername[3] = { "Player" , "Computer" , "No Winner" };
	return arrWinnername[Winner - 1];

} 


enWinner WhoWonTheround(stRoundInfo RoundInfo)
{
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.PlayerChoice)
	{
	case enGameChoice::Stone:

		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;

		}
		break;
	}
		return enWinner::Player;

	
}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoice[3] = { "Stone" , "Paper" , "Scissors" };
	return arrGameChoice[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player:
		system("Color 2F");
		
		break;
	case enWinner::Computer:
		system("Color 4F");
		cout << "\a";
		break;
	case enWinner::Draw:
		system ("Color 6F");
		break;
	}
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n_______________ Round[" << RoundInfo.RoundNumber << "] _______________\n\n";
	cout << "Player Choice : "<< ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner : [" << RoundInfo.WinnerName << "]\n";
	cout << "_______________________________________________________________\n";
SetWinnerScreenColor(RoundInfo.Winner);

}

enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
	if (PlayerWinTimes > ComputerWinTimes)
		return enWinner::Player;
	else if (ComputerWinTimes > PlayerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;


}
stGameResult FillGameResults(int GameRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResult GameResult;

	GameResult.GameRounds = GameRounds;
	GameResult.PlayerWinTimes = PlayerWinTimes;
	GameResult.ComputerWinTimes = ComputerWinTimes;
	GameResult.DrawTimes = DrawTimes;
	GameResult.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
	GameResult.WinnerName = WinnerName(GameResult.GameWinner);
	return GameResult;
}


enGameChoice ReadPlayerChoice()
{
	short Choice = 1;
	do {
		cout << "\nYour Choice [1] : Stone , [2] : Paper , [3] : Scissors ? \n";
		cin >> Choice;

	} while (Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;

}
enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}




stGameResult PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;

	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins : \n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.PlayerChoice = ReadPlayerChoice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheround(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
		
		if (RoundInfo.Winner == enWinner::Player)

			PlayerWinTimes++;

		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;

		PrintRoundResults(RoundInfo);

	}
	return FillGameResults(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);


}

string Taps(short NumberOftRuonds)
{
	string t = "";

	for (int i = 1; i <= NumberOftRuonds; i++)
	{
		t = t + "\t";
	

	}
	return t;
}

void ShowgameOverScreen()
{
	cout << Taps(2) << "________________________________________________________________\n";
	cout << Taps(2) << "                     G A M E  O V E R ++++ \n";
	cout << Taps(2) << "________________________________________________________________\n\n";
}

void ShowFinalGameResults(stGameResult GameReult)
{
	cout << Taps(2) << "____________________[Game Results]____________________\n\n";
	cout << Taps(2) << "\tGame Result        : " << GameReult.GameRounds << endl;
	cout << Taps(2) << "\tPlayer Win Times   : " << GameReult.PlayerWinTimes << endl;
	cout << Taps(2) << "\tComputer Won Times : " << GameReult.ComputerWinTimes << endl;
	cout << Taps(2) << "\tDraw Times         : " << GameReult.DrawTimes << endl;
	cout << Taps(2) << "\tFinal Winner       : " << GameReult.WinnerName << endl;
	cout << Taps(2) << "______________________________________________________\n\n";


	SetWinnerScreenColor(GameReult.GameWinner);

}

short ReadHowManyeRounds()
{
	short GameRounds = 1;

	do
	{
		cout << "How Many Rounds 1 to 10 ?\n";
		cin >> GameRounds;
	} while (GameRounds > 10 || GameRounds < 1);

	return GameRounds;

}

void ResetScreen()
{
	system("cls");
	system("Color 0F");
}

void StartGame()
{
	char PalyAgain = 'Y';

	do 
	{
	    ResetScreen();
		stGameResult GameResult = PlayGame(ReadHowManyeRounds());
		ShowgameOverScreen();
		ShowFinalGameResults(GameResult);

		cout << "\tDo you want to paly agein ? Y/N :\n";
		cin >> PalyAgain;


	}while (PalyAgain == 'Y' || PalyAgain == 'y');


}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();
	return 0;

}