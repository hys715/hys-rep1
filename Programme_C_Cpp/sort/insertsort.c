#include<stdio.h>

int main()
{
    int a[100], size, i, j, k, temp;
    scanf("%d", &size);
    for(i = 0; i < size; i++)
        scanf("%d", &a[i]);
    for(i = 1; i < size; i++)
        for(j = 0; j < i; j++)
        {
            if(a[i] < a[j])
            {
                temp = a[i];
                for(k = i; k > j; k--)
                    a[k] = a[k - 1];
                a[j] = temp;
                break;
            }
        }
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}