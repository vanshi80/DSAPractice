#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        // every node has a left and right child
        Node* left;
        Node* right;

        Node(int val){
            data = val;
            left = right = NULL;
        }
};
// now create a tree with the given preorder sequence->root,left,right is the preorder traversal of a tree.
static int idx = -1;
Node* buildTree(vector<int>preorder){
    idx++;
    if(preorder[idx] == -1) return NULL;

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}
void kthlevelnodes(Node* root, int k){
    if(root == NULL) return;
    if(k == 1){
        cout<<root->data<<" ";
        return;
    }
    kthlevelnodes(root->left,k-1);
    kthlevelnodes(root->right,k-1);
}
int main(){
    // We are given a preorder seq and we have to form a binary tree out of it
    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    // now if we want to return the preorder,postorder and inorder traversal of our binary tree then we can make functions for them
    
    Node* root = buildTree(preorder);
    cout<<"Tree build successfully"<<endl;4
    int k;
    cout<<"Enter value of k:";
    cin>>k;
    
    kthlevelnodes(root, k);
    cout<<endl;
    return 0;
}