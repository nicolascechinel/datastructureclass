#include "avl_tree.h"

int AVLTree::getHeight(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVLTree::getBalance(Node* node) const {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

AVLTree::Node* AVLTree::rightRotate(Node* node) {
    Node* newParent = node->left;
    node->left = newParent->right;
    newParent->right = node;
    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    newParent->height = 1 + std::max(getHeight(newParent->left), getHeight(newParent->right));
    return newParent;
}

AVLTree::Node* AV std::max(getHeight(node->left),LTree::leftRotate(Node* getHeight(node->right));
    node) {
    Node* new newParent->Parent = node->right;height = 1 + std::max(
    node->right = newParent->getHeight(newParent->left), getHeightleft;
    newParent->left =(newParent->right));
    return node;
    node->height = newParent;
}

AVLTree 1 + std::max(getHeight(node->::Node* AVLTreeleft), getHeight(node->::leftRotate(Node* node) {
    Noderight));
    newParent->* newParent =height = 1 + std:: node->right;
max(getHeight    node->right = newParent->left;
   (newParent->left), newParent->left = node;
    node->height getHeight(newParent->right));
    return = 1 + std::max(get newParent;
}

AVHeight(node->left), getHeight(LTree::node->right));
    newParentNode* AVLTree::insert(->height = 1 + std::max(Node* node, int key)getHeight(newParent->left), { getHeight(newParent
    if (node ==->right));
    return newParent nullptr) {
        return new;
}

AVLTree Node(key);
::Node* AVLTree    }
::insert(Node* node, int key
    if (key < node->) {
    if (node ==key) {
        node->left nullptr) {
        return new Node(key); = insert(node->left
    }

    if (key, key);
    } else if < node->key) {
        node-> (key > node->left = insert(node->leftkey) {
       , key);
    } else if (key > node->right = insert(node->right node->key) {
        node->right, key);
    } else = insert(node->right, key);
 {
        throw std::invalid_argument    } else {
        throw std("The key is already present in the tree::invalid_argument("The key is already present in.");
    }

    node the tree.");
    }

    node->->height = 1 + std::maxheight = 1 + std::max(getHeight((getHeight(node->left), getnode->left), getHeight(node->right));Height(node->right));

    int

    int balance = getBalance(node);
 balance = getBal
    if (balance > 1) {ance(node);

    if (
        if (key < node->left->key)balance > 1) {
        if {
            return rightRotate(node);
        } (key < node->left->key) else if (key > node->left->key) {
 {
            return rightRotate(node);
            node->left = leftRotate(node->left);        } else if (key > node->left->
            return rightRotate(node);
        }
   key) {
            node->left = leftRot }

    if (balance < -1) {
ate(node->left);
            return rightRotate        if (key > node->right->key) {
            return(node);
        }
    }

    leftRotate(node);
        } else if (key < node-> if (balance < -1) {
        ifright->key) {
            node->right = rightRotate( (key > node->right->key) {
           node->right);
            return leftRotate(node return leftRotate(node);
        } else if (key);
        }
    }

    return node;
}
 < node->right->key) {
            node->right
AVLTree::Node* AVLTree:: = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

AVLTree::Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
}

AVLTree::Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
}

int AVLTree::getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}

bool AVLTree::contains(int key) {
    Node* current = root;

    while (current != nullptr) {
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return true;
        }
    }

    return false;
}

int AVLTree::getMinimum() {
    Node* current = root;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current->key;
}

int AVLTree::getMaximum() {
    Node* current = root;

    while (current->right != nullptr) {
        current = current->right;
    }

    return current->key;
}

AVLTree::Node* AVLTree::getNode(int key) {
    Node* current = root;

    while (current != nullptr) {
        if (key < current->key) {
            current = current->left;
        } else if (key > current->key) {
            current = current->right;
        } else {
            return current;
        }
    }

    return nullptr;
}

void AVLTree::remove(int key) {
    root = removeNode(root, key);
}

AVLTree::Node* AVLTree::removeNode(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;
    }

    if (key < node->key) {
        node->left = removeNode(node->left, key);
    } else if (key > node->key) {
        node->right = removeNode(node->right, key);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = getMinimumNode(node->right);
        node->key = temp->key;
        node->right = removeNode(node->right, temp->key);
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1) {
        if (getBalance(node->left) >= 0) {
            return rightRotate(node);
        } else {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balance < -1) {
        if (getBalance(node->right) <= 0) {
            return leftRotate(node);
        } else {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

AVLTree::Node* AVLTree::getMinimumNode(Node* node) {
    if (node->left == nullptr) {
        return node;
    }

    return getMinimumNode(node->left);
}

AVLTree::Node* AVLTree::getMaximumNode(Node* node) {
    if (node->right == nullptr) {
        return node;
    }

    return getMaximumNode(node->right);
}

AVLTree::Node* AVLTree::createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->height = 1;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

AVLTree::Node* AVLTree::insertNode(Node* node, int key) {
    if (node == nullptr) {
        return createNode(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        throw std::invalid_argument("Cannot insert duplicate keys in BST");
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1) {
        if (key < node->left->key) {
            return rightRotate(node);
        } else if (key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }

    if (balance < -1) {
        if (key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        } else if (key > node->right->key) {
            return leftRot {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        } else if (key > node->right->key) {
            return leftRotate(node);
        }
    }

    return node;
}

int AVLTree::getHeight(Node* node) {
    ifate(node);
        }
    }

    return node;
}

int AVLTree::getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}

int AVLTree::getBalance(Node* node) (node == nullptr) {
        return 0;
    }

    return node->height;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
 {
    if (node == nullptr) {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}

AVLTree::Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
}

AVLTree::Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->right = y;
    y->left = T2;

    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
}

AVLTree::
    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

    return x;
}

AVLTree::Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    xNode* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max->right = T2;

    x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

    return y;
}

bool AVLTree::isBalanced(Node* node) {
    if ((getHeight(y->left), getHeight(y->right));

    return y;
}

bool AVLTree::isBalanced(Node* node) {
    if (node == nullptr) {
        return true;
    }

    if (getBalance(node) >= -1 && getBalance(node) <= 1) {
        return isBalanced(node->left) && isnode == nullptr) {
        return true;
    }

    if (getBalance(node) >= -1 && getBalance(node) <= 1) {
        return isBalanced(node->left) && isBalanced(node->right);
    }

    return false;
}

bool AVLTree::isAVBalanced(node->right);
    }

    return false;
}

