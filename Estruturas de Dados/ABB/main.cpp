#include <iostream>
#include "BinaryTree.h"


using namespace std;


int main(int argc, char *argv[]) {

	BinaryTree TreeTeste = BinaryTree();

	TreeTeste.SearchInsert(10);
	TreeTeste.SearchInsert(5);
	TreeTeste.SearchInsert(15);
	TreeTeste.SearchInsert(6);
	TreeTeste.SearchInsert(4);
	TreeTeste.SearchInsert(7);
	TreeTeste.SearchInsert(7);
	TreeTeste.SearchInsert(7);
	TreeTeste.SearchInsert(7);
	TreeTeste.SearchInsert(7);
	TreeTeste.SearchInsert(7);
	TreeTeste.Print();
	//cout<<"-----------------"<<endl;
	//TreeTeste.Delete(5);
	//TreeTeste.Print();

}
