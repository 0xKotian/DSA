/*
the four sum probelem states to print 4 numbers whose sum is equal to target,but the elements should not be repeated.
logic-> for elements not to be repeated we first sort the array and i will be at starting and j will be iterating from i+1 and k will be iterating from j+1 
and l will be iterating from n-1.every iteration of i the element should not be same so we run the continue condetion(line 14). 
when we find the sum we k++ and l-- until we get new element 
*/
#include<bits/stdc++.h>
using namespace std;

void foursum(vector<int> &a, int n,int target){
    vector<vector<int>> ans;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(i>0 && a[i] == a[i-1]) continue;//every iteration ith element in arr should not be same,so continue till ith element is different
        for(int j = i+1;j<n;j++){
            if(j>1 && a[j] == a[j-1]) continue;//every iteration jth element in arr should not be same,so continue till jth element is different
            int k = j+1;
            int l = n-1;
            while(k < l){
                int sum = a[i] + a[j] + a[k] + a[l];
                if(sum < target){ // that is we need bigger number, since arr is sorted so we do k++
                    k++;
                }
                else if(sum > target){ //that is we need smaller number, since arr is sorted so we do l--
                    l--;
                } 
                else{
                   vector<int> temp = {a[i],a[j],a[k],a[l]};
                   ans.push_back(temp);
                   k++;
                   l--;
                   while(k<l && a[k] == a[k-1]) k++; // next iteration kth element should not be same
                   while(k<l && a[l] == a[l+1]) l--; // next iteration lth element should not be same
                }
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
    vector<int> a = {1,0,-1,0,-2,2,4,5};
    int n = a.size();
    int target = 8;
    foursum(a,n,target);
}


