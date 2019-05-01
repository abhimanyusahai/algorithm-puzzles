#include <iostream>

class BinaryTree
{
    int m_data;
    BinaryTree *m_left;
    BinaryTree *m_right;

public:
    BinaryTree(int data) : m_data(data), m_left(NULL), m_right(NULL)
    {
    }

    int getRootVal() { return m_data; }

    void setRootVal(int data) { m_data = data; }

    BinaryTree* getLeft() { return m_left; }

    void setLeft(BinaryTree *left) { m_left = left; }

    BinaryTree* getRight() { return m_right; }

    void setRight(BinaryTree *right) { m_right = right; }

    void addLeft(int data)
    {
        BinaryTree *t = new BinaryTree(data);
        m_left = t;
    }

    void addRight(int data)
    {
        BinaryTree *t = new BinaryTree(data);
        m_right = t;
    }
};

void preorder(BinaryTree *tree)
{
    if (tree)
    {
        std::cout << tree->getRootVal() << ' ';
        preorder(tree->getLeft());
        preorder(tree->getRight());
    }
}

void postorder(BinaryTree *tree)
{
    if (tree)
    {
        postorder(tree->getLeft());
        postorder(tree->getRight());
        std::cout << tree->getRootVal() << ' ';
    }
}

void inorder(BinaryTree *tree)
{
    if (tree)
    {
        inorder(tree->getLeft());
        std::cout << tree->getRootVal() << ' ';
        inorder(tree->getRight());
    }
}

int main()
{
    BinaryTree *r = new BinaryTree(12);
    r->addLeft(8);
    r->addRight(15);
    r->getLeft()->addLeft(3);
    r->getLeft()->addRight(2);
    inorder(r);
}
