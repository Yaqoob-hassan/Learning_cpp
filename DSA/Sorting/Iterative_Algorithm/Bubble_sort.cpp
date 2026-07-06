// Important Note for Bubble Sort ALgorithm 

// The Bubble sort algorithm is adaptive.. But, Actually it is made adaptive by already setting sorted element of array 
// For example { 0, 1 , 2, 3, 4, 5} like this 

// Time complexity -- Minimum O(n) 
// Time complexity -- Maximum O(n^2)

// It is also a stable algorithm 

#include<iostream>
using namespace std;

void bubble_sort(int arr[], int n) {

    for(int i = 0; i < n - 1; i++) {    // why n - 1  ? -- (Answer)  Suppose we have an array of 5
                                       //  when we do sorting, in the first pass the largest element is already sorted than 
        bool swapped = false;          // we dont need any reason to do full sort.

        for(int j = 0; j < n - 1 - i; j++) { //  why n - 1 - i ?  we are asking to reduce comaparision also that why. 

            if(arr[j] > arr[j + 1]){

                swap(arr[j], arr[j + 1]);

                swapped = true;
            }
        }

        if(!swapped) {break;}
    }
}

void display(int arr[], int n) { // Displaying function

    for(int i = 0; i < n; i++) {

        cout << arr[i] << " ";
    }

    cout << endl;
}

int main() {
  int arr[] = {7, 3, 8, 5, 12, 31};

  int n = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, n);
  
  cout << "Sorting element by {Bubble Sort}." << endl;
  display(arr, n);

  return 0;
}

