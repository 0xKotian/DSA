/*
if the given question is to remove kth ele from the last then do K = n - k + 1. and now follow remove the Kth ele from front.  
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

node* RemoveKth(node* head, int k){
    if(head == nullptr) return nullptr;
    node* previous = nullptr;
    node* temp = head;
    int cnt = 0;
    if(k == 1){
        head = head->next;
        delete temp;
        return head;
    }
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            previous->next = previous->next->next;
            delete temp;
            break;
        }
        else{
            previous = temp;
            temp = temp->next;
        }
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
    int k = 3;
    node* head = gethead(a,n);
    head = RemoveKth(head,k);
    printLL(head);
}