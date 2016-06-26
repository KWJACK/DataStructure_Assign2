///////////////////////////////////////////////////////////////////////////////
// File Name : MinLeftistTree.cpp											 
// Date : 2015/11/05														 
// Compiler : g++ 4.6.3														 
// Os : ubuntu 12.04.3														 
// Author : Jae Ken Lee														 
// Student ID : 2012722081													 
// --------------------------------------------------------------------------
// ver : 1.0																 
// Description :Please see the detailed description of samenamed headfile.	 
// here is for the space to describe how to act these funcs in class         
// Etc : Data Structure Assignment #2 (Huffman tree)						 
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "MinLeftistTree.h"
#include "LeftistNode.h"
using namespace std;
MinLeftistTree::MinLeftistTree()
{	/*
	MinLeftistTree::MinLeftistTree
	==================================================
	input : void
	otuput : void
	purpose :initialization in MinLeftistTree
	*/
	
	Huffman = NULL;//Huffman is root of Huffmantree
}
MinLeftistTree::~MinLeftistTree()
{	/*
	MinLeftistTree::~MinLeftistTree
	==================================================
	input : void
	otuput : void
	purpose :destructor
	*/
	//but no exist to need clear or destrucntion
	//becaues clear meomory executed by clearMinLeftistTree func already.
	//so this also had written as standard notation like LeftistNode's destructor	
}
LeftistNode* MinLeftistTree::getRoot()
{/*
	MinLeftistTree::getRoot
	==================================================
	input : void
	otuput : LeftistNode*
	purpose :return root's address as LeftistNode*
	*/
	return root;
}
LeftistNode* MinLeftistTree::getposition(int n)
{/*
	MinLeftistTree::getposition
	==================================================
	input : int n--->count of array 
	otuput : LeftistNode*
	purpose :return leaf node's address in huffmantree per n-th
	*/
	return position[n];
}
void MinLeftistTree::setposition(LeftistNode* node, int i)
{/*
	MinLeftistTree::setposition
	==================================================
	input : int i--->count of array
			LeftistNode* node--->in case of this node address
	otuput : void
	purpose :delivery this parameter's node address to array of position per n-th
	*/
	position[i] = node;
}
string* MinLeftistTree::getCode()
{	/*
	MinLeftistTree::getCode
	==================================================
	input : void
	otuput : string*
	purpose :sent the address what array of code to to other class or domain etc.
	*/
	return code;
}
string MinLeftistTree::getCode_n(int n)
{	/*
	MinLeftistTree::getCode_n
	==================================================
	input : int n--->n-th
	otuput : string
	purpose :return leaf encoded data per n-th
	*/
	return code[n];
}
void MinLeftistTree::setRoot()
{	/*
	MinLeftistTree::setRoot
	==================================================
	input : void
	otuput : void
	purpose :making dummy of root
	*/
	root = new LeftistNode;
}
LeftistNode* MinLeftistTree::getHuffman()
{	/*
	MinLeftistTree::getHuffman
	==================================================
	input : void
	otuput : LeftistNode* ---> root of HuffmanTree
	purpose :send root's address
	*/
	return Huffman;
}
void MinLeftistTree::Insert(LeftistNode* newNode)
{	/*
	MinLeftistTree::Insert
	==================================================
	input : LeftistNode* newNode--->new node
	otuput : void
	purpose : insert newNode to MinleftistTree
	*/
	if (root->leftChild == NULL)//Root of LeftistTree is exsisted form as dummy, so should check root's leftchild 
		root->leftChild=newNode;//so, if leftchild of root is NULL, newNode would be new root(but it isn't real root)
	else{//if root exsist, 
		Meld(root->leftChild, newNode);//call meld function
	}
}
LeftistNode* MinLeftistTree::Meld(LeftistNode* a, LeftistNode* b)
{	/*
	MinLeftistTree::Meld
	==================================================
	input : LeftistNode* a--->sub tree from a
			LeftistNode* b--->melded by a
	otuput : LeftistNode* ---> return a's address
	purpose : meld to two Node, exactly saying, insert b to the sub tree strated from a
	*/
	//the parameter a's frequency should be lower than b
	//so, if a's frequency is higer than b's, should excute to swap
	if (b != NULL){
		if (a->m_frequency > b->m_frequency){
			swap(*a, *b);
		}
		else if (a->m_frequency == b->m_frequency){//if both are same, try to compare their data
			if (a->data > b->data){//also a's data is higher than b's, should excute to swap
				swap(*a, *b);
			}
		}
	}
	//in short to explain, meld function is insert to b from a
	if (!a->leftChild) a->leftChild = b;//if a's right child is NULL, insert the node 'b' to a's right child.
	//the reason why insert to right is that Leftist tree is left-sided.
	else {//but a right child is not NULL means both side are full. so insert next subtree:a->rightchild
		a->leftChild = Meld(a->leftChild, b);//
	}
	//after insert b to right side of a, rearrange about leftist tree property
	if (!a->leftChild){//check to whether left side is empty or not
		a->leftChild = a->rightChild;//if left side is empty, shift b node to a's right child
		a->rightChild = NULL;//and should initialization rightchild is null, because a's right was shifted
	}
	if (a->rightChild != NULL && a->leftChild != NULL){//in case of full state of a's child 
		if (a->rightChild->shortest < a->leftChild->shortest){//compare a's shorest for left tree priority whether balnced or not
			swap(*a->rightChild, *a->leftChild);//if current tree is not balanced, swap each a's chlid
		}
	}
	//set shortest data number
	if (!a->leftChild) a->shortest = 1;//if a's right child is NULL, means not full state aspect of a
	else a->shortest = a->leftChild->shortest + 1;//else a is full state(exsist both side), update shortest
	return a;//return a
}
LeftistNode* MinLeftistTree::Pop()
{	/*
	MinLeftistTree::Pop
	==================================================
	input : void	
	otuput : LeftistNode* ---> return address of the node what had pop
	purpose : pop root node in Leftist tree for make huffman tree
	*/
	LeftistNode* pCur = root->leftChild;//start to root's leftchild since root is dummy
	if (pCur->rightChild != NULL){		
		if (pCur->leftChild->m_frequency > pCur->rightChild->m_frequency)//because leftist property, tree should be left-side
			swap(*pCur->leftChild, *pCur->rightChild);//if current tree is not balanced about property of leftist, swap right with left
		else if (pCur->leftChild->m_frequency == pCur->rightChild->m_frequency){//if both's frequency are same, let's consider the data in node
			if (pCur->leftChild->data > pCur->rightChild->data)//rearrange the tree likewise process of insert
				swap(*pCur->leftChild, *pCur->rightChild);
		}
	}	
	if (pCur->leftChild == NULL && pCur->rightChild == NULL){//if both side doesn't exist anymore,
		root = NULL;//dummy node is NULL, because leftistNode is not uesfull ever, for Huffman tree is complete.
		return pCur;//deliver to thet fact that tree is completely exsisted only one element(root) in LeftistTree 
	}
	//connect to root with subtree when end of pop
	root->leftChild = pCur->leftChild;
	Meld(pCur->leftChild, pCur->rightChild);
	//after combine with subtree with root, initialization the two way in LeftistTree
	pCur->leftChild = NULL;
	pCur->rightChild = NULL;
	return pCur;//return pCur<- is element of making huffman tree
}
//
void MinLeftistTree::makeHuffman(char* letter, int n)
{   /*
	MinLeftistTree::makeHuffman
	==================================================
	input : char* letter--->get to array of letter from file class
			int n---> n-th
	otuput : void
	purpose : makehuffman convert to HuffmanTree from Leftistree
	*/
	//for make new node:parent, both first and second node in Lefitisttree should pop about in order priority
	LeftistNode* first = Pop();//the role of pop function is to get a root in LeftistTree
	traveling(first, n, letter);//the role of traveling function is setting the array of position about node's address
	LeftistNode* second = Pop();//get second node in original order
	traveling(second, n, letter);//setting position about the node address likewise first

	LeftistNode* parent = new LeftistNode;//create new a space about parent
	//compose data and frequency for making parent
	parent->data = first->data + second->data; 
	parent->m_frequency = first->m_frequency + second->m_frequency;
	//setting way in HuffmanTree
	parent->H_leftChild = first;//left should be first, because of the element from priority queue.
	parent->H_rightChild = second;//Likewise, right should be second
	parent->H_rightChild->isleft = false;//isleft mean that where is located by aspect of partent. false means right
	if (root != NULL){//if root is exsist, insert to parent to the LeftistTree.
		Meld(root->leftChild, parent);
	}
	else{
		Huffman = parent;//if root is not exsist anymore, it means huffman tree was complete. so declare to root of HuffmanTree
	}	
}
void MinLeftistTree::setTree(MinLeftistTree root, char* letter, int* frequency, int n)
{	/*
	MinLeftistTree::setTree
	==================================================
	input : MinLeftistTree root--->tell where to setting tree
			char* letter---> per letter in array, declare new node
			int* frequency ---> likewise letter, this will be used to make node as data : m_frequency
			int n---> n-th
	otuput : void
	purpose : setting LeftistTree by using parameters
	*/	
	for (int i = 0; i < n; i++){//As the number of leftter, create new node and then insert to LeftistTree
		//make newNode via letter and frequency
		LeftistNode* newNode = new LeftistNode;
		newNode->data = letter[i];
		newNode->m_frequency = frequency[i];
		root.Insert(newNode);
	}
	LeftistNode* pCur = root.getRoot();//insert function have Meld function at inner
	pCur = pCur->leftChild;
}
void MinLeftistTree::traveling(LeftistNode* ptr, int n, char* letter)
{	/*
	MinLeftistTree::traveling
	==================================================
	input : LeftistNode* ptr--->starting point
			char* letter--->offer the data that ptr could find order among letter
			int n---> the count array
	otuput : void
	purpose : setting the array of position inorder of letter
	*/
	if (ptr->data.length() == 1){//this purpose is to distinguish the letter
		int i = 0;
		while (1){//till find the node what have ptr's address among array of position
			const char* temp = ptr->data.c_str();//convert variable style from string to char
			if (*temp == letter[i]){//check to matching temp's data among array of letter
				setposition(ptr, i);//setting leaf's address to array of position
				break;//if this data in temp had been checked, promptly escape loop
			}
			i++;//try to next index
		}//while
	}//if(whether ptr's data is one or not)
}

