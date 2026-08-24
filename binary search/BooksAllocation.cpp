/*
book allocation -> u need to allocate the books to given number of students in a continuous order such that u return the minimum of the max number of 
books alloacted to a single student.

logic -> low will be the max ele and high will be the sum of all ele.
here low = 49 then u need n number of students to allocate all the books, high = 172 u need only 1 student to allocate the books. 
we need to find the minimum number of books that can be allocated to 4 students.
*/
#include<bits/stdc++.h>
using namespace std;

int count_stu(int a[], int n , int mid){
    int t_books = 0;
    int cnt = 1;
    for(int i =0;i<n;i++){
        if(t_books+a[i] <= mid) t_books += a[i];
        else{
            cnt++;
            t_books = a[i];
        } 
    }
    return cnt;
}

void BooksAllocation(int a[], int n , int students){
    if(students > n){
        cout<<"invalid";
        return;
    }
    int low = *max_element(a,a+n);
    int high = accumulate(a,a+n,0);
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(count_stu(a,n,mid) <= students){
            ans = mid;
            high = mid -1;
        }
        else low = mid +1;
    }
    if(ans == -1) cout <<"unsucessful";
    else cout << ans;
}

int main(){
    int n =5;
    int a[n] = {25,46,28,49,24};
    int students = 4;
    BooksAllocation(a,n,students);
}