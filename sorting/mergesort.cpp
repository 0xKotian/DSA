/*
first we divide the array until there is only one element left (dividing the array is done by indexing). then we merg the array by comparing  
*/
#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else {
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(a[left]);
            left++;
    }
    while(right <= high){
        temp.push_back(a[right]);
            right++;
    }
    for(int i = low; i <= high; i++){
        a[i] = temp[i-low];
    }
}
void mergesort(int a[], int low, int high){
    if(low == high) return;
    int mid = (low + high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}
int main() {
    int n = 5;
    int a[n] = {54,21,46,37,12};
    mergesort(a,0,n-1);
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}