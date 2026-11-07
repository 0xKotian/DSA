/* to iterate through the binary tree in the vertical format */
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    
    node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
void problem(node* root){
    map<int,map<int,multiset<int>>> mpp; // create a map with x coordinate and another map inside which stores the y coordinates
    // along with the data stored in multiset(which stores the data in ascending order / sorted manner) 
    queue<pair<node*,pair<int,int>>> q; // in every iteration node and the x y coordinates will be stored
    q.push({root,{0,0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        node* temp = p.first;
        int x = p.second.first;
        int y = p.second.second;
        mpp[x][y].insert(temp->data); // inserts the value of the node of that x y coordinate
        if(temp->left) q.push({temp->left,{x-1,y+1}});
        if(temp->right) q.push({temp->right,{x+1,y+1}});
    }
    vector<vector<int>> ans;
    for(auto it : mpp){
        vector<int> cols;
        for(auto x : it.second){
            cols.insert(cols.end(), x.second.begin(), x.second.end()); // means insert from end, x.second is multiset and insert
            //from .begin() to the .end() of that particular iteration
        }
        ans.push_back(cols);
    }

    for(auto it : ans){
        for(auto x : it){
            cout<<x<<" ";
        }
    }
}

int main(){
node* root = new node(1);
    root->left= new node(2);
    root->right = new node(3);
    root->left->left= new node(4);
    root->left->right = new node(5);
    root->left->right->right = new node(8);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->left = new node(9);
    root->right->right->left->right = new node(11);
    root->right->right->right = new node(10);
    problem(root);
}