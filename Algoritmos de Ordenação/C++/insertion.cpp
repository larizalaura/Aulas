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

int main() {
	int n = 6;
	int a[] = {2, 3, 15, 8, 11, 9};
	
	insercao(n, a);
	
	for(int i=0; i < 6; i++){
		cout<<a[i]<< endl;
	}

}

