#include<bits/stdc++.h>
using namespace std; 

bool balancedParanthesis(string s){
    stack<char> st;
    for(char ch : s){
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }
        else{
            if(st.empty()) return false;
            char x = st.top();
            if((ch == ')' && x == '(') || (ch == '}' && x == '{') || (ch == ']' && x == '[')){
                st.pop();
            }
            else return false;
        }
    }
    return st.empty();
}

int main(){
    string s = "(){[]()}";
    if(balancedParanthesis(s)) cout<<"balanced";
    else cout<<"not balanced";
}