/*
 * HashTable.cpp
 *
 *  Created on: Jan 19, 2018
 *      Author: $$$$$$$$$$$$$$$$$$$$
 */

#include <iostream>
#include <string>
# include <iostream>
# include <cstddef>
# include <string>
# include <assert.h>
# include <algorithm>
#include "BST.h"
#include "Books.h"

using namespace std;

int* test(int* c);

int main()
{
	Book B1;
	Book* N = &B1;
	B1.settitle("rich dad poor dad");
	B1.setauthor("Tri Doan");
	B1.setIDnumber(14124);

	BST<int> T1;
	T1.insert(N);

}



