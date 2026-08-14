/*
left rotating of the array d times is done by first rotating the array till the dth element and then rotating the elements after dth element and then finally 
rotating all the elements  
for right rotate:
reverse(a,0,n-1-d);
reverse(a,d+1,n-1);
reverse(a,0,n-1);

if u use vector<int> u can use the in built stl (reverse works in range => [first,last))
reverse(a.begin(),a.begin(+d)) -> 3 2 1 4 5 6 7
reverse(a.begin()+d,a.end()) -> 3 2 1 7 6 5 4
reverse(a.begin(),a.end()) -> 4 5 6 7 1 2 3
*/
#include<bits/stdc++.h>
using namespace std;

void reverse(int a[], int start, int end){
    while(start <= end){
        swap(a[start],a[end]);
        start++;
        end--;
    }
}
void leftrotate(int a[], int n, int d){
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
}
int main(){
    int n=7;
    int a[n] = {1,2,3,4,5,6,7};
    int d=3;
    leftrotate(a,n,d);
    for(int i = 0; i < n; i++) cout<<a[i]<<" ";
}