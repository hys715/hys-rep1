#include<stdio.h>
#define m 100

struct queue{
    int a[m];
    int len;
}queue;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swim()
{
    int parent, child;
    for(parent = queue.len / 2; parent > 0; parent--)
    {
        child = 2 * parent;
        if(child + 1 <= queue.len && queue.a[child + 1] < queue.a[child])
            child++;
        if(queue.a[child] < queue.a[parent])
            swap(&queue.a[child], &queue.a[parent]);
    }
}

void sink()
{
    int parent = 1, child = 2;
    while(child <= queue.len)
    {
        if(child + 1 <= queue.len && queue.a[child + 1] < queue.a[child])
            child++;
        if(queue.a[child] < queue.a[parent])
        {
            swap(&queue.a[child], &queue.a[parent]);
            parent = child;
            child = 2 * parent;
        }
        else
            break;
    }
}

void dequeue()
{
    swim();
    printf("Delete the num:%d\n", queue.a[1]);
    swap(&queue.a[1], &queue.a[queue.len]);
    queue.len--;
    sink();
}

void print()
{
    int i;
    for (i = 1; i <= queue.len; i++)
        printf("%d ", queue.a[i]);
    printf("\n");
}

int main()
{
    int order;
    queue.len = 0;
    while(1)
    {
        printf("1.inqueue   2.dequeue   3.print   -1.quit:");
        scanf("%d", &order);
        if(order == 1)
        {
            printf("Enter the num:");
            scanf("%d", &queue.a[++queue.len]);
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