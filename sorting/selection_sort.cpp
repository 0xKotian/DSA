#include<bits/stdc++.h>
using namespace std;

void selection_sort(int a[], int n){
    int mini,i,j,temp;
    for(i = 0; i <= n-2; i++){
        mini = i;
        for(j = i+1; j <= n-1; j++){
            if(a[j] < a[mini]) mini = j;
        }
        temp = a[mini];
        a[mini] = a[i];
        a[i] = temp;
    }
    for(i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}

int main() { 
    int n=5;
    int a[5] = {54,21,46,37,12};
    selection_sort(a,n);
    return 0;
}