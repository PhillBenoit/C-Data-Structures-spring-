// 269 - Homework 6 - Recursion.cpp : Defines the entry point for the console application.
//

#include "Util.h"
#include "Ex5.h"
#include "Maze.h"

int main()
{
	setbuf(stdout, NULL);
	printStart();
	printf("This program counts odd numbers recursivly and demostrates maze functionality.\n");
	printf("******************************************************************************\n");

	//the number used to count to and from
	int testSize = 11;
	
	printSeparator("Count Up");
	countUp(&testSize);

	printSeparator("Count Down");
	countDown(&testSize);
	
	
	string testMaze[11];

	//most basic test
	//finds a path to the exit
	printSeparator("Starting Maze Success Test");
	pause();

	testMaze[0] =  "111111111111111111111111111111111111111111";
	testMaze[1] =  "m00000000000000000000000000000000000000001";
	testMaze[2] =  "101111111111111111111111111111111111111101";
	testMaze[3] =  "101e00000000000000000000000000000000000001";
	testMaze[4] =  "101111111111111111111111111111111111111101";
	testMaze[5] =  "101000000000000000000000000000000000000001";
	testMaze[6] =  "101111111111111111111111111111111111111101";
	testMaze[7] =  "101000000000000000000000000000000000000001";
	testMaze[8] =  "101111111111111111111111111111111111111111";
	testMaze[9] =  "100000000000000000000000000000000000000001";
	testMaze[10] = "111111111111111111111111111111111111111111";

	Maze(testMaze, lengthOf(testMaze)).exitMaze();

	
	//exit is blocked to test for failure
	printSeparator("Starting Maze Failure Test");
	pause();

	testMaze[0] =  "111111111111111111111111111111111111111111";
	testMaze[1] =  "m00000000000000000000000000000000000000001";
	testMaze[2] =  "101111111111111111111111111111111111111101";
	testMaze[3] =  "101e10000000000000000000000000000000000001";
	testMaze[4] =  "101111111111111111111111111111111111111101";
	testMaze[5] =  "101000000000000000000000000000000000000001";
	testMaze[6] =  "101111111111111111111111111111111111111101";
	testMaze[7] =  "101000000000000000000000000000000000000001";
	testMaze[8] =  "101111111111111111111111111111111111111111";
	testMaze[9] =  "100000000000000000000000000000000000000001";
	testMaze[10] = "111111111111111111111111111111111111111111";

	Maze(testMaze, lengthOf(testMaze)).exitMaze();


	//tests to make sure entrance and exit cells can be set in the middle of the board
	//entry cell is tested to make sure it cannot be used for an exit
	printSeparator("Starting Unobstructed Entrance / Exit Test");
	pause();

	testMaze[0] =  "111111111111111111111111111111111111111111";
	testMaze[1] =  "100000000000000000000000000000000000000001";
	testMaze[2] =  "100000000000000000000100000000000001000001";
	testMaze[3] =  "1010000000000000000000m0000000000000000001";
	testMaze[4] =  "1000000000000000000000000000000000000e0001";
	testMaze[5] =  "100000000000000000000000000000000000000001";
	testMaze[6] =  "100000000000000000011111100000000001000001";
	testMaze[7] =  "100000000000000000000000000000000000000001";
	testMaze[8] =  "100000000000100000000000000000000000000001";
	testMaze[9] =  "100000000000000000000000000000000000000001";
	testMaze[10] = "111111111111111111111111111111111111111111";
	
	Maze(testMaze, lengthOf(testMaze)).exitMaze();

	printEnd();
	return 0;
}