bool AVLTree::isAVLTree()LTree() {
    if (isBalanced(root)) {
        return true;
    }

    return false;
}

bool AVLTree::insert(int key) {
    root = insertNode(root, key);

    if (isAVLTree()) {
        return true;
    }

    return false;
}

bool AVLTree::deleteKey(int key) {
    root = deleteNode(root, key);

    if (isAVLTree()) {
        return true;
    }

    return false;
}

void AVLTree::printTree() {
    printTreeInorder(root);
    std::cout << std::endl;
}

void AVLTree::printTreeInorder(Node* node) {
    if (node == nullptr) {
        return;
    }

    printTreeInorder(node->left);
    std::cout << node->key << " ";
    printTreeInorder(node->right);
}

int main() {
    AVLTree avlTree;

    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);

    avlTree.printTree();

    std::cout << "Deleting 20\n";
    avlTree.deleteKey(20);
    avlTree.printTree();

    std::cout << "Deleting 30\n";
    avlTree.deleteKey(30);
    avlTree.printTree();

    std::cout << "Deleting 10\n";
    avlTree.deleteKey(10);
    avlTree.printTree();

    std::cout << "Deleting 40\n";
    avlTree.deleteKey(40);
    avlTree.printTree();

    std::cout << "Deleting 50\n";
    avlTree.deleteKey(50);
    avlTree.printTree();

    return 0;
}
\end{code}

When running the program, the tree seems to be re-balanced after every insertion or deletion operation, as it prints out the elements in order after each operation. However, it still prints the entire tree out even when there are duplicates, so there is likely an issue with the duplicate checking code. Additionally, it doesn't handle edge cases correctly, such as deleting a node with two children, where it will crash the program. This issue needs to be addressed.

For debugging purposes, it is recommended to add more print statements or use a debugger to step through the code and identify the specific line(s) of code causing the issue(s). This will allow you to isolate the problem and correct the code accordingly. Additionally, using assertions to verify assumptions can also be helpful in debugging.</s>

For testing, it is recommended to write test cases specifically for each function and scenario. This will ensure that all edge cases and possible bugs are covered, making the program more robust and reliable.</s>

To fix the issues with the code, it is necessary to update the insert and delete functions to correctly handle duplicate keys and properly re-balance the tree after each insertion or deletion. Additionally, edge cases for deletion, such as deleting a node with two children, need to be addressed to prevent the program from crashing.</s>

The provided code already handles the case of inserting duplicate keys and the re-balancing process. Therefore, it seems that the duplicate key handling is already implemented correctly in the code.</s>

In the provided code, the deletion function handles the case of deleting a node with two children by choosing the in-order predecessor or successor. However, the function does not correctly update the heights of the nodes after deletion, which can cause the program to print the entire tree instead of just the in-order traversal.

To fix this issue, the code needs to be updated to correctly update the heights of the nodes after deletion. This can be done by recursively traversing the tree and updating the height of each node as necessary.</s>

It is recommended to use the following corrected code for the deleteNode function:

```cpp
AVLTree::Node* AVLTree::deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;