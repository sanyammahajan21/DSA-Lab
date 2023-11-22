#include <iostream>

using namespace std;

void insertionSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

int main() {
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
  
  insertionSort(array, size);
  cout << "\nThe sorted array is: ";
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  return 0;
}