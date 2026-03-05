//Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    int n,k,x,i;
    scanf("%d",&n);
    struct node *head=NULL,*temp=NULL,*newnode=NULL,*tail=NULL;
    
    for(i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }else{
            tail->next=newnode;
            tail=newnode;
        }
    }

    scanf("%d",&k);

    if(n>0){
        k=k%n;
        for(i=0;i<k;i++){
            struct node *prev=NULL;
            temp=head;
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }
            temp->next=head;
            prev->next=NULL;
            head=temp;
        }
    }

    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

    return 0;
}
