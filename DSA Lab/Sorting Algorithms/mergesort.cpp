#include <iostream> 
using namespace std; 
 
void merge(int array[], int const left, 
		int const mid, int const right) 
{ 
	auto const subArrayOne = mid - left + 1; 
	auto const subArrayTwo = right - mid; 

	auto *leftArray = new int[subArrayOne], 
		*rightArray = new int[subArrayTwo]; 

    for (auto i = 0; i < subArrayOne; i++) 
		leftArray[i] = array[left + i]; 
	for (auto j = 0; j < subArrayTwo; j++) 
		rightArray[j] = array[mid + 1 + j]; 
 
	auto indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 

	 
	int indexOfMergedArray = left; 

	 
	 
	while (indexOfSubArrayOne < subArrayOne && 
		indexOfSubArrayTwo < subArrayTwo) 
	{ 
		if (leftArray[indexOfSubArrayOne] <= 
			rightArray[indexOfSubArrayTwo]) 
		{ 
			array[indexOfMergedArray] = 
			leftArray[indexOfSubArrayOne]; 
			indexOfSubArrayOne++; 
		} 
		else
		{ 
			array[indexOfMergedArray] = 
			rightArray[indexOfSubArrayTwo]; 
			indexOfSubArrayTwo++; 
		} 
		indexOfMergedArray++; 
	} 
	 
	while (indexOfSubArrayOne < subArrayOne) 
	{ 
		array[indexOfMergedArray] = 
		leftArray[indexOfSubArrayOne]; 
		indexOfSubArrayOne++; 
		indexOfMergedArray++; 
	} 
 
	while (indexOfSubArrayTwo < subArrayTwo) 
	{ 
		array[indexOfMergedArray] = 
		rightArray[indexOfSubArrayTwo]; 
		indexOfSubArrayTwo++; 
		indexOfMergedArray++; 
	} 
} 
 
void mergeSort(int array[], 
			int const begin, 
			int const end) 
{ 
 
	if (begin >= end) 
		return; 

	auto mid = begin + (end - begin) / 2; 
	mergeSort(array, begin, mid); 
	mergeSort(array, mid + 1, end); 
	merge(array, begin, mid, end); 
} 

 
void printArray(int A[], int size) 
{ 
	for (auto i = 0; i < size; i++) 
		std::cout << A[i] << " "; 
	std::cout<<endl; 
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
 


	mergeSort(array, 0, size - 1); 

	std::cout << "Sorted array is "<<endl; 
	printArray(array, size); 
	return 0; 
} 
