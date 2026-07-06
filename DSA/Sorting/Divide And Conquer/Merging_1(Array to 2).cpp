// Time complexity : best -- worst -- avg O(n log n)
// Stable But not adaptive 
// Space O(n)

#include<iostream>
using namespace std;


void merge(int arr[], int arr2[], int l, int h, int mid) {
    int i = l;
    int j = mid + 1;
    int k = i;

    while(i <= mid && j <= h) {

        if(arr[i] < arr[j]) {
            arr2[k++] = arr[i++];
        }

        else {
            arr2[k++] = arr[j++];
        }
    }

    for(; i <= mid; i++) {
        arr2[k++] = arr[i];
    }

    for(; j <= h; j++) {
        arr2[k++] = arr[j];
    }

    for(int x = l; x <= h; x++) {
        arr[x] = arr2[x];
    }
}

void merge_Sort(int arr[], int arr2[], int l, int h) {

    if(l >= h) {
        return;
    }

    int mid = ( l + h) / 2;

    merge_Sort(arr, arr2, l, mid);
    merge_Sort(arr, arr2, mid + 1, h);
    merge(arr, arr2, l , h, mid);
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 2, 15, 4, 5, 3, 1, 18, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int arr2[n];

    merge_Sort(arr, arr2, 0, n - 1);
    display(arr, n);

    return 0;
}