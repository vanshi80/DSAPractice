#include<iostream>
#include<stdio.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
Node* merge(Node *a, Node* b){
    if(!a) return b;
    if(!b) return a;
    Node* head = NULL;
    Node* tail = NULL;
    if(a->data <= b->data){
        head = tail = a;
        a = a->next;
    }else{
        head = tail = b;
        b = b->next;
    }

    while(a!=NULL && b!=NULL){
        if(a->data <= b->data){
           tail->next = a;
           tail = a; 
           a = a->next;
        }else{
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }
    
    if(a == NULL) tail->next = b;
    else tail->next = a;

    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    Node* head2 = new Node(2);
    head2->next = new Node(6);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(10);

    Node* newhead = merge(head, head2);
    Node* curr = newhead;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    return 0;
}