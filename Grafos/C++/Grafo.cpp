/******
*    Implementação de Grafo com matriz de adjacência
*
******/

#include <iostream>
#include "Queue.h"
#include "Grafo.h"


using namespace std;


// Inicializa a matriz com zero
Grafo::Grafo(int numVertices) {
	this->numVertices = numVertices;
	numArestas = 0;
	//cout<< "num_vertices " << numVertices<< endl;
	adjMatriz = new int*[numVertices];
	for (int i = 0; i < numVertices; i++) {
		adjMatriz[i] = new int[numVertices];
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
int Grafo::nEdges(){
	return(numArestas);
}
//int size()
//int degree(int v);

// Adiciona arestas
void Grafo::addEdge(int i, int j, int value) {
	adjMatriz[i][j] = value;
	adjMatriz[j][i] = value;
	numArestas +=2;
}

// Remove as arestas
void Grafo::removeEdge(int i, int j, int value) {
	adjMatriz[i][j] = 0;
	adjMatriz[j][i] = 0;
	numArestas -=2;
}

// Printa a matriz
void Grafo::toString() {
	for (int i = 0; i < numVertices; i++) {
		cout << i << " : ";
		for (int j = 0; j < numVertices; j++){
			cout << adjMatriz[i][j] << "\t";
		}
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

// Breadth First Search (Busca em profundidade)
void Grafo::BFS(int v, int visited[]){
	Queue q = Queue();
	visited[v] = 1;
	q.Append(v);
	while(!q.Empty()){
		q.Serve(v);
		cout<< " " << v << " "<< endl;
		for (int w = 0; w < numVertices; w++){
			if(adjMatriz[v][w] ==1 && visited[w] ==0){
				q.Append(w);
				visited[w] = 1;
			}
		}

	}

}

void Grafo::callBFS(int v){
	int visited[numVertices];
	for (int i = 0; i < numVertices; i++)
		visited[i] = 0;

	BFS(v, visited);
}


int Grafo::countEdges(int** adjMatrizTemp){
	int count = 0;
	for(int i=0; i<numVertices; i++){
		for(int j=0; j<numVertices; j++){
			if(adjMatrizTemp[i][j]){
				count++;
			}

		}
	}
				
	return count/2;
}
// Encontra o conjunto de um vértice i
int find(int i, int parent[] ) 
{ 
	//cout<<"find "<< i<<" ";
    while (parent[i] != i){
        i = parent[i]; // se for diferente ele retorna esse cara
     //   cout<< "parent " << parent[i] <<" ";
    }

    return i; 
} 
  
// Faz a uniao de i e j
// false se i e j estao no mesmo conjunto
void union1(int i, int j, int parent[]) 
{ 
   // cout<< "dentro do union-----------------------------"<<endl;
    int a = find(i, parent); 
    int b = find(j, parent); 
  //  cout<< "no union " <<"a: " << a <<"  b:"<< b<<" parent[a] " << parent[a]<< "parent a recebe b"<< endl;
    parent[a] = b; // liga o vertice a ao vértice b, ou seja, a esta ligado a b
} 
  

void Grafo::Kruskal(){
	int parent[numVertices]; // array de vertices

	int** tree; // arvore de cobertura de menor custo
	int** adjMatrizTemp; //copia da matriz de adjacencia
	adjMatrizTemp = adjMatriz;
	int arestas_adicionadas = 0;
	int arestas_removidas = numArestas;

	for(int i=0; i<numVertices; i++){
		parent[i] = i;
	}
	adjMatrizTemp = new int*[numVertices];
	tree = new int*[numVertices];
	for (int i = 0; i < numVertices; i++) {
		adjMatrizTemp[i] = new int[numVertices];
		tree[i] = new int[numVertices];
		for (int j = 0; j < numVertices; j++){
			adjMatrizTemp[i][j] = adjMatriz[i][j];
			tree[i][j] = 0;
		}

	}

	while((arestas_removidas !=0) && (arestas_adicionadas < (numVertices -1))){

		int menor = INF;
		int v = 0;
		int w = 0;

		for(int i=0; i<numVertices; i++){
			for(int j=0; j<numVertices; j++){
				
				if((adjMatrizTemp[i][j]) < menor && (adjMatrizTemp[i][j] >0)){
					menor = adjMatrizTemp[i][j];
					v = i; //vertices do menor valor
					w = j; //vertices do menor valor
				}
			}
		}

		if(find(v, parent) != find(w, parent)){ // não tem ciclo
			cout<< "nao eh igual " <<endl;
			adjMatrizTemp[v][w] = adjMatrizTemp[w][v] = 0;; // removo eles
			tree[v][w] = tree[w][v] = menor;
			arestas_adicionadas += 1;
			arestas_removidas -= 1;

			union1(v, w, parent);
			//cout<< "fim de ciclo " << v << "  "<< parent[v] <<"   " << w<< " "<<parent[w]<<endl;
		
		}else{
			//cout<< "eh igual  tem ciclo ----------------- fim de ciclo" <<endl;
			adjMatrizTemp[v][w] =adjMatrizTemp[w][v] = 0;
			arestas_removidas -= 1;
		}

	}

	//cout<< "arvore de menor custo" <<endl;
	for (int i = 0; i < numVertices; i++) {
		cout << i << " : ";
		for (int j = 0; j < numVertices; j++){
			cout << tree[i][j] << "\t";

		}
		cout << "\n";
	}
}


Grafo::~Grafo() {
	for (int i = 0; i < numVertices; i++)
		delete[] adjMatriz[i];
		delete[] adjMatriz;
}


