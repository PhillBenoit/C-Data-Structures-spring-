// Sudoku c++.cpp : Defines the entry point for the console application.
//

#include "Sudoku.h"


int main()
{
	setbuf(stdout, NULL);
	string inputFile = "board.txt";
	Sudoku * testBoard = new Sudoku();
	testBoard->addFile(inputFile);
	testBoard->solve();
	
	if (testBoard->solved != testBoard->fullGridSize)
	{
		printf("Brute Force Mode\n");
		BruteForceSolver solver = BruteForceSolver();
		solver.copyBoard(&solver.startingBoard, *testBoard);
		solver.copyBoard(&solver.testBoard, *testBoard);
		solver.start();
		while (solver.solution->top != nullptr)
		{
			testBoard->assignSquare(solver.solution->top->guess, solver.solution->top->x, solver.solution->top->y);
			solver.solution->pop();
		}
		testBoard->solve();
		testBoard->savePossible("possible.txt");
	}
	
	testBoard->printBoard();
	return 0;
}