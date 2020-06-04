//Fila .cpp

#include <iostream>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H

typedef int QueueEntry;

class Queue
{
  public:
    Queue();
    ~Queue();
    void Append(QueueEntry x);
    void Serve(QueueEntry &x);
    bool Empty();
    bool Full();
    void Clear();
    void Front(QueueEntry &x);
    void Rear(QueueEntry &x);
    int Size();
    void Print();
    void PrintFile(char nome[]);
    void Copy(Queue &B);
    void Invert();
    void Invert(Queue &B);


  private:

  // declaração de tipos
  struct QueueNode
  { QueueEntry Entry; // tipo de dado colocado na fila
    QueueNode *NextNode; // ligação para próximo elemento na fila
  };

  typedef QueueNode *QueuePointer;

  // declaração de campos
  QueuePointer head, tail;
  int count;         //contador
};

#endif
