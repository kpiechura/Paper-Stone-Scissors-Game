//Copyrights (c) 2013 by Kamil Piechura

/*Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.*/


/************************************************************
*************************************************************
**Paper Stone Scrissors Game 2013 v.1 for DOS
**Author: Kamil Piechura
**Date compile: 17.05.2013 r.
**License: Free
**IDE: Visual C++ 2013
**Copyrights: All copyrights are reserved by Kamil Piechura
************************************************************
************************************************************
*/


#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <Windows.h>
#include <vector>
#include "functions.h"

struct INFO
	  {
		  int _rounds;
		  std::string names[2];
		  unsigned int score_player[2];
	  };
struct SCORE_PLAYER
	  {
		  std::string name;
		  int number_rounds;
		  int score_player1;
		  int score_computer;
      };

int key1 = 0, key2 = 0;
int counter_rounds = 1;
int counter_rounds_for_computer = 1;
int number_players = 0;
int color123 = 0;
int cnt=0;



extern int colP1;
extern int colP2;

const unsigned int SLEEP_TIME = 1000;
const unsigned int TAB = 31;

std::string names[2];


char weapon_player;
int	 weapon_computer;
char level_difficult;
char key_keyboard;
char type_weapon, type_weapon1;
char choose_end;
char chend;

INFO game_options;
SCORE_PLAYER game_vs_computer;


void DrawString(void)
{

	game_options.score_player[0] = 0;
	game_options.score_player[1] = 0;
	system("COLOR 07");
	std::cout << "\t\t\t";
		for (int i = 0; i < TAB; ++i)
			{
			std::cout << "=";
			}
		std::cout << "\n\t\t\t";
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute( handle , 4 );
		std::cout << "=  Paper Stone Scrissors Game =" << std::endl;
		SetConsoleTextAttribute( handle , 7 );
		std::cout << "\t\t\t";
			for (int i = 0; i < TAB; ++i)
				{
					std::cout << "=";
				}
	std::cout << "\n\n" << std::endl;
}

void DrawMenuPlayerVsPlayer();
	void DrawMenuPlayerVsComputer();
			void DrawCountdown();
				void DrawTypesWeaponsPlayer1();
					void DrawTypesWeaponsPlayer2();
						void GameForPlayers();
							void DrawScreenForChangePlayer();
								void DrawStringForBattle();
									int CheckGame();
										void DrawStatistics();
											void GetNumberRoundsForComputer();
												void GameForComputer();
													void GetTypeWeaponPlayer();
														void DrawScreenForComputerMove();
															char GetComputerDifficultLevel();
																char AI();
																	void CheckGameForComputer();
																		void StatisticsForComputer();
																			int ReturnNumberPlayers();
																				void GetNamesPlayers(const int number_players);
																					void DrawStringEliminations();
																						void GetTypeWeaponsPlayers();
																							void DrawCountdownForComputer();


void GetTypeGame(int __type)
{
	std::cin.sync();
	std::cin.clear();

	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute (handle, 2);
		std::cout << "\t\t\t     Enter type your game: " << std:: endl << std:: endl << std::endl;
	Sleep (SLEEP_TIME);
	DrawMenuPlayerVsPlayer();
		DrawMenuPlayerVsComputer();
	std::cout << std::endl << std::endl;
}

void DrawMenuPlayerVsPlayer (void)
{
	std::cout << "  ";
	Sleep (SLEEP_TIME + 1000);
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute (handle, 4);
			for (int i = 0; i < 21; ++i)
				{
					std::cout << "-";
				}
			SetConsoleTextAttribute (handle, 7);
				  std::cout << std::endl;
				  std::cout	<< "\a  |   0           0   |" << std::endl;
				  std::cout << "  |  - -    Vs   - -  |     [1] Player Vs Player" << std::endl;
				  std::cout << "  |   ||          ||  |"  << std::endl;
				  SetConsoleTextAttribute (handle, 4);
				  std::cout << "  ";
						for (int i = 0; i < 21; ++i)
							{
								std::cout << "-";
							}
						std::cout << std::endl;
}

void DrawMenuPlayerVsComputer (void)
{
	std::cout << std::endl << std::endl;
	std::cout << "  ";
	Sleep (SLEEP_TIME + 1000);
				for (int i = 0; i < 21; ++i)
					{
						std::cout << "-";
					}
		HANDLE handle;
		handle = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute (handle, 7);
				  std::cout << std::endl;
				  std::cout	<< "\a  |   0          ---  |" << std::endl;
				  std::cout << "  |  - -    Vs  |CPU| |     [2] Player Vs Computer" << std::endl;
				  std::cout << "  |   ||         ---  |" << std::endl;
				  SetConsoleTextAttribute (handle, 4);
				  std::cout << "  ";
						for (int i = 0; i < 21; ++i)
							{
								std::cout << "-";
							}
		Sleep (SLEEP_TIME);
		std::cout << std::endl;

		key_keyboard = _getch();
		if (key_keyboard == '1')  {GetNumberRounds();}
			if (key_keyboard == '2')  {GetNumberRoundsForComputer();}
				else
				{
					std::cout << "\n\n\n  Wrong option!";
					Sleep(700);
					DrawBoard();
				}

}

