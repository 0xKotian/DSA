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

node* sort012(node* head){
    node* dummy0 = new node(-1);
    node* dummy1 = new node(-1);
    node* dummy2 = new node(-1);
    node* ptr0 =  dummy0;
    node* ptr1 =  dummy1;
    node* ptr2 =  dummy2;
    node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0){
            ptr0->next = temp;
            ptr0 = ptr0->next;
        }
        if(temp->data == 1){
            ptr1->next = temp;
            ptr1 = ptr1->next;
        }
        if(temp->data == 2){
            ptr2->next = temp;
            ptr2 = ptr2->next;
        }
        temp = temp->next;
    }
    ptr2->next = nullptr;
    ptr0->next = (dummy1->next != nullptr) ? dummy1->next : dummy2->next;
    ptr1->next = dummy2->next;
    return dummy0->next; 
}

void printLL(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    vector<int> a = {1,0,2,1,1,2,0,0,2,1,1};
    int n = a.size();
    node* head = convertArrtoDLL(a,n);
    head = sort012(head);
    printLL(head);
}