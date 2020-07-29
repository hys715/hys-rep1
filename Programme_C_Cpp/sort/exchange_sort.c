#include<stdio.h>

int main()
{
    int a[100], size, i, j, temp;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < size - 1; i++)
        for(j = i + 1; j < size; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}