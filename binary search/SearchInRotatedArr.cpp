/*
search in rotated sorted array -> normal sorted arr = {1,2,3,4,5,}; rotated arr at 4 = {4,5,1,2,3}
*/
#include<bits/stdc++.h>
using namespace std;

void MinInRotatedArr(int a[], int n){ // logic -> always search the min element in the sorted side (left or right) 
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    while(low <= high){
        int mid  = (low + high)/2;
        if(a[low] <= a[mid]){ // left side is sorted minimum ele may be a[low]
            ans = min(ans,a[low]);
            high = mid -1;
        }
        else { // right side is sorted min element may be a[mid];
            ans = min(ans,a[mid]);
            low = mid +1;
        }
    }
    cout << " minimum element in the arr is "<<ans;
}

int searchinarr(int a[], int n, int target){
    int low =0;
    int high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] == target) return mid+1;
        
        if(a[low] <= a[mid]){//this checks that left half of arr is sorted 
            if(a[low] <= target && a[mid] >= target) high = mid-1; // check for the sorted region
            else low = mid +1;
        }
        else{// right half of arr is sorted 
            if(a[mid] <= target && target <= a[high]) low = mid +1; // check for the sorted region
            else high = mid -1;  
        }
    }
    return -1;
}

int main(){
    int n = 5;
    int a[n] = {4,5,1,2,3};
    int target = 2;
    int res = searchinarr(a,n,target);
    if(res != -1)cout<<"in index "<<res;
    else cout<<"not found";
    MinInRotatedArr(a,n);
}