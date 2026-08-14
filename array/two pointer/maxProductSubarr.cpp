/*
max product sub arr states to find the sub arr whose product is maximum.

logic -> initialize leftproduct and rightproduct to 1. iterate through the arr and find the products of element from left side and als0 from the right side
in the same iteration. find the max of (maxi,max(leftproduct,rightproduct)).   
*/
#include<bits/stdc++.h>
using namespace std;

void maxproduct(int a[], int n){
    int leftproduct =1;
    int rightproduct = 1;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        if(leftproduct == 0) leftproduct =1;// whenever leftproduct is 0 initialize it to 1 of futher multiplication
        if(rightproduct == 0) rightproduct =1;// whenever rightproduct is 0 initialize it to 1 of futher multiplication
        leftproduct *= a[i];
        rightproduct *= a[n-i-1];
        maxi = max(maxi,max(leftproduct,rightproduct));
    }
    cout<<maxi;
}

int main(){
    int n = 5;
    int a[n] = {2,5,0,6,3};
    maxproduct(a,n);
}