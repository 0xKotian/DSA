/*
A binary tree is balanced if the height difference between the left and right subtrees of every node is at most 1.

logic -> Return height if balanced, return -1 if unbalanced.
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

int checkbalanced(node* root){
    if(root == nullptr) return 0;
    int left = checkbalanced(root->left);
    if(left == -1) return -1;
    int right = checkbalanced(root->right);
    if(right == -1) return -1;
    if(abs(left - right) > 1) return -1;
    return(1 + max(left,right)); 
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6);
    int ans = checkbalanced(root);
    if(ans != -1) cout<<"balnced ";
    else cout<<"not balanced";
}