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
    int i, from, to, w, pos;
    printf("请输入顶点信息：");
    for (i = 0; i < vertex; i++)
    {
        scanf("%d", &G[i].adjvex);
        G[i].head = NULL;
    }
    printf("请输入边的信息：\n");
    for (i = 0; i < edge; i++)
    {
        scanf("%d %d %d", &from, &to, &w);
        pos = local(G, vertex, from);
        if(G[pos].head == NULL)
        {
            G[pos].head = (edgenode *)malloc(sizeof(edgenode));
            G[pos].head->adjvex = to;
            G[pos].head->weight = w;
            G[pos].head->next = NULL;
        }
        else
        {
            edgenode *p = G[pos].head;
            while(p->next != NULL)
                p = p->next;
            p->next = (edgenode *)malloc(sizeof(edgenode));
            p->next->adjvex = to;
            p->next->weight = w;
            p->next->next = NULL;
        }
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