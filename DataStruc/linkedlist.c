#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} LL;

// Create a node
LL* makenode() {
    LL* p;
    p = (LL*)malloc(sizeof(LL));
    printf("Enter data: ");
    scanf("%d", &p->data);
    p->next = 0;
    return p;
}

// Add first node
LL* addfirst(LL* head) {
    LL* p;
    p = makenode();
    p->next = head;
    return p; // p is the head now
}

// Add last node
LL* addlast(LL* head) {
    LL* p, *t;
    p = makenode();
    // When the list is empty
    if (head == 0) {
        // Here the head changes
        return p;
    }
    t = head;
    // When the list is not empty
    while (t->next != 0) {
        t = t->next;
    }
    t->next = p;
    // Here the head remains the same
    return head;
}

// Delete First
LL* delFirst(LL* head) {
    // Element is there or no element
    if (head == 0) {
        printf("List is already empty\n");
        return head;
    }
    LL* t = head;
    head = head->next;
    printf("Deleting %d\n", t->data);
    free(t);
    return head;
}

// Delete last
LL* dellast(LL * h){
    LL*t,*p;
    if(h==0) {
        printf("List is empty");
        return 0;
    }
    if(h->next == 0){
        printf("Deleting %d",h->data);
        free(h);
        return 0;
    }
    t = h;
    while(t->next->next != 0){
        t = t->next;
    }
    p = t->next;
    t->next = 0;
    printf("Deleting %d",p->data);
    free(p);
    return h;
}

// Add between
// Delete be
// Display the list
void display(LL* head) {
    if (head == 0) {
        printf("List is empty\n");
        return;
    }
    LL* t = head;
    printf("List elements: ");
    while (t != 0) {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    LL* head = 0;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add First\n");
        printf("2. Add Last\n");
        printf("3. Delete First\n");
        printf("4. Delete Last\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = addfirst(head);
                break;
            case 2:
                head = addlast(head);
                break;
            case 3:
                head = delFirst(head);
                break;
            case 4:
                head = dellast(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
