// Stable and adaptive 
// Time Complexity -- Minimum time O(n)
// Time Complexity --  Maximum Time O(n^2)
#include<iostream>
using namespace std;

void insertion_sort(int arr[], int n) {

    
    for(int i = 1; i < n ; i++) {
        int key = arr[i];

        int j = i - 1;
        while( j >= 0 && arr[j] >  key) {
            arr[ j + 1] = arr[j];
            j = j - 1;
        }
    
    arr[j + 1] = key;
    }
}


void display(int arr[], int n) {
    for(int i = 0; i < n ; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
    int arr[] = {12, 0, 14, 144, 19, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    display(arr, n);


    return 0;
}