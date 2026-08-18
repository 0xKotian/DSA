/*
find single ele in sorted arr which has other all elemnts twice.

lofic -> fist find if the a[0] != a[1] then the single ele is a[0]. if a[n-1] != a[n-2] then the single ele is a[n-1].
now the search range is from 1 to n-2. find the mid and see if a[mid] is not equal to previous and next element then the single ele is a[mid].
since the elements are present twice so the single ele will always be in even index.
left side of the single ele apirs are => (even index,odd index); right side of the single ele pair are => (odd index,even index).

if mid is in the odd index and a[mid] == a[mid-1] then all the elements to the left of mid is in sorted pair, therefore single ele is in right side. OR
if mid is in the even index and a[mid] == a[mid+1] then all the elements to the left of mid is in sorted pair, therefore single ele is in right side.
else single ele is in left side of mid.

If mid is correctly paired according to the normal (even, odd) pattern -> go right. Otherwise -> go left.
*/ 
#include<bits/stdc++.h>
using namespace std;

int FindSingleEle(int a[], int n){
    if(n == 1 || a[0] != a[1]) return a[0];
    if(a[n-1] != a[n-2]) return a[n-1];
    int low =1;
    int high = n-2;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] != a[mid-1] && a[mid] != a[mid+1]) return a[mid]; 
        if(mid % 2 == 1 && a[mid] == a[mid-1] || mid % 2 == 0 && a[mid] == a[mid+1]) low = mid + 1;
        else high = mid - 1; 
    }
    return -1;
}

int main(){
    int n = 9;
    int a[n] = {1,1,2,2,3,3,4,5,5,};
    int res = FindSingleEle(a,n);
    if(res != -1)cout<<"ele is "<<res;
    else cout<<"not found";
}