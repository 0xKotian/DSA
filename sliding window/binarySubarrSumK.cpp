/*
length of the longest binary subarr with sum equal to k.

logic -> countingsubarr(a,n,k) gives number of subarr whose sum is <=k; countingsubarr(a,n,k-1) gives number of subarr whose sum is <=k-1;
now (<=k) - (<=k-1) gives number of subarr whose sum == k
*/
#include<bits/stdc++.h>
using namespace std;

int countingsubarr(int a[], int n, int k){
    if(k < 0) return 0;
    int l=0,r=0,cnt=0,sum=0;
    while(r < n){
        sum += a[r];
        while(sum > k){
            sum -= a[l];
            l++;
        }
        if(sum <= k){
            cnt = cnt + (r-l+1);
        }
        r++;
    }
    return cnt;
}

void problem(int a[], int n, int k){
    int ans = countingsubarr(a,n,k) - countingsubarr(a,n,k-1); 
    cout << ans;
}

int main(){
    int n = 6;
    int a[n] = {1,0,0,1,1,0};
    int k = 2;
    problem(a,n,k);
}