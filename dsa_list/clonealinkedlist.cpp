// we have to clone a linked list and it contains the random pointers along with the normal next pointers so we can make use of the 
// hashmap
#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(int x){
        data = x;
        next = NULL;
        random = NULL;
    }
};
Node* clone(Node* head){
    Node* curr = head;
    unordered_map<Node*, Node*>m;
    while(curr!=NULL){
        m[curr] = new Node(curr->data);
        curr = curr->next;
    }
    for(Node* curr = head; curr!=NULL; curr=curr->next){
        m[curr]->next = m[curr->next];
        m[curr]->random = m[curr->random];
    }
    return m[head];
}
void printlist(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->random = head->next->next;       // 1 -> 3
    head->next->random = head;             // 2 -> 1
    head->next->next->random = head->next; // 3 -> 2
    head->next->next->next->random = NULL;

    printlist(head);
    cout<<endl;
    Node* newhead = clone(head);
    printlist(newhead);
    return 0;
}