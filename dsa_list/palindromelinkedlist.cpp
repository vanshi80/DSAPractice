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
Node* reverselist(Node*head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }
    return prev;
}
bool checkPalindrome(Node* head){
    Node* slow = head,*fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* firsthead = head;
    Node* secondhead = reverselist(slow);
    while(secondhead!=NULL){
        if(firsthead->data != secondhead->data){
            return false;
        }
        secondhead = secondhead->next;
        firsthead = firsthead->next;
    }
    return true;
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);

    if(checkPalindrome(head)){
        cout<<"The linked list is palindromic";
    }else{
        cout<<"The linked list is not palindromic";
    }
    
}