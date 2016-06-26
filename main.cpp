//////////////////////////////////////////////////////////////////////////////
// File Name : Main.cpp														 
// Date : 2015/11/05														 
// Compiler : g++ 4.6.3														 
// Os : ubuntu 12.04.3														 
// Author : Jae Ken Lee														 
// Student ID : 2012722081													 
// --------------------------------------------------------------------------
// ver : 1.0																 
// Description :in here, Program enable to declare file object named my file.
// and then read the input file using read function,in File class for incoing
// as manner of huffman algorithm											 
// Etc : Data Structure Assignment #2 (Huffman tree)						 
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include "File.h"
int main(){	
	File myfile;//declare File object myfile
	cout << "=letter=freqeucny==code" << endl;
	myfile.read();//execute read function

	return 0;
}