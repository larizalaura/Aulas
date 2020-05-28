/******
*    Implementação de Grafo com matriz de adjacência
*
******/

#include <iostream>
using namespace std;

class Grafo {
   private:
  bool** adjMatriz;
  int numVertices;

   public:
  // Inicializa a matriz com zero
  Grafo(int numVertices) {
    this->numVertices = numVertices;
    adjMatriz = new bool*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatriz[i] = new bool[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatriz[i][j] = false;
    }
  }

  // Adiciona arestas
  void addEdge(int i, int j) {
    adjMatriz[i][j] = true;
    adjMatriz[j][i] = true;
  }

  // Remove as arestas
  void removeEdge(int i, int j) {
    adjMatriz[i][j] = false;
    adjMatriz[j][i] = false;
  }

  // Printa a matriz
  void toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatriz[i][j] << " ";
      cout << "\n";
    }
  }

  ~Grafo() {
    for (int i = 0; i < numVertices; i++)
      delete[] adjMatriz[i];
    delete[] adjMatriz;
  }
};

int main() {
  Grafo g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);

  g.toString();
}