void GetNumberRounds(void)
{
	system ("CLS");
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\n\t\t\t" << std::endl;
					std::cout <<"              ******     *      *******   *******  *******"<< std::endl;
					std::cout<<"              *     *   * *     *      *  *        *      *"<< std::endl;
					std::cout<<"              ******   *   *    ********  ******   *******"<< std::endl;
					std::cout<<"              *       *******   *         *        *     *"<< std::endl;
					std::cout<<"              *      *       *  *         *******  *      *"<< std::endl;
			SetConsoleTextAttribute( handle , 7 );
			std::cout << "\t\t ========================================" << std::endl;
				SetConsoleTextAttribute (handle, 3);
				std::cout << "\t\t\t     Stone, Scrissors" << std::endl << std::endl << std:: endl << std::endl << std::endl;

		Sleep (SLEEP_TIME);
		SetConsoleTextAttribute (handle, 7);
		std::cout << "\t\t\t";
		for (int i = 0; i < 31; ++i)
			{
				SetConsoleTextAttribute (handle, 5);
				std::cout << "-";
			}
		SetConsoleTextAttribute (handle, 7);
		std::cout << std::endl;
		std::cout << "\t\t\tEnter number of rounds [max.5] ";
	std::cin >> game_options._rounds;
							while(game_options._rounds > 5 || game_options._rounds <= 0)
									{
										std::cout << "\n\t\t\t";
										for (int i = 0; i < 36; ++i)
												{
													SetConsoleTextAttribute (handle, 2);
													std::cout << "-";
												}
										std::cin.sync();
										std::cin.clear();
										SetConsoleTextAttribute (handle, 7);
										std::cout << "\n\t\t\tEnter again number of rounds [max.5] ";
										std::cin >> game_options._rounds;
									}
			Sleep (SLEEP_TIME);
			system("CLS");
	SetConsoleTextAttribute( handle , 2 );
	std::cout << "\n\t\t\t" << std::endl;
					std::cout <<"              ******     *      *******   *******  *******"<< std::endl;
					std::cout<<"              *     *   * *     *      *  *        *      *"<< std::endl;
					std::cout<<"              ******   *   *    ********  ******   *******"<< std::endl;
					std::cout<<"              *       *******   *         *        *     *"<< std::endl;
					std::cout<<"              *      *       *  *         *******  *      *"<< std::endl;
			SetConsoleTextAttribute( handle , 7 );
			std::cout << "\t\t ========================================" << std::endl;
				SetConsoleTextAttribute (handle, 2);
				std::cout << "\t\t\t     Stone, Scrissors" << std::endl << std::endl << std:: endl << std::endl << std::endl;
		SetConsoleTextAttribute (handle, 7);
		std::cout << "\t\t\t";
					for (int i = 0; i < 28; ++i)
						{
							SetConsoleTextAttribute (handle, 1);
							std::cout << "-";
						}
		SetConsoleTextAttribute (handle, 7);
			std::cout << "\n\t\t\tEnter name player 1: ";
	std::cin >> game_options.names[0];
	std::cout << "\t\t\t";
					for (int i = 0; i < 28; ++i)
						{
							SetConsoleTextAttribute (handle, 1);
							std::cout << "-";
						}
		SetConsoleTextAttribute (handle, 7);
		std::cout << "\n\t\t\tEnter name player 2: ";
	std::cin>>game_options.names[1];
						while (game_options.names[0] == game_options.names[1])
								{
										std::cin.sync();
										std::cin.clear();
									std::cout << std::endl;
									std::cout << "\t\t\t";
											for (int i = 0; i < 28; ++i)
												{
													SetConsoleTextAttribute (handle, 2);
													std::cout << "-";
												}
			SetConsoleTextAttribute (handle, 7);
			std::cout << "\n\t\t\tEnter another name: ";
			std::cin>>game_options.names[1];
		}
						GameForPlayers();
}




void GameForPlayers(void)
{
	for(int counter_loop = 0; counter_loop < game_options._rounds; counter_loop++)
	{
		DrawCountdown();
		DrawTypesWeaponsPlayer1();
		DrawScreenForChangePlayer();
		DrawTypesWeaponsPlayer2();
		DrawStringForBattle();
		CheckGame();
	}
	DrawStatistics();

}

void DrawTypesWeaponsPlayer1(void)
{
	if(colP1 == 1 || colP1 == 0) {system("COLOR 07");}
	if(colP1 == 2) {system("COLOR 17");}
	if(colP1 == 3) {system("COLOR 20");}
	if(colP1 == 4) {system("COLOR 30");}
	if(colP1 == 5) {system("COLOR 4f");}
	if(colP1 == 6) {system("COLOR 50");}
	if(colP1 == 7) {system("COLOR 60");}
	if(colP1 == 8) {system("COLOR 70");}
	if(colP1 == 9) {system("COLOR 80");}
	system ("CLS");
	std::cin.sync();
	std::cin.clear();
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "\t\t\t";
		for (int i = 0; i < TAB; ++i)
			{
			std::cout << "=";
			}
		std::cout << "\n\t\t\t";
		std::cout << "=  Paper Stone Scrissors Game =" << std::endl;
		std::cout << "\t\t\t";
			for (int i = 0; i < TAB; ++i)
				{
					std::cout << "=";
				}
	std::cout << "\n\n" << std::endl;
	Sleep(SLEEP_TIME);
	std::cout << "\t\t\t" <<  game_options.names[0] <<  ", enter type of your weapon" << std::endl;
	Sleep(SLEEP_TIME + 2000);

				  std::cout << std::endl;
				  std::cout	<< "\a\t |   ******    |" << std::endl;
				  std::cout << "\t |   *     *   |     [1] Paper" << std::endl;
				  std::cout << "\t |   ******    |"  << std::endl;
				  std::cout << "\t |   *         |"  << std::endl;
				  std::cout << "\t |   *         |"  << std::endl;

						std::cout << std::endl;
						Sleep (SLEEP_TIME + 1000);


				  std::cout	<< "\a\t\t  |   ******   |" << std::endl;
				  std::cout << "\t\t  |   *        |     [2] Stone" << std::endl;
				  std::cout << "\t\t  |   ******   |"  << std::endl;
				  std::cout << "\t\t  |        *   |"  << std::endl;
				  std::cout << "\t\t  |   ******   |"  << std::endl;
					std::cout << std::endl;
					Sleep(SLEEP_TIME + 1000);


				  std::cout	<< "\a\t\t\t  |   ******        |" << std::endl;
				  std::cout << "\t\t\t  |   *             |     [3] Scrissors" << std::endl;
				  std::cout << "\t\t\t  |   ******  ....  |"  << std::endl;
				  std::cout << "\t\t\t  |        *  .     |"  << std::endl;
				  std::cout << "\t\t\t  |   ******  ....  |"  << std::endl;


type_weapon = _getch();
if(type_weapon != '1' && type_weapon != '2' && type_weapon != '3') {system("CLS"); DrawTypesWeaponsPlayer1();}
}



