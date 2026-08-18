#include<bits/stdc++.h>
using namespace std;

void IntegerOfSqroot(int n){
    int low = 1;
    int high = n;
    int ans;
    while(low <= high){
        int mid = (low+high)/2;
        if(mid*mid <= n) ans = mid;
        if(mid*mid > n) high = mid - 1;
        else low = mid + 1;
    }
    cout<<ans;
}

int main(){
    int n = 28;
    IntegerOfSqroot(n);
}