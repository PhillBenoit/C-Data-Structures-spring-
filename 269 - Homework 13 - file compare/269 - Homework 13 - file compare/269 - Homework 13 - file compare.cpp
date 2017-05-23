// Phillip Benoit
// CIS269
// Homework 13
// 269 - Homework 13 - file compare.cpp : Defines the entry point for the console application.

#include "Util.h"
#include "fileCompare.h"

int main() {
	setbuf(stdout, NULL);
	printStart();
	printf("* This program compares two files.                     *\n"
		   "* Lines thaat are the same are written to a text file. *\n"
		   "* Lines that differ are printed to the screen.         *\n");
	printf("********************************************************\n");

	string firstFile = "f1.txt";
	string secondFile = "f2.txt";
	string outputFile = "identical.txt";

	compareFiles(firstFile, secondFile, outputFile);

	printEnd();
	return 0;
}
