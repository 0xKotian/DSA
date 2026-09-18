/*
length of the longest substring after replacing k char. if a[] = {abcbadaa} k=2 then length is 5 i.e b(replace to a), a, d(replace to a), a, a

logic-> take 2 pointers iterate through string, add all char freq to mpp. use maxf to find the max freq of a single char in that iteration window.
use replace to count the number of char that need to be changed to make a valid substring. 
*/
#include<bits/stdc++.h>
using namespace std;

void longestsubstr(string s, int n, int k){
    int l=0,r=0,maxlen=0,maxf=0;
    unordered_map<char,int> mpp; // stores char and its freq. 
    while(r < n){
        mpp[s[r]]++;// update char in every iteration 
        maxf = max(maxf,mpp[s[r]]); // used to keep the count of max freq of a single char in that iteration window.
        int replace = (r-l+1) - maxf; // length of substr in that window - repeating char gives the number of char that needs to be changed.
        if(replace > k){ // number of replacing char exceeds the limit then reduce the freq of left ptr number and move l++
            mpp[s[l]]--;
            l++;
        }
        if(replace <= k){ // if  replacing cahr is in limit then update maxlen.
            maxlen = max(maxlen,r-l+1);
        }
        r++;
    }
    cout<<"longest substring "<< maxlen;
    return;
}

int main(){
    string s = "vababdb";
    int n = s.size();
    int k = 2;
    longestsubstr(s,n,k);
}