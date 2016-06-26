///////////////////////////////////////////////////////////////////////////////
// File Name : File.h														 
// Date : 2015/11/05														 
// Compiler : g++ 4.6.3														 
// Os : ubuntu 12.04.3														 
// Author : Jae Ken Lee														 
// Student ID : 2012722081													 
// --------------------------------------------------------------------------
// ver : 1.0																 
// Description : File header is the space for the file class.			     
// in here, file class incode the code from input.txt and decode the original
// character, by using I/O stream variables.								  
// Etc : Data Structure Assignment #2 (Huffman tree)						 
///////////////////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <fstream>
#include "MinLeftistTree.h"
class File
{
private:
	ifstream inputfile;//for reading intput.txt
	ifstream Read_outputfile;//Read_outputfile can be used to read encode.txt
	ofstream outputfile;//for writing encode.txt
	ofstream decodefile;//for writing decode.txt
	MinLeftistTree atree;//File has object of MinLeftistTree named atree.
public:
	File();//constructor
	~File();//destructor
	void read();//This function role is to make encode file and decode file by LeftistTree and HuffmanTree
	void writeCode(string* code, char* str, char* letter);//write code to "encode.txt"
	void readCode(string* code, char* str2, int n, char* letter);//convert to character from encode.txt to "decode.txt"
};