void DrawCountdown(void)
{
	system("CLS");
	Sleep (SLEEP_TIME);
		system("COLOR 17");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "\a";
		std::cout << "\t\t\t\t     ROUND " << counter_rounds << std::endl;
		Sleep(SLEEP_TIME + 500);
	system("CLS");
	Sleep(SLEEP_TIME);
	system("COLOR 40");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\a";
	std::cout << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t   *******" << std::endl;
	Sleep(SLEEP_TIME + 500);
	system("CLS");
	system("COLOR e0");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\a";
	std::cout << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t *********" << std::endl
			  << "\t\t\t\t  *   ***  " << std::endl
			  << "\t\t\t\t     ***   " << std::endl
			  << "\t\t\t\t    ***    " << std::endl
			  << "\t\t\t\t   ***     " << std::endl
			  << "\t\t\t\t  ***     " << std::endl
			  << "\t\t\t\t ***      " << std::endl
			  << "\t\t\t\t *******" << std::endl
			  << "\t\t\t\t *******" << std::endl;
	Sleep(SLEEP_TIME + 500);
	system("CLS");
	system("COLOR a0");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\a";
	std::cout << "\t\t\t\t       ***" << std::endl
			  << "\t\t\t\t     *****" << std::endl
			  << "\t\t\t\t    ******" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl;
	++counter_rounds;
	Sleep(1000);
}

void DrawTypesWeaponsPlayer2(void)
{
	if(colP2 == 1 || colP2 == 0) {system("COLOR 07");}
	if(colP2 == 2) {system("COLOR 17");}
	if(colP2 == 3) {system("COLOR 20");}
	if(colP2 == 4) {system("COLOR 30");}
	if(colP2 == 5) {system("COLOR c0");}
	if(colP2 == 6) {system("COLOR 50");}
	if(colP2 == 7) {system("COLOR 60");}
	if(colP2 == 8) {system("COLOR 70");}
	if(colP2 == 9) {system("COLOR 80");}
	system ("CLS");
	std::cout << "\t\t\t";
		for (int i = 0; i < TAB; ++i)
			{
			std::cout << "=";
			}
		std::cout << "\n\t\t\t";
		std::cout << "=  Paper Stone Scrissors Game =" << std::endl;
		std::cout << "\t\t\t";
			for (int i = 0; i < TAB; ++i)
				{
					std::cout << "=";
				}
	std::cout << "\n\n" << std::endl;
	Sleep(SLEEP_TIME);
	std::cout << "\t\t\t" << game_options.names[1] << ", enter type of your weapon" << std::endl;
	Sleep(SLEEP_TIME + 2000);

				  std::cout << std::endl;
				  std::cout	<< "\a\t   |   ******    |" << std::endl;
				  std::cout << "\t   |   *     *   |     [1] Paper" << std::endl;
				  std::cout << "\t   |   ******    |"  << std::endl;
				  std::cout << "\t   |   *         |"  << std::endl;
				  std::cout << "\t   |   *         |"  << std::endl;

						std::cout << std::endl;
						Sleep (SLEEP_TIME + 1000);


				  std::cout	<< "\a\t\t   |   ******   |" << std::endl;
				  std::cout << "\t\t   |   *        |     [2] Stone" << std::endl;
				  std::cout << "\t\t   |   ******   |"  << std::endl;
				  std::cout << "\t\t   |        *   |"  << std::endl;
				  std::cout << "\t\t   |   ******   |"  << std::endl;
					std::cout << std::endl;
					Sleep(SLEEP_TIME + 1000);



				  std::cout	<< "\a\t\t\t  |   ******        |" << std::endl;
				  std::cout << "\t\t\t  |   *             |     [3] Scrissors" << std::endl;
				  std::cout << "\t\t\t  |   ******  ....  |"  << std::endl;
				  std::cout << "\t\t\t  |        *  .     |"  << std::endl;
				  std::cout << "\t\t\t  |   ******  ....  |"  << std::endl;

type_weapon1 = _getch();
if(type_weapon1 != '1' && type_weapon1 != '2' && type_weapon1 != '3') {system("CLS"); DrawTypesWeaponsPlayer2();}

}


