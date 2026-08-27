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

node* RemoveKth(node* head, int k){
    if(head == nullptr || head->next == nullptr) return nullptr;
    node* temp = head;
    int cnt = 0;
    if(k == 1){
        head = head->next;
        head->back = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            node* previous = temp->back;
            previous->next = temp->next;
            temp->next = nullptr;
            temp->back = nullptr;
            delete temp;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

node* removeELE(node* head, int ele){
    if(head == nullptr) return head;
    node* temp = head;
    while(temp != nullptr){
        if(temp->data == ele){
            if(temp == head) head = head->next; 
            node* front = temp->next;
            node* prev = temp->back;
            if(front != nullptr) front->back = prev;
            if(prev != nullptr) prev->next = front;
            delete temp;
            temp = front;
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
    cout<<endl;
}

int main(){
    vector<int> a = {12,8,5,9};
    int n = a.size();
    int k = 3;
    node* head = convertArrtoDLL(a,n);
    head = RemoveKth(head,k);
    printLL(head);

    vector<int> b = {10,6,10,10,4,10,1};
    int m = b.size();
    int ele = 10;
    node* head1 = convertArrtoDLL(b,m);
    head1 = removeELE(head1,ele);
    printLL(head1);
}