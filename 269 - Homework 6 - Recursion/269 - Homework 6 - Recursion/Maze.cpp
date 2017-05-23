// Phillip Benoit
// CIS269
// Homework 6
// Maze.cpp - Code used for Exercise 5 on pg212

#include "Maze.h"

//default constructor
Maze::Maze() : exitMarker('e'), entryMarker('m'), visited('.'),
			   passage('0'), wall('1') {
	Stack<char*> mazeRows;
	char str[80], *s;
	int col, row = 0;
	cout << "Enter a rectangular maze using the following "
		 << "characters:\nm - entry\ne - exit\n1 - wall\n0 - passage\n"
		 << "Enter one line at at time; end with Ctrl-z:\n";
	while (cin >> str) {
		row++;
		cols = strlen(str);
		s = new char[cols+3];    // two more cells for borderline columns;
		mazeRows.push(s);
		strcpy(s+1,str);
		s[0] = s[cols+1] = wall; // fill the borderline cells with 1s;
		s[cols+2] = '\0';
		if (strchr(s,exitMarker) != 0) {
			 exitCell.x = row;
			 exitCell.y = strchr(s,exitMarker) - s;
		}
		if (strchr(s,entryMarker) != 0) {
			 entryCell.x = row;
			 entryCell.y = strchr(s,entryMarker) - s;
		}
	}
	cin.clear();   //added so pause works
	rows = row;
	store = new char*[rows+2];        // create a 1D array of pointers;
	store[0] = new char[cols+3];      // a borderline row;
	for ( ; !mazeRows.empty(); row--) {
		store[row] = mazeRows.pop();
	}
	store[rows+1] = new char[cols+3]; // another borderline row;
	store[0][cols+2] = store[rows+1][cols+2] = '\0';
	for (col = 0; col <= cols+1; col++) {
		store[0][col] = wall;         // fill the borderline rows with 1s;
		store[rows+1][col] = wall;
	}
}

//constructor that uses a string array from the driver
Maze::Maze(string testMaze[], int size) : exitMarker('e'), entryMarker('m'),
								  visited('.'), passage('0'), wall('1') {
	Stack<char*> mazeRows;
	char str[80], *s;
	int col, row = 0;

	while (row < size) {
		col = 0;
		do
		{
			str[col] = testMaze[row].at(col);
			col++;
		} while (col < testMaze[row].length());
		while (col < lengthOf(str))
		{
			str[col] = '\0';
			col++;
		}
		row++;
		cols = strlen(str);
		s = new char[cols + 3];    // two more cells for borderline columns;
		mazeRows.push(s);
		strcpy(s + 1, str);
		s[0] = s[cols + 1] = wall; // fill the borderline cells with 1s;
		s[cols + 2] = '\0';
		if (strchr(s, exitMarker) != 0) {
			exitCell.x = row;
			exitCell.y = strchr(s, exitMarker) - s;
		}
		if (strchr(s, entryMarker) != 0) {
			entryCell.x = row;
			entryCell.y = strchr(s, entryMarker) - s;
		}
	}
	rows = row;
	store = new char*[rows + 2];        // create a 1D array of pointers;
	store[0] = new char[cols + 3];      // a borderline row;
	for (; !mazeRows.empty(); row--) {
		store[row] = mazeRows.pop();
	}
	store[rows + 1] = new char[cols + 3]; // another borderline row;
	store[0][cols + 2] = store[rows + 1][cols + 2] = '\0';
	for (col = 0; col <= cols + 1; col++) {
		store[0][col] = wall;         // fill the borderline rows with 1s;
		store[rows + 1][col] = wall;
	}
}

//starting point for trying to solve the maze
void Maze::exitMaze()
{
	//defines the starting point
	int x = entryCell.x;
	int y = entryCell.y;
	
	//loads currentCell so it can be used for comparisons
	currentCell.x = x;
	currentCell.y = y;
	
	//runs all the calls from this method so that the entry point is never used twice
	exitMaze(x - 1, y);
	exitMaze(x + 1, y);
	exitMaze(x, y - 1);
	exitMaze(x, y + 1);
	
	//prints the board after completing all the calls
	clearScreen();
	cout << *this;
	
	//prints out success or failure message
	if (currentCell == exitCell) cout << "Success\n";
	else cout << "Failure\n";
}

void Maze::exitMaze(int x, int y)
{
	//uses currentCell to test for base case
	if (!(currentCell == exitCell))
	{
		//sets currentCell to stop looping if x,y is the exit square
		if (store[x][y] == exitMarker)
		{
			currentCell.x = x;
			currentCell.y = y;
		}

		//calls are only made if x,y is a passage
		if (store[x][y] == passage)
		{
			//sets the current space to "visited"
			store[x][y] = visited;
			
			//print a snapshot
			clearScreen();
			cout << *this;
			
			//calls cell above
			exitMaze(x - 1, y);
			
			//calls cell below
			exitMaze(x + 1, y);
			
			//calls cell to the left
			exitMaze(x, y - 1);

			//calls cell to the right
			exitMaze(x, y + 1);
		}
	}
}

/*  Old Code
void Maze::pushUnvisited(int row, int col) {
	if (store[row][col] == passage || store[row][col] == exitMarker) {
		mazeStack.push(Cell(row,col));
	}
}
void Maze::exitMaze() {
	int row, col;
	currentCell = entryCell;
	while (!(currentCell == exitCell)) {
		row = currentCell.x;
		col = currentCell.y;
		cout << *this;         // print a snapshot;
		clearScreen();
		if (!(currentCell == entryCell))
			store[row][col] = visited;
		pushUnvisited(row-1,col);
		pushUnvisited(row+1,col);
		pushUnvisited(row,col-1);
		pushUnvisited(row,col+1);
		if (mazeStack.empty()) {
			 cout << *this;
			 cout << "Failure\n";
			 return;
		}
		else currentCell = mazeStack.pop();
	}
	cout << *this;
	cout << "Success\n";
}
*/

//print maze
ostream & operator<<(ostream & out, const Maze & maze)
{
	for (int row = 0; row <= maze.rows + 1; row++)
		out << maze.store[row] << endl;
	out << endl;
	return out;
}