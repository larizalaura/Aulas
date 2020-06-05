//  Pilha.h
//  Esta pilha é do modelo dinamico;

/*   Observações importantes:
  - A pilha possui elementos (StackNode) conectados entre si;
  - Cada elemento possui duas estruturas: Entry e NextNode;
  - Entry é um campo do tipo NewEntry definido pelo programador;
  - Função de Entry: receber dados;
  - NextNode é um ponteiro que aponta para o elemento anterior da pilha;
  - Função de NextNode: conectar elementos da pilha;
  - Quando NextNode é aterrado quer dizer que este elemento StackNode é
o primero da pilha;
  - Top é um ponteiro que aponta para o elemento StackNode do topo,
informando que este é o ultimo da pilha;
  - Top aterrado significa que a pilha está vazia;
*/

#include <iostream>
using namespace std;

#ifndef STACK_H
#define STACK_H

typedef string StackEntry;           // Nova declaração de int (NewEntry);

class Stack
{ public:
    Stack();                      // Construidor;
    void Push(StackEntry x);        // Coloca elemento x na pilha;
    void Pop(StackEntry &x);        // Retira o elemento x da pilha;
    bool Empty();                 // Verifica se está vazia;
    bool Full();                  // Verifica se está cheia;
    void Clear();                 // Transforma em uma pilha vazia;
    void Top(StackEntry &x);        // Mostra qual elemento está no topo;
    int Size();                   // Retorna quantos elementos está na pilha;
    void Print();                 // Imprime os elementos da pilha
    void PrintFile(char nome[]);  // Imprime os elementos da pilha em um arquivo
    void Copy(Stack &B);          // Copia pilha para a pilha B;
    void Invert();                // Inverte a pilha nela mesma
    void Invert(Stack &B);        // Invert a pilha em outra pilha
    ~Stack();                     // Destruidor;

  private:
    // declaração de tipos
    struct StackNode
    { StackEntry Entry;               // Tipo de dado colocado na pilha;
      StackNode *NextNode;     // Ligação para próximo elemento na pilha;
    };

    typedef StackNode *StackPointer;  // *StackPointer é um ponteiro para
                                      //StackNode (Estrutura: Entry,
                                      //*NextNode);

    // declaração de campos
    StackPointer top;        // Topo da pilha
    int count;               // contador

};

#endif