void MinLeftistTree::setcode(int n)
{	/*
	MinLeftistTree::setcode
	==================================================
	input :	int n---> the count array
	otuput : void
	purpose : setting array of code about letter, about leaf node
	*/
	string one = "1";
	string zero = "0";	
	LeftistNode* pCur = NULL;
	for (int i = 0; i < n; i++){//till end of array of position
		pCur = position[i];//get a address of the i-th position
		while (1){
			if (pCur->isleft == true){
				code[i] = zero + code[i];// "0" + "code"
			}
			else{
				code[i] = one + code[i];// "1' + "code"
			}
			pCur = pCur->Toparent;
			if (pCur == Huffman){//synthetic the code til reach to the root, 
				break;
			}			
		}//while(1)
	}//for
}

void MinLeftistTree::setParent(LeftistNode* ptr)
{	/*
	MinLeftistTree::setParent
	==================================================
	input : LeftistNode* ptr--->parent node : ptr
	otuput : void
	purpose : setting toparent way about ptr's H_leftChild and H_rightChild
	*/
	LeftistNode* before = ptr;
	if (Huffman->H_leftChild != NULL){//setting ptr's H_leftChild
		ptr = Huffman->H_leftChild;
		ptr->Toparent = before;
		inorder(ptr, before);//by manner of inorder setting toparent
	}
	if (Huffman->H_rightChild != NULL){//setting ptr's H_rightChild
		ptr = Huffman->H_rightChild;
		ptr->Toparent = before;
		inorder(ptr, before);//by manner of inorder setting toparent
	}
}
void MinLeftistTree::inorder(LeftistNode* pCur, LeftistNode* pBefore)
{	/*
	MinLeftistTree::inorder
	==================================================
	input : LeftistNode* ptr--->parent node : ptr
	otuput : void
	purpose : setting toparent way about ptr's H_leftChild and H_rightChild
	*/
	if (pCur->H_leftChild != NULL)
		inorder(pCur->H_leftChild, pCur);

	pCur->Toparent = pBefore;//setting toparent

	if (pCur->H_rightChild != NULL)
		inorder(pCur->H_rightChild, pCur);
}
void MinLeftistTree::clearMinLeftistTree(int n)
{	/*
	MinLeftistTree::clearMinLeftistTree
	==================================================
	input : int n--->delivery how to reapeatition
	otuput : void
	purpose : clear all data in MinLeftistTree, for new encoding and decoding about next sentence
	*/
	for (int i = 0; i < n; i++){
		code[i] = "";//initialization all aboout string variables in array
		position[i] = NULL;//clear all data
	}
	postorder(Huffman);//by manner of postorder, clear all node's space
	Huffman = NULL;//HuffmanTree was cleard so root should be null
}
void MinLeftistTree::postorder(LeftistNode* pCur)
{	/*
	MinLeftistTree::postorder
	==================================================
	input : LeftistNode* pCur--->parent node : ptr
	otuput : void
	purpose : setting toparent way about ptr's H_leftChild and H_rightChild
	*/
	if (pCur->H_leftChild != NULL)
		postorder(pCur->H_leftChild);
	if (pCur->H_rightChild != NULL)
		postorder(pCur->H_rightChild);
	delete pCur;//clear memory
}