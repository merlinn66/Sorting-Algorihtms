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

void insertionsort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int temp = arr[i];
        int j = i - 1;

        // we are elements of array[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
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

    cout << "Unsorted array:\n";
    print_array(arr, size);

    insertionsort(arr, size);

    cout << "Sorted array:\n";
    print_array(arr, size);

    delete[] arr;
    return 0;
}