/*
u have to find the next greater element of the ith index ele in the given arr.
*/
#include<bits/stdc++.h>
using namespace std;

void nextGreaterEle(int a[], int n){
    vector<int> ans;
    stack<int> st;
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= a[i]) st.pop();// check if a[i] is greater then top ele if yes then their next greater ele is a[i], therefore pop.
                                                        // here the st will be empty or top ele is graeter than a[i]. 
        if(st.empty()) ans.push_back(-1);// when st is empty pushback -1 to ans 
        else ans.push_back(st.top()); // if not empty then the top ele is greater than a[i], pushback top to ans.

        st.push(a[i]); // push a[i] to stack.
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

/*
next greater ele in a circular arr means after the n-1 index is 0th index.
a[] = {2,10,12,1,11} = ans = 10 12 -1 11 12

logic -> for(int i = 2*n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= a[i%n]) st.pop(); 

        if(i < n) ans.push_back((st.empty()) ? -1 : st.top());

        st.push(a[i%n]); 
    }
*/