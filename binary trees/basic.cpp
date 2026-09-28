/*
transversals in BT => recursive pre post in order transveral in BT, iterative pre post in order transversal in BT, level order transversal 
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

// inorder : left->root->right 
void recursive_inoreder(node* root){
    if(root == nullptr) return;
    recursive_inoreder(root->left);// check left
    cout<<root->data<<" "; // print root
    recursive_inoreder(root->right);// check right
}

// preorder : root->left->right
void recursive_preorder(node* root){
    if(root == nullptr) return;
    cout<<root->data<<" "; // print root
    recursive_preorder(root->left); // check left
    recursive_preorder(root->right); // check right
}

// postorder : left->right->root
void recursive_postorder(node* root){
     if(root == nullptr) return;
    recursive_postorder(root->left);// check left 
    recursive_postorder(root->right);//check right
    cout<<root->data<<" ";// print root
}

// create a stack and push root first, while st is not empty consider the top ele as root(temp node) and pop from st, push in ans and check if it has right node if yes 
// push temp->right to st and check if it has left node if yes push temp->left to st. next iteration st.top that is the left of the previous root ele. because st is 
// last in first out    
void iterative_preorder(node* root){
    vector<int> ans;
    stack<node*> st;
    node* temp = root;
    st.push(temp);
    while(!st.empty()){
        temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right != nullptr) st.push(temp->right);
        if(temp->left != nullptr) st.push(temp->left);
    } 
    for(auto it : ans) cout<<it<<" ";
}

//create a st and iterate throough BT, temp starts fom root and if temp is != nullptr then add that node to st and go to left, if the temp == nullptr then add the 
// top() ele too  ans andd go to right 
void iterative_inorder(node* root){
    vector<int> ans;
    stack<node*> st;
    node* temp = root;
    while(temp != nullptr || !st.empty()){
        if(temp != nullptr){ // till temp is not nullptr it will go to extreame left node
            st.push(temp);
            temp = temp->left;
        }
        else{ // when extreme left is reached then its left node is null so st.top() will be the recent itreated node and u add that to ans and search to its right.
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    for(auto it : ans) cout<<it<<" ";
}

void iterative_postorder(node* root){
    vector<int> ans;
    stack<node*> st;
    node* temp = root;
    st.push(temp);
    while(!st.empty()){
        temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->left != nullptr) st.push(temp->left);
        if(temp->right != nullptr) st.push(temp->right);
    } 
    reverse(ans.begin(),ans.end());
    for(auto it : ans) cout<<it<<" ";
}

// create vector<vector<int>> ans and a q, push root to q. for every iteration of while loop create a new vector level and iterate through q using for loop, take the 
// font ele and search its left if node exist the add to q and search to right if exist add to q, add front ele to level and add level to ans. now evey iteration
// of new level the front ele will be the left of the previously added ele and next ele after front will be the right of previously added ele.   
void level_order(node* root){
    vector<vector<int>> ans;
    queue<node*> q;
    node* temp = root;
    q.push(temp);
    while(!q.empty()){
        vector<int> level;
        for(int i=0;i<q.size();i++){
            temp = q.front();
            q.pop();
            if(temp->left != nullptr) q.push(temp->left);
            if(temp->right != nullptr) q.push(temp->right);  
            level.push_back(temp->data);
        }
        ans.push_back(level);
    }
    for(auto it : ans){
        for(auto x : it) cout<<x<<" ";
    } 
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
    root->right->right->right = new node(10);
    // recursive_inoreder(root);
    // recursive_preorder(root);
    // recursive_postorder(root);
    // iterative_preorder(root);
    // iterative_inorder(root);
    // iterative_postorder(root);
     level_order(root);
}


