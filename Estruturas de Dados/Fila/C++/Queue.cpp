//Fila.cpp

#include <iostream>
#include "Queue.h"
#include <string>
#include <fstream>

using namespace std;
//==============================================================================
//Construtor
Queue::Queue()
{
  head = tail = NULL;       //ponteiros aterrados
  count = 0;                //contador inicial
}
//==============================================================================
//Destrutor
Queue::~Queue()
{
  QueueEntry x;          //QueueEntry e uma string
  while ( ! Empty() )
    Serve(x);            //Retira elementos da fila
  cout << "Fila Destruida" << endl;
}
//==============================================================================
//Verifica se é vazio
bool Queue::Empty()
{
  return(head == NULL);       //se head for Nulo , logo é vazio
}
//==============================================================================
//Verifica se esta cheio
bool Queue::Full()
{
  return false;
}
//==============================================================================
//Coloca elementos no final da Fila
void Queue::Append(QueueEntry x)
{
  QueuePointer p;
  p = new QueueNode;
  if(p == NULL)
  { cout << "Memoria insuficiente" << endl;
    abort();
  }
  p->Entry = x;
  if (Empty())             //se for o primeiro
    head = tail = p;
  else
  { tail->NextNode = p;
    tail = p;
  }
  p->NextNode = NULL;

  count++;
}
//==============================================================================
//Retira elementos do inicio da fila
void Queue::Serve(QueueEntry &x)
{
  QueuePointer p;
  if (Empty())
    cout << "Fila Vazia" << endl;
  else
  { x = head->Entry;
    p = head;
    head = head->NextNode;
    delete p;

    if (head == NULL)
      tail = NULL;
    count--;
  }
}
//==============================================================================
//Limpa a Fila
void Queue::Clear()
{
  QueuePointer p;
  while(head != NULL)
  { p = head;
    head = head->NextNode;
    delete p;
  }

  tail = NULL;
  count = 0;
}
//==============================================================================
//Retorna o que esta no inicio da Fila
void Queue::Front(QueueEntry &x)
{
  if(Empty())
  { cout << "Fila vazia" << endl;
    abort();
  }
  x = head->Entry;
}
//==============================================================================
//Retorna o que esta atras da fila
void Queue::Rear(QueueEntry &x)
{
  if(Empty())
  { cout << "Fila vazia" << endl;
    abort();
  }

  x = tail->Entry;
}
//==============================================================================
//Retorna o numero de elementos na fila
int Queue::Size()
{
  return (count);
}
//==============================================================================
//Imprime os elenmentos da Fila
void Queue::Print()
{ QueuePointer p;
  p = head;
  cout << " inicio ->{ ";
  while(p!=NULL)
  { cout << p->Entry;
    if (p->NextNode != NULL)
      cout << " ; " ;
    p = p->NextNode;
  }
  cout << " } " ;
}
//==============================================================================
//Imprime no arquivo desejado (nome) os elementos da fila
void Queue::PrintFile(char nome[])#include "Queue.h"
{ QueuePointer p;
  ofstream outfile;
  outfile.open( nome, ios::app);

  p = head;
  outfile << " { ";
  while(p != NULL)
  { outfile << p->Entry;
    p = p->NextNode;
    if(p->NextNode != NULL)
      outfile << " ; ";
  }
  outfile << " } ";
}
//==============================================================================
// Copia a Fila para outra fila fornecida
void Queue::Copy(Queue &B)
{ QueuePointer p;

  p = head;
  if (Empty())
    cout <<"Fila Vazia " << endl;
  else
  { while (p != NULL)
    { B.Append(p->Entry);
      p = p->NextNode;
    }
  }
}
//==============================================================================
//Inverte a sequencia dos elemetos da fila nela mesma
void Queue::Invert()
{ QueuePointer p, q;

  p = head;
  q = NULL;
  if (Empty())
    cout << "Fila vaizia" << endl;
  else
  { p = p->NextNode;
    head->NextNode = q;
    q = head;
    head = p;
    tail = q;
    while (p != NULL)
    { p = p->NextNode;
      head->NextNode = q;
      q = head;
      head = p;
    }
    head = q;
  }
}
//==============================================================================
//Inverte a sequencia de elementos da fila em outra fila fornecida
void Queue::Invert(Queue &B)
{ QueuePointer p, q, r;

  p = head;
  q = B.head;
  if (Empty())
    cout << "Fila vazia" << endl;
  else
  { r = new QueueNode;
    r->Entry = p->Entry;
    r->NextNode = NULL;
    B.tail = B.head = r;
    p = p->NextNode;
    q = r;
    while(p != NULL)
    { r = new QueueNode;
      r->Entry = p->Entry;
      r->NextNode = q;
      B.tail = r;
      p = p->NextNode;
    }
    B.count = count;
  }
}
//==============================================================================
