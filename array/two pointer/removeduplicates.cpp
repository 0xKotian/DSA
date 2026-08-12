/*
problem states to remove all the duplicate numbers and print only unique numbers.
removing the duplicates is done by using 2 pointers i and j 
output 1 2 3
*/
#include<bits/stdc++.h>
using namespace std;

int removedup(int a[], int n){
    int i = 0;
    for(int j = 0; j < n; j++){
        if(a[i] != a[j]){
        a[i+1] = a[j];
        i++;
        }
    }
    return i+1;
}
int main(){
    int n=5;
    int a[n] = {1,1,2,3,3};
    int n1 = removedup(a,n);
    for(int i = 0; i < n1; i++) cout<<a[i]<<" ";
}