#include<stdio.h>

int map[100][100];
char vex[100];

int local(char x, int vertex)
{
    int i;
    for(i = 0; i < vertex; i++)
        if(vex[i] == x)
            return i;
    return -1;
}

int main()
{
    int vertex, edge, i, j, order, w, pos1, pos2;
    char v1, v2, c;
    printf("请依次输入顶点数和边数：");
    scanf("%d %d", &vertex, &edge);
    printf("请输入指令：1.无向图    2.有向图\n");
    scanf("%d", &order);
    printf("请输入顶点信息：");
    for(i = 0; i < vertex; i++)
        scanf("%c %c", &c, &vex[i]);
    printf("请输入边的信息：\n");
    for(i = 0; i < edge; i++)
    {
        scanf("%c %c %c %d", &c, &v1, &v2, &w);
        pos1 = local(v1, vertex);
        pos2 = local(v2, vertex);
        map[pos1][pos2] = w;
        if(order == 1)
            map[pos2][pos1] = w;
    }
    printf("邻接矩阵如下：\n");
    printf(" ");
    for(i = 0; i < vertex; i++)
        printf("    %c", vex[i]);
    printf("\n");
    for(i = 0; i < vertex; i++)
    {
        printf("%c", vex[i]);
        for(j = 0; j < vertex; j++)
            printf("%5d", map[i][j]);
        printf("\n");
    }
    return 0;
}