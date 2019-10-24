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


#ifndef functions_hpp
#define functions_hpp

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <Windows.h>


//start declaration functions in game.cpp file
void DrawStartScreen(int key);
void DrawBoard(void);
void DrawString(void);
void GetTypeGame(int type_game);
void DrawString(void);
void GetNumberRounds(void);
void DrawStatisctics(void);



void DrawTypesWeaponsPlayer1(void);
void SetPlayerVsComputer(void);
void SetPlayerVsPlayer (void);
void SetTournament (void);
void SaveDataFile(std::string _name_player,std::string _name_player1);

//start declaration functions in menu.cpp file
int SetColorsP1();

//end declaration functions in game.cpp file


//start declaration functions for computer AI




//end declaration functions for computer AI


#endif
