/*
agressive cows -> find the largest of the minimum distance of cows in the arr 
u will be given the arr of coordinates and we have to place the number of cows(here 4) and find the minimum distance bw them and return the 
largest of these minimum distance

logic -> low = 0 and high = a[n-1] - a[0] find mid, now find the number of cows that can be kept with mid as the minimum distance two cows
if the cows count with mid as the minimum distance is greater than or equal to the given number of cows then store the ans and find to right 
side else find left side.     
*/
#include<bits/stdc++.h>
using namespace std;

int countcows(int a[], int n, int mid, int cows){
    int cow_cnt = 1, last_cow = a[0];// first cow is always kept in the a[0] and cow count will be 1.
    for(int i =1;i<n;i++){
        if(a[i] - last_cow >= mid){
            cow_cnt++;
            last_cow = a[i];
        }
    }
    if(cow_cnt >= cows) return 0;
    else return -1;
}

void AgressiveCows(int a[],int n, int cows){
    int low = 0;
    int high = a[n-1] - a[0];
    int ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(countcows(a,n,mid,cows) == 0){
            ans = mid;
            low = mid +1;
        }
        else high = mid -1;
    }
    if(ans == -1) cout <<"unsucessful";
    else cout << ans;
}

int main(){
    int n = 6;
    int a[n] = {0,3,4,7,9,10};
    int cows = 4;
    AgressiveCows(a,n,cows);
} 
