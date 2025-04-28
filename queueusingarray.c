#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int rear = -1,front = -1;
void insertinQ(){
	if(rear == size-1){
		printf("Insertion not possible!");
		return;
	}
	if(rear == -1){
		rear = front = 0;
	}else{
		rear++;
	}
	printf("Enter data: ");
	scanf("%d",&queue[rear]);
}
void deletefromQ(){
	if(front == -1){
		printf("Deletion not possible!");
		return;
	}
	printf("Deleting .. %d",queue[front]);
	if(front == rear){
		front = rear = -1;
	}
	else{
		front++;
	}
}
int main(){
	int ch;
	while(1){
		printf("\nMenu\n");
		printf("1.Insert in queue\n");
		printf("2.Delete from queue\n");
		printf("3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1: insertinQ(); break;
			case 2: deletefromQ(); break;
			default: printf("Thanks a lot!\n");
					 exit(0);	
		}
	}
	return 0;
}
