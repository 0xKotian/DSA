/*
below code represents all the sorting techniques 

1. selection sort logic -> u take the reference of the starting elements adn compare if any small element is present futhere and find the smallest element and 
swap the starting element and the smallest element. TIME COMPLEXITY => O(n^2).

2. bubble sort logic -> we push the max element to he last then then move the pointer (here i) to the right side, this pushing the max element to last is done by 
adjasent comparing and swaping. TIME COMPLEXITY => O(n^2).

3. insertion sort logic -> first we take starting 2 elements and we check and sort, the nstarting 3 elements and check the elements and sort from right to left.
TIME COMPLEXITY => O(n^2).


*/


#include<bits/stdc++.h>
using namespace std;

int temp; // global varibable can be used in any of the user defined functions without declaring 

void selection_sort(int a[], int n){
    int mini,i,j;
    for(i = 0; i <= n-2; i++){
        mini = i;
        for(j = i+1; j <= n-1; j++){
            if(a[j] < a[mini]) mini = j;
        }
        temp = a[mini];
        a[mini] = a[i];
        a[i] = temp;
    }
    for(i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}

void bubble_sort(int a[], int n){
    int i,j;
    for(i = n-1; i > 0; i--){
        int didSwap = 0; // if the given a[] is sorted the nthis is used  
        for(j = 0; j < i; j++){
            if(a[j] > a[j+1]){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                didSwap = 1; 
            }
        }
        if(didSwap == 0) break; // is there is swap done in the iteration, then that means the code is sorted and no need for futher iteration, improves the TIME COMPLEXITY
    }
    for(i = 0; i < n; i++){
        cout<<a[i]<<" ";
    } 
}

void insertion_sort(int a[], int n){
    int i,j;
    for(i = 0; i < n; i++){
        j=i;
        while(j > 0 && a[j-1] > a[j]){
            temp = a[j-1];
            a[j-1] = a[j];
            a[j] = temp;
            j--; 
        }
    }
    for(i = 0; i < n; i++){
        cout<<a[i]<<" ";
    } 
}

int main() { 
    int n=5;
    int a[5] = {54,21,46,37,12};
    //selection_sort(a,n);
    //bubble_sort(a,n);
    insertion_sort(a,n);
    return 0;
}