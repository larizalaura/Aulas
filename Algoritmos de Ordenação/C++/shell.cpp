/******
*    Implementação dos algoritmos Shell sort
*	@Lariza Laura de Oliveira
*/


#include <iostream>
using namespace std;

// Shell sort que rearranja elementos a intervalos n/2, n/4 n/8 ... 1

void shellSort(int array[], int n) {

  for (int interval = n / 2; interval > 0; interval /= 2){  // esse for calcula o tamanho dos intervalos n/2 e vai dividindo por 2 sucessivamente

    for (int i = interval; i < n; i++) {
  
      for (int j = i-interval; j >= 0; j -= interval) {
	if(array[j + interval] > array[j]){
		break;
	}
	else{// trocamos o array[j + interval] pelo array[j]
		int temp = array[j+ interval];
        	array[j + interval] = array[j];
		array[j] = temp;
	}
      }
    }
  }
}

//Printa o array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main() {
  int data[] = {9, 8, 3, 7, 5, 6, 4, 1};
  int size = sizeof(data) / sizeof(data[0]);
  shellSort(data, size);
  cout << "vetor ordenado: \n";
  printArray(data, size);
}


