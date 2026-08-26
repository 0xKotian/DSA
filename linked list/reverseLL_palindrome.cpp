/*
logic -> initially prev = nullptr,every iteration create a font node which pointes to temp->next. now point the temp->next to prev and now bring 
prev to temp and temp to front. at last return prev.

logic for palindrome -> using fast and slow ptr find the middle node, reverse after middle node and iterate from start and reversed and compare for palindrome
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

void palindrome(node* head){
    node* fast = head;
    node* slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    node* newhead = reverseLL(slow->next);//slow is at middle node, reverse after middle
    node* first = head;
    node* second = newhead;
    while(second != nullptr){
        if(first->data != second->data){
            reverseLL(newhead);//always reverse the LL again back to original before return.
            cout<<"not palindrome";
            return;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newhead);//always reverse the LL again back to original before return.
    cout<<"palindrome";
    return;
}

int main(){
    vector<int> a = {1,2,3,2,1};
    int n = a.size();
    node* head = gethead(a,n);
    head = reverseLL(head);
    palindrome(head);
}