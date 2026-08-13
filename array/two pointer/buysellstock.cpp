/*
buy and sell stock problem gives array of price of stock daywise,we have to print when to buy and when to sell the stock inorder to have maximum profit

logic -> initialize the minimum price to buy at 1st day,maxprofit to 0 and iterate from 2nd day, if the profit is greater than to equal to maxprofit then 
initialize the sellday to that index and update the maxprofit, if the value of that day is less than the minimum price that initialize the buyday to that
index adn update the minimum price. 
*/
#include<bits/stdc++.h>
using namespace std;

void buysellstock(int a[], int n){
    int mini = a[0];
    int maxprofit = 0;
    int profit,buy,sell;
    for(int i = 1; i < n; i++){
        profit = a[i] - mini;
        if(profit >= maxprofit){
            sell = i;
            maxprofit = profit;
        }
        if(a[i] < mini){
            buy = i;
            mini = a[i];
        }
    }
    cout <<"buy day "<< buy+1<<endl;
    cout<<"sell day "<< sell+1<<endl;
    cout<<"total profit "<<maxprofit;
}

int main(){
    int n = 6;
    int a[n] = {7,1,5,3,6,4};
    buysellstock(a,n);
}