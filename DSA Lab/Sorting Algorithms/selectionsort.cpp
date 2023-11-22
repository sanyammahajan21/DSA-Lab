#include <bits/stdc++.h> 
using namespace std; 

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx;  
	for (i = 0; i < n-1; i++) 
	{ 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		swap(&arr[min_idx], &arr[i]); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		std::cout << arr[i] << " "; 
	std::cout << endl; 
} 
 
int main() 
{ 
	int size;
    std::cout << "Enter the size of the array: ";
    std::cin >> size;
    if (size <= 0) {
        std::cerr << "Invalid array size. Please enter a positive integer." << std::endl;
        return 1; 
    }

    int array[size];

    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> array[i];
    }


	int n = sizeof(array)/sizeof(array[0]); 
	selectionSort(array, n); 
	std::cout << "Sorted array: "; 
	printArray(array, n); 
	return 0; 
} 
