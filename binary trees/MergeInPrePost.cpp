/*
create a st that contains node* ptr and key, when key is 1 add to pre order, when key is 2 add to in order, when key is 3 add to postorder.
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

void problem(node* root){
    vector<int> in,pre,post;
    stack<pair<node*,int>> st;// stored node and key
    st.push({root,1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second == 1){// when key is 1 add to pre order and increase the key and search for left
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left != nullptr) st.push({it.first->left,1});
        }
        else if(it.second == 2){// when key is 2 add to inorder adn increase the key adn search for right
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right != nullptr) st.push({it.first->right,1});
        }
        else{// when key is 3 add to post order 
            post.push_back(it.first->data);
        }
    }
    cout<<"inorder : \n";
    for(auto it : in) cout<<it<<" ";
    cout<<"\npreorder : \n";
    for(auto it : pre) cout<<it<<" ";
    cout<<"\npostorder : \n";
    for(auto it : post) cout<<it<<" ";
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
    problem(root);
}