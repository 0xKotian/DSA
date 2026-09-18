/*
length of the longest subarr of only k distinct integers. if a[] = {1,1,3,2,3,3,2,4} k=2 then length is 5 i.e 3,2,3,3,2.

logic-> take 2 pointers iterate through arr, store the number with its frequency in mpp every iteration. if size() of mpp is > k then start removing the frequency of a[l]
in mpp. and l++; when size() of mpp <= k update maxlen. 
*/
#include<bits/stdc++.h>
using namespace std;

void longestsubarr(int a[], int n, int k){
    int l=0,r=0,maxlen=0;
    unordered_map<int,int> mpp; // stores integer with its frequency.
    while(r < n){
        mpp[a[r]]++;
        if(mpp.size() > k){ // if size of mpp exceed k it will remove freq of left ponter number and if the freq is 0 then erase that number from mpp and l++;
            mpp[a[l]]--;
            if(mpp[a[l]] == 0) mpp.erase(a[l]);
            l++;
        }
        if(mpp.size() <= k){ // updates the maxlen when ever mpp size is in k limit. 
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    cout<<"longest subarr "<< maxlen;
    return;
}

int main(){
    int n = 11;
    int a[n] = {3,3,3,1,2,1,1,2,3,3,4};
    int k = 2;
    longestsubarr(a,n,k);
}