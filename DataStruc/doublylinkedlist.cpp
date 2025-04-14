#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    struct list *next,*prev;
}DL;
// make node function
DL* makenode(){
    DL* p;
    p = (DL*)malloc(sizeof(DL));
    printf("Enter the data");
    scanf("%d",&p->data);
    p->next = 0;
    p->prev = 0;
    return p;
}
// Add first function
DL* addfirst(DL* h){
    DL* p = makenode();
    p->next = h;
    if(h) h->prev = p;  //because h->prev only exists when h exists
    return p;
}
// Delete first function
DL* delfirst(DL* h){
    if(!h){
        printf("List is empty!");
        return h;
    }
    DL* p = h;
    h = p->next;
    if(h) h->prev = 0;
    printf("Deleting  %d",p->data);
    free(p);
    return h;
}
// Add last node
DL* addLast(DL* h){
    DL*p = makenode();
    if(h==0){
        return p;
    }
    DL*t  = h;
    while(t->next!=0){
        t = t->next;
    }
    t->next = p;
    p->prev = t;
    return h;
}
// Delete last node
DL* delLast(DL* h){
    if(h==0){
        printf("List is already empty");
        return 0;
    }
    if(h->next ==0){
        printf("\nDeleting %d",h->data);
        free(h);
        return 0;
    }
    DL* t = h;
    while(t->next->next!=0){
        t = t->next;
    }
    DL* p = t->next;
    t->next = 0;
    printf("Deleting %d",p->data);
    free(p);
    return h;
}
// Add position
DL* addpos(DL* h){
    int pos,count = 0;
    if(h) count = 1;
    DL* t,*p;
    t = h;
    while(t->next!=0){
        count++;
        t = t->next;
    }
    printf("\nWe have %d number of nodes..enter the position where you want to make the addition",count);
    scanf("%d",&pos);
    if(pos<1 || pos>count+1){
        printf("Mission Impossible!\n");
        return h;
    }
    if(pos == 1){
        h = addfirst(h);
        return h;
    }
    if(pos == count+1){
        h = addLast(h);
        return h;
    }
    t = h;
    for(int i=2;i<count;i++){
        t = t->next;
    }
    p = makenode(); 
    p->next = t->next;
    t->next->prev = p;
    t->next = p;
    p->prev = t;
    return h;
}
// Delete Position
DL* delPos(DL* h){
    int pos,count = 0;
    if(h) count = 1;
    DL* t,*p;
    t = h;
    while(t->next!=0){
        count++;
        t = t->next;
    }
    printf("\nWe have %d number of nodes..enter the position where you want to delete",count);
    scanf("%d",&pos);
    if(pos<1 || pos>count){
        printf("Mission Impossible!\n");
        return h;
    }
    if(pos == 1){
        h = delfirst(h);
        return h;
    }
    if(pos == count){
        h = delLast(h);
        return h;
    }
    t = h;
    for(int i=2;i<count;i++){
        t = t->next;
    }
    p = t->next;
    t->next = p->next;
    p->next->prev = t;
    printf("\nDeleting %d",p->data);
    free(p);
    return h;
}
// display list-Forward
void displayforw(DL* h){
    if(!h){
        printf("List is empty");
    }
    while(h){
        printf("%d ",h->data);
        h = h->next;
    }
}
// Display list backward
void displayBack(DL* h){
    while(h->next!=0){
        h=h->next;
    }
    while(h){
        printf("%d ",h->data);
        h = h->prev;
    }
}
int main(){
    int choice;
    DL* head = 0;
    while(1){ 
        printf("\nMenu:\n");
        printf("1. Add First\n");
        printf("2. Delete First\n");
        printf("3. Add Last\n");
        printf("4. Delete Last\n");
        printf("5. Add at a position\n");
        printf("6. Delete From a position\n");
        printf("7. Display List in Forward Fashion\n");
        printf("8. Display List in Backward Fashion\n");
        printf("9. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addfirst(head);
                break;
            case 2:
                head = delfirst(head);
                break;
            case 3:
                head = addLast(head);
                break;
            case 4: 
                head = delLast(head);
                break;
            case 5: 
                head = addpos(head);
                break;
            case 6: 
                head = delPos(head);
                break;
            case 7: 
                displayforw(head);
                break;
            case 8: 
                displayBack(head);
                break;
            default:
                printf("Thanks a lot!\n");
                exit(0);
        }
    }

    return 0;
}
