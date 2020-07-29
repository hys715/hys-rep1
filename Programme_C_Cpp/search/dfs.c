#include<stdio.h>
#include<string.h>

char map[500][500];
int visit[500][500], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
int n, m, ok, sx, sy, fx, fy;

void dfs(int x, int y)
{
    if(x == fx && y == fy)
    {
        ok = 1;
        return;
    }
    int i;
    for(i = 0; i < 4; i++)
    {
        if(x + dx[i] < 0 || x + dx[i] >= n || y + dy[i] < 0 || y + dy[i] >= m)
            continue;
        if(visit[x + dx[i]][y + dy[i]] == 0 && map[x + dx[i]][y + dy[i]] != '#')
        {
            visit[x][y] = 1;
            dfs(x + dx[i], y + dy[i]);
            visit[x][y] = 0;
            if(ok)
                return;
        }
    }
}

int main()
{
    int i, j;
    char c;
    scanf("%d %d ", &n, &m);
    for(i = 0; i < n; i++)
        scanf("%s", map[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if(map[i][j] == 's')
            {
                sx = i;
                sy = j;
            }
            if(map[i][j] == 'g')
            {
                fx = i;
                fy = j;
            }
        }
    dfs(sx, sy);
    if(ok)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}