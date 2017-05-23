#include "Sudoku.h"

//initializes the board and the possibilites.
//posibilities reresent the boolean posibility of that number being in that location.
//
//If the upper left most is square is blank:
//	board[0][0] = 0 and possible[0][0][0-8] all are true
//
//If the upper left most is square is 1:
//	board[0][0] = 1 and possible[0][0][0] is true but:
//							possible[0][0][1 - 8] are all false because that number is assigned to that square
//							possible[1 - 8][0][0] are all false because that row has a 1
//							possible[0][1 - 8][0] are all false because that column has a 1
//                          possible[0-2][0-2][0] are all false because that 3x3 grid has a 1
Sudoku::Sudoku()
{
	for (short x = 0; x < size; x++)
	{
		for (short y = 0; y < size; y++)
		{
			board[x][y] = 0;
			for (short z = 0; z < size; z++)
			{
				possible[x][y][z] = true;
			}
		}
	}
	solved = 0;
}

Sudoku::~Sudoku()
{
}

//Adds the contents of a text file to the board.
void Sudoku::addFile(string inputFile)
{
	//creates stream from passed file name
	ifstream file(inputFile);

	//tests to make sure file was oppened properly
	if (file.is_open())
	{
		//counter for integer characters found in the file
		short intCounter = 0;

		//will hold a single line of text extracted from the file
		string lineOfText;

		//loops until end of file or 81 integers are found
		while (getline(file, lineOfText) && intCounter < fullGridSize)
		{
			//steps through the characters of the line of text
			for (short step = 0; step < (short)lineOfText.length(); step++)
			{
				char testChar = lineOfText[step];
				//if the character is a digit, add it to the board
				if (isdigit(testChar))
				{
					//skipps adding 0s as they were added when the object was initialized
					if (atoi(&testChar) != 0)
					{
						assignSquare(atoi(&testChar), intCounter / size, intCounter % size);
					}

					//steps up number of integers found
					intCounter++;
				}
			}
		}
		//if not enough integers were found, there was an error
		if (intCounter > fullGridSize)
		{
			printf("Not enough integers were found in the text file. (found: %d expected: %d)\n", intCounter, fullGridSize);
		}
		file.close();
	}
	else //else flag for improper file oppening
	{
		printf("Error opening text file.\n");
	}
}

//If the upper left most is square is 1:
//	board[0][0] = 1 and possible[0][0][0] is true but:
//							possible[0][0][1 - 8] are all false because that number is assigned to that square
//							possible[1 - 8][0][0] are all false because that row has a 1
//							possible[0][1 - 8][0] are all false because that column has a 1
//                          possible[0-2][0-2][0] are all false because that 3x3 grid has a 1
void Sudoku::assignSquare(short numberToAssign, short x, short y)
{
	board[x][y] = numberToAssign;
	//if (board[5][6] == 1) printf("found the problem\n");

	//decriments to allow proper assignment of matrix values
	numberToAssign--;
	
	//makes possibilites fase as per the above rules
	//also overwrites the true area as a side effect
	for (short counter = 0; counter < size; counter++)
	{
		possible[x][y][counter]	             = false;
		possible[x][counter][numberToAssign] = false;
		possible[counter][y][numberToAssign] = false;
		
		//nifty way of stepping through a 2d object with a linear value
		short subGridX = ((x / subGridSize) * subGridSize) + (counter / subGridSize);
		short subGridY = ((y / subGridSize) * subGridSize) + (counter % subGridSize);
		possible[ subGridX ][ subGridY ][numberToAssign] = false;
	}
	//Switches the only true statement back on
	possible[x][y][numberToAssign] = true;

	//steps up count of solved squares
	solved++;
	
}

//formats the board for printing to the screen
void Sudoku::printBoard()
{
	//steps through rows
	for (short x = 0; x < size; x++)
	{
		//add blank line every three lines
		if (x % subGridSize == 0) printf("\n");
		//seps through columns
		for (short y = 0; y < size; y++)
		{
			//add blank space every three columns
			if (y % subGridSize == 0) printf(" ");
			
			//print - instead of 0
			if (board[x][y] == 0) printf("-");
			
			//print digits
			else printf("%d", board[x][y]);
		}
		//new line
		printf("\n");
	}
	//new line when done
	printf("\n");
}

