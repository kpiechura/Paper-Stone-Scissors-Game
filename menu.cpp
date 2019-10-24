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
**Paper Stone Scrissors Game 2013 v.1 for DOS 2013
**Author: Kamil Piechura
**Date compile: 17.05.2013 r.
**License: Free
**IDE: Visual C++ 2013
**Copyrights: All copyrights are reserved by Kamil Piechura
************************************************************
************************************************************
*/


#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "functions.h"
#include <fstream>


//var
int TAB = 31;
int TAB1 = 19;
int colP1 = 0;
int colP2 = 0;


//prototypes functions
bool OpenFile(std::string file_name);
void SaveDataFile(std::string _name_player,std::string _name_player1);
void ClearTable();
void DrawQuestionFile();
void OpenHighScores();
void DrawOptions();
void DrawHighScores();
void DrawCredits();
void DrawExitQuestion();
void DrawSetColorsOptions();
int SetColorsP1();
int SetColorsP2();

void ClearTable()
{
    std::ofstream file;
    file.open("High Scores.txt");
    file << "\n\n\n\n\n\n\t\t\t1. "  << std::endl;
    file << "\n\t\t\t2.  " << std::endl;
    file << "\n\t\t\t3.  " << std::endl;
    file << "\n\t\t\t4.  " << std::endl;
    file << "\n\t\t\t5.  " << std::endl;
    file.close();
}

bool OpenFile(std::string file_name)
{
    //creation buffor for plik
    //fstream.h
    system("CLS");
    std::ifstream file;
    file.open( file_name.c_str() );
    if( !file.good() )
         return false;

    std::string line;
    while( std::getline( file, line ) )
         std::cout << line << std::endl;

    file.close();
    return true;
}

void SaveDataFile(std::string _name_player,std::string _name_player1)
{
    std::ofstream file;
    if(!file.good()){std::cout << "Program can't open this file!";}
    file.open("High Scores.txt");
    file << "\n\n\n\n\n\n\t\t\t1. "  << _name_player << std::endl;
    Sleep(1000);
    file << "\n\t\t\t2. " << _name_player1 << std::endl;
    Sleep(1000);
    file << "\n\t\t\t3.  " << std::endl;
    Sleep(500);
    file << "\n\t\t\t4.  " << std::endl;
    Sleep(500);
    file << "\n\t\t\t5.  " << std::endl;
    file.close();
}
void DrawQuestionFile()
{
    system ("CLS");
	char character;
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
						std::cout << "\a\n\n\n\n\n\n\n\n\n\t\t   ";
							for (int i = 0; i < TAB + 14; ++i)
							{
								SetConsoleTextAttribute( handle , 3 );
								std::cout << "-";
							}
						std::cout << "\n";
						SetConsoleTextAttribute( handle , 7 );
						std::cout << "\t\t   - Are you sure you want to clear table? <Y/N> ";
						character = _getch();


						if (character == 'y' || character == 'Y' )
						{
							ClearTable();
							system("CLS");
							std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
                            std::cout << "\a";
                            std::cout << "\t\t\t\tOperation succesfull! " << std::endl;
                            Sleep(1000);
                            DrawOptions();
						}
						if (character == 'n' || character == 'n') { system ("CLS"); DrawOptions();}
						else
						{
							system ("CLS");
							DrawOptions();
						}
}

void DrawStartScreen(int key)
{
	std::cin.sync();
	std::cin.clear();

	system("CLS");
	system("COLOR 07");
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\n\n\n\n\n\n\t\t\t" << std::endl;
					std::cout <<"              ******     *      *******   *******  *******"<< std::endl;
					std::cout<<"              *     *   * *     *      *  *        *      *"<< std::endl;
					std::cout<<"              ******   *   *    ********  ******   *******"<< std::endl;
					std::cout<<"              *       *******   *         *        *     *"<< std::endl;
					std::cout<<"              *      *       *  *         *******  *      *"<< std::endl;
			SetConsoleTextAttribute( handle , 7 );
			std::cout << "\t\t ========================================" << std::endl;
				SetConsoleTextAttribute (handle, 3);
				std::cout << "\t\t\t     Stone, Scrissors" << std::endl << std::endl << std:: endl << std::endl << std::endl;
				SetConsoleTextAttribute (handle, 7);
					std::cout << "\t\t\t      Press any key...";
					_getch();


}

