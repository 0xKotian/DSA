#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
    int data;
    node* next;
    node* back;
    node(int val,node* next1, node* back1){
        data = val;
        next = next1;
        back = back1;
    }
    public:
    node(int val){
        data = val;
        next = nullptr;
        back = nullptr;
    }
};

node* convertArrtoDLL(vector<int> &a, int n){
    node* head = new node(a[0]);
    node* previous = head;
    for(int i = 1; i < n; i++){
        node* temp = new node(a[i]);
        previous->next = temp;
        temp->back = previous;
        previous = previous->next;
    } 
    return head;
}

node* insertDLL(node* head, int k,int ele){
    if(k == 1 || head->next == nullptr){
        node* newele = new node(ele,head,nullptr);
        head->back = newele;
        return newele;
    }
    node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k-1){
            node* front = temp->next;
           temp->next = new node(ele,front,temp);
           front->back = temp->next;
           break;
        }
        temp = temp->next;
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
    node* head = convertArrtoDLL(a,n);
    head = insertDLL(head,k,ele);
    printLL(head);
}