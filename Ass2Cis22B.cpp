//============================================================================
// Name        : Ass2Cis22B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>

using namespace std;



void bubblesort(string array1[], string array2[], int counter1, int counter2);

int main() {
	//set counter to check how mant elements in the file
	int counter1 = 0;
	int counter2 = 0;

	//open file 1 and check for how many elements
	ifstream inputfile;
	inputfile.open("unsorted_dictionary.txt");
	if(inputfile.is_open())
	{
		while(!inputfile.eof())
		{
			string data;
			inputfile >> data;
			counter1++;
		}
	}
	else
	{
		cout <<"Error!";
	}

	//open file 2 and check for how many elements
	ifstream inputfile2;
	inputfile2.open("keywords.txt");
	if(inputfile2.is_open())
	{
		while(!inputfile2.eof())
		{
			string data;
			inputfile2 >> data;
			counter2++;
		}
	}
	else
	{
		cout <<"Error!";
	}

	//create string array with numbers of elements counted
	string array1[counter1];
	string array2[counter2];

	//open file 1 and input all elements into the array
	ifstream inputfile3;
	inputfile3.open("unsorted_dictionary.txt");
	if(inputfile3.is_open())
	{
		int counter = 0;		//set counter for array
		while(!inputfile3.eof())
		{
			string data = "";
			inputfile3 >> data;
			array1[counter] = data;
			counter++;
		}
	}
	else
	{
		cout <<"Error!";
	}



	//Print out elements in array1 to check if correct
	//for (int i = 0; i < counter1; i++)
	//{
	//	cout << array1[i] <<endl;
	//}


	//open file 2 and input all elements into the array
	ifstream inputfile4;
	inputfile4.open("keywords.txt");
	if(inputfile4.is_open())
	{
		int counter = 0;		//set counter for array
		while(!inputfile4.eof())
		{
			string data = "";
			inputfile4 >> data;
			array2[counter] = data;
			counter++;
		}
	}
	else
	{
		cout <<"Error!";
	}

	//Print out elements in array2 to check if correct
	//for (int i = 0; i < counter2; i++)
	//{
	//	cout << array2[i] << endl;
	//}


	bubblesort(array1, array2, counter1, counter2);

	return 0;
}



/*
 * buddle sort
 * Arguments: string array1, string array2, counter1, and counter2
 * create 2 chars arrays, sort it using bubble sort and sort it with the string array as well.
 */
void bubblesort(string array1[], string array2[], int counter1, int counter2)
{
	//create two empty array type char
	char alphabet1[counter1];
	char alphabet2[counter2];


	//insert every first word in array1 into char array
	for (int i = 0; i < counter1; i++)
	{
		alphabet1[i] = array1[i][0];
	}

	//print out to check if alphabet2 contains correct elements
	//for (int i = 0; i < counter1; i++)
	//{
		//cout << i+1 << ": "<< alphabet1[i] << endl;
	//}

	//insert every first word in array2 into char array
	for (int i = 0; i < counter2; i++)
	{
		alphabet2[i] = array2[i][0];
	}

	//print out to check if alphabet2 contains correct elements
	//for (int i = 0; i < counter2; i++)
	//{
	//	cout << i+1 << ": " << alphabet2[i] << endl;
	//}

	//start the bubble sort to sort char array and at the same time with the string array1
	for (int i = 0; i < counter1-1; i++)
	{
	    //for (j = 0; j < n-i-1; j++)
		for (int j = 0; j < counter1-i-1; j++)
		{
			char temp;
			string stemp;
			if(alphabet1[j] >= alphabet1[j+1])
			{
				temp = alphabet1[j];
				stemp = array1[j];

				alphabet1[j] = alphabet1[j+1];
				array1[j] = array1[j+1];

				alphabet1[j+1] = temp;
				array1[j+1] = stemp;
			}
			else
			{
				continue;
			}
		}
	}

	//start the bubble sort to sort char array and at the same time with the string array2
	//for (i = 0; i < n-1; i++)
	for (int i = 0; i < counter2-1; i++)
	{
	    //for (j = 0; j < n-i-1; j++)
		for (int j = 0; j < counter2-i-1; j++)
		{
			char temp;
			string stemp;
			if(alphabet2[j] >= alphabet2[j+1])
			{
				temp = alphabet2[j];
				stemp = array2[j];

				alphabet2[j] = alphabet2[j+1];
				array2[j] = array2[j+1];

				alphabet2[j+1] = temp;
				array2[j+1] = stemp;
			}
			else
			{
				continue;
			}
		}
	}

	//print out to the console to check if array1 already store the words sorted or not
	for (int i = 0; i < counter1;i++)
	{
		cout << i+1 << ": " << array1[i] << endl;
	}

	//print out to the console to check if array2 already store the words sorted or not
	for (int i = 0; i < counter2;i++)
	{
		cout << i+1 << ": " << array2[i] << endl;
	}

	return;
}
