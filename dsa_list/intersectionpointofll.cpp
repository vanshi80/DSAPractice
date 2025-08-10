#include<stdio.h>
#include<stdlib.h>
typedef struct list{
 int data;
 struct list *next;
	
}ll;

int sizeLinkedList(ll *head){
 ll *curr=head;
 int count=0;
 while(curr!=0){
  count++;
  curr=curr->next;
 }
 return count;
}
ll *makenode(){
 ll *p;
 p=(ll *)malloc(sizeof(ll));
 scanf("%d",&p->data);
 p->next=0;
 return p;
}
void printlist(ll *head){
 ll *curr=head;
 while(curr!=0){
  printf("%d ",curr->data);
  curr=curr->next;
 }
}
ll *intersection(ll *headA,ll *headB){
 int d,i;
 ll *curr1=headA;
  ll *curr2=headB;
 int len1,len2;
 len1=sizeLinkedList(headA);
 len2=sizeLinkedList(headB);
 if(len1>len2)
 d=len1-len2;
 else
 d=len2-len1;
 for(i=0;i<d;i++){
   
 if(len1>len2)
 curr1=curr1->next;
 else 
 curr2=curr2->next;
}
while(curr1!=0&&curr2!=0){

if(curr1==curr2)
return curr1;
else{
curr1=curr1->next;
 curr2=curr2->next; 
}
	
}
return NULL;
}
int main(){
 ll *headA=0,*headB=0,*p,*head=0;
 int n,i;
 scanf("%d",&n);
 for(i=0;i<n;i++){
  p=makenode();
  if(headA==0)
  headA= p;
  else{
   ll *curr=headA; 
   while(curr->next!=0){
   curr= curr->next;
  // curr->next=p;
   }
   curr->next=p;
  }
 }
 scanf("%d",&n);
	
 for(i=0;i<n;i++){
 ll *p=makenode();
 if(headB==0)
 headB=p;
 else{
  ll *curr=headB;
  while(curr->next!=0){
   curr=curr->next;
  // curr->next=p;
   
  }
  curr->next=p;
 }
  
  
 }
 printlist(headA);
 printlist(headB);
 head=intersection(headA,headB);
	
}