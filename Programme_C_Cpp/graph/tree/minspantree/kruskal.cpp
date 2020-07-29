#include<stdio.h>
#include<algorithm>
using namespace std;

struct node{
    int x, y;
    int weight;
}edge[200000];
int f[5001];

int cmp(struct node a, struct node b)
{
    return a.weight < b.weight;
}

int Find(int x)
{
    if(f[x] == x)
        return x;
    else
        return f[x] = Find(f[x]);
}

int main()
{
    int n, m, i, ans = 0, a, b, count = 0;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        f[i] = i;
    for (i = 0; i < m; i++)
        scanf("%d %d %d", &edge[i].x, &edge[i].y, &edge[i].weight);
    sort(edge, edge + m, cmp);
    for (i = 0; i < m; i++)
    {
        a = Find(edge[i].x);
        b = Find(edge[i].y);
        if(a != b)
        {
            ans += edge[i].weight;
            count++;
            f[a] = b;
        }
        if(count == n - 1)
            break;
    }
    if(count == n - 1)
        printf("%d\n", ans);
    else
        printf("orz\n");
    return 0;
}