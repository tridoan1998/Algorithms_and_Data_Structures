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
#include <iomanip>

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
void readfile(string &StudentID, int &labex, int AssignmentPoint[], int &MidtermPoint, int &FinalPoint, int &CodeLabPoint);
string grade(int grade);

//read data to the file
void offile();

void sortarray();


int main() {
	string StudentID = "";
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

void readfile(string &StudentID, int &labex, int AssignmentPoint[], int &MidtermPoint, int &FinalPoint, int &CodeLabPoint)
{
	string line;
	int countA = 0;
	int countB = 0;
	int countC = 0;
	int countD = 0;
	int countF = 0;
	int counter = 0;
	int highest = 0;

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
			int T = 0;
			inputfile >> StudentID >> labex;
			outfile << StudentID << "  " << labex << " ";
			for(int i = 0; i < 10; i++)
			{
				inputfile >> AssignmentPoint[i];
				total += AssignmentPoint[i];
				outfile << setw(3) << AssignmentPoint[i];
			}
			inputfile >> MidtermPoint;
			outfile << setw(5) << total;
			outfile << setw(4) << MidtermPoint;
		    inputfile >> FinalPoint;
			inputfile >>CodeLabPoint;
			T += labex + total + MidtermPoint + FinalPoint + CodeLabPoint;
			outfile << setw(5) << FinalPoint << setw(4) << CodeLabPoint << setw(5) << T;

			if(T >= highest)
			{
				highest = T;
			}
			else
			{

			}

			float divided = (float) T/ (float) 400 * (float) 100;
			outfile << setw(5) << int(divided) << "  " << grade(T) <<endl;

			if(grade(T) == "A+" || grade(T)== "A" ||grade(T)== "A-")
			{
				countA++;
			}
			else if(grade(T) == "B+" || grade(T)== "B" ||grade(T)== "B-")
			{
				countB++;
			}
			else if(grade(T) == "C+" || grade(T)== "C" ||grade(T)== "C-")
			{
				countC++;
			}
			else if(grade(T) == "D+" || grade(T)== "D" ||grade(T)== "D-")
			{
				countD++;
			}
			else
			{
				countF++;
			}
		}
	}
	else
	{
		cout << "Error!";
	}
	inputfile.close();

	ofstream report;
	report.open("summary_report_file.txt");
	if(report.is_open())
	{
		report << "Number of A's = " << countA << endl;
		report << "Number of B's = " << countB << endl;
		report << "Number of C's = " << countC << endl;
		report << "Number of D's = " << countD << endl;
		report << "Number of F's = " << countF << endl << endl;
		report << "Maximum points = " << highest << endl;
	}
	else
	{
		cout << "Error!";
	}
	report.close();
}

string grade(int score)
{

	cout << score << endl;
	string grade = "";
	if( 388 <= score && score <= 400)
	{
		grade = "A+";
	}
	else if(372 <= score && score <= 387)
	{
		grade = "A";
	}
	else if(360 <= score  && score<= 371)
	{
		grade = "A-";
	}
	else if( 348 <= score && score <= 359)
	{
		grade = "B+";
	}
	else if( 332 <= score && score <= 347)
	{
		grade = "B";
	}
	else if( 320 <= score  && score<= 331)
	{
		grade = "B-";
	}
	else if(308 <= score && score <= 319)
	{
		grade = "C+";
	}
	else if(296 <= score && score<= 307)
	{
		grade = "C";
	}
	else if( 284 <= score  && score<=295)
	{
		grade = "C-";
	}
	else if( 272 <= score && score <= 283)
	{
		grade = "D+";
	}
	else if( 260 <= score  && score<= 271)
	{
		grade = "D";
	}
	else if( 248 <= score  && score<= 259)
	{
		grade = "D-";
	}
	else
	{
		grade = "F";
	}
	return grade;
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
