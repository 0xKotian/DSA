/*
u will be given with 2 sorted arr and need to merge both the arr without using any extra space.

logic -> use 2 pointers i= n-1 and j=0 and iterate from right side of a[] and left side from b[] compare the last element of a[] with the first element
of the b[] if its a[i] > b[j] then swap a[i] and b[j], this will sort the arrays where a[] will have only the smaller elements and b[] will have the 
next greater elements. sort a[] and b[] and now print a[] then b[]. 
*/
#include<bits/stdc++.h>
using namespace std;

void mergearr(int a[], int b[], int n, int m){
    int i = n-1;
    int j = 0;
    while(i>=0 && j<m){
        if(a[i] > b[j]){
            swap(a[i],b[j]);
            i--;
            j++;
        }
        else break;
    } 
    sort(a,a+n);
    sort(b,b+m);
    for(int k=0;k<n;k++){
        cout<<a[k]<<" ";
    }
    for(int k=0;k<m;k++){
        cout<<b[k]<<" ";
    }
}
int main(){
    int n = 4;
    int m = 5;
    int a[n] = {0,1,2,3};
    int b[m] = {5,6,7,8,9};
    mergearr(a,b,n,m);
}