/*
two sum prbm states to find if there is 2 elements whose sum is == target and print yes or no.

basic code logic -> to do nested loop 
for(i=0->n){
for(j=i->n){
if(a[i]+a[j] == target) print yes
}
} 

logic for optimal code -> first u need a sorted arr and using 2 pointer left=0 and right=n-1 add them and if the sum is less than target move left pointer(left++)
and if sum is greater then move then right pointer(right--).    
*/
#include<bits/stdc++.h>
using namespace std;

void twosum(vector<int> &a, int n, int target){ // TC -> O(n)+O(nlogn) SC -> O(1)
    int left=0,right=n-1;
    sort(a.begin(),a.end());
    while(left < right){
        int sum = a[left] + a[right];
        if(sum < target) left++;
        else if(sum > target) right--;
        else{
            cout<<"yes";
            return;
        }
    }
    cout<<"no";
}
/*
logic for solving using map -> u create a map which stores the element and the index, and iterate in the arr and find if target-a[i] is present in the map,
if not present the push it in map with the index.  
*/
void hashmap(vector<int> &a,int n,int target){ // TC -> O(nlogn) SC ->(n)
    map<int,int> mpp;
    for(int i=0; i<n; i++){
        if(mpp.find(target-a[i]) != mpp.end()){
            cout<<"yes, in index "<<mpp[target-a[i]]<<" "<<i<<endl;// prints index 
            cout<<"numbers are "<<a[mpp[target-a[i]]] <<" "<<a[i]; // prints the numbers 
            return;
        }
        mpp[a[i]] = i;
    }
    cout<<"no";
}
int main(){
    int n = 5;
    vector<int> a = {6,4,8,9,1};
    int target = 12;
    twosum(a,n,target);
    //hashmap(a,n,target);
}