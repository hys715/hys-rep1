#include<stdio.h>
#include<stdbool.h>
#define MAX 1000000

int map[5001][5001];
int dis[5001];
bool visit[5001];

int main()
{
    int n, m, x, y, z, i, j, ans = 0, ok = 1, min, pos;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            if(i != j)
                map[i][j] = MAX;
            else
                map[i][j] = 0;
        }
    for(i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &x, &y, &z);
        if(z < map[x][y])
            map[x][y] = map[y][x] = z;
    }
    for(i = 1; i <= n; i++)
        dis[i] = map[1][i];
    visit[1] = true;
    for(i = 1; i < n; i++)
    {
        min = MAX;
        pos = -1;
        for(j = 1; j <= n; j++)
            if(dis[j] != 0 && dis[j] < min)
            {
                min = dis[j];
                pos = j;
            }
        if(pos == -1)
        {
            ok = 0;
            break;
        }
        visit[pos] = true;
        ans += dis[pos];
        dis[pos] = 0;
        for(j = 1; j <= n; j++)
            if(visit[j] == false && map[pos][j] < dis[j])
                dis[j] = map[pos][j];
    }
    if(ok)
        printf("%d\n", ans);
    else
        printf("orz\n");
    return 0;
}
