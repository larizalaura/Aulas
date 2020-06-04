#include <iostream>
#include "Grafo.h"


using namespace std;


int main(int argc, char *argv[]) {
  Grafo g(7);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 5);
  g.addEdge(2, 3);
  g.addEdge(2, 6);
  g.addEdge(4, 5);
  g.addEdge(2, 5);

  g.toString();

  cout<< "------ Deep First Search: ----" <<endl;
	g.callDFS(0);
	

}

