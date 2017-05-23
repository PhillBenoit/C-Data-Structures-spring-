// Phillip Benoit
// CIS269
// Homework 13
// fileCompare.h : Defines method for comparing files
#include "fileCompare.h"

void compareFiles(string firstFile, string secondFile, string outputFile)
{
	//opens files with passed names
	ifstream first(firstFile);
	ifstream second(secondFile);
	ofstream output(outputFile);
	
	//buffers to hold lines of input
	string lineFromFirst, lineFromSecond;
	
	//boolean to tell if the first file is longer
	bool firstLonger = false;

	//catches file open errors
	if (first.is_open() && second.is_open() && output.is_open())
	{
		//loads lines from file in to strings until End of File
		while (getline(first, lineFromFirst) && getline(second, lineFromSecond))
		{
			//allows while loop to use both file streams even if first is longer
			if (!first.eof() && second.eof()) firstLonger = true;

			//tests to see if lines are the same
			if (lineFromFirst.compare(lineFromSecond)==0)
			{
				//writes to file stream
				output << lineFromFirst + "\n";
			}
			else
			{
				//displays lines that differ
				cout << "> " + lineFromFirst + "\n" +
					    "< " + lineFromSecond + "\n";
			}
		}
		
		//prints out buffered line from while loop
		if (firstLonger) cout << "> " + lineFromFirst + "\n";

		//prints out the rest of the first file
		if (!first.eof())
		{
			while (getline(first, lineFromFirst))
				cout << "> " + lineFromFirst + "\n";
		}

		//prints out the rest of the second file
		if(!second.eof())
		{
			while (getline(second, lineFromSecond))
				cout << "< " + lineFromSecond + "\n";
		}

		//closes open files
		first.close();
		second.close();
		output.close();
	}
	else
	{
		//error message
		printf("Error opening text files.\n");
	}
}