//Grafo.cpp

#include <iostream>
using namespace std;

#ifndef Grafo_H
#define Grafo_H

typedef int GrafoEntry;

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

	    void addEdge(int i, int j);
	    void removeEdge(int i, int j);

	    void toString();

	    void callDFS(int v);
	   // void callBFS(int v);
	private:
		bool** adjMatriz;
		int numVertices;

		//void BFS(int v, int visited[]);
		void DFS(int v, int visited[]);
};

#endif

