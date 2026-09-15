/*
logic -> we need the next smaller element index and the previous smaller element index to find the maxarea with the height of a element of index. formula for finding the 
maxarea is a[index]*(nsi-psi-1).   
*/
#include<bits/stdc++.h>
using namespace std;

int largestrectangle(int a[], int n){
    stack<int> st;
    int maxarea = 0;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()] > a[i]){// checking the maxarea of the st.top() index element with next smaller index(nsi) as i because a[st.top()] > a[i] and previous
                                                // smaller index(psi) as the second top() if st is not empty. if empty -1
            int index = st.top();
            st.pop();// we area finding maxarea of st.top() which is assigned to index so pop() st.top element.
            int nsi = i;
            int psi = (st.empty()) ? -1 : st.top(); // here the st.top() will be the previous small ele for element for a[index].
            maxarea = max(a[index]*(nsi-psi-1),maxarea);
        }
        st.push(i);
    }
    while(!st.empty()){
        int index = st.top();
        st.pop();
        int nsi = n;
        int psi = (st.empty()) ? -1 : st.top();
        maxarea = max(a[index]*(nsi-psi-1),maxarea);
    }
    return maxarea;
}

int main(){
    int n = 6;
    int a[n] = {2,1,5,6,2,3};
    cout<<largestrectangle(a,n);
}