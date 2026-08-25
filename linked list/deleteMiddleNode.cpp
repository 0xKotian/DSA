/*
these both problem uses TORTOISE HARE method. fast pointer moves d distance(moves 2 step forward at once) then slow pointer moves d/2 distance(moves one step
forward at once).
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

node* DeleteMiddleNode(node* head){
    if(head == nullptr || head->next == nullptr) return NULL;
    node* slow = head;
    node* fast = head;
    fast = fast->next->next;// by thiswe skip the first step of slow, so that it ends at the previous node of middle node.
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    } 
    node* middle = slow->next;
    slow->next = slow->next->next;
    middle->next = nullptr;
    delete middle;
    return head;
}

void FindMiddleNode(node* head){
    if(head == nullptr){
        cout<<"empty LL";
        return;
    }
    if(head->next == nullptr){
        cout<<head->data;
        return;
    } 
    node* slow = head;
    node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    } 
    cout<<"middle ele is "<<slow->data<<endl;
}

void printLL(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    vector<int> a = {12,8,5,9,10};
    int n = a.size();
    node* head = gethead(a,n);
    FindMiddleNode(head);
    head = DeleteMiddleNode(head);
    printLL(head);
}