//============================================================================
// Name        : ahihi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Info
{

private:
	int StudentID = 0;
	int AssignmentPoint[11];
	int MidtermPoint = 0;
	int FinalPoint = 0;
	int CodeLabPoint= 0;
public:
	void setStudentID(int id)
	{
		StudentID = id;
	}
	int getStudentID()
	{
		return StudentID;
	}



};
//choose files to open
void openfile();

//read and display text data file on consult
void readfile(int &StudentID, int &labex, int AssignmentPoint[], int &MidtermPoint, int &FinalPoint, int &CodeLabPoint);

//read data to the file
void offile();

void sortarray();

void recursion(int array[]);

int main() {
	int StudentID = 0;
	int labex = 0;
	int AssignmentPoint[11] = {0};
	int MidtermPoint = 0;
	int FinalPoint = 0;
	int CodeLabPoint= 0;
	readfile(StudentID, labex, AssignmentPoint, MidtermPoint, FinalPoint, CodeLabPoint);	//read in datas from file and display it
	//offile();		//ask user to enter data and ofstream to a text file
	//cout << endl << endl << endl;
	//cout << StudentID;
	//sortarray();
	return 0;
}

void sortarray()
{
	int SIZE;
	int temp;
	cin >> SIZE;
	int array[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cin >> array[i];
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;


	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE-1; j++ )
		{
			if (array[j] > array[j+1])
			{
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
			else
			{
			}
		}
	}


	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

	cout << sizeof(array);
	cout << sizeof(int);
	//recursion(array);
}

void recursion(int array[])
{
	cout << sizeof(array);
	cout << sizeof(int);
	int t = sizeof(array)/sizeof(int);
	int number;
	bool found;
	cout << t;
	cout << endl;
	cout << "Enter number you want to find: ";

	cin >> number;
	if(array[t] == number)
	{
		found = true;
		cout << found;
		return;
	}
	else if(t == 0)
	{
		found = false;
		cout << found;
	}
	else
	{
		recursion(&array[t-1]);
	}
}

void readfile(int &StudentID, int &labex, int AssignmentPoint[], int &MidtermPoint, int &FinalPoint, int &CodeLabPoint)
{

	int temp = 0;
	string line;
	//input file instruction
	ifstream inputfile;
	ofstream outfile;
	inputfile.open("data1.txt");
	outfile.open("readout.txt");
	if(inputfile.is_open())
	{
		outfile << "Stdnt Id  Ex  ------- Assignments ---------  Tot  Mi  Fin  CL  Pts  Pct  Gr\n";
		outfile << "--------  --  -----------------------------  ---  --  ---  --  ---  ---  --\n";
		while(!inputfile.eof())
		{
			int total = 0;
			inputfile >> StudentID >> labex;

			outfile << StudentID << "  " << labex << "  ";
			for(int i = 0; i < 10; i++)
			{
				inputfile >> AssignmentPoint[i];
				total += AssignmentPoint[i];
				outfile << AssignmentPoint[i] << " ";
			}
			inputfile >> MidtermPoint;
			outfile << " " << total;
			outfile << "  " << MidtermPoint;
		    inputfile >> FinalPoint;
			inputfile >>CodeLabPoint;
			outfile << "  " << FinalPoint << "   " << CodeLabPoint << " \n";
	}
	}
	else
	{
		cout << "Error!";
	}
	inputfile.close();
}

//funtion to ask user what file to open
void openfile()
{
	ifstream file1, file2, file3;
	int i;
	cout << "Enter the file you want to open\n";
	cout << "Enter 1 or 2 or 3\n";
	cin >> i;
	switch(i)
	{
	case 1:
		file1.open("data1.txt");
		if(file1.is_open())
		{
			cout << "00000000000000";
		}
		else
		{
			cout << "Error!";
		}
		break;
	case 2:
		cout << "gg";
		break;
	case 3:
		cout << "ee";
		break;
	}
}

void offile()
{
	string data = "";
	ofstream file;
	file.open("readout.txt");
	cout << "Enter data: ";
	cin >> data;
	file << data << endl;
}
