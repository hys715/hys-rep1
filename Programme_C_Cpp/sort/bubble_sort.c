#include<stdio.h>

int main()
{
    int a[100], size, i, j, temp;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < size - 1; i++)
        for(j = size - 1; j > i; j--)
        {
            if(a[j] < a[j - 1])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}