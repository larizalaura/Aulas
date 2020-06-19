//Grafo.cpp

#include <iostream>
using namespace std;

#ifndef Grafo_H
#define Grafo_H

#define INF 100000

class Grafo{
	public:
		Grafo(int numVertices);
	    ~Grafo();
	    
	    bool empty();
	    int nVertices();
	    int nEdges();
	    int size();
	    int vertex(int i);
	    int edge(int i);
	    int distance(int v, int w);
	    int degree(int v);

	    void addEdge(int i, int j, int value);
	    void removeEdge(int i, int j, int value);

	    void toString();

	    void callDFS(int v);
	    void callBFS(int v);

	    int getConnected();
	    void Kruskal();
	    int countEdges(int** adjMatrizTemp);
	    
	private:
		int** adjMatriz;
		int numVertices;
		int numArestas;

		void BFS(int v, int visited[]);
		void DFS(int v, int visited[]);
};

#endif

