#include<bits/stdc++.h>
using namespace std;

int binarysearch_recursion(int a[], int target, int low, int high){
    if(low > high) return -1;
    int mid = (low + high)/2;
    if(a[mid] == target) return mid+1;
    else if(a[mid] > target) high = mid -1;
    else low = mid +1;
    return binarysearch_recursion(a,target,low,high);
}

int problem(int a[],int n,int target,int low, int high){
    return binarysearch_recursion(a,target,0,n-1);
    
}

int binarysearch_loop(int a[], int n , int target){
    int mid,low=0,high=n-1;
    while(low < high){
        mid = (low + high)/2;
        if(a[mid] == target) return mid+1;
        else if(a[mid] > target) high = mid-1;
        else low = mid +1;
    }
    return -1;
}

int main(){
    int n = 10;
    int a[n] = {2,5,7,8,10,14,19,21,32,45};
    int target = 21;
    int result = binarysearch_loop(a,n,target);
   // int result = problem(a,n,target,0,n-1);
    if(result == -1) cout<<"not found in the array ";
    else cout<<"found at position "<<result;
}