/* C++ QuickSort */
#include <iostream>
using namespace std; 

// uma função para swap, trocar valores
void swap(int* a, int* b) 
{ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 

/* Essa função considera o último elemento do vetor como pivot, coloca o pivo
na posição correta no vetor ordenado, e posiciona os menores que o pivo
a esquerda e os maiores que o pivo a direta  */
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) 
	{ 
		// Se o elemento atual for menor que o pivo 
		if (arr[j] < pivot) 
		{ 
			i++; // incrementa o indice do menor elemento 
			swap(&arr[i], &arr[j]); 

		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/* função principal que implementa o  QuickSort 
arr[] --> Array a ser ordenado, 
low --> Indice inicial, 
high --> Indice final */
void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		/* pi é o pivo que esta no lugar correto*/
		int pi = partition(arr, low, high); 


		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 

/* Printa o array array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

int main() 
{ 
	int arr[] = {10, 7, 8, 9, 1, 5}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	quickSort(arr, 0, n - 1); 
	cout << "Sorted array: \n"; 
	printArray(arr, n); 
	return 0; 
} 

