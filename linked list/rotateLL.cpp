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

node* findnode(node* head, int cnt){
    cnt -= 1;
    node* temp = head;
    while(temp != nullptr && cnt > 0){
        temp = temp->next;
        cnt--;
    }
    return temp;
}

node* rotateLL(node* head, int k){
    if(head == nullptr && head->next == nullptr) return head;
    node* tail = head;
    int length = 1;
    while(tail->next != nullptr){
        tail = tail->next;
        length++; // find the length of the LL and brint tail ptr to the last node.
    } 
    k = k % length; // if k<length then k % length will be k only, and if k>length then k % length is 0 
    if(k == 0) return head;
    node* newnode = findnode(head,length - k);
    tail->next = head;
    head = newnode->next;
    newnode->next = nullptr;
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
    vector<int> a = {1,2,3,4,5};
    int n = a.size();
    int k = 2;
    node* head = gethead(a,n);
    head = rotateLL(head,k);
    printLL(head);
}