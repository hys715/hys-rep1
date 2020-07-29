#include<stdio.h>
#include<string.h>

void sort(int a[], int lstart, int lend, int rstart, int rend)
{
    int p[100], i = lstart, j = rstart, k = 0;
    while(i <= lend && j <= rend)
    {
        if(a[i] < a[j])
            p[k++] = a[i++];
        else
            p[k++] = a[j++];
    }
    while(i <= lend)
        p[k++] = a[i++];
    while(j <= rend)
        p[k++] = a[j++];
    for(i = 0; i <= rend - lstart; i++)
        a[i + lstart] = p[i];
}

void merge(int a[], int left, int right, int size)
{
    if(size == 1)
        return;
    if(size % 2 == 0)
    {
        merge(a, left, left + size / 2 - 1, size / 2);
        merge(a, right - size / 2 + 1, right, size / 2);
        sort(a, left, left + size / 2 - 1, right - size / 2 + 1, right);
    }
    else
    {
        merge(a, left, left + size / 2, size / 2 + 1);
        merge(a, right - size / 2 + 1, right, size / 2);
        sort(a, left, left + size / 2, right - size / 2 + 1, right);
    }
}

int main()
{
    int a[100], size, i;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
        scanf("%d", &a[i]);
    merge(a, 0, size - 1, size);
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}