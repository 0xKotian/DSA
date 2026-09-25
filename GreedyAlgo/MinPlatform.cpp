/*
given is arriving and departure time of train a[] and d[], return min number of platform is req.   
*/
#include<bits/stdc++.h>
using namespace std;

void MInplatform(int a[], int d[], int n){
    int i=0,j=0,cnt=0,max_cnt=0;
    sort(a,a+n);
    sort(d,d+n);
    while(i < n){
        if(a[i] <= d[j]){ // increase the platform cnt when the next arriving train time <= departure time of the priviously arrived train
            cnt++;
            i++;
        }
        else { // decrease the platform cnt when the next arriving train time > departure time of the priviously arrived train
            cnt--;
            j++;
        }
        max_cnt = max(max_cnt,cnt); // keep the cnt of the max platform needed during this iteration 
    }
    cout<<max_cnt;
}

int main(){
    int n = 6;
    int a[n] = {900,945,955,110,1500,1800};
    int d[n] = {925,1200,1130,1150,1900,2000};
    MInplatform(a,d,n);
}