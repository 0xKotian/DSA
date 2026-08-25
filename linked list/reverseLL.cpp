/*
logic -> initially prev = nullptr,every iteration create a font node which pointes to temp->next. now point the temp->next to prev and now bring 
prev to temp and temp to front. at last return prev.
*/
#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node* next;
    node(int val){
        data = val;
        next = nullptr;
    }
};

node* gethead(vector<int> &a, int n){
    node* head = new node(a[0]);
    node* temp = head;
    for(int i = 1; i < n; i++){
        temp->next = new node(a[i]);
        temp = temp->next;
    } 
    return head;
}

node* reverseLL(node* head){
    node* temp = head;
    node* prev = nullptr;
    while(temp != nullptr){
        node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
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
    node* head = gethead(a,n);
    head = reverseLL(head);
    printLL(head);
}