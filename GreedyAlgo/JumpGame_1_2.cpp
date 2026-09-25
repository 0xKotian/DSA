/*
jump1 -> each element of a[i] represent max jump length you can make, you are at 0th index and need to reach or cross n-1th index. return yes or no

jump2 -> each element of a[i] represent max jump length you can make, you are at 0th index and need to reach or cross n-1th index. return number of jumps req
*/
#include<bits/stdc++.h>
using namespace std;
/*
logic -> iterate through every element and find the farthest jump that can be made. and point the current end to the farthest and i.e where jump is counted.  
*/
int jump2(int a[], int n){
    int farthest=0,current_end=0,jump=0;
    for(int i=0; i < n; i++){
        farthest = max(farthest,i+a[i]);

        if(i == current_end){
            jump++;
            current_end = farthest;

            if(current_end >= n-1) break;
        }
    }
    return jump;
}

string jump1(int a[], int n){
    int i=0,farthest=0;
    while(i < n && i<= farthest){
        farthest = max(farthest,i+a[i]);
        i++;
    }
    return (farthest >= n-1) ? "yes" : "no";
}

int main(){
    int n = 8;
    int a[n] = {1,2,4,1,1,0,2,5};
    cout<<"jump game 1 result : "<<jump1(a,n)<<endl;
    cout<<"jump game 2 result : "<<jump2(a,n)<<endl;
}