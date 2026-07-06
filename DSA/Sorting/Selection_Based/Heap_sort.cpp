#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_build(int arr[], int n){
    int start = (n - 1) / 2;
    for(int i = start; i >= 0; i--){
        heapify(arr, n, i);
    }
}

void heap_sort(int arr[], int n){
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {45, 85, 75, 12, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_build(arr, n);
    heap_sort(arr, n);

    display(arr, n);

    return 0;
}