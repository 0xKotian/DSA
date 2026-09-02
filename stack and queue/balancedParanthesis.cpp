/*
expression will be given having paranthesis. return if it is balanced or not. (){[]} -> balanced (){[])} -> not balanced. every opening of paranthesis
should have its closed paranthesis and vice versa.

logic -> iterate through the string and if its a open paranthesis then push it in stack if its closing paranthesis then its open paranthesis should be
at the top of stack. when u find the open paranthesis of the closed paranthesis the pop it out. at end check if the stack is empty or not if empty then balanced. 
*/
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