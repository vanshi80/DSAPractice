#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
    int data;
    struct BST* left,* right;
}bst;
// Insertion in the bst
bst* insertinBst(bst* rt, int val){
    if(rt == NULL){
        rt = (bst*)malloc(sizeof(bst));
        rt->data = val;
        rt->left = rt->right = NULL;
    }else{
        if(val < rt->data){
            rt->left = insertinBst(rt->left, val);
        }else{
            rt->right = insertinBst(rt->right, val);
        }
    }
    return rt;
}
void inorder(bst* rt){
    if(rt == NULL) return;
    inorder(rt->left);
    printf("\t%d",rt->data);
    inorder(rt->right);
}
void preorder(bst* rt){
    if(rt == NULL) return;
    preorder(rt->left);
    preorder(rt->right);
    printf("\t%d",rt->data);
}
void postorder(bst* rt){
    if(rt == NULL) return;
    printf("\t%d",rt->data);
    postorder(rt->left);
    postorder(rt->right);
}
bst* findmin(bst* rt){
    if(rt == NULL) return NULL;
    if(rt->left!=NULL) return findmin(rt->left);
    return rt;
}
// Deletion
bst* deleteBst(bst* rt, int key){
    if(rt == NULL){
        printf("Tree is already empty!");
        return rt;
    }
    if(key < rt->data) rt->left = deleteBst(rt->left, key);
    else if(key > rt->data) rt->right = deleteBst(rt->right, key);
    else{
        if(rt->left == NULL && rt->right == NULL){
            printf("Deleting %d", rt->data);
            free(rt);
            return 0;
        }
        else if(rt->left == NULL || rt->right == NULL){
            bst* temp;
            if(rt->right == NULL) temp = rt->left;
            if(rt->left == NULL) temp = rt->right;
            printf("Deleting %d", rt->data);
            free(rt);
            return temp;
        }else{
            bst* t = findmin(rt->right);
            rt->data = t->data;
            rt->right = deleteBst(rt->right, t->data);
        }
        return rt;
    }

}
int main(){
    bst* root = NULL;
    int ch,val,key;
    while(1){
        printf("\nMenu");
        printf("\n1. Insert in tree");
        printf("\n2. Delete from tree");
        printf("\n3. Inorder Traversal");
        printf("\n4. PreOrder Traversal");
        printf("\n5. PostOrder Traversal\n");
        printf("Enter your choice");
        scanf("%d",&ch);
        
        switch(ch){
            case 1 :printf("Enter the value");
                    scanf("%d",&val);
                    root = insertinBst(root,val);
                    break;
            case 2: printf("Enter the value to delete");
                    scanf("%d",&key);
                    root = deleteBst(root, key); break;
            case 3: inorder(root); break;
            case 4: preorder(root); break;
            case 5: postorder(root); break;
            default: printf("Thanks a lot!");
                    exit(0);
        }

    }
    return 0;
}