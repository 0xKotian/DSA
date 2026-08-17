/*
floor -> largest number in arr <= target
ceil -> smallest number in arr >= taregt 
*/
#include<bits/stdc++.h>
using namespace std;

void FloorAndCeil(int a[],int n,int target){
    int low = 0,mid,high = n-1,floor=-1,ceil=-1;
    while(low <= high){
        mid = (low + high)/2;
        if(a[mid] == target){
            floor = a[mid];
            ceil = a[mid];
            break;
        }
        else if(a[mid] > target){
            ceil = a[mid];
            high = mid-1;
        }
        else {
            floor = a[mid];
            low = mid+1;
        }
    }
    if(floor == -1) cout<<"floor not found"<<endl;
    else cout<<"floor is "<<floor<<endl;

    if(ceil == -1) cout<<"ceil not found"<<endl;
    else cout<<"ceil is "<< ceil;
}

int main(){
    int n = 6;
    int a[n] = {1,3,5,7,9,11};
    int target = 6;
    FloorAndCeil(a,n,target);
}