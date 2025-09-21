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

int partition(int arr[], int left, int right) {
    int pivot = arr[right];  // choosing last element as pivot
    int i = left - 1;        // index of smaller element

    for (int j = left; j <= right - 1; j++) {
        // If current element is smaller or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Quick Sort function
void quicksort(int arr[], int left, int right) {
    if (left < right) {
        // pi is partitioning index, arr[pi] is at right place
        int pi = partition(arr, left, right);

        // Recursively sort elements before and after partition
        quicksort(arr, left, pi - 1);
        quicksort(arr, pi + 1, right);
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

    quicksort(arr, 0, size - 1);

    cout << "Sorted array:\n";
    print_array(arr, size);

    delete[] arr;
    return 0;
}