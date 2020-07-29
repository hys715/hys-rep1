#include<stdio.h>
#define m 10

struct queue{
    int a[m];
    int len, end;
} queue;

void inqueue(int x)
{
    if(queue.len == m)
    {
        printf("The queue is full!\n");
        return;
    }
    if(queue.end == m)
    {
        queue.end = 0;
        queue.a[queue.end++] = x;
        queue.len++;
    }
    else
    {
        queue.a[queue.end++] = x;
        queue.len++;
    }
}

void dequeue()
{
    if(queue.len == 0)
    {
        printf("The queue is empty!\n");
        return;
    }
    if(queue.end - queue.len >= 0)
    {
        printf("%d\n", queue.a[queue.end - queue.len]);
        queue.len--;
    }
    else
    {
        printf("%d\n", queue.a[queue.end + m - queue.len]);
        queue.len--;
    }
}

void print()
{
    int i;
    if(queue.len == 0)
    {
        printf("The queue is empty!\n");
        return;
    }
    for(i = 0; i < queue.len; i++)
    {
        if(queue.end - queue.len + i >= 0)
            printf("%d ", queue.a[queue.end - queue.len + i]);
        else
            printf("%d ", queue.a[queue.end + m - queue.len + i]);
    }
    printf("\n");
}

int main()
{
    int order, x;
    queue.len = queue.end = 0;
    while(1)
    {
        printf("1.inqueue   2.dequeue   3.print   -1.quit:");
        scanf("%d", &order);
        if(order == 1)
        {
            printf("Enter the num:");
            scanf("%d", &x);
            inqueue(x);
        }
        if(order == 2)
            dequeue();
        if(order == 3)
            print();
        if(order == -1)
            break;
    }
    return 0;
}