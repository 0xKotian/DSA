/*
to print all the ele in odd node and then print all the ele in even node.
logic -> initialize odd and even ptr to head and head->next respectively, initialize evenhead to even. now iterate, odd next links to even next and
move the odd, even next links to odd next and move the even. at last link the last ele of odd to evenhead. 
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

node* seperateOddEven(node* head){
    node* odd = head;
    node* even = head->next;
    node* evenhead = head->next;
    while(even != nullptr && even->next != nullptr){
        odd->next = even->next;
        odd = odd->next;
        
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenhead;
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
    vector<int> a = {1,2,3,4,5,6,7,8,9};
    int n = a.size();
    node* head = gethead(a,n);
    head = seperateOddEven(head);
    printLL(head);
}