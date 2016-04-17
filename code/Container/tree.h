#ifndef TREE_H
#define TREE_H

struct node
{
    node* root;
    node* left;
    node* right;
    int data;
};

class Tree
{
    node* root;
    void insert(node* pRoot, int Data);
public:
    Tree();
    Tree(int Data);
    ~Tree();
    void show();
    void remove(int Data);
    void insert(int Data);
};

#endif // TREE_H
