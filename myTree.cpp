#include <iostream>
#include "myTree.h"


void treeInsert(int input, Node * root){
	if(root->value == NULL){
		root->value = input;
		std::cout <<"Inserted " << input << std::endl;
	}
	else{
		if(input < root->value){
			if(root->leftChild == NULL){
				root->leftChild = new Node;
				root->leftChild->value = input;
				std::cout << "leftChild, Inserted " << input << std::endl;
			}
			else{
				std::cout << "leftChild, ";
				treeInsert(input, root->leftChild);
			}			
		}
		else{
			if(root->rightChild == NULL){
				root->rightChild = new Node;
				root->rightChild->value = input;
				std::cout << "rightChild, Inserted " << input << std::endl;
			}
			else{
				std::cout << "rightChild, ";
				treeInsert(input, root->rightChild);
			}			
		}
	}
}

bool treeInOrder(Node * root){
	if(root == NULL){
		return false;
	}
	if(root->leftChild != NULL){
		treeInOrder(root->leftChild);
	}
	std::cout << root->value << std::endl;
	if(root->rightChild != NULL){
		treeInOrder(root->rightChild);
	}
	return true;
}
bool treePreOrder(Node * root){
	if(root == NULL){
		return false;
	}
	std::cout << root->value << std::endl;
	if(root->leftChild != NULL){
		treePreOrder(root->leftChild);
	}	
	if(root->rightChild != NULL){
		treePreOrder(root->rightChild);
	}
	return true;
}
bool treePostOrder(Node * root){
	if(root == NULL){
		return false;
	}
	
	if(root->leftChild != NULL){
		treePostOrder(root->leftChild);
	}	
	if(root->rightChild != NULL){
		treePostOrder(root->rightChild);
	}
	std::cout << root->value << std::endl;
	return true;
}

void deleteTree(Node * root){
	if(root == NULL){
		return;
	}
	
	if(root->leftChild != NULL){
		deleteTree(root->leftChild);
		std::cout << "Deleting " << root->leftChild->value << std::endl;
		delete root->leftChild;
	}	
	if(root->rightChild != NULL){
		deleteTree(root->rightChild);
		std::cout << "Deleting " << root->rightChild->value << std::endl;
		delete root->rightChild;
	}
	std::cout << "Deleted children of " << root->value << std::endl;
	return;	
}