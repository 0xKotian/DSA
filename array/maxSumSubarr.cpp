#include<bits/stdc++.h>
using namespace std;
void maxsumsubarr(int a[],int n){
    int cur = a[0];
    int maxi = a[0];
    for(int i=1;i<n;i++){
        cur = max(a[i],cur+a[i]);
        maxi = max(cur,maxi);
    }
    cout<<maxi;
}

int main(){
    int n = 5;
    int a[n] = {2,-1,6,-9,-8};
    maxsumsubarr(a,n);
}