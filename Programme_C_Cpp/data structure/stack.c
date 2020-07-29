#include<stdio.h>
#include<stdlib.h>
#define m 5

typedef struct node{
    int value;
    struct node *next;
} Node;

struct{
    Node *head, *end;
    int size;
} stack;

void stack_push()
{
    if(stack.size == m)
    {
        printf("The stack is full!\n");
        return;
    }
    Node *p = (Node *)malloc(sizeof(Node));
    printf("Enter the num:");
    scanf("%d", &p->value);
    p->next = NULL;
    if(stack.head == NULL)
    {
        stack.head = p;
        stack.end = p;
        stack.size++;
    }
    else
    {
        stack.end->next = p;
        stack.end = p;
        stack.size++;
    }
}

void stack_pop()
{
    if(stack.size == 0)
    {
        printf("The stack is empty!\n");
        return;
    }
    printf("Delete the num:%d\n", stack.end->value);
    free(stack.end);
    stack.size--;
    if(stack.size == 0)
    {
        stack.head = NULL;
        stack.end = NULL;
        return;
    }
    Node *p = stack.head;
    int i;
    for(i = 1; i < stack.size; i++)
        p = p->next;
    p->next = NULL;
    stack.end = p;
}

void stack_top()
{
    if(stack.size == 0)
    {
        printf("The stack is empty!\n");
        return;
    }
    printf("The position is %d, The value is %d\n", stack.size, stack.end->value);
}

void print()
{
    if(stack.size == 0)
    {
        printf("The stack is empty!\n");
        return;
    }
    Node *p = stack.head;
    while(p != NULL)
    {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}

void clear()
{
    Node *p = stack.head, *q;
    while(p != NULL)
    {
        q = p->next;
        free(p);
        p = q;
    }
}

int main()
{
    int order;
    stack.head = NULL;
    stack.end = NULL;
    stack.size = 0;
    while(1)
    {
        printf("Enter the order:1.push  2.pop  3.top  4.print  -1.quit:");
        scanf("%d", &order);
        if(order == 1)
            stack_push();
        else if(order == 2)
            stack_pop();
        else if(order == 3)
            stack_top();
        else if(order == 4)
            print();
        else
        {
            clear();
            break;
        }
    }
    return 0;
}