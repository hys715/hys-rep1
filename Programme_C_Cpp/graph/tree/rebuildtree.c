#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* reConstructBinaryTree(int *pre, int *in, int size)
{
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->val = *pre;
    root->left = NULL;
    root->right = NULL;
    if(size == 1)
        return root;
    int pos;
    for (pos = 0; pos < size; pos++)
        if(in[pos] == *pre)
            break;
    if(pos != 0)
        root->left = reConstructBinaryTree(pre + 1, in, pos);
    if(pos != size - 1)
        root->right = reConstructBinaryTree(pre + pos + 1, in + pos + 1, size - pos - 1);
    return root;
}

void postOrder(TreeNode* root) {
    if (root == NULL) return ;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

void deleteTree(TreeNode* root)
{
    if(root == NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main() {
    int preOrder[100], inOrder[100];
    int size, i;
    scanf("%d", &size);
    for (i = 0; i < size; ++i) {
        scanf("%d", &preOrder[i]);
    }
    for (i = 0; i < size; ++i) {
        scanf("%d", &inOrder[i]);
    }

    TreeNode* root = reConstructBinaryTree(preOrder, inOrder, size);
    postOrder(root);
    printf("\n");
    deleteTree(root);
    root = NULL;
    return 0;
}
