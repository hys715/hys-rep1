#include<stdio.h>

int w[25], v[25], d[25][150000];

int main()
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= m; i++)
		scanf("%d %d", &w[i], &v[i]);
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
		{
			if(w[i] <= j && d[i - 1][j - w[i]] + w[i] * v[i] > d[i - 1][j])
				d[i][j] = d[i - 1][j - w[i]] + w[i] * v[i];
			else
				d[i][j] = d[i - 1][j];
		}
	printf("%d\n", d[m][n]);
	return 0;
}