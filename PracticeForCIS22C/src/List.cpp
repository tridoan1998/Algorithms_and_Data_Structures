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
	Array l;
	l.add(3);
	l.wrap(3);
	cout << l.here();
	return 0;
}
