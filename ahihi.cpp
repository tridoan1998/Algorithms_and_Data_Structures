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

//choose files to open
void openfile();

int main() {
	ifstream myfile;
	string askforfilename;
	string name;
	int id;
	int score;

	myfile.open("text.txt");
	if(myfile.is_open())
	{
		cout << "good";
		openfile();
	}
	else
	{
		cout << "Error";
	}
	return 0;
}

void openfile()
{
	int i;
	cout << "Enter the file you want to open\n";
	cout << "Enter 1 or 2 or 3\n";
	cin >> i;
	switch(i)
	{
	case 1:
		;
		break;
	case 2:
		cout << "gg";
		break;
	case 3:
		cout << "ee";
		break;
	}
}
