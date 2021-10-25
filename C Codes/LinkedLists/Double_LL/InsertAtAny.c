#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *create()
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    return temp;
}

// here we are simply inserting the node at the start of the linked list
node *insert(node *head, int data, int pos)
{
    int count = 1;
    node *t = head;
    node *ptr = create();
    ptr->data = data;

    // we need to check several conditions before inserting the node
    if (pos <= 0 || (pos > count && head == NULL))
    {
        printf("INVALID");
    }
    else if (pos == 1 && head == NULL)
    {
        head = ptr;
    }
    else if (pos == 1)
    {
        t->prev = ptr;
        ptr->next = t;
        head = ptr;
    }
    else
    {
        while (t->next != NULL && count < pos)
        {
            t = t->next;
            count++;
        }
        ptr->next = t;
        ptr->prev = t->prev;
        t->prev->next = ptr;
        t->prev = ptr;
    }
    return head;
}

void traversal(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    node *head = create();
    node *second = create();
    node *third = create();
    node *fourth = create();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = NULL;

    head = insert(head, 69, 3);
    traversal(head);
}