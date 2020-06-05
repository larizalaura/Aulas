// Pilha.cpp
// Esta pilha é implementada apartir do modelo dinâmico

#include <iostream>
#include "Stack.h"
#include <fstream>
using namespace std;

// Criador de Pilha
Stack::Stack()
{
  top = NULL;
  count = 0;
}

// Verificador de ausencia de elementos
bool Stack::Empty()
{
  return( top == NULL );          // Verifica se top esta aterrado;
}

// Verificador de quantidade cheia
bool Stack::Full()
{
  // Para o modelo dinâmico, só estará cheio se não possuir mais memoria
  //disponível no computador, desde então será falso;
  return( false );
}

// Adiciona elemento x no topo da Pilha
void Stack::Push(StackEntry x)
{
  StackPointer p;                   // Ponteiro para StackNode;

  p = new StackNode;                // Criar novo StackNode;

  // Verifica se memória é insuficiente, caso verdade aborta missão;
  if (p == NULL)
  {  cout << " Memoria Insuficiente "<< endl;
     abort();
  }

  // Adicionando elemento na pilha;
  p->Entry = x;
  p->NextNode = top;
  top = p;
  count++;
}

// Retirada de elemento do Topo da pilha
void Stack::Pop(StackEntry &x)
{
  StackPointer p;                // P é um ponteiro para StackNode

  // Verifica se a pilha está vazia;
  if (Empty())
    cout << "Pilha Vazia" << endl;

  else
  {
    // Comandos de deleção do elemento do topo da pilha;
    p = top;
    x = p->Entry;                // Recebe o elemento do topo da pilha
    top = top->NextNode;
    delete p;
    count--;
  }
}

// Retira todos os elementos da pilha, sem retorno dos elementos
void Stack::Clear()
{
  StackEntry x;
  while(! Empty())
    Pop(x);
/*
  // Outro método sem chamar métodos auxiliares;
  StackPointer p;                     // p é um ponteiro para StackNode;

  while(top != NULL)
  { p = top;
    top = top->NextNode;
    delete p;
  }
  count = 0;
*/

}


// Retorna o elemento do topo da pilha
void Stack::Top(StackEntry &x)
{
  if(top == NULL)
  {
    cout << "Pilha Vazia" << endl;
    abort();
  }

  x = top->Entry;        // x recebe a cópia do elemento do topo da pilha

  /*
  // Pode utilizar outro método com auxilio do Push e do Pop;
  // Somente o comando de retirada da copia do elemento do topo;
  Pop(x);
  Push(x);
  */
}

// Contador de elementos da pilha;
int Stack::Size()
{
  return count;
// ou
/*StackPointer p;         // p é um ponteiro para StackNode;
  int contador = 0;

  p = top;

  while( p != NULL)       // Enquanto não aterrar;
  {
    p = p->NextNode;
    contador++;
  }
  return contador;        // Retorna o numero de elementos da pilha;
*/
}

void Stack::Print()
{
  StackPointer p;
  p = top;
  cout << " topo -> { " ;
  while (p != NULL)
  {
    cout << p->Entry;
    if (p->NextNode != NULL)
      cout << " ; ";
    p = p->NextNode;
  }
  cout << " } " ;
}

void Stack::PrintFile(char nome[])
{
  StackPointer p;
  ofstream outfile;
  outfile.open( nome , ios::app);

  p = top;
  outfile << " topo -> { ";
  while(p != NULL)
  {
    outfile << p->Entry;
    if(p->NextNode != NULL)
      outfile << " ; ";
    p = p->NextNode;
  }
  outfile << " } ";
  outfile.close();
}

void Stack::Copy(Stack &B)
{
  StackPointer p, q, r;

  p = top;
  q = B.top;
  if(Empty())
    cout << "Pilha vazia" << endl;
  else
  { r = new StackNode;
    r->Entry = p-> Entry;
    r->NextNode = NULL;
    B.top = r;
    q = r;
    p = p->NextNode;
    while (p != NULL)
    { r = new StackNode;
      r->Entry = p-> Entry;
      r->NextNode = NULL;
      q->NextNode = r;
      p = p->NextNode;
      q = q->NextNode;
    }
  }
  B.count = count;
}

void Stack::Invert()
{
  StackPointer p, q;
  p = top;
  q = NULL;
  if(Empty())
    cout << "Pilha Vazia" << endl;
  else
  { while (p != NULL)
    { p = top->NextNode;
      top->NextNode = q;
      q = top;
      top = p;
    }
    top = q;
  }
}

void Stack::Invert(Stack &B)
{ StackPointer p, q, r;

  p = top;
  if(Empty())
    cout << "Pilha vazia" << endl;
  else
  { while (p != NULL)
    { r = new StackNode;
      r->Entry = p-> Entry;
      r->NextNode = B.top;
      B.top = r;
      p = p->NextNode;
    }
    B.count = count;
  }
}

//Destruidor de Pilha
Stack::~Stack()
{
  StackEntry x;
  // Enquanto não aterrar, retira todos os elementos da pilha;
  while (!Empty())
    Pop(x);
  cout << "Pilha destruida" << endl;
}
