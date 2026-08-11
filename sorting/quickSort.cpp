/*
quicksort logic -> we take reference elements and place it in the crt position by sorting and grouping, the elements to the left of the ref element is smaller 
than ref element and the elements to the right are greater. then we consider the left side with low 0 and high has ref index(here partition_index)-1 and 
sort with same logic. similarly the right side is sorted with same logic by taking the low has ref index +1 and high has high only.   
*/
#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high){
    int ref = a[high];
    int i = low-1;
    for(int j = low; j < high; j++){
        if(a[j] < ref){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}

void quicksort(int a[], int low, int high){
    if(low < high){
        int partition_index = partition(a,low,high);
        quicksort(a,0,partition_index-1);
        quicksort(a,partition_index+1,high);
    }
}

int main() {
    int n = 5;
    int a[n] = {54,21,46,37,12};
    quicksort(a,0,n-1);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}