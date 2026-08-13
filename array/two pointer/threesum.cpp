/*
the three sum probelem states to print 3 numbers whose sum is 0,but the elements should not be repeated.
logic-> for elements not to be repeated we first sort the array and i will be at starting and j will be iterating from i+1 and k will be iterating from n-1
every iteration of i the element should not be same so we run the continue condetion(line 13). when we find the sum we j++ and k-- until we get new element 
*/
#include<bits/stdc++.h>
using namespace std;

void threesum(vector<int> &a, int n){
    vector<vector<int>> ans;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(i>0 && a[i] == a[i-1]) continue;//every iteration ith element in arr should not be same,so continue till ith element is different
        int j = i+1;
        int k = n-1;
        while(j < k){
            int sum = a[i] + a[j] + a[k];
            if(sum < 0){ // that is we need bigger number, since arr is sorted so we do j++
                j++;
            }
            else if(sum > 0){ //that is we need smaller number, since arr is sorted so we do k--
                k--;
            }
            else{
                vector<int> temp = {a[i],a[j],a[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && a[j] == a[j-1]) j++; // next iteration jth element should not be same
                while(j<k && a[k] == a[k+1]) k--; // next iteration kth element should not be same
            }
        }
    }
    for(auto x: ans){ // this is used to print
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