#include<stdio.h>
#include<stdlib.h>

typedef struct edgenode{
    int adjvex;
    int weight;
    struct edgenode *next;
}edgenode;

typedef struct vertexnode{
    int adjvex;
    edgenode *head;
}vertexnode;

int local(vertexnode * G, int vertex, int x)
{
    int i;
    for (i = 0; i < vertex; i++)
        if(G[i].adjvex == x)
            return i;
    return -1;
}

void build(vertexnode *G, int vertex, int edge)
{
    int i, v1, v2, w, pos1, pos2;
    edgenode *e;
    printf("请输入顶点信息：");
    for (i = 0; i < vertex; i++)
    {
        scanf("%d", &G[i].adjvex);
        G[i].head = NULL;
    }
    printf("请输入边的信息：\n");
    for (i = 0; i < edge; i++)
    {
        scanf("%d %d %d", &v1, &v2, &w);
        pos1 = local(G, vertex, v1);
        pos2 = local(G, vertex, v2);
        
        e = (edgenode *)malloc(sizeof(edgenode));
        e->adjvex = v2;
        e->weight = w;
        e->next = G[pos1].head;
        G[pos1].head = e;

        e = (edgenode *)malloc(sizeof(edgenode));
        e->adjvex = v1;
        e->weight = w;
        e->next = G[pos2].head;
        G[pos2].head = e;
    }
}

void print(vertexnode *G, int vertex)
{
    int i;
    edgenode *p;
    for (i = 0; i < vertex; i++)
    {
        printf("%d", G[i].adjvex);
        p = G[i].head;
        while(p != NULL)
        {
            printf("-->%d", p->adjvex);
            p = p->next;
        }
        printf("\n");
    }
}

void clear(vertexnode *G, int vertex)
{
    int i;
    edgenode *p, *q;
    for (i = 0; i < vertex; i++)
    {
        p = G[i].head;
        while(p != NULL)
        {
            q = p->next;
            free(p);
            p = q;
        }
    }
}

int main()
{
    int vertex, edge;
    printf("请依次输入顶点数和边数：");
    scanf("%d %d", &vertex, &edge);
    vertexnode *G = (vertexnode *)malloc(vertex * sizeof(vertexnode));
    build(G, vertex, edge);
    printf("邻接表如下：\n");
    print(G, vertex);
    clear(G, vertex);
    free(G);
    return 0;
}