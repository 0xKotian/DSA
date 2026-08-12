/*
problem states to move all the zeros to end and print array.
movezeros is done by using 2 pointers i and j 
output 1 2 3 0 0
*/
#include<bits/stdc++.h>
using namespace std;

void movezero(int a[], int n){
    int i = 0;
    for(int j = 0; j < n; j++){
        if(a[j] != 0){
            swap(a[i],a[j]);
            i++;
        }
    }
}
int main(){
    int n=5;
    int a[n] = {1,0,2,0,3};
    movezero(a,n);
    for(int i = 0; i < n; i++) cout<<a[i]<<" ";
}