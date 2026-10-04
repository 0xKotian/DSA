/*
diameter of a BT is The longest path between any two nodes in the tree, which may or maynot pass through root node.

logic -> go to each node and find the length opf left and right subtree and if left+right length is more than diameter then update the diameter and return 1 + max of left or
right subtree length. (1 is the current node and max of left or right length is added to it nad returns to the upper node)  
*/
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

int MaxDistance(node* root, int &diameter){
    if(root == nullptr) return 0;
    int left = MaxDistance(root->left,diameter);
    int right = MaxDistance(root->right,diameter);
    diameter = max(diameter,left+right);
    return(1 + max(left,right));
}

int problem(node* root){
    int diameter = 0;
    MaxDistance(root,diameter);
    return diameter;
}

int main(){
    node* root = new node(1);
    root->left= new node(2);
    root->right = new node(3);
    root->left->left= new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(8);
    root->right->left = new node(6);
    root->right->left->left = new node(7);
    root->right->left->right = new node(8);
    root->right->left->right->right = new node(9);
    root->right->left->right->right->left = new node(10);
    root->right->right = new node(11);
    cout<<problem(root);
}