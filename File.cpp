///////////////////////////////////////////////////////////////////////////////
// File Name : File.cpp														 
// Date : 2015/11/05														 
// Compiler : g++ 4.6.3														 
// Os : ubuntu 12.04.3														 
// Author : Jae Ken Lee														 
// Student ID : 2012722081													 
// --------------------------------------------------------------------------
// ver : 1.0																 
// Description : Please see the detailed description of samenamed headfile.	  
// here is for the space to describe how to act these funcs in class         
// Etc : Data Structure Assignment #2 (Huffman tree)						 
///////////////////////////////////////////////////////////////////////////////
#include "File.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

File::File()
{	/*
	File::File
	==================================================
	input : void
	otuput : void
	purpose : manage the open files as like appendix mode or outmode(clear before existed In some cases) 
	*/
	inputfile.open("input.txt");//open the "input.txt" for reading sentences

	//outputfile read the sentence and then, convert the code by each sentence
	outputfile.open("encode.txt", ios::out);//this command mean that to write newly the file called 'encode.txt', 
	//even it had existed the old file smae with name of new file
	//In short, clear the outputfile before start to write new version of outputfile.
	outputfile.close();//and then close the file, this file would be written nothing
	outputfile.open("encode.txt", ios::app);//open appendix mode

	//decodefile is same with outputfile.
	//decodefile read the code in "decode.txt" and convert to the character to suit on encoded code
	decodefile.open("decode.txt", ios::out);
	decodefile.close();
	decodefile.open("decode.txt", ios::app);
	Read_outputfile.open("encode.txt", ios::app);////open the "encode.txt" for reading code in there
}


File::~File()
{	/*
	File::~File
	==================================================
	input : void
	otuput : void
	purpose :close all of file
	*/	
	inputfile.close();
	outputfile.close();
	Read_outputfile.close();
}
void File::read()
{	/*
	File::read
	==================================================
	input : void
	otuput : void
	purpose : All of executions would be managed in here, for make code from inputfile.
	and convert to original letters or sentence.
	*/
	if (inputfile.is_open() == false){//check to the file name. if it doesn't exist, print the msg "fail" on computer screen"
		cout << "Need to check the file name" << endl;
	}
	else{
		while (!inputfile.eof()){
			atree.setRoot();
			//initializtion str, letter, frequency, length, n for next sentence in input file
			char str[256] = { 0 };//str variable is used to store characthers about one sentence in inputfile
			char letter[60] = { 0 };//Each character in one sentence are stored in letter array
			int frequency[60] = { 0 };//Each frequency is stored in the order of the letter array
			int length = 0;//length variable is about the length of a sentence
			int i = 0, j = 0, n = 1;//n means the number of each characters
			
			inputfile.getline(str, 256, '\n');//read up to 256
			cout << str << endl;
			if (str[0] == '\0'){
				continue;
			}
			letter[0] = str[0];//First character should directly store to letter array without having to check
			frequency[0] = 1;//also same reason, first word has one frequency

			length = strnlen_s(str, 256);//measurement a sentence length
			for (i = 1; i < length; i++){//the sentence is converted letter and code one by one til i is smae with length
				//the reason why start to i=1 is that 1st letter already set before
				j = 0;//initialization j=0. j is for checking this character to suit on letter
				while (letter[j] != NULL){//til the end of the array of letter, find the suitable character in letter
					if (str[i] == letter[j]){//when find suitable charcter in array of letter,
						frequency[j]++;//add one to this character's frequency 
						break;//Because it achieve the aim, shift to the following characters in str
					}
					j++;//shifting for next character in array of letter
					if (letter[j] == NULL){//if it have not found the characters to fit on the letter, 
						letter[n] = str[i];// adding a new character
						frequency[n] = 1;//and new character's frequency is one
						n = n + 1;//add one the the number of all characters
						break;// shift to the following characters in str
					}
				}//while
			}//for
			atree.setTree(atree, letter, frequency, n);//creation LeftistTree
			while (atree.getHuffman() == NULL){
			//The reason the getting Huffmans's root functhion keep the state:NULL is that  
			//the Hoffman root should be determined when configuring the perfect tree.
				atree.makeHuffman(letter, n);//making HuffmanTree the manner of pop by two nodes in LeftistTree
			}
			atree.setParent(atree.getHuffman());//setting the way to paraent node in each all of node in HuffmanTree
			atree.setcode(n);//setting array to encoded code.
			
			for (int i = 0; i < n; i++){//for console window
				cout << letter[i] << " : " << frequency[i] << " : " <<atree.getCode_n(i) << endl;
			}
			cout << "===========================================================================" << endl;
			writeCode(atree.getCode(), str, letter);///write to encode.txt by using array of code. The array of code is located in atree, so 
			char str2[256] = { 0 };//initialization str2, the array is for storing the encoded code
			Read_outputfile.getline(str2, 256, '\n');//read up to 256

			readCode(atree.getCode(), str2, n, letter);//write decode to decode.txt after reading code in encode.txt
			
			atree.clearMinLeftistTree(n);//clear all data of atree for next a sentence in inputfile
			
		}//while
	}//else(file read or not)
}//read()
void File::writeCode(string* code, char* str, char* letter)
{	/*
	File::writeCode
	==================================================
	input : string* code--->Array of code, this propose how to convert the str as code
			char* str --->inputfile's data
			char* letter--->Array of letter, this decide to make new letter or not about str
	otuput : void
	purpose : write code from encoded inputfile to "encode.txt"
	*/
	int i = 0;
	while (str[i] != NULL){//up to end of str
		int j = 0;//the role of variable "j" is for repetition letter array to keep finding to suit on character in array of letter  
		while (letter[j] != NULL){ //so, til end of array of letter
			if (str[i] == letter[j]){//if it find the character(str) to suit on letter, 				
				//cout << letter[j];
				outputfile << code[j];//write the code to suitable with order of letter  
				break;// because of achievement the aim, shift to the following characters in str
			}
			j++;//for go to next letter in array
		}//while(letter)
		i++;//for next character in str
	}//while(str)
	outputfile << endl;//all of process what write code are over, this line division need to distinguish other sentence's code
}

void File::readCode(string* code, char* str2, int n, char* letter)
{	/*
	File::writeCode
	==================================================
	input : string* code--->Array of code, this would be used matching array of code with str2
	char* str2 --->inputfile(incoded file)'s data
	int n---> length of array the letter, this will be used  number of repetition in loop
	char* letter--->Array of letter, this will be writed to decodefile per matching code
	otuput : void
	purpose : write decoded character from "encode.txt" to "decode.txt"
	*/
	string temp;//this variable is need to find the suitable letter with temporary code.
	//temporary code will be kept changing til finding suitable letter
	int i = 0;//The role of this variable is that for reaching to the end of array of str2 
	temp = temp + str2[i];
	while (str2[i] != NULL){//til end of array of str2
		for (int j = 0; j < n; j++){//keep repetite the finding process on the code range. 
			if (temp == code[j]){//if temporay code suit with one among array of code,
				//cout << letter[j];
				decodefile << letter[j];//write decoded character to "decode.txt"
				temp.clear();//clear temp variable
				break;//after acheievement aim, escape in here for finding next writing the suitable character 
			}			
		}//for
		i++;//shift the next code in str2
		temp = temp + str2[i];//because of initiallzation, make new temp code 
	}
	decodefile << endl;//all of process what write character are over, this line division need to distinguish other sentence's character 
}