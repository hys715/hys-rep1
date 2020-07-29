#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree{
    char node;
    struct tree *left, *right;
}Tree;

Tree *Buildtree(char *in, char *post, int len)
{
    Tree *root = (Tree *)malloc(sizeof(Tree));
    root->node = post[len - 1];
    root->left = NULL;
    root->right = NULL;
    if(len == 1)
        return root;
    char in1[10], in2[10], post1[10], post2[10];
    int pos, i;
    for (pos = 0; pos < len; pos++)
        if(in[pos] == post[len - 1])
            break;
    if(pos != 0)
    {
        for (i = 0; i < pos; i++)
            in1[i] = in[i];
        for (i = 0; i < pos; i++)
            post1[i] = post[i];
        root->left = Buildtree(in1, post1, pos);
    }
    if(pos != len - 1)
    {
        for (i = 0; i < len - 1 - pos; i++)
            in2[i] = in[i + pos + 1];
        for (i = 0; i < len - 1 - pos; i++)
            post2[i] = post[i + pos];
        root->right = Buildtree(in2, post2, len - 1 - pos);
    }
    return root;
}

void pretravel(Tree * root)
{
    if(root == NULL)
        return;
    printf("%c", root->node);
    pretravel(root->left);
    pretravel(root->right);
}

void clear(Tree *root)
{
    if(root == NULL)
        return;
    clear(root->left);
    clear(root->right);
    free(root);
}

int main()
{
    char in[10], post[10];
    scanf("%s %s", in, post);
    int len = strlen(in);
    Tree *root = Buildtree(in, post, len);
    pretravel(root);
    printf("\n");
    clear(root);
    return 0;
}