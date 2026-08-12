#include<bits/stdc++.h>
using namespace std;

void threesum(vector<int> &a, int n){
    vector<vector<int>> ans;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(i>0 && a[i] == a[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j < k){
            int sum = a[i] + a[j] + a[k];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int> temp = {a[i],a[j],a[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && a[j] == a[j-1]) j++;
                while(j<k && a[k] == a[k+1]) k--; 
            }
        }
    }
    for(auto x: ans){
        for(auto it:x){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<int> a = {2,0,-1,-2,0,-2,-2,-1,2,-1,0,2};
    int n = a.size();
    threesum(a,n);
}