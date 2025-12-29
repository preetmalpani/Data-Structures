#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};

struct node* createList(int n){
    struct node* head=NULL, *newnode, *temp;
    int i,val;
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ",i+1);
        scanf("%d",&val);
        newnode->data=val;
        newnode->link=NULL;
        if(head==NULL)
            head = newnode;
        else{
            temp=head;
            while(temp->link!=NULL){
                temp=temp->link;
            }
            temp->link = newnode;
        }
    }
    return head;
}

void displayList(struct node* head){
    struct node* temp = head;
    if(temp==NULL){
        printf("list is empty\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

struct node* sortList(struct node* head){
    struct node* i,*j;
    int temp;
    for(i=head; i!=NULL; i=i->link){
        for(j=i->link; j!=NULL; j=j->link){
            if(i->data > j->data){
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

struct node* reverseList(struct node* head){
    struct node* prev=NULL, *current=head, *link=NULL;
    while(current != NULL){
        link = current->link;
        current->link = prev;
        prev = current;
        current = link;
    }
    head=prev;
    return head;
}

struct node* concatenate(struct node* head1, struct node* head2){
    if(head1==NULL)
        return head2;
    struct node* temp = head1;
    while(temp->link != NULL)
        temp=temp->link;
    temp->link = head2;
    return head1;
}

int main(){
    struct node* head1 = NULL, *head2 = NULL;
    int n1,n2,choice;
    printf("Enter number of elements for 1st list: ");
    scanf("%d",&n1);
    head1 = createList(n1);
    printf("Enter number of elements for 2nd list: ");
    scanf("%d",&n2);
    head2 = createList(n2);
    while(1){
        printf("\n1.display list1\n2.display list2\n3.sort 1\n4.sort 2\n5.reverse 1\n6.reverse 2\n7.concatenate\n8.exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        displayList(head1);
        break;

         case 2:
        displayList(head2);
        break;

        case 3:
        head1 = sortList(head1);
        printf("List 1 sorted\n");
        break;

        case 4:
        head2 = sortList(head2);
        printf("List 2 sorted\n");
        break;

        case 5:
        head1 = reverseList(head1);
        printf("List 1 reversed\n");
        break;

            case 6:
        head2 = reverseList(head2);
        printf("List 2 reversed\n");
        break;

        case 7:
        head1 = concatenate(head1, head2);
        printf("Lists concatenated (List2 added to List1)\n");
        break;

        case 8:
        exit(0);

        default:
        printf("Enter a valid choice\n");
    }

    }
}

OUTPUT:
Enter number of elements for 1st list: 3
Enter element 1: 20
Enter element 2: 10
Enter element 3: 30
Enter number of elements for 2nd list: 4
Enter element 1: 60
Enter element 2: 15
Enter element 3: 70
Enter element 4: 90

1.display list1
2.display list2
3.sort 1
4.sort 2
5.reverse 1
6.reverse 2
7.concatenate
8.exit
Enter your choice: 3
List 1 sorted

1.display list1
2.display list2
3.sort 1
4.sort 2
5.reverse 1
6.reverse 2
7.concatenate
8.exit
Enter your choice: 4
List 2 sorted

1.display list1
2.display list2
3.sort 1
4.sort 2
5.reverse 1
6.reverse 2
7.concatenate
8.exit
Enter your choice: 1
10 20 30 

1.display list1
2.display list2
3.sort 1
4.sort 2
5.reverse 1
6.reverse 2
7.concatenate
8.exit
Enter your choice: 2
15 60 70 90 

1.display list1
2.display list2
3.sort 1
4.sort 2
5.reverse 1
6.reverse 2
7.concatenate
8.exit
Enter your choice: 5
List 1 reversed

1.display list1
2.display list2
3.sort 1
4.sort 2
5.reverse 1
6.reverse 2
7.concatenate
8.exit
Enter your choice: 7
Lists concatenated (List2 added to List1)

1.display list1
2.display list2
3.sort 1
4.sort 2
5.reverse 1
6.reverse 2
7.concatenate
8.exit
Enter your choice: 1
30 20 10 15 60 70 90 

1.display list1
2.display list2
3.sort 1
4.sort 2
5.reverse 1
6.reverse 2
7.concatenate
8.exit
Enter your choice: 8
