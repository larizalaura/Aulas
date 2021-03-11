#include <string.h>
#include <iostream>     // std::cout, std::endl
#include <iomanip>      // std::setw

#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree() {
	root = NULL;  //aterrando a raiz
}
BinaryTree::~BinaryTree() {
	root = NULL;  
}


void BinaryTree::Print(){
	BinaryTree::Print(root,0);
}

void BinaryTree::Print(TreePointer &t, int s){
	int i;
	if(t != NULL){ 
		Print(t->RightNode, s+3);

		for(i=1; i<=s; i++)
			cout << " ";
		// espaços
		cout << setw(6) << t->Elemento << endl;
		Print(t->LeftNode, s+3);
	}
}
void BinaryTree::DelMin(TreePointer &q, TreePointer &r){
	if(r->LeftNode != NULL)
		DelMin(q,r->LeftNode);
	else{ 
		q->Elemento = r->Elemento;
		q = r;
		r = r->RightNode;
	}
}

void BinaryTree::Delete(int x){
	Delete(x,root);
}
void BinaryTree::Delete(int x, TreePointer &p){ 
	cout<< "meu x eh: "<<x<<endl;
	TreePointer q;
	if(p == NULL){
		cout << "Elemento inexistente";  
		abort();
	}
	if(x < p->Elemento){  
		Delete(x,p->LeftNode); // recursivamente
		cout<< " x eh menor, procure na esquerda"<< endl;
	}
	else{
		if(x > p->Elemento){
			cout<< " x eh maior, procure na direita"<< endl;

			Delete(x,p->RightNode); //recursivamente
		}else{ //  encontrei quem eu quero deletar
			q = p;
			if(q->RightNode == NULL)  
				p = q->LeftNode;
			else
			if(q->LeftNode == NULL)  
				p = q->RightNode;
			else
				DelMin(q,q->RightNode);  
			delete q;
		}
	}
}

void BinaryTree::SearchInsert(int x){ // publica
	SearchInsert(x,root);
}

void BinaryTree::SearchInsert(int x, TreePointer &t){ //privada
	// x eh o valor que queremos inserir e t eh um ponteiro pra arvore
	if(t == NULL){
 		t = new TreeNode;
		t->Elemento = x;
		t->count = 1;
		t->LeftNode = t->RightNode = NULL;
	}
	else
		if(x < t->Elemento) // procurar x na subárvore esquerda
			SearchInsert(x,t->LeftNode);
		else
			if(x > t->Elemento) // procurar x na subárvore direita
				SearchInsert(x,t->RightNode);
			else // x encontrado, atualizar contador
				t->count++;
}


