/*
maximize total value taht can fit in a bag of capacity w(weight), where given arr has {val,weight} of an item and u can take fractions of items

logic -> greedly sort the arr in decending order of value per weight (val/weight) adn take the starting items and take fractions from last.
*/
#include<bits/stdc++.h>
using namespace std;
// every time sort() calls comapare, if comapare(a,b) is true, sort will place a before b. so that it arranges items in descending order of val/weight
bool compare(pair<int,int> a, pair<int,int> b){
    return (double) a.first / a.second > b.first / b.second; // first is val and second is weight therefore val/weight
}

void problem(vector<pair<int,int>> a, int w){
    int total=0;
    sort(a.begin(),a.end(),compare);// sorts the arr as val/weight descending order. 
    for(int i=0;i<a.size();i++){
        if(a[i].second <= w){
            total += a[i].first; // has u add the items to total reduce the w capacity with the ith item weight
            w -= a[i].second;
        }
        else{                                               // if 50(weight) -> 100 (val)
            total += (double) (a[i].first/a[i].second) * w ;//    10(w) ->     100/50 * w
             break;
        }
    } 
    cout<<total;
}

int main(){
    vector<pair<int,int>> a = {{100,20},{100,50},{60,10},{200,50}};
    int w = 90;
    problem(a,w);
}