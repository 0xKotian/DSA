/*
to find the pairs whose sum is equal to val.
*/
#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node* next;
    node* back;
    node(int val,node* next1, node* back1){
        data = val;
        next = next1;
        back = back1;
    }
    public:
    node(int val){
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

node* convertArrtoDLL(vector<int> &a, int n){
    node* head = new node(a[0]);
    node* previous = head;
    for(int i = 1; i < n; i++){
        node* temp = new node(a[i]);
        previous->next = temp;
        temp->back = previous;
        previous = previous->next;
    } 
    return head;
}

node* findtail(node* head){
     node* temp = head;
     while(temp->next != nullptr){
        temp = temp->next;
     }
     return temp;
}

vector<pair<int,int>> FindSum(node* head, int val){
    vector<pair<int,int>> ans;
    node* left = head;
    node* right = findtail(head);
    while(left->data < right->data){
        if(left->data + right->data == val){
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data+right->data < val) left = left->next;
        else right = right->back;
    }
    return ans;
}

void printLL(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    vector<int> a = {1,2,3,4,9};
    int n = a.size();
    int val = 5;
    node* head = convertArrtoDLL(a,n);
    vector<pair<int,int>> res = FindSum(head,val);
    for(auto it : res){
        cout<<it.first<<" "<<it.second<<endl;
    }
}