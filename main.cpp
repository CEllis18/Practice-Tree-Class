#include <iostream>
#include <list>
#include <vector>
#include "myTree.h"

void buildLevel(std::vector<std::list<Node *>> * levelList,int curLevel,Node * root);

int main(){
	std::cout << "Program Start" << std::endl;
	Node root;
	Node * rootPtr = &root;
	treeInsert(16,rootPtr);
	treeInsert(20,rootPtr);
	treeInsert(2,rootPtr);
	treeInsert(45,rootPtr);
	treeInsert(15,rootPtr);
	treeInsert(77,rootPtr);
	treeInsert(55,rootPtr);
	treeInsert(25,rootPtr);
	treeInsert(1,rootPtr);
	std::cout << "In order traversal" << std::endl;
	treeInOrder(rootPtr);
	std::cout << "PreOrder Traversal" << std::endl;
	treePreOrder(rootPtr);
	std::cout << "PostOrder Traversal" << std::endl;
	treePostOrder(rootPtr);
	std::cout << std::endl;
	
	
	//want to make an list of each level
	std::vector<std::list<Node*>> levels;
	levels.resize(30);
	std::vector<std::list<Node*>> *levelPTR = &levels;
	buildLevel(levelPTR,0,rootPtr);
	
	for(int x = 0; x < levels.size();x++){
		std::list<Node*>::iterator itr = levels[x].begin();
		if(itr == levels[x].end()) break;
		std::cout << "Level " << x << " contents" << std::endl;
		while(itr != levels[x].end()){
			std::cout << (*itr)->value << ", ";
			itr++;
		}
		std::cout << std::endl;
	}
	
	
	deleteTree(rootPtr);
	return 0;
}

void buildLevel(std::vector<std::list<Node *>> *levelList,int curLevel,Node * root){
	//std::cout << "root->value = " << root->value << std::endl;
	if(root == NULL) return;
	if(root->leftChild != NULL){
		buildLevel(levelList,curLevel+1,root->leftChild);
	}
	//std::cout << "CurLevel = " << curLevel << std::endl;
	//std::cout << "root->value = " << root->value << std::endl;
	//Node * curNode = &(*root);
	(*levelList)[curLevel].push_front(root);
	//std::cout << "CurLevel = " << curLevel << std::endl;
	if(root->rightChild != NULL){
		buildLevel(levelList,curLevel+1,root->rightChild);
	}
	return;
}