/*
first return left boundry elements then leaf elements then the right boundry elements
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

bool isleaf(node* root){ // returns true only if the root has no left and right ele, then its a leaf node
    return(root->left == nullptr && root->right == nullptr);
}

// iterate from root left and check if its a leaf node, if its not leaf node pushback element to ans then check if its left exist then move to left orelse move to right
// repeat the process intil temp reaches nullptr 
void left_boundry(node* root, vector<int> &ans){
    node* temp = root->left;
    while(temp){
        if(isleaf(temp) == false) ans.push_back(temp->data);
        if(temp->left) temp = temp->left;
        else temp = temp->right; 
    }
}

// iterate to every node from left side and if its a leaf node then pushback to ans and return then check right side.  
void leaf_boundry(node* root,vector<int> &ans){
    node* temp = root;
    if(isleaf(temp) == true){
        ans.push_back(temp->data);
        return;
    }
    if(temp->left) leaf_boundry(temp->left,ans);
    if(temp->right) leaf_boundry(temp->right,ans);
}

// iterate through right side and if the ele is not the leaf node the add to stack and move to right if it exists orelse move to left. at last pushback st.top elements to ans.
// right side boundry should be returned from downside to upside, but we iterate from upside so we store in stack FILO or LIFO. 
void right_boundry(node* root, vector<int> &ans){
    node* temp = root->right;
    stack<int> st;
    while(temp){
        if(isleaf(temp) == false) st.push(temp->data);
        if(temp->right) temp=temp->right;
        else temp=temp->left;
    }
    while(!st.empty()) { // 
        ans.push_back(st.top());
        st.pop();
    }
}

void problem(node* root){
    vector<int> ans;
    if(isleaf(root) == false) ans.push_back(root->data);// firstly root is added to ans
    left_boundry(root,ans);
    leaf_boundry(root,ans);
    right_boundry(root,ans);

    for(auto it : ans) cout<<it<<" ";
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