/*
logic -> iterate through the LL and find the pos and mark with the cyclepoint node. then link the last node to the cyclepoint node to create a loop
now to detect the loop run fast(2 steps) and slow(1 step) pointer and if there is a loop then fast and slow will meet at a point. 
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

node* createloop(node* head,int pos){
    node* temp = head;
    node* cyclepoint = nullptr;
    int i = 1;
    while(temp->next != nullptr){
        if(i == pos) cyclepoint = temp;
        temp = temp->next;
        i++;
    }
    temp->next = cyclepoint;
    return head;
}

void detectloop(node* head){
    node* fast = head;
    node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            cout<<"loop detected";
            return;
        }
    }
    cout<<"loop not detected";
    return;
}

int main(){
    vector<int> a = {12,8,5,9};
    int n = a.size();
    int pos = 2;
    node* head = gethead(a,n);
    head = createloop(head,pos);
    detectloop(head);
}