int CheckGame()
{
	system("CLS");
	system("COLOR f1");

			if(type_weapon == '1')
			{

	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	Sleep(SLEEP_TIME + 1000);
				  std::cout	<< "\a\t\t\t       |   ******    |" << std::endl;
				  std::cout << "\t\t\t       |   *     *   |" << std::endl;
				  std::cout << "\t\t\t       |   ******    |"  << std::endl;
				  std::cout << "\t\t\t       |   *         |"  << std::endl;
				  std::cout << "\t\t\t       |   *         |"  << std::endl << std::endl << std::endl;
				  std::cout << "\t\t\t            PAPER" << std::endl;

						std::cout << std::endl;
			}
				if(type_weapon == '2')
				{
					std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				  std::cout << "\a\t\t\t          |   ******   |" << std::endl;
				  std::cout << "\t\t\t          |   *        |" << std::endl;
				  std::cout << "\t\t\t          |   ******   |"  << std::endl;
				  std::cout << "\t\t\t          |        *   |"  << std::endl;
				  std::cout << "\t\t\t          |   ******   |"  << std::endl << std::endl;
					std::cout << std::endl;
					std::cout << "\t\t\t               STONE" << std::endl;
					Sleep(SLEEP_TIME + 1000);
				}
					if(type_weapon == '3')
					{
						std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
						std::cout << "\a\t\t\t      |   ******        |" << std::endl;
						std::cout << "\t\t\t      |   *             |" << std::endl;
						std::cout << "\t\t\t      |   ******  ....  |"  << std::endl;
						std::cout << "\t\t\t      |        *  .     |"  << std::endl;
						std::cout << "\t\t\t      |   ******  ....  |"  << std::endl << std::endl << std::endl;
						std::cout << "\t\t\t           SCRISSORS" << std::endl;
						Sleep(SLEEP_TIME + 1000);
					}
					Sleep(SLEEP_TIME);
					system("CLS");
					system("COLOR 3f");
					std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
						std::cout << "\a\t\t\t ********  ********       " << std::endl;
						std::cout << "\t\t\t  *******  *******     " << std::endl;
						std::cout << "\t\t\t   ******  ******   ******   " << std::endl;
						std::cout << "\t\t\t    *****  *****    *  " << std::endl;
						std::cout << "\t\t\t     ****  ****     ******  " << std::endl;
						std::cout << "\t\t\t      ***  ***           *" << std::endl;
						std::cout << "\t\t\t      ********  ##  ******" << std::endl;
					Sleep(1000);

	system("CLS");
	system("COLOR f1");
			if(type_weapon1 == '1')
			{
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				  std::cout	<< "\a\t\t\t       |   ******    |" << std::endl;
				  std::cout << "\t\t\t       |   *     *   |" << std::endl;
				  std::cout << "\t\t\t       |   ******    |"  << std::endl;
				  std::cout << "\t\t\t       |   *         |"  << std::endl;
				  std::cout << "\t\t\t       |   *         |"  << std::endl << std::endl << std::endl;
				  std::cout << "\t\t\t            PAPER" << std::endl;
				  Sleep(SLEEP_TIME + 1000);

						std::cout << std::endl;
			}
				if(type_weapon1 == '2')
				{
					std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				  std::cout << "\a\t\t\t          |   ******   |" << std::endl;
				  std::cout << "\t\t\t          |   *        |" << std::endl;
				  std::cout << "\t\t\t          |   ******   |"  << std::endl;
				  std::cout << "\t\t\t          |        *   |"  << std::endl;
				  std::cout << "\t\t\t          |   ******   |"  << std::endl << std::endl;
					std::cout << std::endl;
					std::cout << "\t\t\t               STONE" << std::endl;
					Sleep(SLEEP_TIME + 1000);
				}
					if(type_weapon1 == '3')
					{
						std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
						std::cout << "\a\t\t\t      |   ******        |" << std::endl;
						std::cout << "\t\t\t      |   *             |" << std::endl;
						std::cout << "\t\t\t      |   ******  ....  |"  << std::endl;
						std::cout << "\t\t\t      |        *  .     |"  << std::endl;
						std::cout << "\t\t\t      |   ******  ....  |"  << std::endl << std::endl << std::endl;
						std::cout << "\t\t\t           SCRISSORS" << std::endl;
						Sleep(SLEEP_TIME + 1000);
					}
		system("CLS");
		if(type_weapon == '1' && type_weapon1 == '1' || type_weapon == '2' && type_weapon1 == '2' || type_weapon == '3' && type_weapon1 == '3')
		{
			system("COLOR 5f");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t     DRAW! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			system("CLS");
		}

		if(type_weapon == '1' && type_weapon1 == '2')
		{
			system("COLOR 9c");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tPAPER wraps STONE! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_options.score_player[0];
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_options.names[0] << " win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(type_weapon == '2' && type_weapon1 == '1')
		{
			system("COLOR 3a");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tPAPER wraps STONE! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_options.score_player[1];
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_options.names[1] << " win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(type_weapon == '1' && type_weapon1 == '3')
		{
			system("COLOR 1e");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tSCRISSORS cut PAPER! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_options.score_player[1];
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_options.names[1] << " win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(type_weapon == '3' && type_weapon1 == '1')
		{
			system("COLOR 2e");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tSCRISSORS cut PAPER! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_options.score_player[0];
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_options.names[0] << " win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(type_weapon == '2' && type_weapon1 == '3')
		{
			system("COLOR 4e");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tSTONE destroy SCRISSORS! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_options.score_player[0];
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_options.names[0] << " win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(type_weapon == '3' && type_weapon1 == '2')
		{
			system("COLOR 3c");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t STONE destroy SCRISSORS! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_options.score_player[1];
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_options.names[1] << " win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
	return 0;
}



void DrawScreenForChangePlayer(void)
{
	system("COLOR 2f");
	system("CLS");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "\a";
		std::cout << "\t\t\t    Changing Player, wait... " << std::endl;
		Sleep(1000);
}

void DrawStatistics()
{
	system("COLOR 3f");
	system("CLS");
	std::cout << "\t\t\t";
		for (int i = 0; i < TAB; ++i)
			{
			std::cout << "=";
			}
		std::cout << "\n\t\t\t";
		std::cout << "=          Statistics         =" << std::endl;
		std::cout << "\t\t\t";
			for (int i = 0; i < TAB; ++i)
				{
					std::cout << "=";
				}
			Sleep(SLEEP_TIME);
	std::cout << "\n\n" << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t";
					for(int i = 0; i<25; ++i)
					{
						std::cout << "-";
					}
					std::cout << std::endl;
			std::cout << "\a\t\t\t" << game_options.names[0] << ": " << game_options.score_player[0] << " rounds winning" << std::endl;
			std::cout << "\t\t\t";
			for(int i = 0; i<25; ++i)
					{
						std::cout << "-";
					}
					std::cout << std::endl;
			std::cout << "\a\t\t\t" << game_options.names[1] << ": " << game_options.score_player[1] << " rounds winning" << std::endl << std::endl << std::endl << std::endl;
			Sleep(SLEEP_TIME);
			std::cout << "\t\t\tPress any key to continue...";
			_getch();
			system("CLS");
			if(game_options.score_player[0] > game_options.score_player[1])
			{

			    SaveDataFile(game_options.names[0],game_options.names[1] );
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_options.names[0] << " win battle!" << std::endl;
			}
			if(game_options.score_player[0] == game_options.score_player[1])
			{
				std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" <<  "Battle is unresolved!" << std::endl;
			}
			if(game_options.score_player[0] < game_options.score_player[1])
			{
			    SaveDataFile(game_options.names[1],game_options.names[0]);
				system("COLOR 20");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_options.names[1] << " win battle!" << std::endl;
			}
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			Sleep(2000);
			std::cout << "\t\t\t\t [1] Play Again" << std::endl;
			Sleep(SLEEP_TIME - 500);
			std::cout << "\t\t\t\t ";
			for (int i = 0; i < 15; ++i)
				{
					std::cout << "-";
				}
			std::cout << std::endl;
			std::cout << "\t\t\t\t [2] Exit to menu" << std::endl;

				choose_end = _getch();
				if(choose_end == '1') {GetNumberRounds();}
				if(choose_end == '2') {DrawBoard();}
				else
					while(choose_end != '1' && choose_end != '2')
					{
						std::cout << "\n\n\t\t\t\t Select the correct option! " << std::endl;
						choose_end = _getch();
							if(choose_end == '1') {GetNumberRounds();}
							if(choose_end == '2') {DrawBoard();}
					}
}

/***********************************************************************************************************************************************************************************************/
//code for Computer AI

void GetNumberRoundsForComputer(void)
{
	system("COLOR 07");
	system ("CLS");
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\n\t\t\t" << std::endl;
					std::cout <<"              ******     *      *******   *******  *******"<< std::endl;
					std::cout<<"              *     *   * *     *      *  *        *      *"<< std::endl;
					std::cout<<"              ******   *   *    ********  ******   *******"<< std::endl;
					std::cout<<"              *       *******   *         *        *     *"<< std::endl;
					std::cout<<"              *      *       *  *         *******  *      *"<< std::endl;
			SetConsoleTextAttribute( handle , 7 );
			std::cout << "\t\t ========================================" << std::endl;
				SetConsoleTextAttribute (handle, 3);
				std::cout << "\t\t\t     Stone, Scrissors" << std::endl << std::endl << std:: endl << std::endl << std::endl;

		Sleep (SLEEP_TIME);
		SetConsoleTextAttribute (handle, 7);
		std::cout << "\t\t\t";
		for (int i = 0; i < 31; ++i)
			{
				SetConsoleTextAttribute (handle, 5);
				std::cout << "-";
			}
		SetConsoleTextAttribute (handle, 7);
		std::cout << std::endl;
		std::cout << "\t\t\tEnter number of rounds [max.5] ";
	std::cin >> game_vs_computer.number_rounds;
							while(game_vs_computer.number_rounds > 5 || game_vs_computer.number_rounds <= 0)
									{
										std::cin.sync();
										std::cin.clear();
										std::cout << "\n\t\t\t";
										for (int i = 0; i < 36; ++i)
												{
													SetConsoleTextAttribute (handle, 2);
													std::cout << "-";
												}
										SetConsoleTextAttribute (handle, 7);
										std::cout << "\n\t\t\tEnter again number of rounds [max.5] ";
										std::cin >> game_vs_computer.number_rounds;
									}
			Sleep (SLEEP_TIME);
			system("CLS");
	SetConsoleTextAttribute( handle , 2 );
	std::cout << "\n\t\t\t" << std::endl;
					std::cout <<"              ******     *      *******   *******  *******"<< std::endl;
					std::cout<<"              *     *   * *     *      *  *        *      *"<< std::endl;
					std::cout<<"              ******   *   *    ********  ******   *******"<< std::endl;
					std::cout<<"              *       *******   *         *        *     *"<< std::endl;
					std::cout<<"              *      *       *  *         *******  *      *"<< std::endl;
			SetConsoleTextAttribute( handle , 7 );
			std::cout << "\t\t ========================================" << std::endl;
				SetConsoleTextAttribute (handle, 2);
				std::cout << "\t\t\t     Stone, Scrissors" << std::endl << std::endl << std:: endl << std::endl << std::endl;
		SetConsoleTextAttribute (handle, 7);
		std::cout << "\t\t\t";
					for (int i = 0; i < 28; ++i)
						{
							SetConsoleTextAttribute (handle, 1);
							std::cout << "-";
						}
		SetConsoleTextAttribute (handle, 7);
			std::cout << "\n\t\t\tEnter your name: ";
	std::cin >> game_vs_computer.name;
	std::cout << "\t\t\t";
	GetComputerDifficultLevel();

}

void GetTypeWeaponPlayer(void)
{
	system ("CLS");
	std::cin.sync();
	std::cin.clear();
	system("COLOR 17");
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "\t\t\t";
		for (int i = 0; i < TAB; ++i)
			{
			std::cout << "=";
			}
		std::cout << "\n\t\t\t";
		std::cout << "=  Paper Stone Scrissors Game =" << std::endl;
		std::cout << "\t\t\t";
			for (int i = 0; i < TAB; ++i)
				{
					std::cout << "=";
				}
	std::cout << "\n\n" << std::endl;
	Sleep(SLEEP_TIME);
	std::cout << "\t\t\t" <<  game_vs_computer.name <<  ", enter type of your weapon" << std::endl;
	Sleep(SLEEP_TIME + 2000);

				  std::cout << std::endl;
				  std::cout	<< "\a\t |   ******    |" << std::endl;
				  std::cout << "\t |   *     *   |     [1] Paper" << std::endl;
				  std::cout << "\t |   ******    |"  << std::endl;
				  std::cout << "\t |   *         |"  << std::endl;
				  std::cout << "\t |   *         |"  << std::endl;

						std::cout << std::endl;
						Sleep (SLEEP_TIME + 1000);


				  std::cout	<< "\a\t\t  |   ******   |" << std::endl;
				  std::cout << "\t\t  |   *        |     [2] Stone" << std::endl;
				  std::cout << "\t\t  |   ******   |"  << std::endl;
				  std::cout << "\t\t  |        *   |"  << std::endl;
				  std::cout << "\t\t  |   ******   |"  << std::endl;
					std::cout << std::endl;
					Sleep(SLEEP_TIME + 1000);


				  std::cout	<< "\a\t\t\t  |   ******        |" << std::endl;
				  std::cout << "\t\t\t  |   *             |     [3] Scrissors" << std::endl;
				  std::cout << "\t\t\t  |   ******  ....  |"  << std::endl;
				  std::cout << "\t\t\t  |        *  .     |"  << std::endl;
				  std::cout << "\t\t\t  |   ******  ....  |"  << std::endl;


weapon_player = _getch();
if(weapon_player != '1' && weapon_player != '2' && weapon_player != '3') {system("CLS"); GetTypeWeaponPlayer();}
}

char GetComputerDifficultLevel()
{
		system ("CLS");
		system("COLOR 07");
	std::cin.sync();
	std::cin.clear();
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout << "\t\t\t";
		for (int i = 0; i < TAB; ++i)
			{
			std::cout << "=";
			}
		std::cout << "\n\t\t\t";
		SetConsoleTextAttribute (handle, 4);
		std::cout << "=  Paper Stone Scrissors Game =" << std::endl;
		SetConsoleTextAttribute (handle, 7);
		std::cout << "\t\t\t";
			for (int i = 0; i < TAB; ++i)
				{
					std::cout << "=";
				}
	std::cout << "\n\n" << std::endl;
	Sleep(SLEEP_TIME);
	SetConsoleTextAttribute (handle, 6);
	std::cout << "\t\t\t  " <<  game_vs_computer.name <<  ", enter level difficult" << std::endl;
	Sleep(SLEEP_TIME + 2000);

				  std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
				  SetConsoleTextAttribute (handle, 2);
				  std::cout	<< "\a\t\t\t\t   [1] Easy" << std::endl << std::endl;
				  std::cout << "\t\t\t\t   ";
				  Sleep(SLEEP_TIME);
				  SetConsoleTextAttribute (handle, 7);
		for(int i=0; i<8; ++i){std::cout << "-";}
				  SetConsoleTextAttribute (handle, 6);
				  std::cout << "\a\n\n\t\t\t\t   [2] Normal" << std::endl << std::endl;
				  std::cout << "\t\t\t\t   ";
				  Sleep(SLEEP_TIME);
				  SetConsoleTextAttribute (handle, 7);
		for(int i=0; i<8; ++i){std::cout << "-";}
				  SetConsoleTextAttribute (handle, 4);
				  std::cout << "\a\n\n\t\t\t\t   [3] High"  << std::endl << std::endl;

level_difficult = _getch();
if(level_difficult != '1' && level_difficult != '2' && level_difficult != '3')
{
	SetConsoleTextAttribute (handle, 7);
	std::cout << "\n\n\n  Wrong option!";
					Sleep(700);
					system("CLS"); GetComputerDifficultLevel();}
GameForComputer();
return level_difficult;
}

char AI(char weapon_player, char level_difficult)
{
	int random_computer =( rand() % 3 ) + 1;
	if(level_difficult == '1')
	{
		if(weapon_player == '1')
		{weapon_computer = 2 ;}
			if(weapon_player == '2')
			{weapon_computer = random_computer;}
				if(weapon_player == '3')
				{weapon_computer = 1;}
	}
	if(level_difficult == '2')
	{
		weapon_computer = random_computer;
	}
	if(level_difficult == '3')
	{
		if(weapon_player == '1')
		{weapon_computer = 3;}
			if(weapon_player == '2')
			{weapon_computer = random_computer;}
				if(weapon_player == '3')
				{weapon_computer = 3;}
	}
	return weapon_computer;

}

void CheckGameForComputer()
{
	system("CLS");
	system("COLOR f1");

			if(weapon_player == '1')
			{

	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	Sleep(SLEEP_TIME + 1000);
				  std::cout	<< "\a\t\t\t       |   ******    |" << std::endl;
				  std::cout << "\t\t\t       |   *     *   |" << std::endl;
				  std::cout << "\t\t\t       |   ******    |"  << std::endl;
				  std::cout << "\t\t\t       |   *         |"  << std::endl;
				  std::cout << "\t\t\t       |   *         |"  << std::endl << std::endl << std::endl;
				  std::cout << "\t\t\t            PAPER" << std::endl;

						std::cout << std::endl;
			}
				if(weapon_player == '2')
				{
					std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				  std::cout << "\a\t\t\t          |   ******   |" << std::endl;
				  std::cout << "\t\t\t          |   *        |" << std::endl;
				  std::cout << "\t\t\t          |   ******   |"  << std::endl;
				  std::cout << "\t\t\t          |        *   |"  << std::endl;
				  std::cout << "\t\t\t          |   ******   |"  << std::endl << std::endl;
					std::cout << std::endl;
					std::cout << "\t\t\t               STONE" << std::endl;
					Sleep(SLEEP_TIME + 1000);
				}
					if(weapon_player == '3')
					{
						std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
						std::cout << "\a\t\t\t      |   ******        |" << std::endl;
						std::cout << "\t\t\t      |   *             |" << std::endl;
						std::cout << "\t\t\t      |   ******  ....  |"  << std::endl;
						std::cout << "\t\t\t      |        *  .     |"  << std::endl;
						std::cout << "\t\t\t      |   ******  ....  |"  << std::endl << std::endl << std::endl;
						std::cout << "\t\t\t           SCRISSORS" << std::endl;
						Sleep(SLEEP_TIME + 1000);
					}
					Sleep(SLEEP_TIME);
					system("CLS");
					system("COLOR 3f");
					std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
						std::cout << "\a\t\t\t ********  ********       " << std::endl;
						std::cout << "\t\t\t  *******  *******     " << std::endl;
						std::cout << "\t\t\t   ******  ******   ******   " << std::endl;
						std::cout << "\t\t\t    *****  *****    *  " << std::endl;
						std::cout << "\t\t\t     ****  ****     ******  " << std::endl;
						std::cout << "\t\t\t      ***  ***           *" << std::endl;
						std::cout << "\t\t\t      ********  ##  ******" << std::endl;
					Sleep(1000);

	system("CLS");
	system("COLOR f1");
			if(weapon_computer == 1)
			{
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				  std::cout	<< "\a\t\t\t       |   ******    |" << std::endl;
				  std::cout << "\t\t\t       |   *     *   |" << std::endl;
				  std::cout << "\t\t\t       |   ******    |"  << std::endl;
				  std::cout << "\t\t\t       |   *         |"  << std::endl;
				  std::cout << "\t\t\t       |   *         |"  << std::endl << std::endl << std::endl;
				  std::cout << "\t\t\t            PAPER" << std::endl;
				  Sleep(SLEEP_TIME + 1000);

						std::cout << std::endl;
			}
				if(weapon_computer == 2)
				{
					std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
				  std::cout << "\a\t\t\t          |   ******   |" << std::endl;
				  std::cout << "\t\t\t          |   *        |" << std::endl;
				  std::cout << "\t\t\t          |   ******   |"  << std::endl;
				  std::cout << "\t\t\t          |        *   |"  << std::endl;
				  std::cout << "\t\t\t          |   ******   |"  << std::endl << std::endl;
					std::cout << std::endl;
					std::cout << "\t\t\t               STONE" << std::endl;
					Sleep(SLEEP_TIME + 1000);
				}
					if(weapon_computer == 3)
					{
						std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
						std::cout << "\a\t\t\t      |   ******        |" << std::endl;
						std::cout << "\t\t\t      |   *             |" << std::endl;
						std::cout << "\t\t\t      |   ******  ....  |"  << std::endl;
						std::cout << "\t\t\t      |        *  .     |"  << std::endl;
						std::cout << "\t\t\t      |   ******  ....  |"  << std::endl << std::endl << std::endl;
						std::cout << "\t\t\t           SCRISSORS" << std::endl;
						Sleep(SLEEP_TIME + 1000);
					}
		system("CLS");
		if(weapon_player == '1' && weapon_computer == 1 || weapon_player == '2' && weapon_computer == 2 || weapon_player == '3' && weapon_computer == 3)
		{
			system("COLOR 5f");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t     DRAW! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			system("CLS");
		}

		if(weapon_player == '1' && weapon_computer == 2)
		{
			system("COLOR 9c");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tPAPER wraps STONE! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_vs_computer.score_player1;
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_vs_computer.name << " win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(weapon_player == '2' && weapon_computer == 1)
		{
			system("COLOR 3a");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tPAPER wraps STONE! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_vs_computer.score_computer;
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << "Computer win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(weapon_player == '1' && weapon_computer == 3)
		{
			system("COLOR 1e");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tSCRISSORS cut PAPER! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_vs_computer.score_computer;
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << "Computer win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(weapon_player == '3' && weapon_computer == 1)
		{
			system("COLOR 2e");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tSCRISSORS cut PAPER! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_vs_computer.score_player1;
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_vs_computer.name << " win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(weapon_player == '2' && weapon_computer == 3)
		{
			system("COLOR 4e");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\tSTONE destroy SCRISSORS! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_vs_computer.score_player1;
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_vs_computer.name << " win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
		if(weapon_player == '3' && weapon_computer == 2)
		{
			system("COLOR 3c");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t STONE destroy SCRISSORS! " << std::endl;
			Sleep(SLEEP_TIME + 1000);
			++game_vs_computer.score_computer;
			system("CLS");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << "Computer win round!" << std::endl;
			Sleep(SLEEP_TIME + 1000);
		}
}

void DrawStringForBattle()
{
	system("COLOR 80");
	system("CLS");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\t\t\t   ";
		for(int i=0; i<30; ++i)
		{
			std::cout << "=";
		}
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "\a";
		std::cout << "\t\t\t\t     BATTLE!!! " << std::endl;
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "\t\t\t   ";
		for(int i=0; i<30; ++i)
		{
			std::cout << "=";
		}
		Beep(1000, 50);
		Beep(1000, 100);
		Beep(1000, 20);
		Beep(400, 70);
		Beep(750, 50);
		Beep(750, 90);
		Beep(800, 100);
		std::cout << std::endl << std::endl << std::endl;
		Sleep(1000);
}

void StatisticsForComputer()
{
	system("COLOR 3f");
	system("CLS");
	std::cout << "\t\t\t";
		for (int i = 0; i < TAB; ++i)
			{
			std::cout << "=";
			}
		std::cout << "\n\t\t\t";
		std::cout << "=          Statistics         =" << std::endl;
		std::cout << "\t\t\t";
			for (int i = 0; i < TAB; ++i)
				{
					std::cout << "=";
				}
			Sleep(SLEEP_TIME + 1000);
	std::cout << "\n\n" << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t";
					for(int i = 0; i<25; ++i)
					{
						std::cout << "-";
					}
					std::cout << std::endl;
			std::cout << "\a\t\t\t" << game_vs_computer.name << ": " << game_vs_computer.score_player1 << " rounds winning" << std::endl;
			std::cout << "\t\t\t";
			for(int i = 0; i<25; ++i)
					{
						std::cout << "-";
					}
					std::cout << std::endl;
					std::cout << "\a\t\t\t" <<"Computer: " << game_vs_computer.score_computer <<  " rounds winning" << std::endl << std::endl << std::endl << std::endl;
			Sleep(SLEEP_TIME);
			std::cout << "\t\t\tPress any key to continue...";
			_getch();
			system("CLS");
			if(game_vs_computer.score_player1 > game_vs_computer.score_computer)
			{
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << game_vs_computer.name << " win battle!" << std::endl;
			}
			if(game_vs_computer.score_player1 == game_vs_computer.score_computer)
			{
				std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" <<  "Battle is unresolved!" << std::endl;
			}
			if(game_vs_computer.score_player1 < game_vs_computer.score_computer)
			{
				system("COLOR 20");
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			std::cout << "\a";
			std::cout << "\t\t\t\t" << "Computer win battle!" << std::endl;
			}
			std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
			Sleep(2000);
			std::cout << "\t\t\t\t [1] Play Again" << std::endl;
			Sleep(SLEEP_TIME - 500);
			std::cout << "\t\t\t\t ";
			for (int i = 0; i < 15; ++i)
				{
					std::cout << "-";
				}
			std::cout << std::endl;
			std::cout << "\t\t\t\t [2] Exit to menu" << std::endl;

				chend = _getch();
				if(chend == '1') {GetNumberRoundsForComputer();}
				if(chend == '2') {DrawBoard();}
				else
					{
						std::cout << "\n\n\t\t\t\t Wrong option! " << std::endl;
						system("CLS");
						StatisticsForComputer();


					}
}

void DrawScreenForComputerMove(void)
{
	system("COLOR 20");
	system("CLS");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "\a";
		std::cout << "\t\t\t Computer selects weapon, wait... " << std::endl;
		Sleep(3000);
}

void GameForComputer(void)
{
	for(int counter_loop = 0; counter_loop < game_vs_computer.number_rounds; counter_loop++)
	{
		DrawCountdownForComputer();
		GetTypeWeaponPlayer();
		DrawScreenForComputerMove();
		AI(weapon_player, level_difficult);
		DrawStringForBattle();
		CheckGameForComputer();
	}
	StatisticsForComputer();
}

void DrawCountdownForComputer(void)
{
	system("CLS");
	Sleep (SLEEP_TIME);
		system("COLOR 17");
		std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
		std::cout << "\a";
		std::cout << "\t\t\t\t     ROUND " << counter_rounds_for_computer << std::endl;
		Sleep(SLEEP_TIME + 500);
	system("CLS");
	Sleep(SLEEP_TIME);
	system("COLOR 40");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\a";
	std::cout << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t   *******" << std::endl;
	Sleep(SLEEP_TIME + 500);
	system("CLS");
	system("COLOR e0");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\a";
	std::cout << "\t\t\t\t   *******" << std::endl
			  << "\t\t\t\t *********" << std::endl
			  << "\t\t\t\t  *   ***  " << std::endl
			  << "\t\t\t\t     ***   " << std::endl
			  << "\t\t\t\t    ***    " << std::endl
			  << "\t\t\t\t   ***     " << std::endl
			  << "\t\t\t\t  ***     " << std::endl
			  << "\t\t\t\t ***      " << std::endl
			  << "\t\t\t\t *******" << std::endl
			  << "\t\t\t\t *******" << std::endl;
	Sleep(SLEEP_TIME + 500);
	system("CLS");
	system("COLOR a0");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\a";
	std::cout << "\t\t\t\t       ***" << std::endl
			  << "\t\t\t\t     *****" << std::endl
			  << "\t\t\t\t    ******" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl
			  << "\t\t\t\t        **" << std::endl;
	++counter_rounds_for_computer;
	Sleep(1000);
}

