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
// preorder
void preOrder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
// without next line after every level
// void levelOrder(Node* root){
//     if(root == NULL) return;
//     queue<Node*>q;
//     q.push(root);
//     while(!q.empty()){
//         Node* curr = q.front();
//         cout<<curr->data<<" ";
//         q.pop();

//         if(curr->left){
//             q.push(curr->left);
//         }
//         if(curr->right){
//             q.push(curr->right);
//         }
//     }
// }
// with new line after every level
void levelOrder(Node* root){
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(1){
        Node* curr = q.front();
        q.pop();
        if(curr == NULL){
            // next line need to be introduced
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            // second case-> queue is empty now
            else{
                break;
            }
        }
        cout<<curr->data;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

}
int main(){
    // We are given a preorder seq and we have to form a binary tree out of it
    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    // now if we want to return the preorder,postorder and inorder traversal of our binary tree then we can make functions for them

    Node* root = buildTree(preorder);
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    levelOrder(root);
    cout<<endl;
    return 0;
}