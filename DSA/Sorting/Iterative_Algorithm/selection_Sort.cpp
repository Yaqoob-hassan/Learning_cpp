// It perfrom minimum number of swaps 
// It is not stable and not adaptive aswell 
// Time complexity of this algorithm is : O(n^2)

#include<iostream>
using namespace std;

void selection_sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int k, j;

        for(int j = k = i; j < n; j++) {
            if(arr[j] > arr[k]) {
                k = j;
            }
        }
        swap(arr[i], arr[k]);
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[] = {10, 2, 15, 4, 5, 3, 1, 18, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);
    display(arr, n);

    return 0;
}