/*
logic -> when the Y LL is created iterate temp1 and temp2 from head1 and head2 respectively and when == return temp1, if temp1 is nullptr then start 
iterating from head2, similarly if temp2 is nullptr satrt iteraing from head1 till both ==.  
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

node* attachLL(node* head,node* commonhead){
    node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = commonhead;
    return head;
}

node* problem(node* head1, node* head2){
    node* temp1 = head1;
    node* temp2 = head2;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2) return temp1;
        if(temp1 == nullptr) temp1 = head2;
        if(temp2 == nullptr) temp2 = head1;
    }
    return temp1;
}

int main(){
    vector<int> a = {12,5};
    vector<int> b = {6,8,7};
    vector<int> common = {8,9,4};
    int n = a.size();
    int m = b.size();
    int c = common.size();
    node* head1 = gethead(a,n);
    node* head2 = gethead(b,m);
    node* commonhead = gethead(common,c);
    attachLL(head1,commonhead);
    attachLL(head2,commonhead);
    cout<<problem(head1,head2)->data;
}