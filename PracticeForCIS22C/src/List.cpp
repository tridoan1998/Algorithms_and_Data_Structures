//============================================================================
// Name        : PracticeForCIS22C.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "List.h"

using namespace std;

int main() {
	List<int> L1;
	if(L1.IsEmpty() == true)
	{
		cout << "The list is empty.";
	}
	else
		cout << "The list has element.";
	cout << endl;
	for (int i = 0; i <= 10; i++)
	{
		L1.insertStop(i);
	}
	L1.print();
	cout << endl;
	cout << L1.getStart();
	cout << endl;
	if(L1.IsEmpty() == true)
	{
		cout << "The list is empty.";
	}
	else
		cout << "The list has element.";
	L1.removeStart();
	L1.removeStop();
	cout << endl;
	L1.getIterator();
	cout << endl;
	L1.print();
	return 0;

}
