/*
4 --> survives
7 --> <-- -7 collision
1 and 2 --> <-- -3 collision
17 --> and <-- -16 17 survives
ans = 17 and 4 
*/
#include<bits/stdc++.h>
using namespace std;

void aestroid(int a[], int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        bool destroyed = false;
        while(!st.empty() && st.top() > 0 && a[i] < 0){
            if(st.top() < abs(a[i])){
                st.pop();
                continue;
            }
            else if(st.top() == abs(a[i])) st.pop();
            
            destroyed = true;
            break;
        }
        if(!destroyed) st.push(a[i]); 
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return;
}

int main(){
    int n = 8;
    int a[n] = {4,7,1,2,-3,-7,17,-16};
    aestroid(a,n);
}