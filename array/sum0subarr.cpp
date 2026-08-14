/*
find the length of the longest subarr with sum 0;

logic -> take map data structure to store the sum and index. iterate in the array and find the sum, if the sum == 0 then length is i+1,else if find the sum 
in the map and find the maximum of length or the i-mpp[sum]. else add the sum and the index to map. 
*/
#include<bits/stdc++.h>
using namespace std;
void sum0subarr(int a[], int n){
    int length=0,sum=0;
    map<int,int> mpp; 
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum == 0) length = i+1;
        else if(mpp.find(sum) != mpp.end()){
            length = max(length,i-mpp[sum]);// when the sum is not 0 and if the sum is already stored in tha map then i - index of the sum gives length of the 
        }                                   // subarr with sum 0.          
        else mpp[sum] = i;
    }
    cout<<"length of the longest subarr of sum 0 is "<<length;
}
int main(){
    int n = 5;
    int a[n] = {15,-8,7,1,10};
    sum0subarr(a,n);
}