#include <iostream>
 
using namespace std;
 
// A função Merge junta dois vetores em um vetor ordenado
void Merge(int *a, int low, int high, int mid){
    //Temos de low até mid (subvetor1) e de mid+1 até high (subvetor 2) ja ordenados.
    int i, j, k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;
 
    // Junte tudo em um array temporario temp[].
    while (i <= mid && j <= high){
        if (a[i] < a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }
        else{
            temp[k] = a[j];
            k++;
            j++;
        }
    }
 
    // Insira os valores remanescentes de i até mid em temp[].
    while (i <= mid){
        temp[k] = a[i];
        k++;
        i++;
    }
 
    // Insira os valores remanescentes de j até high em temp[].
    while (j <= high){
        temp[k] = a[j];
        k++;
        j++;
    }
 

    // copie os valores ordenados de  temp[] para a[].
    for (i = low; i <= high; i++){
        a[i] = temp[i-low];
    }
}
 
// Divide um vetor em duas partes
void MergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        // Digite o vetor no meio e chama o Merge para cada metade
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
 
        // Junta tudo em um vetor ordenado
        Merge(a, low, high, mid);
    }
}

//Printa o array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main()
{
    int data[] = {4, 3, 5, 1, 2};
    int size = sizeof(data) / sizeof(data[0]);
    MergeSort(data,0, size);
    cout << "vetor ordenado: \n";
    printArray(data, size);
}
