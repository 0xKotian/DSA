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

node* findmiddle(node* head){
    node* slow = head;
    node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* mergLL(node* list1, node* list2){
    node* ref_node = new node(-1);
    node* temp = ref_node;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1 != nullptr) temp->next = list1;
    if(list2 != nullptr) temp->next = list2;
    return ref_node->next;
}

node* sortLL(node* head){ // here u split the LL to left and right and when at last u have only 2 ele the nu compare and merg
    if(head == nullptr || head->next == nullptr) return head;
    node* middle = findmiddle(head);
    node* righthead = middle->next;
    node* lefthead = head;
    middle->next = nullptr;
    lefthead = sortLL(lefthead);
    righthead = sortLL(righthead);
    return mergLL(lefthead,righthead);
}

void printLL(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    vector<int> a = {3,4,2,6,1,5};
    int n = a.size();
    node* head = gethead(a,n);
    head = sortLL(head);
    printLL(head);
}