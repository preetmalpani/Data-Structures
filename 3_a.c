#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front=-1, rear=-1;

void insert(int value){
    if(rear == SIZE-1){
        printf("\nQueue overflow\n");
    }else{
        if(front==-1)
            front=0;
        rear++;
        queue[rear]=value;
        printf("%d inserted in queue\n",value);
    }
}
void delete(){
    if(front==-1 || front>rear){
        printf("\nQueue is empty.\n");
    }else{
        printf("%d is deleted from queue",queue[front]);
        front++;
    }
}
void display(){
    if(front==-1 || front>rear){
        printf("\nQueue is empty.\n");
    }else{
        printf("Queue elements are: ");
        for(int i=front;i<=rear;i++){
            printf("%d",queue[i]);
        }
        printf("\n");
    }
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
10 inserted in queue
Enter your choice: 1
Enter the value to insert: 20
20 inserted in queue
Enter your choice: 1
Enter the value to insert: 30
30 inserted in queue
Enter your choice: 3
Queue elements are: 10 20 30 
Enter your choice: 2
10 is deleted from queueEnter your choice: 3
Queue elements are: 20 30 
Enter your choice: 4
Exiting program...
