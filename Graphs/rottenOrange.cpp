/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, 
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally(top,bottom,left,right) adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

logic -> we will use modified BFS starting from rotten orange(i.e number 2) and iterate to their neighbours first(first level neighbour), all the neighbours get 
rotten in that first min. next iterate to their neighbour(second level neighbours) that get rotten in second min. 
*/
#include<bits/stdc++.h>
using namespace std;

int rottenOrange(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    queue<pair<pair<int,int>,int>> q; // stores ((i,j),time)
    for(int i=0;i<n;i++){ // mark visited for only rotten oranges 
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                vis[i][j] = true;
            }
        }
    }

    while(q.size() > 0){
        int i = q.front().first.first;
        int j = q.front().first.second;
        int time = q.front().second;
        q.pop();

        ans = max(ans,time);
        if(i-1 >= 0 && vis[i-1][j] == false && grid[i-1][j] == 1){ // search for top neighbour
            q.push({{i-1,j},time+1});
            vis[i-1][j] = true;
        }
        if(i+1 < n && vis[i+1][j] == false && grid[i+1][j] == 1){ // search for bottom neighbour
            q.push({{i+1,j},time+1});
            vis[i+1][j] = true;
        }
        if(j-1 >= 0 && vis[i][j-1] == false && grid[i][j-1] == 1){ // search for left neighbour
            q.push({{i,j-1},time+1});
            vis[i][j-1] = true;
        }
        if(j+1 < m && vis[i][j+1] == false && grid[i][j+1] == 1){ // search for right neighbour
            q.push({{i,j+1},time+1});
            vis[i][j+1] = true;
        }
    }
    // search for any left out good orange (i.e number 1) if yes then return -1 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 && vis[i][j] == false){
                return -1;
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout<<rottenOrange(grid);
}