void DrawBoard()
{
	std::cin.sync();
	std::cin.clear();

	system ("CLS");
	system("COLOR 07");

	std::cout << "\t\t\t";
	for (int i = 0; i < TAB; ++i)
	{
		std::cout << "=";
	}
	std::cout << "\n\t\t\t";
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "=  Paper Stone Scrissors Game =" << std::endl;
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "\t\t\t";
	for (int i = 0; i < TAB; ++i)
	{
		std::cout << "=";
	}
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\n\n\n\n\t\t\t\t     Menu  " << std::endl << std::endl;
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "\n\n\t\t\t      |    Start Game   |" << std::endl;
	std::cout << "\t\t\t      ";

		for (int i = 0; i < TAB1; ++i)
		{
			std::cout << "-";
		}
	std::cout << "\n\t\t\t      |     Options     |" << std::endl;
	std::cout << "\t\t\t      ";
	for (int i = 0; i < TAB1; ++i)
		{
			std::cout << "-";
		}
	std::cout << "\n\t\t\t      |    High Scores  |" << std::endl;
	std::cout << "\t\t\t      ";
					for (int i = 0; i < TAB1; ++i)
					{
						std::cout << "-";
					}
	std::cout << "\n\t\t\t      |     Credits     |" << std::endl;
	std::cout << "\t\t\t      ";
							for (int i = 0; i < TAB1; ++i)
							{
								std:: cout << "-";
							}
	std::cout << "\n\t\t\t      |      Exit       |" << std::endl;
	std::cout << "\t\t\t      ";
								for (int i = 0; i < TAB1; ++i)
								{
								std::cout << "-";
								}
								char user_char;
	user_char = _getch();
	if (user_char == '1')
	{
		system ("CLS");
	}
		if (user_char == '2')
		{
			DrawOptions();
		}
            if (user_char == '3')
					{


					    //open file - fstream.h
                        if( !OpenFile( "High Scores.txt"));
                        Sleep(2000);
                        std::cout << "\n\n\n\n\t\t\t Press any key...";
                        char chr;
                        chr=_getch();
                        DrawBoard();
					}
					if (user_char == '4')
					{
						DrawCredits();
					}
						if (user_char == '5')
						{
							DrawExitQuestion();
						}
			if (user_char != '1' && user_char != '2' && user_char != '3' && user_char != '4' && user_char != '5')
			{
				system ("CLS");
				DrawBoard();
			}
}
void DrawOptions(void)
{
	system ("CLS");
		std::cout << "\a\n\t\t\t";
		for (int i = 0; i < TAB; ++i)
		{
			std::cout << "=";
		}
		std::cout << std::endl;
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\t\t\t\t";
	std::cout << " =  Options =" << std::endl;
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "\t\t\t";
	for (int i = 0; i < TAB; ++i)
	{
		std::cout << "=";
	}
	std::cout << std::endl << std::endl << std:: endl << std::endl << std::endl << std::endl;
	std::cout << "\t\t\t  ";
		for (int i = 0; i < TAB1 + 10; ++i)
		{
			std::cout << "-";
		}
	std::cout << "\n\t\t          |         Set Colors        |" << std::endl;
	std::cout << "\t\t          ";
	for (int i = 0; i < TAB1 + 10; ++i)
		{
			std::cout << "-";
		}
	std::cout << "\n\t\t          |      Reset Scores Table   |" << std::endl;
	std::cout << "\t\t          ";

			for (int i = 0; i < TAB1 + 10; ++i)
			{
				std::cout << "-";
			}
	std::cout << "\n\t\t          |            Back           |" << std::endl;
	std::cout << "\t\t          ";
			for (int i = 0; i < TAB1 + 10; ++i)
			{
				std::cout << "-";
			}

	char user_char;
	user_char = _getch();
	if (user_char == '1')
	{
		DrawSetColorsOptions();
	}
				if (user_char == '2')
				{
				    DrawQuestionFile();
					ClearTable();
					std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
                    std::cout << "\a";
                    system("CLS");
                    std::cout << "\t\t\t\tOperation succesfull! " << std::endl;
                    Sleep(1000 + 500);
					system("CLS");
					DrawOptions();
				}
                    if (user_char == '3')
				{
					DrawBoard();
				}

			if (user_char != '1' && user_char !='2' && user_char !='3' )
			{
				system ("CLS");
				DrawOptions();
			}
}