//converts possible array to text 1s and 0s and saves it to a text file.
//Used for debugging what spaces have been left unsolved.
void Sudoku::savePossible(string outputFile)
{
	ofstream file(outputFile);
	if (file.is_open())
	{
		for (short x = 0; x < size; x++)
		{
			//blank row between sub grids
			if (x % subGridSize == 0) file << "\n";
			for (short y = 0; y < size; y++)
			{
				//extra space between sub grids
				if (y % subGridSize == 0) file << " ";
				for (short z = 0; z < size; z++)
				{
					//converts boolean to 1 or 0
					if (possible[x][y][z]) file << z+1;
					else file << "-";
				}
				//space between represented squares
				file << " ";
			}
			//new line at the end of every row
			file << "\n";
		}
		file.close();
	}
	else
	{
		printf("Error opening output file.\n");
	}
}

void Sudoku::clear()
{
	for (short x = 0; x < size; x++)
	{
		for (short y = 0; y < size; y++)
		{
			board[x][y] = 0;
			for (short z = 0; z < size; z++)
			{
				possible[x][y][z] = true;
			}
		}
	}
	solved = 0;
}

bool Sudoku::isValid()
{
	for (short x = 0; x < size; x++)
	{
		for (short y = 0; y < size; y++)
		{
			short s = findOnlyPossible(possible[x][y]);
			if ( s > size)
			{
				return false;
			}
		}
	}
	return true;
}

void Sudoku::solve()
{
	//used to see how many new squares were solved between loops
	short solved;
	do
	{
		//saves the current number of solved squares to see how many 
		//new squares were solved after the running the tests
		solved = this->solved;
		
		onlyRemaining();
		onlyPossibleRow();
		onlyPossibleColumn();
		onlyPossibleSubGrid();

		//if nothing was found, search for pairs
		//if (this->solved == solved) pairSearch();

		//displays the number added through each loop
		printf("Added %d\n", this->solved - solved);
	//ends if no new solutions are found or the board has been filled
	} while (this->solved != solved && this->solved < fullGridSize);

	if (this->solved == fullGridSize) printf("The board was completed.\n");
	//saves possible for debugging if the board wasn't finished
	else
	{
		printf("The board was not completed.\n");
	}
}

//Checks a boolean array to see if only 1 value is true.
//Returns the value or 9 if muliple or 10 if 0 values are found.
short Sudoku::findOnlyPossible(bool possible[])
{
	short returnValue = size + 1;
	for (short step = 0; step < size; step++)
	{
		if (possible[step] && returnValue < size)
		{
			step = size;
			returnValue = size;
		}
		if (possible[step] && returnValue > size) returnValue = step;
	}
	return returnValue;
}

//steps through the board and tests each 0 square for only 1 possible solution
void Sudoku::onlyRemaining()
{
	for (short x = 0; x < size; x++)
	{
		for (short y = 0; y < size; y++)
		{
			if (board[x][y] == 0)
			{
				short found = findOnlyPossible(possible[x][y]);
				if (found < size) assignSquare(found + 1, x, y);
			}
		}
	}
}

//tests each row to see if each value is only possible in one place
void Sudoku::onlyPossibleRow()
{
	bool searchArray[size];
	for (short row = 0; row < size; row++)
	{
		for (short value = 0; value < size; value++)
		{
			//assigns search array for passing to findOnlyPossible
			for (short step = 0; step < size; step++)
				searchArray[step] = possible[row][step][value];
			short foundColumn = findOnlyPossible(searchArray);
			
			//assigns the found square if one was found
			//and it has a value of 0 on the board
			if (foundColumn < size && board[row][foundColumn] == 0)
				assignSquare(value + 1, row, foundColumn);
		}
	}
}

//tests each column to see if each value is only possible in one place
void Sudoku::onlyPossibleColumn()
{
	bool searchArray[size];
	for (short column = 0; column < size; column++)
	{
		for (short value = 0; value < size; value++)
		{
			//assigns search array for passing to findOnlyPossible
			for (short step = 0; step < size; step++)
				searchArray[step] = possible[step][column][value];
			short foundRow = findOnlyPossible(searchArray);

			//assigns the found square if one was found
			//and it has a value of 0 on the board
			if (foundRow < size && board[foundRow][column] == 0)
				assignSquare(value + 1, foundRow, column);
		}
	}
}

