///////////////////////////////////////////////////////////////////////////////
// File Name : LeftistNode.cpp												 
// Date : 2015/11/05														 
// Compiler : g++ 4.6.3														 
// Os : ubuntu 12.04.3														 
// Author : Jae Ken Lee														 
// Student ID : 2012722081													 
// --------------------------------------------------------------------------
// ver : 1.0																 
// Description :Please see the detailed description of samenamed headfile	 
// here is for the space to describe how to act these funcs in class
// Etc : Data Structure Assignment #2 (Huffman tree)						 
///////////////////////////////////////////////////////////////////////////////
#include "LeftistNode.h"
#include <iostream>
using namespace std;
LeftistNode::LeftistNode()
{	/*
	LeftistNode::LeftistNode()
	==================================================
	input : void
	otuput : void
	purpose : initialization of 5 ways and other variable in LeftistNode
	*/
	//////////////HuffmanTree////////
	Toparent = NULL;
	H_leftChild = NULL;
	H_rightChild = NULL;
	isleft = true;//isleft value's default is true.
	////////////////////////////////

	//////////////LeftistTree////////
	leftChild = NULL;
	rightChild = NULL;
	shortest = 1;
	////////////////////////////////	
}
LeftistNode::~LeftistNode()
{	/*
	LeftistNode::~LeftistNode
	==================================================
	input : void
	otuput : void
	purpose : destructor, but no exist to need clear or destrucntion
	this had written as standard notation.
	*/
}
void LeftistNode::setData(char letter)
{	/*
	LeftistNode::setData
	==================================================
	input : char letter---> parameter to setting data
	otuput : void
	purpose :setting the data in LeftistNode
	*/
	data = letter;
}
void LeftistNode::setFrequency(int frequency)
{	/*
	LeftistNode::setFrequency
	==================================================
	input : int frequency---> parameter to setting m_frequency what is composed the number
	otuput : void
	purpose :setting the m_frequency in LeftistNode
	*/
	m_frequency = frequency;
}
