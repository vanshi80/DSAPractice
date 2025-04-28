#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}Q;
Q* makenode(){
	Q* p = (Q*)malloc(sizeof(Q*));
	p->next = 0;
	printf("Enter data: ");
	scanf("%d",&p->data);
	return p;
}
Q* insertinQ(Q* h){
	Q*p = makenode();
	if(h == 0){
		return p;
	}
	Q*t = h;
	while(t->next!=0){
		t = t->next;
	}
	t->next = p;
	return h;
}
Q* deletefromQ(Q* h){
	Q* t;
	if(h == 0){
		printf("Queue is empty\n");
		return h;
	}
	t = h;
	h = h->next;
	printf("Deleting %d",t->data);
	free(t);
	return h;
}
int main(){
	int ch;
	Q* h = 0;
	while(1){
		printf("\nMenu\n");
		printf("1.Insert in queue\n");
		printf("2.Delete from queue\n");
		printf("3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:h = insertinQ(h); break;
			case 2:h = deletefromQ(h); break;
			default: printf("Thanks a lot!\n");
					 exit(0);	
		}
	}
	return 0;
}
