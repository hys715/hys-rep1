#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct node {
    int value, height;
    node *left, *right;
    node(int v = 0, node *l = nullptr, node *r = nullptr)
    : value(v), height(0), left(l), right(r) {}
};

int getheight(node *p) { return p ? p->height : 0; }

node *LLRotate(node *p)
{
    node *p1 = p->left;
    p->left = p1->right;
    p1->right = p;
    p->height = max(getheight(p->left), getheight(p->right)) + 1;
    p1->height = max(getheight(p1->left), getheight(p1->right)) + 1;
    return p1;
}

node *RRRotate(node *p)
{
    node *p1 = p->right;
    p->right = p1->left;
    p1->left = p;
    p->height = max(getheight(p->left), getheight(p->right)) + 1;
    p1->height = max(getheight(p1->left), getheight(p1->right)) + 1;
    return p1;
}

node *LRRotate(node *p)
{
    p->left = RRRotate(p->left);
    return LLRotate(p);
}

node *RLRotate(node *p)
{
    p->right = LLRotate(p->right);
    return RRRotate(p);
}

node *insert(node *root, int &val)
{
    if (!root)
        root = new node(val);
    else if (val == root->value)
        cout << "*****ERROR!*****\n";
    else if (val < root->value)
    {
        root->left = insert(root->left, val);
        if (getheight(root->left) - getheight(root->right) == 2)
        {
            if (val < root->left->value)
                root = LLRotate(root);
            else
                root = LRRotate(root);
        }
    }
    else
    {
        root->right = insert(root->right, val);
        if (getheight(root->right) - getheight(root->left) == 2)
        {
            if (val > root->right->value)
                root = RRRotate(root);
            else
                root = RLRotate(root);
        }
    }
    root->height = max(getheight(root->left), getheight(root->right)) + 1;
    return root;
}

void show(node *root)
{
    if (!root)
        return;
    cout << '(' << root->value << ", " << root->height << ") ";
    show(root->left);
    show(root->right);
}

void destroy(node *root)
{
    if (!root)
        return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main()
{
    ifstream fin;
    int val;
    node *root = nullptr;
    fin.open("in.txt");
    if (!fin)
        cout << "~~~~ERROR!~~~~~\n";
    else
    {
        while (fin >> val)
        {
            root = insert(root, val);
            show(root);
            cout << endl;
        }
        fin.close();
    }
    destroy(root);
    return 0;
}