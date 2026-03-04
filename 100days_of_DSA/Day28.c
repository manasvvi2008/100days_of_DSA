//Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    int n,i,x;
    scanf("%d",&n);
    struct node *head=NULL,*temp=NULL,*newnode=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    if(temp!=NULL)
        temp->next=head;

    temp=head;
    if(head!=NULL){
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }while(temp!=head);
    }
    return 0;
}
