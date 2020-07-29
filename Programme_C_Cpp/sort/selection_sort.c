#include<stdio.h>

int main()
{
    int a[100], size, i, j, temp, min;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < size - 1; i++)
    {
        temp = i;
        min = a[temp];
        for(j = i + 1; j < size; j++)
        {
            if(min > a[j])
            {
                min = a[j];
                temp = j;
            }
        }
        a[temp] = a[i];
        a[i] = min;
    }
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}