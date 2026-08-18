/*
to find the median of 2 sorted arr 

logic -> first add the the sizes of both the arr and find the index1 and index2 (i.e n/2-1 and n/2 respectively) which are used to find the medium.
imagin merging 2 arr and find the elements of index1 and index2,(not actually merging but tracking the index by using the cnt,when cnt is same the 
index 1 or 2 then that is the ele 1 and 2)and return ele2 if n is odd size and (ele1+ele2)/2 for n even size 
*/
#include<bits/stdc++.h>
using namespace std;

void MedianOf2Arr(int a[], int b[], int n1, int n2){
    int i = 0, j = 0,cnt=0;
    int ele1,ele2;
    int n = n1 + n2;
    int ind1 = n/2 - 1, ind2 = n/2;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            if(cnt == ind1) ele1 = a[i];
            if(cnt == ind2) ele2 = a[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == ind1) ele1 = b[j];
            if(cnt == ind2) ele2 = b[j];
            cnt++;
            j++;
        }
    }
    while(i < n1){
        if(cnt == ind1) ele1 = a[i];
        if(cnt == ind2) ele2 = a[i];
        cnt++;
        i++;
    }
    while(j < n2){
        if(cnt == ind1) ele1 = b[j];
        if(cnt == ind2) ele2 = b[j];
        cnt++;
        j++;
    }
    if(n % 2 == 1) cout<<ele2;
    else cout << (ele1+ele2)/2;
}

int main(){
    int n1 = 6;
    int n2 = 4;
    int a[n1] = {1,3,4,7,10,12};
    int b[n2] = {2,3,6,15};
    MedianOf2Arr(a,b,n1,n2);
}