//tests each sub grid to see if each value is only possible in one place
void Sudoku::onlyPossibleSubGrid()
{
	bool searchArray[size];
	for (short subGridXCounter = 0; subGridXCounter < subGridSize; subGridXCounter++)
	{
		for (short subGridYCounter = 0; subGridYCounter < subGridSize; subGridYCounter++)
		{
			for (short value = 0; value < size; value++)
			{
				short subGridX;
				short subGridY;
				//assigns search array for passing to findOnlyPossible
				for (short step = 0; step < size; step++)
				{
					subGridX = ((subGridXCounter * subGridSize) + (step / subGridSize));
					subGridY = ((subGridYCounter * subGridSize) + (step % subGridSize));
					searchArray[step] = possible[subGridX][subGridY][value];
				}
				short foundValue = findOnlyPossible(searchArray);
				subGridX = ((subGridXCounter * subGridSize) + (foundValue / subGridSize));
				subGridY = ((subGridYCounter * subGridSize) + (foundValue % subGridSize));

				//assigns the found square if one was found
				//and it has a value of 0 on the board
				if (foundValue < size && board[subGridX][subGridY] == 0)
					assignSquare(value + 1, subGridX, subGridY);
			}
			
		}
	}
}

void Sudoku::pairSearch()
{
	//An array of pointers to lists with the possibilites for each square.
	//Lists contain a count used for finding pairs of matched sets
	PossibleList * linkedPossible[size][size];
	for (short x = 0; x < size; x++)
	{
		for (short y = 0; y < size; y++)
		{
			linkedPossible[x][y] = new PossibleList();
			if (board[x][y] == 0) linkedPossible[x][y]->addList(possible[x][y], size);
		}
	}
	if (!rowPairSearch(linkedPossible))
		if (!columnPairSearch(linkedPossible))
			bruteForceMode(linkedPossible);
	
}

bool Sudoku::rowPairSearch(PossibleList * searchBoard[size][size])
{
	for (int x = 0; x < size; x++)
	{
		for (int y = 0; y < size - 1; y++)
		{
			if (searchBoard[x][y]->size == 2)
			{
				for (int restOfY = y + 1; restOfY < size; restOfY++)
				{
					if (searchBoard[x][restOfY]->size == 2)
					{
						PossibleList * testList = new PossibleList();
						short ommited = testList->mergePair(searchBoard[x][y], searchBoard[x][restOfY]);
						if (testList->size == 3)
						{
							for (short threeStep = 0; threeStep < size; threeStep++)
							{
								if (searchBoard[x][threeStep]->size == 3 &&
									searchBoard[x][threeStep]->head->value == testList->head->value &&
									searchBoard[x][threeStep]->head->next->value == testList->head->next->value &&
									searchBoard[x][threeStep]->tail->value == testList->tail->value)
								{
									assignSquare(ommited + 1, x, threeStep + 1);
									assignFromPair(x, y, ommited, searchBoard[x][y]);
									assignFromPair(x, restOfY, ommited, searchBoard[x][restOfY]);
									return true;
								}//end compare value if
							}//end threeStep for loop
						}//end 3 in merged list if
					}//end find second set if
				}//end rest of y loop
			}//end find first set if
		}//end y
	}//end x
	return false;
}//end method

bool Sudoku::columnPairSearch(PossibleList * searchBoard[size][size])
{
	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size - 1; x++)
		{
			if (searchBoard[x][y]->size == 2)
			{
				for (int restOfX = x + 1; restOfX < size; restOfX++)
				{
					if (searchBoard[restOfX][y]->size == 2)
					{
						PossibleList * testList = new PossibleList();
						short ommited = testList->mergePair(searchBoard[x][y], searchBoard[restOfX][y]);
						if (testList->size == 3)
						{
							for (short threeStep = 0; threeStep < size; threeStep++)
							{
								if (searchBoard[threeStep][y]->size == 3 &&
									searchBoard[threeStep][y]->head->value == testList->head->value &&
									searchBoard[threeStep][y]->head->next->value == testList->head->next->value &&
									searchBoard[threeStep][y]->tail->value == testList->tail->value)
								{
									assignSquare(ommited + 1, threeStep, y);
									assignFromPair(x, y, ommited, searchBoard[x][y]);
									assignFromPair(restOfX, y, ommited, searchBoard[threeStep][y]);
									return true;
								}//end compare value if
							}//end threeStep for loop
						}//end 3 in merged list if
					}//end find second set if
				}//end rest of x loop
			}//end find first set if
		}//end x
	}//end y
	return false;
}

