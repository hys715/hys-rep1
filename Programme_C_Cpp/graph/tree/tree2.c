#include<stdio.h>

int a[100];

void buildtree(int pre[], int in[], int root, int size)
{
    a[root] = pre[0];
    if(size == 1)
        return;
    int pos, pre1[100], pre2[100], in1[100], in2[100], i;
    for(pos = 0; pos < size; pos++)
        if(pre[0] == in[pos])
            break;
    if(pos != 0)
    {
        for(i = 0; i < pos; i++)
            pre1[i] = pre[i + 1];
        for(i = 0; i < pos; i++)
            in1[i] = in[i];
        buildtree(pre1, in1, 2 * root + 1, pos);
    }
    if(pos != size - 1)
    {
        for(i = 0; i < size - pos - 1; i++)
            pre2[i] = pre[i + pos + 1];
        for(i = 0; i < size - pos - 1; i++)
            in2[i] = in[i + pos + 1];
        buildtree(pre2, in2, 2 * root + 2, size - pos - 1);
    }
}

void postorder_traversal(int root)
{
    if(a[root] == 0)
        return;
    postorder_traversal(2 * root + 1);
    postorder_traversal(2 * root + 2);
    printf("%d ", a[root]);
}

int main()
{
    int pre[100], in[100], i, size;
    printf("请输入二叉树的大小：\n");
    scanf("%d", &size);
    printf("请输入二叉树的前序序列：\n");
    for(i = 0; i < size; i++)
        scanf("%d", &pre[i]);
    printf("请输入二叉树的中序序列：\n");
    for(i = 0; i < size; i++)
        scanf("%d", &in[i]);
    buildtree(pre, in, 0, size);
    printf("二叉树的后序序列为：\n");
    postorder_traversal(0);

    return 0;
}