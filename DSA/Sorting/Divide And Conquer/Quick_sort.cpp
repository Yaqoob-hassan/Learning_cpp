#include<iostream>
using namespace std;

int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l, j = h;

    do {
        do { i++; } while(i <= h && arr[i] <= pivot);
        do { j--; } while(j >= l && arr[j] > pivot);
        
        if(i < j) {
            swap(arr[i], arr[j]);
        }
    } while(i < j);
    
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h) {
    if(l < h) {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
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

    quickSort(arr, 0, n - 1);
    display(arr, n);

    return 0;
}