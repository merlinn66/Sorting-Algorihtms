#include <iostream>
#include <cstdlib>  // for rand, srand
#include <ctime>    // for time

using namespace std;

void initialize_seed(int seed) {
    srand(seed);
}

void generate_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 101;  // random integers from 0 to 100 included
    }
}

void selection_sort(int arr[], int size) { // selection sort implementation
    for (int i = 0; i < size; ++i) {
        int min_value = i; // assume current i is index of minimum value
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_value]) // finds smaller values
                min_value = j; // if true, updates min_value with the smaller value
        }
        int temp = arr[i]; // swap the values 
        arr[i] = arr[min_value];
        arr[min_value] = temp;
    }
}

void print_array(const int arr[], int size) { // print the array at point
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " " ;
    cout << '\n';
}

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    int* arr = new int[size];

    initialize_seed(time(0));   // initialize_seed with current time

    generate_array(arr, size);

    cout << "Unsorted array: ";
    print_array(arr, size);

    selection_sort(arr, size);

    cout << "Sorted array:   ";
    print_array(arr, size);

    delete[] arr;
    return 0;
}
