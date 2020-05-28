/******
*    Implementação dos algoritmos de Ordenção por Seleção e Inserção
* 	@Lariza Laura de Oliveira
*
******/

#include <iostream>
using namespace std;

void insercao (int n, int v[]){
   for (int j = 1; j < n; ++j) {
      int x = v[j];
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i) 
         v[i+1] = v[i];
      v[i+1] = x;
   }
}


void selecao (int n, int v[]){
   for (int i = 0; i < n-1; ++i) {
      int min = i;
      for (int j = i+1; j < n; ++j)
         if (v[j] < v[min])  min = j;
      int x = v[i]; 
      v[i] = v[min]; 
      v[min] = x;
   }
}

int main() {
	int n = 6;
	int a[] = {2, 3, 15, 8, 11, 9};
	
	insercao(n, a);
	
	for(int i=0; i < 6; i++){
		cout<<a[i]<< endl;
	}

	int b[] = {2, 3, 15, 8, 11, 9};

	for(int i=0; i < 6; i++){
		cout<<b[i]<< endl;
	}
	selecao(n, b);
}

