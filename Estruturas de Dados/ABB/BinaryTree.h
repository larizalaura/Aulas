#include <iostream>
#include <string>

using namespace std;

#ifndef BinaryTree_H
#define BinaryTree_H


class BinaryTree {


	public:
		BinaryTree();
		~BinaryTree();
		void Insert(int x);
		void Delete(int x);
		void SearchInsert(int x);
		void Print();
	
	private:

		struct TreeNode // um no da minha ABB
		{ 
			int Elemento;// tipo de dado colocado na árvore
			int count;
			TreeNode *LeftNode, *RightNode; // subárvores
		};
		typedef TreeNode *TreePointer;
		// declaração de campos
		
		TreePointer root;

		void SearchInsert(int x, TreePointer &t);
		void Delete(int x, TreePointer &p);
		void Print(TreePointer &t, int s);
		void DelMin(TreePointer &q, TreePointer &r);

};

#endif
