#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=6;
    vector<int> a = {2,8,5,9,4,0};
    next_permutation(a.begin(),a.end());
    for(int i=0;i<n;i++){
        cout<<a[i];
        
    }
}