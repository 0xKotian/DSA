/*
union of 2 array means merge both array and print in sorted order adn no duplicates
logic -> assign 2 pointers i and j to a[] and b[] and check if the previous element are same then move the respective pointers. when previous element are 
differ in both the array then compare both the element and print the smallest element and move the pointer of the respective array
*/
#include<bits/stdc++.h>
using namespace std;

void unionofarr(int a[], int b[], int n, int m){
    int i=0,j=0;
    while(i < n && j < m){
        if(i>0 && a[i] == a[i-1]){ // skipping the duplicates in a[]
            i++;
            continue;
        }
        if(j>0 && b[j] == b[j-1]){ // skipping the duplicates in b[]
            j++;
            continue;
        }
        if(a[i] < b[j]){ // comparing if a[] < b[] then print and move i
            cout<<a[i]<<" ";
            i++;
        }
        else if(a[i] > b[j]){ // comparing if b[] < a[] then print and move j
            cout<<b[j]<<" ";
            j++;
        }
        else{
            cout<<a[i]<<" "; // if both the elements are same then print one adn move both the pointers
            i++;
            j++;
        }
    }
    while(i < n){ // if the elements in a[] are still leftout and all elements in b[] are over
        if(i == 0 || a[i] != a[i-1]){
            cout<<a[i]<<" ";
        }
        i++;
    }
    while(j < m){ //if the elements in b[] are still leftout and all elements in a[] are over
        if(j == 0 || b[j] != b[j-1]){
            cout<<b[j]<<" ";
        }
        j++;
    }
}
int main(){
    int n = 6, a[n] = {1,1,2,3,4,5};
    int m = 6, b[m] = {2,3,4,4,5,6};
    unionofarr(a,b,n,m);
}