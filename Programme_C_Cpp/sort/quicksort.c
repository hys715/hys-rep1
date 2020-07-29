#include<stdio.h>

void sort(int a[], int left, int right)
{
    int i = left, j = right, mid = a[(left + right) / 2], temp;
    while(i <= j)
    {
        while(a[i] < mid) 
            i++;
        while(a[j] > mid)
            j--;
        if(i <= j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if(i < right)
        sort(a, i, right);
    if(j > left)
        sort(a, left, j);
}

int main()
{
    int a[100], size, i;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
        scanf("%d", &a[i]);
    sort(a, 0, size - 1);
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}