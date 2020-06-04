/******
*    Implementação de Grafo com matriz de adjacência
*
******/

#include <iostream>
//#include "Queue.h"
#include "Grafo.h"


using namespace std;


// Inicializa a matriz com zero
Grafo::Grafo(int numVertices) {
	this->numVertices = numVertices;
	//cout<< "num_vertices " << numVertices<< endl;
	adjMatriz = new bool*[numVertices];
	for (int i = 0; i < numVertices; i++) {
		adjMatriz[i] = new bool[numVertices];
		for (int j = 0; j < numVertices; j++){
			adjMatriz[i][j] = false;
		}

	}
}

bool Grafo::empty(){
	return(numVertices==0);
}

int Grafo::nVertices(){
	return(numVertices);
}
//int nEdges(){
//int size()
//int degree(int v);

// Adiciona arestas
void Grafo::addEdge(int i, int j) {
	adjMatriz[i][j] = true;
	adjMatriz[j][i] = true;
}

// Remove as arestas
void Grafo::removeEdge(int i, int j) {
	adjMatriz[i][j] = false;
	adjMatriz[j][i] = false;
}
  // Printa a matriz
void Grafo::toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatriz[i][j] << " ";
      cout << "\n";
    }
 }
// Deep First Search (Busca em profundidade)
void Grafo::DFS(int v, int visited[]){
	visited[v] = 1;
	cout<< " " << v << " "<< endl;
	for (int w = 0; w < numVertices; w++){
		if(adjMatriz[v][w] ==1 && visited[w] ==0)
			DFS(w, visited);
	}
}

void Grafo::callDFS(int v){
	int visited[numVertices];
	for (int i = 0; i < numVertices; i++)
		visited[i] = 0;

	DFS(v, visited);
}

Grafo::~Grafo() {
	for (int i = 0; i < numVertices; i++)
		delete[] adjMatriz[i];
		delete[] adjMatriz;
}


