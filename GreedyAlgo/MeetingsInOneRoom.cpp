/*
each meeting has {start,end} time adn there is one room, you have to schedule the max number of meeting.

logic -> sort the {start,end} arr in ascending order of end time. if the start time is > than the last end timing then the meeting can happen so cnt++.
*/
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second <= b.second;  
}

void problem(vector<pair<int,int>> a){
    int cnt=0,last_end=0;
    sort(a.begin(),a.end(),compare);
    for(auto it : a){
        if(it.first >= last_end){
            cnt++;
            last_end = it.second;
        }
    }
    cout<<cnt;
}

int main(){
    vector<pair<int,int>> a = {{0,6},{5,9},{1,2},{5,7},{8,9},{3,4}};
    problem(a);
}