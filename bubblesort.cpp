#include <iostream>
#include <ctime>

using namespace std;

void initialize_seed(int seed) {
    srand(seed);
}

void generate_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 101;  // random integers from 0 to 100 included
    }
}

// perform bubble sort
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size -1; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {

        // swapping elements if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

int main() {
  int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];

    initialize_seed(time(0));   // initialize_seed with current time

    generate_array(arr, size);

    cout << "Unsorted Array:\n";  
    printArray(arr, size);

    bubbleSort(arr, size);
  
  cout << "Sorted Array in Ascending Order:\n";  
  printArray(arr, size);

  delete[] arr;
  return 0;
}