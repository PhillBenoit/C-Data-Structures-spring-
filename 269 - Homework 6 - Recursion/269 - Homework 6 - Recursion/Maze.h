// Phillip Benoit
// CIS269
// Homework 6
// Maze.h - Code used for Exercise 5 on pg212

#include <iostream>
#include <string>
#include <stack>
#include "Util.h"

using namespace std;


#ifndef __MAZE_H__
#define __MAZE_H__

template<class T>
class Stack : public stack<T> {
public:
	T pop() {
		T tmp = top();
		stack<T>::pop();
		return tmp;
	}
};

class Cell {
public:
	Cell(int i = 0, int j = 0) {
		x = i; y = j;
	}
	bool operator== (const Cell& c) const {
		return x == c.x && y == c.y;
	}
private:
	int x, y;
	friend class Maze;
};

class Maze {
public:
	Maze();
	Maze(string testMaze[], int size);
	void exitMaze();
	void exitMaze(int x, int y);
private:
	Cell currentCell, exitCell, entryCell;
	const char exitMarker, entryMarker, visited, passage, wall;
	Stack<Cell> mazeStack;
	char **store;         // array of strings;
	//void pushUnvisited(int, int); old code
	int rows, cols;
	friend ostream& operator<< (ostream& out, const Maze& maze);
};


#endif // __MAZE_H__
