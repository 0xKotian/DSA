/*
Given an m x n 2D binary grid which represents a map of '1's (land) and '0's (water), return the number of islands.

logic -> create a 2D visited matrix and iterate through grid, if the number is 1 then search for top right left bottom for land i.e 1 and mark true for that i j index
in visited matrix. ignore all 0 
*/
#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int n,int m){
    if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == true || grid[i][j] != '1'){ // when the vertex is already visited by another vertex or if the vertex is 0 then return 
        return;
    }
    vis[i][j] = true;
    dfs(i-1,j,vis,grid,n,m);
    dfs(i,j+1,vis,grid,n,m);
    dfs(i+1,j,vis,grid,n,m);
    dfs(i,j-1,vis,grid,n,m);
}

int numIsland(vector<vector<char>> &grid){
    int island = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '1' && vis[i][j] == false){
                dfs(i,j,vis,grid,n,m); // once the dfs function is called it finds all the land adjacent to it. therefore confirms a island and returns 
                island++; // once the dfs function is returned then all the land surrounding for that vertex is marked visited (true) and it together forms one island 
            }
        }
    }
    return island;
}

int main(){
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    cout<<"number of islands : "<<numIsland(grid);
}