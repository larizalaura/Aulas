/******
*    Implementação dos algoritmos Bubble sort
*	@Lariza Laura de Oliveira
*/

#include <iostream>
using namespace std;

void bubbleSort(int array[], int n) {

  // um loop percorre o array
  // o outro ocmpara
  for (int i = 0; i < n - 1; ++i) {// ele faz n vezes
    for (int j = 0; j <n-i-1; ++j) {

      // Para mudar de ordem asc para desc mude > para <.
      if (array[j] > array[j + 1]) {

        // troque se o maior esta no final
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}


// printando o array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

// tester
int main() {
  int data[] = {-2, 45, 0, 11, -9};
  int n = sizeof(data) / sizeof(data[0]);
  bubbleSort(data, n);
  cout << "Array em ordem Descendente:\n";
  printArray(data, n);
}
