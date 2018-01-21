/*
 * Books.h
 *
 *  Created on: Jan 14, 2018
 *      Author: $$$$$$$$$$$$$$$$$$$$
 */

#ifndef BOOKS_H_
#define BOOKS_H_

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
	string title;
	string author;
	int IDnumber;


public:
	void settitle(string stitle);
	void setauthor(string aauthor);
	void setIDnumber(int id);

	string gettitle();
	string getauthor();
	int getIDnumber();

};

void Book::settitle(string stitle)
{
	title = stitle;
}

void Book::setauthor(string aauthor)
{
	author =  aauthor;
}

void Book::setIDnumber(int id)
{
	IDnumber = id;
}

string Book::gettitle()
{
	return title;
}

string Book::getauthor()
{
	return author;
}

int Book::getIDnumber()
{
	return IDnumber;
}


#endif /* BOOKS_H_ */
