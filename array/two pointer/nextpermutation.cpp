/*
next permutation means let 132 is the given number then all the permutation in sorted order is {123 132 213 231 312 321}. therefore next permutation of 
132 is 213. next permutation of 321 is 123.

logic -> iterate from last second number adn find a number which has a greater number to its right side. initialize it to index i. then iterate from n-1 
till that index and find the number that is grater than the number in the index,swap both and reverse the arr from index+1 till end.
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> nextpermutation(vector<int> &a, int n){
    int index =-1;
    for(int i =n-2;i>=0;i--){
        if(a[i] < a[i+1]){
            index = i;
            break;
        }
    }
    if(index == -1){
        reverse(a.begin(),a.end());// if there is no next permutation then reverse the arr and return.
        return a;
    }
    else{
        for(int i=n-1;i>index;i--){
            if(a[i] > a[index]){
                swap(a[i],a[index]);
                break;
            }
        }
    }
    reverse(a.begin()+index+1,a.end());
    return a;
}

int main(){
    int n=6;
    vector<int> a = {2,8,5,9,4,0};
    nextpermutation(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i];
        
    }
}