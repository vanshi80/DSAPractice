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
Node* addlists(Node* h1, Node* h2){
    Node* t1 = h1;
    Node* t2 = h2;

    Node* dummy = new Node(-1);
    Node* curr = dummy;
    int carry = 0;
    while(t1!=NULL || t2!=NULL){
        int sum = carry;
        if(t1) sum = t1->data + sum;
        if(t2) sum = t2->data + sum;

        Node* newNode = new Node(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummy->next;
}
int main(){
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(3);

    Node* head2 = new Node(5);
    head2->next = new Node(6);
    head2->next->next = new Node(4);

    Node* ans = addlists(head, head2);
    while(ans!=NULL){
        cout<<ans->data;
        ans = ans->next;
    }
}