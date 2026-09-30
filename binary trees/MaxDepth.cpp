/*
create a recursive function that counts the left side lenth and then right side length and gives the longest length.  
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

int maxdepth(node* root){
    if(root == nullptr) return 0;
    int cntL = maxdepth(root->left);
    int cntR = maxdepth(root->right);
    return(1+max(cntL,cntR));
}

int main(){
    node* root = new node(1);
    root->left= new node(2);
    root->right = new node(3);
    root->left->left= new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(8);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->left = new node(9);
    root->right->right->left->right = new node(11);
    root->right->right->right = new node(10);
    int ans = maxdepth(root);
    cout<<ans;
}