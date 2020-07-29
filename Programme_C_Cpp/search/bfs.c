#include<stdio.h>

struct queue{
    int x, y;
} queue[250000];

struct lord{
    int x, y;
} lord[100000];

int map[501][501], visit[501][501], n, m, a, b;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main()
{
    int head = 0, end, i, count = 0, x, y, j;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for (i = 0; i < a; i++)
    {
        scanf("%d %d", &queue[i].x, &queue[i].y);
        visit[queue[i].x][queue[i].y] = -1;
    }
    end = a;
    for(i = 0; i < b; i++)
    {
        scanf("%d %d", &lord[i].x, &lord[i].y);
        if(visit[lord[i].x][lord[i].y] == -1)
            count++;
        else
            visit[lord[i].x][lord[i].y] = 1;
    }
    while(head < end)
    {
        x = queue[head].x;
        y = queue[head].y;
        for (i = 0; i < 4; i++)
        {
            if(x + dx[i] <= 0 || x + dx[i] > n || y + dy[i] <= 0 || y + dy[i] > m)
                continue;
            if(visit[x + dx[i]][y + dy[i]] != -1)
            {
                if(visit[x + dx[i]][y + dy[i]] == 1)
                    count++;
                queue[end].x = x + dx[i];
                queue[end].y = y + dy[i];
                end++;
                visit[x + dx[i]][y + dy[i]] = -1;
                map[x + dx[i]][y + dy[i]] = map[x][y] + 1;
            }
        }
        if(count == b)
            break;
        head++;
    }
    for (i = 0; i < b; i++)
        printf("%d\n", map[lord[i].x][lord[i].y]);
    return 0;
}
