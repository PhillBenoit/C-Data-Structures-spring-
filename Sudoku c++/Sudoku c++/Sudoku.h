#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include "stdio.h"
#include "ctype.h"
#include "PossibleList.h"
#include <string>
#include <fstream>

using namespace std;

class Sudoku
{
public:
	
	//It is possible to run this program using perfect squares (4, 9, 16, 25, etc)
	//Just change the constant below.

	//number of rows / columns as well as the value limit
	static const short size = 9;

	//size of the grids within the main board grid
	const short subGridSize = (short)sqrt(size);

	//total number of elements on the board
	const short fullGridSize = (short)pow(size, 2);

	//numeric representation of board valuees
	short board[size][size];

	//boolean representation of the possibilities in each square
	bool possible[size][size][size];
	
	//counts number of solved squares
	short solved;

	Sudoku();
	~Sudoku();
	
	void addFile(string inputFile);
	void assignSquare(short numberToAssign, short x, short y);
	void printBoard();
	void savePossible(string outputFile);
	void clear();
	bool isValid();
	
	void solve();
	short findOnlyPossible(bool possible[]);

	void onlyRemaining();
	void onlyPossibleRow();
	void onlyPossibleColumn();
	void onlyPossibleSubGrid();

	void pairSearch();
	bool rowPairSearch(PossibleList * searchBoard[size][size]);
	bool columnPairSearch(PossibleList * searchBoard[size][size]);
	void assignFromPair(short x, short y, short omit, PossibleList * pair);

	void bruteForceMode(PossibleList * searchBoard[size][size]);
};

class Guess
{
public:
	short x, y, guess;
	Guess * next;

	Guess();
};

class GuessList
{
public:
	Guess * top;

	GuessList();
	void push(short guess, short x, short y);
	void push(Guess passedGuess);
	void pop();
};

class BruteForceSolver
{
public:
	Sudoku startingBoard;
	Sudoku testBoard;
	GuessList * solution;
	short counter;

	BruteForceSolver();
	static void copyBoard(Sudoku * destination, Sudoku source);
	void start();
	void findLeastPossible(GuessList * list, Sudoku s);
};

#endif // __SUDOKU_H__
