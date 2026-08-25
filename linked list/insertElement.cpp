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

node* insertKth(node* head,int k,int ele){
    if(head == nullptr) return new node(ele);
    if(k == 1){
        node* temp = new node(ele);
        temp->next = head;
        return temp;
    }
    int cnt = 0;
    node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k-1){
            node* newnode = new node(ele);
            newnode->next = temp->next;
            temp->next = newnode;
            break;
        }
        else temp = temp->next;
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
    int ele = 0;
    node* head = gethead(a,n);
    head = insertKth(head,k,ele);
    printLL(head);
}