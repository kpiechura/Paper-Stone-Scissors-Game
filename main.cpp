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
#include "functions.h"


//variables
int key;
int type_game;


int main()
{
	srand((unsigned int) time( NULL ) );
while(1)
{
	int draw_computer =( rand() % 3 ) + 1;
	system ("TITLE Paper Stone Scrissors Game - Kamil Piechura");
	DrawStartScreen (key);
		DrawBoard();
			DrawString();
				GetTypeGame(type_game);
	_getch();
}
return EXIT_SUCCESS;
}
