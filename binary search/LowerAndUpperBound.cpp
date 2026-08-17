/*
lower bound is >= target and upper bound is > target
*/
#include<bits/stdc++.h>
using namespace std;

void lowerBound(int a[],int n,int target){
    int low = 0,mid,high = n-1,ans;
    while(low <= high){
        mid = (low + high)/2;
        /*
        to find the upper bound 
        if(a[mid] > target){
            high = mid-1;
            ans = mid;
        }
        */
        if(a[mid] >= target){
            high = mid-1;
            ans = mid;
        }
        else low = mid +1;
    }
    cout<<"lower bound is at index "<<ans+1<<" number is "<<a[ans];
}

int main(){
    int n = 6;
    int a[n] = {1,3,5,7,9,11};
    int target = 6;
    lowerBound(a,n,target);
}