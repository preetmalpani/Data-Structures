#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node *top = NULL;
struct node *front = NULL, *rear = NULL;

void push(){
    struct node* newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d",&x);
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void pop(){
    struct node* temp;
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->link;
    free(temp);
}

void displayStack(){
    struct node* temp = top;
    if(temp == NULL){
        printf("Stack is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void enqueue(){
    struct node* newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d",&x);
    newnode->data = x;
    newnode->link = NULL;
    if(front == NULL)
        front = rear = newnode;
    else{
        rear->link = newnode;
        rear = newnode;
    }
}

void dequeue(){
    struct node* temp;
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->link;
    if(front == NULL)
        rear = NULL;
    free(temp);
}

void displayQueue(){
    struct node* temp = front;
    if(temp == NULL){
        printf("Queue is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("\n1.Push(Stack)");
        printf("\n2.Pop(Stack)");
        printf("\n3.Display Stack");
        printf("\n4.Enqueue(Queue)");
        printf("\n5.Dequeue(Queue)");
        printf("\n6.Display Queue");
        printf("\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
OUTPUT:
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node *top = NULL;
struct node *front = NULL, *rear = NULL;

void push(){
    struct node* newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d",&x);
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void pop(){
    struct node* temp;
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->link;
    free(temp);
}

void displayStack(){
    struct node* temp = top;
    if(temp == NULL){
        printf("Stack is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void enqueue(){
    struct node* newnode;
    int x;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter element: ");
    scanf("%d",&x);
    newnode->data = x;
    newnode->link = NULL;
    if(front == NULL)
        front = rear = newnode;
    else{
        rear->link = newnode;
        rear = newnode;
    }
}

void dequeue(){
    struct node* temp;
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->link;
    if(front == NULL)
        rear = NULL;
    free(temp);
}

void displayQueue(){
    struct node* temp = front;
    if(temp == NULL){
        printf("Queue is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main(){
    int choice;
    while(1){
        printf("\n1.Push(Stack)");
        printf("\n2.Pop(Stack)");
        printf("\n3.Display Stack");
        printf("\n4.Enqueue(Queue)");
        printf("\n5.Dequeue(Queue)");
        printf("\n6.Display Queue");
        printf("\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: push(); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
OUTPUT:
1.Push(Stack)
2.Pop(Stack)
3.Display Stack
4.Enqueue(Queue)
5.Dequeue(Queue)
6.Display Queue
7.Exit
Enter choice: 1
Enter element: 10

Enter choice: 1
Enter element: 20

Enter choice: 3
20 10

Enter choice: 4
Enter element: 30

Enter choice: 4
Enter element: 40

Enter choice: 6
30 40

Enter choice: 2
Popped element: 20

Enter choice: 5
Deleted element: 30

Enter choice: 7
