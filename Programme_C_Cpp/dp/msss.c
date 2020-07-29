#include<stdio.h>

int a[200000], w[200000];

int main()
{
	int n, i, max;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	w[0] = a[0];
	for(i = 1; i < n; i++)
		w[i] = (w[i - 1] + a[i]) > a[i] ? (w[i - 1] + a[i]) : a[i];
	max = w[0];
	for(i = 1; i < n; i++)
		if(w[i] > max)
			max = w[i];
	printf("%d\n", max);
	return 0;
}