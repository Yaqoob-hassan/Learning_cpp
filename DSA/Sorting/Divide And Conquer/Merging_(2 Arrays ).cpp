// Time Complexity O(m + n)
// Stable 
// Not adaptive 
#include<iostream>
using namespace std;

void merge(int arr[], int arr2[], int arr3[], int m, int n) {
    int i = 0, j = 0, k = 0;

    while(i < m && j < n) {

        if(arr[i] < arr2[j]) {
            arr3[k++] = arr[i++];
        }

        else {
            arr3[k++] = arr2[j++];
        }

    }

    for(; i < m; i++) {
        arr3[k++] = arr[i];
    }

    for(; j < n; j++) {
        arr3[k++] = arr2[j];
    }
}

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int A[] = {1, 3, 5, 7};
    int B[] = {2, 4, 6, 8, 10};
    int m = sizeof(A)/ sizeof(A[0]);
    int n = sizeof(B)/ sizeof(B[0]);
    int C[m + n];

    merge(A, B, C, m, n);
    display(C , m + n );

    return 0;
}