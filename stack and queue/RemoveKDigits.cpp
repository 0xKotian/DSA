/*
remove any k digits from the string and make the smallest number without rearranging the numbers.
*/
#include<bits/stdc++.h>
using namespace std;

string RemoveKDigits(string s, int k){
    stack<char> st;
    for(auto it : s){
        while(!st.empty() && k > 0 && st.top() > it){//pop the top ele if the top() > iterating ele. and reduce k 
            st.pop();
            k--;
        }
        st.push(it);// push ele.
    }
    while(!st.empty() && k > 0){// if ele are in assending order then all ele will be pushed to st, nothing will be popped.
        st.pop();               // so remove k elements from top.
        k--;
    }
    string res;
   while(!st.empty()){ // store the ele from st to string res, here the number will be stored in reverse order. 
    res.push_back(st.top());
    st.pop();
   }
    while(!res.empty() && res.back() == '0'){// if res is 0020 then removes zeros => res = 002, after reverse res = 200.
        res.pop_back();
    }
    reverse(res.begin(),res.end());// reverse befoe returning.
    if(res.empty()) return "0";
    else return res;
}

int main(){
    string s = "1432219";
    int k = 3;
    string ans = RemoveKDigits(s,k);
    for(auto it : ans){
        cout<<it;
    }
}