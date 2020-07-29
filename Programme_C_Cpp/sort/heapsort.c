#include<stdio.h>

void swim(int a[], int child)
{
    int parent = child / 2, temp;
    while(parent > 0)
    {
        if(a[child] < a[parent])
        {
            temp = a[child];
            a[child] = a[parent];
            a[parent] = temp;
            child = parent;
            parent = child / 2;
        }
        else
            break;
    }
}

void sink(int a[], int size)
{
    int parent = 1, child = 2 * parent, temp;
    while(child <= size)
    {
        if(child + 1 <= size && a[child + 1] < a[child])
            child++;
        if(a[child] < a[parent])
        {
            temp = a[child];
            a[child] = a[parent];
            a[parent] = temp;
            parent = child;
            child = 2 * parent;
        }
        else
            break;
    }
}

void heapsort(int a[], int size)
{
    int i, temp;
    for(i = size; i > 1; i--)
    {
        printf("%d ", a[1]);
        a[1] = a[i];
        sink(a, i - 1);
    }
    printf("%d\n", a[1]);
}

int main()
{
    int a[100], size, i;
    scanf("%d", &size);
    for(i = 1; i <= size; i++)
    {
        scanf("%d", &a[i]);
        swim(a, i);
    }
    heapsort(a, size);
    return 0;
}