#include<stdio.h>

int a[1000], d[1000];

int main()
{
	int n, i, max = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	d[0] = 1;
	for(i = 1; i < n; i++)
	{
		if(a[i] >= a[i - 1])
			d[i] = d[i - 1] + 1;
		else
			d[i] = 1;
	}
	for(i = 0; i < n; i++)
		if(d[i] > max)
			max = d[i];
	printf("%d\n", max);
	return 0;
}