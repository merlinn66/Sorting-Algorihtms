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

// Merge two sorted subarrays arr[l..m] and arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;  // size of left subarray
    int n2 = r - m;      // size of right subarray

    // Create temporary arrays to hold copies of left and right subarrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data from original array to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;     // Initial index of left subarray
    int j = 0;     // Initial index of right subarray
    int k = l;     // Initial index of merged subarray in original array

    // Merge elements from L and R back into arr in sorted order
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;  // move to next element in left subarray
        }
        else {
            arr[k] = R[j];
            j++;  // move to next element in right subarray
        }
        k++;      // move to next position in merged array
    }

    // Copy any remaining elements of left subarray, if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of right subarray, if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free temporary memory allocated for subarrays
    delete[] L;
    delete[] R;
}

// Recursive merge sort function
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        // Find midpoint to divide array into two halves
        int m = l + (r - l) / 2;

        // Recursively sort first half
        mergesort(arr, l, m);

        // Recursively sort second half
        mergesort(arr, m + 1, r);

        // Merge the two sorted halves
        merge(arr, l, m, r);
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

    mergesort(arr, 0, size - 1);

    cout << "Sorted array:\n";
    print_array(arr, size);

    delete[] arr;
    return 0;
}