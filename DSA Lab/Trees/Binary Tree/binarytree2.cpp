#include <iostream>

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : key(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* root, int key) {
        if (root == nullptr) {
            return new TreeNode(key);
        }

        if (key < root->key) {
            root->left = insert(root->left, key);
        } else if (key > root->key) {
            root->right = insert(root->right, key);
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            root->key = minValueNode(root->right);
            root->right = deleteNode(root->right, root->key);
        }

        return root;
    }

    int minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current->key;
    }

    TreeNode* search(TreeNode* root, int key) {
        if (root == nullptr || root->key == key) {
            return root;
        }

        if (key < root->key) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void deleteNode(int key) {
        root = deleteNode(root, key);
    }

    bool search(int key) {
        return search(root, key) != nullptr;
    }
};

int main() {
    BinaryTree bt;

    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int key : keys) {
        bt.insert(key);
    }

    std::cout << "Searching for 30: " << (bt.search(30) ? "Found" : "Not Found") << std::endl;

    bt.deleteNode(70);

    std::cout << "Searching for 70: " << (bt.search(20) ? "Found" : "Not Found") << std::endl;

    return 0;
}
