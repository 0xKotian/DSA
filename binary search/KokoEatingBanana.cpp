/*
u will be given with arr of which includes number of bananas and u have to find the speed of bananas(k bananas per hr)that koko can finish in h hours.
for example {3,6,7,11} 
3 banana per hr => 1+2+3+4 = 10 hr to eat all bananas (7/3 = 2.33 hr ~ 3 hr we have to take the ceil value)
1 banana per hr => 3+6+7+11 = 27 hr to eat alla bananas
11 or more that 11 bananas per hr => 1+1+1+1 = 4 hr t eat all bananas

logic -> koko can eat 1 banana per hr or 11 banana per hr. this is our binary search range. find the mid and find the total hr needed with mid bananas/hr speed
if the total hr is within the given hr range then that is the ans and find leftside of mid or else right side of mid
*/
#include<bits/stdc++.h>
using namespace std;

int NumberOfHrs(int a[], int mid , int n){
    int t_hrs = 0;
    for(int i=0;i<n;i++){
        t_hrs += ceil((double)a[i]/mid);//since a[i] and mid both are int we get integer as we devide so change the data type to double to get floting number 
    }                                   //and then convert it to ceil of the number.
    return t_hrs;
}

void kokoEatingBanana(int a[], int n, int h){
    int low = 1;
    int high = *max_element(a,a+n);
    int ans;
    while(low <= high){
        int mid = (low + high)/2;
        int t_hrs = NumberOfHrs(a,mid,n);
        if(t_hrs <= h){
            ans = mid;
            high = mid -1; 
        }
        else low = mid +1;
    }
    cout << ans << " bananas per hour";
}

int main(){
    int n = 4;
    int h = 8;
    int a[n] = {3,6,7,11};
    kokoEatingBanana(a,n,h);
}