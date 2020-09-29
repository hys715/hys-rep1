#include<stdio.h>

void shellsort(int a[], int size)
{
    for (int dis = size >> 1; dis > 0; dis >>= 1)
        for (int i = dis; i < size; ++i)
        {
            int tmp = a[i], j = i;
            for (; j >= dis && tmp < a[j - dis]; j -= dis)
                a[j] = a[j - dis];
            a[j] = tmp;
        }
}

int main()
{
    int a[100], size, i;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
        scanf("%d", &a[i]);
    shellsort(a, size);
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}