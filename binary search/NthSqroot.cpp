/*
find the Nth sqroot of the given number.
logic -> 
mid^N > n  -> go LEFT
mid^N = n  -> ANSWER
mid^N < n  -> go RIGHT
*/
#include<bits/stdc++.h>
using namespace std;

int power(int mid,int n,int N){
    long long res = 1;
    for(int i=1; i<=N; i++){
        res = res*mid;
        if(res > n) return 0;
    }
    if(res == n) return 1;
    return 2;
}

void NthSqroot(int n, int N){
    int low = 1;
    int high = n;
    int ans;
    while(low <= high){
        int mid = (low + high)/2;
        int val = power(mid,n,N);
        if(val == 1) {
            ans = mid;
            break;
        }
        if(val == 0) high = mid - 1;
        else low = mid + 1;
    }
    cout << ans;
}

int main(){
    int n = 64;
    int N = 3;
    NthSqroot(n,N);
}