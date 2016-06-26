///////////////////////////////////////////////////////////////////////////////
// File Name : LeftistNode.h												 
// Date : 2015/11/05														 
// Compiler : g++ 4.6.3														 
// Os : ubuntu 12.04.3														 
// Author : Jae Ken Lee														 
// Student ID : 2012722081													 
// --------------------------------------------------------------------------
// ver : 1.0																 
// Description :This Node class is composed to data part and pointer part in 
// private and functions located in public domain.							 
//  LeftistNode has two kind of ways what composed leftistTree or Huffmantree
// In case of huffmanTree, this node should have the way ascending to parent.
//  To satisfy the balance of leftistTree, this node has special variable,   
// named "shortest".														 
// Etc : Data Structure Assignment #2 (Huffman tree)						 
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
using namespace std;
//LeftistNode has five connection ways as a total.
//Two ways are related LeftistTree, other three ways are related HuffmanTree.

class LeftistNode {
	friend class MinLeftistTree;//friend class use all variable or function regardless of its domain 
private:
	//for LeftistTree
	//Node has two way about LeftistTree, leftchild and rightchild respectively
	LeftistNode* leftChild;
	LeftistNode* rightChild;
	int shortest;//shortest means either the more unbalanced aspect of parent node

	//for Huffman tree
	//Node has three way about HuffmanTree, Toparent, H_leftchild and H_rightchild respectively.
	LeftistNode* Toparent;//The way is Toparent what connected from child node to parent node
	LeftistNode* H_leftChild;
	LeftistNode* H_rightChild;
	bool isleft;//True means that Node is located left side aspect of Node's parent, false is contrary to true.
	
	//common value(LeftistTree and HuffmanTree)
	string data;//This is the letter that Node has
	int m_frequency;//frequency is related to each of characters about the sentence in inputfile
public:
	LeftistNode();//constructor
	~LeftistNode();//destructor
	void setData(char letter);//set string variable named data
	void setFrequency(int frequency);//set frequency of individual character
};