void DrawSetColorsOptions()
{
	system ("CLS");
		std::cout << "\a\n\t\t\t";
		for (int i = 0; i < TAB; ++i)
		{
			std::cout << "=";
		}
		std::cout << std::endl;
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\t\t\t\t";
	std::cout << "=  S.Colors =" << std::endl;
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "\t\t\t";
	for (int i = 0; i < TAB; ++i)
	{
		std::cout << "=";
	}
	std::cout << std::endl << std::endl << std:: endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "\n\t\t          |      S.Colors for P1      |" << std::endl;
	std::cout << "\t\t          ";

		for (int i = 0; i < TAB1 + 10; ++i)
		{
			std::cout << "-";
		}
	std::cout << "\n\t\t          |      S.Colors for P2      |" << std::endl;
	std::cout << "\t\t          ";

			for (int i = 0; i < TAB1 + 10; ++i)
			{
				std::cout << "-";
			}
	std::cout << "\n\t\t          |            Back           |" << std::endl;
	std::cout << "\t\t          ";
			for (int i = 0; i < TAB1 + 10; ++i)
			{
				std::cout << "-";
			}

	char option_colors;
	option_colors = _getch();
	if (option_colors == '1')
	{
		SetColorsP1();
	}
		if (option_colors == '2')
		{
			SetColorsP2();
		}
		if (option_colors == '3')
				{
					DrawOptions();
				}
			if (option_colors != '1'  && option_colors != '2' && option_colors != '3')
			{
				system ("CLS");
				DrawOptions();
			}
}


int SetColorsP1()
{
	system ("CLS");
		std::cout << "\t\t\t";
		for (int i = 0; i < TAB; ++i)
		{
			std::cout << "=";
		}
		std::cout << std::endl;
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\t\t\t\t";
	std::cout << "=  Colors P1 =" << std::endl;
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "\t\t\t";
	for (int i = 0; i < TAB; ++i)
	{
		std::cout << "=";
	}
	std::cout << std::endl << std::endl;

	HANDLE handlex;
	handlex = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute( handlex , 7 );
	std::cout << "\t\t\t[1] Black" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 1 );
	std::cout << "\t\t\t[2] Blue" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 2 );
	std::cout << "\t\t\t[3] Green" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 3 );
	std::cout << "\t\t\t[4] Azure" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 4 );
	std::cout << "\t\t\t[5] Red" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 5 );
	std::cout << "\t\t\t[6] Purple" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 6 );
	std::cout << "\t\t\t[7] Yellow" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 7 );
	std::cout << "\t\t\t[8] White" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 8 );
	std::cout << "\t\t\t[9] Grey\t\t\t [10] Exit" << std::endl << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	SetConsoleTextAttribute( handlex , 7 );
	std::cout << "\n\t\t\tEnter number color: ";
	std::cin >> colP1;
	if(colP1 == 10){DrawOptions();}
	while(colP1 > 10 || std::cin.fail() == TRUE){std::cin.sync(); std::cin.clear(); system("CLS"); SetColorsP1();}
	system("CLS");
	DrawSetColorsOptions();

	return colP1;
}


