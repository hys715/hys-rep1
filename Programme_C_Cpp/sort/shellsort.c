#include<stdio.h>

void shellsort(int a[], int size)
{
    int dis = size / 2, i, j, k, temp;
    while(dis > 0)
    {
        for(i = 0; i < dis; i++)
        {
            for(j = i + dis; j < size; j += dis)
            {
                temp = a[j];
                for(k = j - dis; k >= 0 && a[k] > temp; k -= dis)
                    a[k + dis] = a[k];
                a[k + dis] = temp;
            }
        }
        dis /= 2;
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