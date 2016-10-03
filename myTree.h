#ifndef MYTREE_H
#define MYTREE_H

#include <iostream>

struct Node{
	public:
		Node * leftChild = NULL;
		Node * rightChild = NULL;
		int value = NULL;
};


		void treeInsert(int input, Node * root);
		bool treeInOrder(Node * root);
		bool treePreOrder(Node * root);
		bool treePostOrder(Node * root);
		void deleteTree(Node * root);





#endif