int SetColorsP2()
{
	system ("CLS");
		std::cout << "\t\t\t";
		for (int i = 0; i < TAB; ++i)
		{
			std::cout << "=";
		}
		std::cout << std::endl;
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\t\t\t\t";
	std::cout << "=  Colors P2 =" << std::endl;
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "\t\t\t";
	for (int i = 0; i < TAB; ++i)
	{
		std::cout << "=";
	}
	std::cout << std::endl << std::endl;

	HANDLE handlex;
	handlex = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute( handlex , 7 );
	std::cout << "\t\t\t[1] Black" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 1 );
	std::cout << "\t\t\t[2] Blue" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 2 );
	std::cout << "\t\t\t[3] Green" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 3 );
	std::cout << "\t\t\t[4] Azure" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 4 );
	std::cout << "\t\t\t[5] Red" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 5 );
	std::cout << "\t\t\t[6] Purple" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 6 );
	std::cout << "\t\t\t[7] Yellow" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 7 );
	std::cout << "\t\t\t[8] White" << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	std::cout << "\n";
	SetConsoleTextAttribute( handlex , 8 );
	std::cout << "\t\t\t[9] Grey\t\t\t [10] Exit" << std::endl << std::endl;
	std::cout << "\t\t\t";
	for(int i=0; i<10; ++i)
		{
			SetConsoleTextAttribute( handlex , 7 );
			std::cout << "-";
		}
	SetConsoleTextAttribute( handlex , 7 );
	std::cout << "\n\t\t\tEnter number color: ";
	std::cin >> colP2;
	if(colP2 == 10){DrawOptions();}
	while(colP2 > 10 || std::cin.fail() == TRUE){std::cin.sync(); std::cin.clear(); system("CLS"); SetColorsP2();}
	system("CLS");
	DrawSetColorsOptions();


	return colP2;
}

void DrawCredits(void)
{
	system ("CLS");
	Sleep(1000);
	std::cout << "\a\n\t\t\t";
		for (int i = 0; i < TAB; ++i)
		{
			std::cout << "=";
		}
		std::cout << std::endl;
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\t\t\t\t";
	std::cout << "=  Credits =" << std::endl;
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "\t\t\t";
	for (int i = 0; i < TAB; ++i)
	{
		std::cout << "=";
	}
	const UINT SLEEP_TIME = 2000;
	std::cout << "\n\n\n\t\t" << std:: endl;
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\n\n\t\t\t| Author: ";
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "Kamil Piechura" << std::endl;
	std::cout << "\t\t\t--------------------------" << std::endl;
	Sleep (SLEEP_TIME);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\t\t\t| Date compiling: ";
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "01-07-13" << std::endl;
	std::cout << "\t\t\t--------------------------" << std::endl;
	Sleep (SLEEP_TIME);
	SetConsoleTextAttribute( handle , 3 );
	std::cout << "\t\t\t| Program version: ";
	SetConsoleTextAttribute( handle , 7 );
	std::cout << "v.1" << std::endl;
	std::cout << "\t\t\t--------------------------" << std::endl << std::endl << std::endl;
	std::cout << "\t\t\t";
	Sleep (1000);
	std::cout << "Press any key...";
	_getch();
	DrawBoard();
}
void DrawExitQuestion (void)
{
	system ("CLS");
	char upload_char;
	int key = 0;
	HANDLE handle;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
						std::cout << "\a\n\n\n\n\n\n\n\n\n\t\t\t";
							for (int i = 0; i < TAB + 7; ++i)
							{
								SetConsoleTextAttribute( handle , 3 );
								std::cout << "-";
							}
						std::cout << "\n";
						SetConsoleTextAttribute( handle , 7 );
						std::cout << "\t\t\t- Are you sure you want to exit? <Y/N> ";
						SetConsoleTextAttribute (handle , 3);
						std::cout << "\t\t\t\t\t\t";
							for (int i = 0; i < TAB + 7; ++i)
							{
								std::cout << "-";
							}

						upload_char = _getch();


						if (upload_char == 'y' || upload_char == 'Y' )
						{
							exit (1);
						}
						else
						{
							system ("CLS");
							DrawBoard();
						}
}












