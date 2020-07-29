#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *left, *right;
}node;

node *buildtree()
{
    int val;
    scanf("%d", &val);
    if(val == -1)
        return NULL;
    node *root = (node *)malloc(sizeof(node));
    root->value = val;
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

void preorder_traversal(node *root)
{
    if(root == NULL)
        return;
    printf("%d ", root->value);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(node *root)
{
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

void postorder_traversal(node *root)
{
    if(root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->value);
}

void clear(node *root)
{
    if(root == NULL)
        return;
    clear(root->left);
    clear(root->right);
    free(root);
}

int main()
{
    printf("请输入二叉树的前序序列(-1代表根为空）：\n");
    node *root = buildtree();
    
    printf("二叉树的前序序列为：\n");
    preorder_traversal(root);
    printf("\n");
    
    printf("二叉树的中序序列为：\n");
    inorder_traversal(root);
    printf("\n");
    
    printf("二叉树的后序序列为：\n");
    postorder_traversal(root);
    printf("\n");

    clear(root);
    return 0;
}