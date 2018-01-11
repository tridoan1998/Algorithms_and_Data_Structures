/*
 * List.h
 *
 *  Created on: Dec 15, 2017
 *      Author: $$$$$$$$$$$$$$$$$$$$
 */

#ifndef LIST_H_
#define LIST_H_

# include <cstddef> //for NULL
# include <assert.h>
# include <iostream>

using namespace std;

template <class listdata>
class List
{
private:
	struct Node
	{
		Node* linkprevious;
		Node* linknext;
		listdata data;
		Node(listdata ndata)
		{
			data = ndata;
			linkprevious = NULL;
			linknext = NULL;
		}
	};
	Node* start;
	Node* stop;
	Node* iterator;
	int size;


public:

	List();
	~List();
	listdata insertStart(listdata data);
	listdata insertStop(listdata data);
	listdata removeStart();
	listdata removeStop();
	listdata getIterator();
	listdata advangeIterator();
	int getSize();
	bool off_end();
};



#endif /* LIST_H_ */
