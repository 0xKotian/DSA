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

node* reverseDLL(node* head){
    if(head == nullptr || head->next == nullptr) return head;
    node* prev_ele = nullptr;
    node* temp = head;
    while(temp != nullptr){
        prev_ele = temp->back;
        temp->back = temp->next;
        temp->next = prev_ele;
        if(temp->back == nullptr) head = temp;
        temp = temp->back; 
    }
    return head;
}

void printLL(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    vector<int> a = {12,8,5,9};
    int n = a.size();
    node* head = convertArrtoDLL(a,n);
    head = reverseDLL(head);
    printLL(head);
}