/*
find the max sum of k elements either from left or from right or from both.
{6,2,3,4,7,2,1,7,1} k = 4 output is 16
{6,2,3,4}+{} = maxsum = 15
{6,2,3}+{1} = maxsum = 12
{6,2}+{7,1} = maxsum = 16 
{6}+{1,7,1} = maxsum = 15
{}+{2,1,7,1} = maxsum = 11 
*/
#include<bits/stdc++.h>
using namespace std;

void maxsumKele(int a[], int n, int k){
    int lsum=0, rsum=0, maxsum=0, r_index = n-1;
    for(int i=0;i<k;i++){
        lsum += a[i];
    }
    maxsum = lsum; // find the maxsum from leftside till k elements
    for(int j = k-1; j>=0; j--){ // now reduce k elements from leftside sum and add rightside sum and find maxsum 
        lsum -= a[j];
        rsum += a[r_index];
        r_index--;
        maxsum = max(maxsum, lsum+rsum);
    }
    cout<<maxsum;
}

int main(){
    int n = 9;
    int a[n] = {6,2,3,4,7,2,1,7,1};
    int k = 4;
    maxsumKele(a,n,k);
}