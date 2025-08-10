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
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node* addone(Node* head){
    int carry = 1;
    
    head = reverse(head);
    Node* curr = head;
    Node* last = 0;
    while(curr!=NULL){
        int sum = carry + curr->data;

        carry = sum/10;
        curr->data = sum%10;
        last = curr;
        curr = curr->next;
    }
    if(carry){
        last->next = new Node(carry);
        
    }
    head = reverse(head);
    return head;
}
int main(){
    Node* head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(3);

    Node* ans = addone(head);
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    cout<<endl;
}