#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node *head=NULL;

void create(){
    int n,value;
    struct node *temp, *newnode;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&value);
        newnode->data=value;
        newnode->link=NULL;
        if(head==NULL){
            head=newnode;
            temp=head;
        }else{
            temp->link=newnode;
            temp=newnode;
        }
    }
}

void insert_beg(){
    int value;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->link=head;
    head=newnode;
}

void insert_end(){
    int value;
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->link=NULL;
    if(head==NULL){
        head=newnode;
    }else{
        temp=head;
        while(temp->link!=NULL){
            temp=temp->link;
        }
        temp->link=newnode;
    }
}

void insert_pos(){
    int value, pos;
    struct node *newnode, *temp;
    printf("Enter position to insert: ");
    scanf("%d",&pos);
    newnode=(struct node*)malloc(sizeof(newnode));
    printf("Enter data: ");
    scanf("%d",&value);
    newnode->data=value;
    if(pos==1){
        newnode->link=head;
        head=newnode;
        return;
    }
    temp=head;
    for(int i=1; i<pos-1 && temp!=NULL; i++)
        temp=temp->link;
    if(temp==NULL){
        printf("Invalid position\n");
    }else{
        newnode->link = temp->link;
        temp->link=newnode;
    }
}

void display(){
    struct node *temp;
    if(head==NULL){
        printf("SLL is empty\n");
        return;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
int main(){
    int ch;
    while(1){
        printf("\n1.Create\n2.Insert at beginning\n3.Insert at end");
        printf("\n4.Insert at position\n5.Display\n6.Exit");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: create(); break;
            case 2: insert_beg(); break;
            case 3: insert_end(); break;
            case 4: insert_pos(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice.");
        }
    }
}

OUTPUT:
1.Create
2.Insert at beginning
3.Insert at end
4.Insert at position
5.Display
6.ExitEnter your choice: 1
ENter the number of nodes: 3
Enter data: 10
Enter data: 20
Enter data: 30

1.Create
2.Insert at beginning
3.Insert at end
4.Insert at position
5.Display
6.ExitEnter your choice: 2
Enter data: 500

1.Create
2.Insert at beginning
3.Insert at end
4.Insert at position
5.Display
6.ExitEnter your choice: 3
Enter data: 200

1.Create
2.Insert at beginning
3.Insert at end
4.Insert at position
5.Display
6.ExitEnter your choice: 4
Enter position to insert: 2
Enter data: 1000

1.Create
2.Insert at beginning
3.Insert at end
4.Insert at position
5.Display
6.ExitEnter your choice: 5
500 1000 10 20 30 200 
1.Create
2.Insert at beginning
3.Insert at end
4.Insert at position
5.Display
6.ExitEnter your choice: 6
