// reverse function is running on gfg
#include<stdio.h>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next,*prev;
    Node(int val){
        data = val;
        next = prev = NULL;
    }
};
class Doubly{
    Node* head;
    public:
    Doubly(){
        head = NULL;
    }
    void pushback(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }
    void display(){
        if(head == NULL){
            cout<<"Empty"<<endl;
            return;
        }
        Node* curr = head;
        while(curr!=NULL){
            cout<<curr->data<<"<->";
            curr=curr->next;
        }  
        cout<<"NULL"<<endl;  
    }
    void reverse(){
        if(head == NULL || head->next == NULL) return;
        Node* temp = NULL;
        Node* curr = head;
        while(curr!=NULL){
            temp = curr->prev;
            curr->prev ='' curr->next;
            curr->next = temp;
    
            curr = curr->prev;
        }
        if(temp)head =  temp->prev;
    }
};
int main(){
    Doubly dl;
    dl.pushback(3);
    dl.pushback(4);
    dl.pushback(5);
    dl.pushback(6);
    dl.pushback(7);
    dl.pushback(8);
    dl.pushback(9);
    dl.display();
    dl.reverse();
    dl.display();
    return 0;
}