void Sudoku::assignFromPair(short x, short y, short omit, PossibleList * pair)
{
	short value = (pair->head->value == omit) ? pair->head->next->value : pair->head->value;
	assignSquare(value + 1, x, y);
}

void Sudoku::bruteForceMode(PossibleList * searchBoard[size][size])
{
	
}

BruteForceSolver::BruteForceSolver()
{
	startingBoard.clear();
	testBoard.clear();
	solution = new GuessList;
	counter = 0;
}

void BruteForceSolver::copyBoard(Sudoku * destination, Sudoku source)
{
	destination->clear();
	for (short x = 0; x < source.size; x++)
	{
		for (short y = 0; y < source.size; y++)
		{
			if (source.board[x][y] != 0) destination->assignSquare(source.board[x][y], x, y);
		}
	}
}

void BruteForceSolver::start()
{
	if (testBoard.solved != testBoard.fullGridSize)
	{
		if (testBoard.isValid())
		{
			GuessList list = GuessList();
			findLeastPossible(&list, testBoard);
			while (list.top != nullptr)
			{
				copyBoard(&testBoard, startingBoard);
				solution->push(*list.top);
				Guess * currentGuesses = solution->top;
				while (currentGuesses != nullptr)
				{
					testBoard.assignSquare(currentGuesses->guess + 1, currentGuesses->x, currentGuesses->y);
					currentGuesses = currentGuesses->next;
				}
				testBoard.solve();
				start();
				string saveBoard = "possible";
				saveBoard += to_string(counter) + ".txt";
				//testBoard.savePossible(saveBoard);
				testBoard.printBoard();
				counter++;
				testBoard.printBoard();
				if (testBoard.solved != testBoard.fullGridSize) solution->pop();
				if (testBoard.solved == testBoard.fullGridSize) list.top = nullptr;
				list.pop();
			}
		}
	}
}

void BruteForceSolver::findLeastPossible(GuessList * list, Sudoku s)
{
	PossibleList * linkedPossible[s.size][s.size];
	short leastPossible = s.size + 1;
	
	for (short x = 0; x < s.size; x++)
	{
		for (short y = 0; y < s.size; y++)
		{
			linkedPossible[x][y] = new PossibleList();
			if (s.board[x][y] == 0) linkedPossible[x][y]->addList(s.possible[x][y], s.size);
			if (linkedPossible[x][y]->size >= 2 && linkedPossible[x][y]->size < leastPossible)
				leastPossible = linkedPossible[x][y]->size;
		}
	}

	for (short x = 0; x < s.size; x++)
	{
		for (short y = 0; y < s.size; y++)
		{
			if (leastPossible == linkedPossible[x][y]->size)
			{
				PossibleNode * cursor = linkedPossible[x][y]->head;
				while (cursor != nullptr)
				{
					list->push(cursor->value, x, y);
					printf("Value : %d\nx: %d\ny: %d\n\n", cursor->value, x, y);
					cursor = cursor->next;
				}
			}
		}
	}
}

Guess::Guess()
{
	x = 0;
	y = 0;
	guess = 0;
	next = nullptr;
}

GuessList::GuessList()
{
	top = nullptr;
}

void GuessList::push(short guess, short x, short y)
{
	Guess * newGuess = new Guess();
	newGuess->x = x;
	newGuess->y = y;
	newGuess->guess = guess;
	newGuess->next = top;
	top = newGuess;
}

void GuessList::push(Guess passedGuess)
{
	push(passedGuess.guess, passedGuess.x, passedGuess.y);
}

void GuessList::pop()
{
	if (top != nullptr) top = top->next;
}