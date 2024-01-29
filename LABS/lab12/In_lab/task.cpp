#include <iostream>
#include <algorithm>

template <typename T>
class AVLNode {
public:
    T data;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;

    AVLNode(T val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;

    int getHeight(AVLNode<T>* node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalance(AVLNode<T>* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode<T>* rotateRight(AVLNode<T>* y) {
        AVLNode<T>* x = y->left;
        AVLNode<T>* temp = x->right;

        x->right = y;
        y->left = temp;

        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    AVLNode<T>* rotateLeft(AVLNode<T>* x) {
        AVLNode<T>* y = x->right;
        AVLNode<T>* temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    AVLNode<T>* insert(AVLNode<T>* node, T value) {
        if (node == nullptr)
            return new AVLNode<T>(value);

        if (value < node->data)
            node->left = insert(node->left, value);
        else if (value > node->data)
            node->right = insert(node->right, value);
        else
            return node; // Duplicate values not allowed

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data)
            return rotateRight(node);

        // Right Right Case
        if (balance < -1 && value > node->right->data)
            return rotateLeft(node);

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inOrderTraversal(AVLNode<T>* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(T value) {
        root = insert(root, value);
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree<int> avl;
    
    avl.insert(35);
    avl.insert(50);
    avl.insert(40);
    avl.insert(25);
    avl.insert(30);
    avl.insert(60);
    avl.insert(78);
    avl.insert(20);
    avl.insert(28);

    std::cout << "In-order traversal of AVL tree: ";
    avl.inOrderTraversal();

    return 0;
}
