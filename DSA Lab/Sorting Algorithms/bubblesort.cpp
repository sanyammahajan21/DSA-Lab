#include <bits/stdc++.h>
#include <array>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
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

    int N = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, N);
    cout << "Sorted array: \n";
    printArray(array, N);
    return 0;
}