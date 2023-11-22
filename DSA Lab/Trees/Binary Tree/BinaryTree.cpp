#include <iostream>

using namespace std;
struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data) {
  struct node *newNode = new (struct node);
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}

void preorder(struct node *root) {
  if (root != NULL) {
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(struct node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
  }
}

int main() {

  struct node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);

 
  cout << "Inorder traversal: ";
  inorder(root);
  cout << endl;

  cout << "Preorder traversal: ";
  preorder(root);
  cout << endl;

  cout << "Postorder traversal: ";
  postorder(root);
  cout << endl;

  return 0;
}