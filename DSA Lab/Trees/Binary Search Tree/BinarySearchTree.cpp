#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node *createnode(int k)
{
    Node *newnode = new Node();
    newnode->data = k;
    newnode->left = newnode->right = NULL;
    return newnode;
}
Node *insert(Node *root, int k)
{
    if (root == NULL)
    {
        return createnode(k);
    }
    if (k > root->data)
    {
        root->right = insert(root->right, k);
    }
    else
    {
        root->left = insert(root->left, k);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = createnode(10);
    insert(root, 11);
    insert(root, 20);
    insert(root, 5);
    insert(root, 1);
    cout << "BST in increasing order:";
    inorder(root);
}
