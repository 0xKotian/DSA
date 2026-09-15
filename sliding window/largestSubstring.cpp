/*
find the length of largest substring without repeating character.
logic -> take l and r as 2 reference pointers for sliding window, iterate through the string and find maxlen by r-l+1 and add the char and its index. if u find the same char
again then increase l. 
*/
#include<bits/stdc++.h>
using namespace std;

int largestsubstring(string s){
    unordered_map<char,int> mpp;// used to store char and its last accurance index. 
    int n = s.size();
    int l = 0, r = 0, maxlen = 0;
    while(r < n){
        if(mpp.find(s[r]) != mpp.end()){// means s[r] char is present in the mpp
            if(mpp[s[r]] >= l) l = mpp[s[r]]+1;// if the last accurance index of the char is >= l then l is +1 index of that char. 
        }
        maxlen = max(maxlen,r-l+1);
        mpp[s[r]] = r;
        r++;
    }
    return maxlen;
}

int main(){
    string s = "cadbzabcd";
    cout<<largestsubstring(s);
}