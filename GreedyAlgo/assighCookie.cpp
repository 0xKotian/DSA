#include<bits/stdc++.h>
using namespace std;

void assignCookie(vector<int> s, vector<int> c, int n, int m){
    int l=0,r=0,cnt=0;
    sort(s.begin(),s.end());
    sort(c.begin(),c.end());
    while(l < n && r < m){
        if(s[l] <= c[r]){
            cnt++;
            l++;
        }
        r++;
    } 
    cout<< cnt;
}

int main(){
    vector<int> satisfy = {1,5,3,3,4};
    vector<int> cookieSize = {4,2,1,2,1,3};
    int n = satisfy.size();
    int m = cookieSize.size();
    assignCookie(satisfy,cookieSize,n,m);
 }