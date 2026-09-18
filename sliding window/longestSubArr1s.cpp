/*
length of the longest subarr after fliping k 0s to 1s. if a[] = {1,1,0,1,0,0,1} k=2 then length is 5 i.e 1,1,1(flipped),1,1(flipped),0,1 

logic-> take 2 pointers iterate through arr, whenever r hit 0 increase 0s count and when 0s exceed the limit then l++. when 0s in limit then update maxlen. 
*/
#include<bits/stdc++.h>
using namespace std;

void longestsubarr(int a[], int n, int k){
    int l=0,r=0,maxlen=0,zero=0;
    while(r < n){
        if(a[r] == 0) zero++;
        while(zero > k){ // when 0s exceed limit then l++ when a[l] hit 0 then zero--; this loop keeps the 0s in limit 
            if(a[l] == 0) zero--;
            l++;
        }
        if(zero <= k){ // updates maxlen only when 0s is in limit.
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    cout<<"longest subarr "<< maxlen;
    return;
}

int main(){
    int n = 11;
    int a[n] = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    longestsubarr(a,n,k);
}