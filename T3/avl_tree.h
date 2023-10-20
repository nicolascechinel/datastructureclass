#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <stdexcept>

class AVLTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;

        Node(int key) : key(key), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int getHeight(Node* node) const;
    int getBalance(Node* node) const;
    Node* rightRotate(Node* node);
    Node* leftRotate(Node* node);
    Node* insert(Node* node, int key);
    Node* remove(Node* node, int key);
    void clear(Node* node);

public:
    AVLTree();
    ~AVLTree();

    bool insert(int key);
    bool remove(int key);
    void clear();
    bool contains(int key) const;
    int getHeight() const;
    int getBalance() const;
    void preOrder() const;
};

#endif // AVL_TREE_H