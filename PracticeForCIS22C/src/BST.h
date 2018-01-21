/*
 * BST.h
 *
 *  Created on: Jan 18, 2018
 *      Author: $$$$$$$$$$$$$$$$$$$$
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <string>

# include <iostream>
# include <cstddef>
# include <string>
# include <assert.h>
# include <algorithm>

using namespace std;

template <typename bstdata>
class BST
{
private:
	struct Node
	{
		bstdata data;
		Node* leftchild;
		Node* rightchild;
		Node (bstdata newdata)
		{
			data = newdata;
			leftchild = rightchild = NULL;
		}

	};
	Node* root;

    /**Private helper functions*/
    void insertNode(Node* root, bstdata data);
    //private helper function for insert
    //recursively inserts a value into the BST

    void inOrderPrint(ostream& out, Node* root) const;
    //private helper function for inOrderPrint
    //recursively prints tree values in order from smallest to largest

    void preOrderPrint(ostream& out, Node* root) const;
    //private helper function for preOrderPrint
    //recursively prints tree values in pre order

    void postOrderPrint(ostream& out, Node* root) const;
    //private helper function for postOrderPrint
    //recursively prints tree values in post order

    void copyNode(Node* copy);
    //recursive helper function to the copy constructor

    void freeNode(Node* root);
    //private helper function for the destructor
    //recursively frees the memory in the BST

    bool searchNode(Node* root, bstdata data) const;
    //recursive helper function to search
    //returns whether the value is found in the tree

    bstdata minimum(Node* root) const;
    //recursive helper function to minimum
    //returns the minimum value in the tree

    bstdata maximum(Node* root) const;
    //recursive helper function to maximum
    //returns the maximum value in the tree

    Node* deleteNode(Node* root, bstdata data);
    //recursive helper function to remove
    //removes data from the tree

    void getSize(Node* root, int& size) const;
    //recursive helper function to the size function
    //calculates the size of the tree
    //stores the result in size

    int getHeight(Node* root) const;
    //recursive helper function to the height function
    //returns the height of the tree

public:



    /**constructors and destructor*/

    BST();
    //Instantiates a new BST

    BST(const BST &bst);
    //copy constructor

    ~BST();
    //deallocates the tree memory




    /**access functions*/

    bstdata minimum() const;
    //returns the minimum value in the BST
    //pre: !empty()

    bstdata maximum() const;
    //returns the maximum value in the BST
    //pre: !empty()

    bool isEmpty() const;
    //determines whether the BST is empty

    int getSize() const;
    //returns the size of the tree

    bstdata getRoot() const;
    //returns the value stored at the root of the BST
    //pre: !isEmpty()

    int getHeight() const;
    //returns the height of the tree

    bool search(bstdata data) const;
    //returns whether the data is found in the tree
    //pre: !isEmpty()



    /**manipulation procedures*/

    void insert(bstdata data);
    //inserts new data into the BST

    void remove(bstdata data);
    //removes the specified value from the tree
    //pre: data is located in the tree
    //pre: !isEmpty()

    /**additional functions*/

    void inOrderPrint(ostream& out) const;
    //calls the inOrderPrint function to print out the values
    //stored in the BST

    void preOrderPrint(ostream& out) const;
    //calls the reOrderPrint function to print out the values
    //stored in the BST

    void postOrderPrint(ostream& out) const;
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};


template <typename bstdata>
BST<bstdata>::BST()
{
	root = NULL;
}

template <typename bstdata>
BST<bstdata>::~BST()
{
    freeNode(root);

}

template <typename bstdata>
void BST<bstdata>::freeNode(Node* root)
{
	if(root == NULL)
		return;
	else
	{
		freeNode(root->leftchild);
		freeNode(root->rightchild);
		delete root;
	}
}

template <typename bstdata>
BST<bstdata>::BST(const BST &bst)
{
	if(bst.root == NULL)
		root = NULL;
	else
		copyNode(bst.root);
}

template <typename bstdata>
void BST<bstdata>::copyNode(Node* copy)
{
	if(copy == NULL)
		return;
	else
	{
		insert(copy->data);
		copyNode(copy->leftchild);
		copyNode(copy->rightchild);
	}
}


template <typename bstdata>
void BST<bstdata>::insert(bstdata data)
{
	if(root == NULL)
		root = new Node(data);
	else
		insertNode(root, data);
}
template <typename bstdata>
void BST<bstdata>::insertNode(Node* root, bstdata data)
{
	if(root->data == data)
		return;
	else
		if(root->data > data)
			if(root-> leftchild == NULL)
				root->leftchild = new Node(data);
			else
				insertNode(root->leftchild, data);
		else
			if(root->rightchild == NULL)
				root->rightchild = new Node(data);
			else
				insertNode(root->rightchild, data);
}

template <typename bstdata>
void BST<bstdata>::inOrderPrint(ostream& out) const
{
	inOrderPrint(out, root);
	cout << endl;
}


template <typename bstdata>
void BST<bstdata>::inOrderPrint(ostream& out, Node* root) const
{
	if(root == NULL)
		return;
	else
	{
		inOrderPrint(out, root->leftchild);
		cout << root->data << endl;
		inOrderPrint(out, root->rightchild);
	}
}

#endif /* BST_H_ */
