#include<bits/stdc++.h>
using namespace std;

void nextGreaterEle(int a[], int n){
    vector<int> ans;
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= a[i]) st.pop();
        
        if(st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());

        st.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    for(auto it : ans){
        cout<<it<<" ";
    }
}

int main(){
    int n = 5;
    int a[n] = {4,5,2,10,8};
    nextGreaterEle(a,n);
}