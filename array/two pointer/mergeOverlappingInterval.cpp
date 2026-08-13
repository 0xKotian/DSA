/*
merge overlapping intervals we need to find the 
*/
#include<bits/stdc++.h>
using namespace std;

void mergeoverlapping(vector<vector<int>> &a,int n){
    vector<vector<int>> ans;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(ans.empty() || ans.back()[1] < a[i][0]){
            ans.push_back(a[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1],a[i][1]);
        }
    }
    for(auto x : ans){
        cout<<x[0]<<" "<<x[1]<<endl;
    }
}

int main(){
    vector<vector<int>> a = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
    int n = a.size();
    mergeoverlapping(a,n);
}