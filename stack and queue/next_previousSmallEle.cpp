/*
find the next smaller ele to right, and find the previous smaller ele to left.
*/
#include<bits/stdc++.h>
using namespace std;

/*
logic -> iterate from the last and pop out top() ele until top() >= a[i]. pushback -1 if st is empty else pushback top().
at last reverse arr because iteration started from last.
*/
void nextsmaller(int a[], int n){
    vector<int> ans;
    stack<int> st;
    for(int i = n-1; i>=0 ; i--){
        while(!st.empty() && st.top() >= a[i]) st.pop();
        ans.push_back(st.empty() ? -1 : st.top());
        st.push(a[i]);
    }
    reverse(ans.begin(),ans.end());
    for(auto it : ans){
        cout<<it<<" ";
    }
    return;
}

/*
logic -> iterate from the starting and pop out top() ele until top() >= a[i]. pushback -1 if st is empty else pushback top().
*/
void previoussmaller(int a[], int n){
    vector<int> ans;
    stack<int> st;
    for(int i = 0; i<n ; i++){
        while(!st.empty() && st.top() >= a[i]) st.pop();
        ans.push_back(st.empty() ? -1 : st.top());
        st.push(a[i]);
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
    return;
}

int main(){
    int n = 5;
    int a[n] = {4,8,5,2,25};
    nextsmaller(a,n);
    previoussmaller(a,n);
}