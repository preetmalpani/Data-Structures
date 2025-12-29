#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* head=NULL;

void create(){
    int n, value;
    struct node *temp, *newnode;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
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

void delete_first(){
    struct node *temp;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    temp=head;
    head=head->link;
    free(temp);
    printf("first element deleted\n");
}

void delete_specified(){
    int key;
    struct node *temp, *prev;
    if(head==NULL){
        printf("list is empty.");
        return;
    }
    printf("Enter the element to delete: ");
    scanf("%d",&key);
    if(head->data==key){
        delete_first();
        return;
    }
    prev=head;
    temp=head->link;
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->link;
    }
    if(temp==NULL){
        printf("Element not found.");
    }else{
        prev->link = temp->link;
        free(temp);
        printf("specified element deleted.");
    }
}

void delete_last(){
    struct node *temp, *prev;
    if(head==NULL){
        printf("list is empty");
        return;
    }
    if(head->link==NULL){
        free(head);
        head=NULL;
        printf("last element deleted.");
        return;
    }
    prev=head;
    temp=head->link;
    while(temp->link!=NULL){
        prev=temp;
        temp=temp->link;
    }
    prev->link=NULL;
    free(temp);
    printf("last element deleted");
}

void display(){
    struct node *temp;
    if(head==NULL){
        printf("list is empty.");
        return;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int main(){
    int ch;
    while(1){
        printf("\n1.create\n2.delete first\n3.delete specified\n4.delete last\n5.display\n6.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: create(); break;
            case 2: delete_first(); break;
            case 3: delete_specified(); break;
            case 4: delete_last(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("invalid choice");
        }
    }
}

OUTPUT:
1.create
2.delete first
3.delete specified
4.delete last
5.display
6.exit
Enter your choice: 1
Enter the number of nodes: 3
Enter the data: 10
Enter the data: 20
Enter the data: 30

1.create
2.delete first
3.delete specified
4.delete last
5.display
6.exit
Enter your choice: 2
first element deleted

1.create
2.delete first
3.delete specified
4.delete last
5.display
6.exit
Enter your choice: 5
20 30 

1.create
2.delete first
3.delete specified
4.delete last
5.display
6.exit
Enter your choice: 3
Enter the element to delete: 30
specified element deleted.
1.create
2.delete first
3.delete specified
4.delete last
5.display
6.exit
Enter your choice: 5
20 

1.create
2.delete first
3.delete specified
4.delete last
5.display
6.exit
Enter your choice: 3  
Enter the element to delete: 100
Element not found.
1.create
2.delete first
3.delete specified
4.delete last
5.display
6.exit
Enter your choice: 6
