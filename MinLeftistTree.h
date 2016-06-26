///////////////////////////////////////////////////////////////////////////////
// File Name : MinLeftistTree.h												 
// Date : 2015/11/05														 
// Compiler : g++ 4.6.3														 
// Os : ubuntu 12.04.3														 
// Author : Jae Ken Lee														 
// Student ID : 2012722081													 
// --------------------------------------------------------------------------
// ver : 1.0																 
// Description :After completion of the LeftistTree, it will be changed		 
// gradually HoffmanTree. so both two root exsist repectively in this clas.	 
// and MinleftistTree is friend with LeftistNode, so use all func or data    
// in leftistNode regardless of one the domain.								 
// this class is included to File class. one File class variable always has  
// MinleftistTree.															 
// Etc : Data Structure Assignment #2 (Huffman tree)						 
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include "LeftistNode.h"
class MinLeftistTree{
private:	
	LeftistNode* root;//This is for LeftistTree
	LeftistNode* Huffman;//This is for HuffmanTree
	LeftistNode* position[60];//position has the address of each among leaves only to fit on letter.
	string code[60];//Each of the encoded code is stored in the order of their arrangement by letter.
	void inorder(LeftistNode* pCur, LeftistNode* pBefore);//This role is setting to parent the node in Huffman tree as manner of inorder circult
	void postorder(LeftistNode* pCur);//clear humman
public:
	MinLeftistTree();// constructor
	~MinLeftistTree();// destructor
	void Insert(LeftistNode* newNode);//Insert newNode to LeftistTree
	LeftistNode* Meld(LeftistNode* a, LeftistNode* b);//Meld a to b, b should had high frequency or character than a
	LeftistNode* Pop();//pop function role is that deletion root in HuffmanTree and deliver it as element for making HuffmanTree. 
	void traveling(LeftistNode* ptr, int n, char* letter);//traveling function has inorder inner. this purpose is setting the arry, position.
	void makeHuffman(char* letter, int n);//HuffmanTree will be made by pop, Meld function.
	void clearMinLeftistTree(int n);//clear all data in this tree and other variable like code, postion etc..	

	LeftistNode* getRoot();//get Leftist's root
	LeftistNode* getposition(int n);//get the position to suit on 'n'
	LeftistNode* getHuffman();//get Huffman's root
	string* getCode();//get the code array, for using other class or domain
	string getCode_n(int n);
	
	void setTree(MinLeftistTree root, char* letter, int* frequency, int n);//set LeftistTree by using Insert func;
	void setposition(LeftistNode* node, int i);//setting position about its parameter:node
	void setcode(int n);//making encode to suit on n-th character
	void setParent(LeftistNode* ptr);//setting Toparent way for HuffmanTree.
	void setRoot();//This make dummy root	
};