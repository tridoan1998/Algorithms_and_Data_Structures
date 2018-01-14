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
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "List.h"

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
	listdata getStart() const;
	void insertStart(listdata data);
	void insertStop(listdata data);
	bool IsEmpty() const;
	void removeStart();
	void removeStop();
	listdata getIterator();
	listdata advangeIterator();
	int getSize();
	bool off_end();
	void print();

};
template <class listdata>
listdata List<listdata>::getIterator()
{
	assert(!off_end());
	return iterator->data;
}
template <class listdata>
List<listdata>::List()
{
	start = NULL;
	stop = NULL;
	iterator = NULL;
	size = 0;
}

template <class listdata>
List<listdata>::~List()
{
	Node* a = start;
	Node* b = NULL;
	while(a !=NULL)
	{
		b = a->linknext;
		delete a;
		a = b;
	}
}

template <class listdata>
bool List<listdata>::off_end()
{
	if(iterator == NULL)
		return true;
	else
		return false;
}

template <class listdata>
bool List<listdata>::IsEmpty() const
{
	return size == 0;
}
template <class listdata>
listdata List<listdata>::getStart() const
{
	assert(!IsEmpty());
	return start->data;
}

template <class listdata>
void List<listdata>::insertStart(listdata data)
{
	Node* N = new Node(data);
	if(size == 0)
	{
		start = stop = N;
		size++;
	}
	else
	{
		N->linknext = start;
		start->linkprevious = N;
		start = N;
		size++;
	}
}

template <class listdata>
void List<listdata>::insertStop(listdata data)
{
	Node* N = new Node(data);
	if(size == 0)
	{
		stop = start = N;
	}
	else
	{
		N->linkprevious = stop;
		stop->linknext = N;
		stop = N;
	}
	size++;
}

template <class listdata>
void List<listdata>::removeStart()
{
	assert(!IsEmpty());
	if(size == 1)
	{
		delete start;
		start = stop = NULL;
	}
	else
	{
		Node* temp = start;
		start = start->linknext;
		start->linkprevious = NULL;
		delete temp;
	}
	size--;
}

template <class listdata>
void List<listdata>::removeStop()
{
	assert(!IsEmpty());
	if(size == 1)
	{
		delete stop;
		start = stop = NULL;
	}
	else
	{
		Node* temp = stop;
		stop = stop->linkprevious;
		stop->linknext = NULL;
		delete temp;
	}
	size--;
}

template <class listdata>
void List<listdata>::print()
{
	Node* temp = start;
	while(temp->linknext != NULL)
	{
		cout << temp->data << " ";
		temp = temp->linknext;
	}
}
#endif /* LIST_H_ */
