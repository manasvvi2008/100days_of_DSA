// Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int n, key, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL, *prev = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    temp = head;
    prev = NULL;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            if(prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
