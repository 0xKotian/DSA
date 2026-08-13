#include<bits/stdc++.h>
using namespace std;
void sum0subarr(int a[], int n){
    int length=0,sum=0;
    map<int,int> mpp;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum == 0) length = i+1;
        else if(mpp.find(sum) != mpp.end()){
            length = max(length,i-mpp[sum]);
        }
        else mpp[sum] = i;
    }
    cout<<"length of the longest subarr of sum 0 is "<<length;
}
int main(){
    int n = 5;
    int a[n] = {15,-8,7,1,10};
    sum0subarr(a,n);
}