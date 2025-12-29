#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;

void insert(int value){
    if((rear+1)%SIZE==front){
        printf("\nQueue overflow\n");
        return;
    }
    if(front==-1)
        front=rear=0;
    else
        rear = (rear+1)%SIZE;
    queue[rear] = value;
    printf("%d inserted into the circular queue\n",value);
}

void delete(){
    if(front==-1){
        printf("\nQueue is empty\n");
        return;
    }
    printf("deleted element: %d\n",queue[front]);
    if(front==rear)
        front=rear=-1;
    else
        front=(front+1)%SIZE;
}

void display(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i=front;
    while(1){
        printf("%d ",queue[i]);
        if(i==rear) break;
        i=(i+1)%SIZE;
    }
    printf("\n");
}

int main(){
    while(1){
        int choice,value;
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d",&value);
                insert(value);
                break;
            case 2:
                delete();
                break;
             case 3:
                display();
                break;
            case 4:
                printf("Exiting program...");
                return 0;
             default:
                printf("invalid choice.");
        }
    }
}

OUTPUT:
Enter your choice: 1
Enter the value to insert: 10
10 inserted into the circular queue
Enter your choice: 1
Enter the value to insert: 20
20 inserted into the circular queue
Enter your choice: 1
Enter the value to insert: 30
30 inserted into the circular queue
Enter your choice: 3
Queue elements are: 10 20 30 
Enter your choice: 2
deleted element: 10
Enter your choice: 2
deleted element: 20
Enter your choice: 3
Queue elements are: 30 
Enter your choice: 2
deleted element: 30
Enter your choice: 2

Queue is empty
Enter your choice:
