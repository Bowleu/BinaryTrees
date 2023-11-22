<<<<<<< HEAD
#include "qbtree.h"

QBTree::QBTree()
{

}

QBTree::QBTree(QVector <QTreeNode*> nodes) {
    for (int i = 0; i < nodes.length(); i++)
        add(nodes[i]->value);
}

QTreeNode* QBTree::isBalanceNeeded(QTreeNode* node) {
    if (node) {
        QTreeNode* adress = nullptr;
        QTreeNode* tempAdress = nullptr;
        int leftBalance = 0, rightBalance = 0;
        if (node->rightChild)
            rightBalance = node->rightChild->heightDiff;
        if (node->leftChild)
            leftBalance = node->leftChild->heightDiff;
        if (abs(node->heightDiff) == 2 and abs(leftBalance) < 2 and abs(rightBalance) < 2)
            adress = node;
        if (node->rightChild) {
            tempAdress = isBalanceNeeded(node->rightChild);
            if (tempAdress and (!adress or tempAdress->level > adress->level))
                adress = tempAdress;
        }
        if (node->leftChild) {
            tempAdress = isBalanceNeeded(node->leftChild);
            if (tempAdress and (!adress or tempAdress->level > adress->level))
                adress = tempAdress;
        }
        return adress;
    }
    return nullptr;
}

void QBTree::balance(QTreeNode* spinNode) {
    if (spinNode) {
        if (spinNode->heightDiff == 2) {
            if ((spinNode->leftChild->rightChild and spinNode->leftChild->leftChild and spinNode->leftChild->rightChild->h <= spinNode->leftChild->leftChild->h) or (!spinNode->leftChild->rightChild) or (!spinNode->leftChild->leftChild and !spinNode->leftChild->rightChild))
                rotateRight(spinNode);
            else
                rotateLeftRight(spinNode);
        }
        else {
            if ((spinNode->rightChild->rightChild and spinNode->rightChild->leftChild and spinNode->rightChild->leftChild->h <= spinNode->rightChild->rightChild->h) or (!spinNode->rightChild->leftChild) or (!spinNode->rightChild->leftChild and !spinNode->rightChild->rightChild))
                rotateLeft(spinNode);
            else
                rotateRightLeft(spinNode);
        }
    }
    fixHeight();
}

bool QBTree::add(int value) {
    QTreeNode* currNode = head;
    QTreeNode* newNode = new QTreeNode(50);
    if (!currNode) {
        newNode = new QTreeNode(50);
        newNode->value = value;
        head = newNode;
        h = 1;
        return 1;
    }
    while (true) {
        if (value == currNode->value) {
            return 0;
        }
        if (value > currNode->value) {
            if (currNode->rightChild)
                currNode = currNode->rightChild;
            else
                break;
        }
        else {
            if (currNode->leftChild)
                currNode = currNode->leftChild;
            else
                break;
        }
    }
    newNode->value = value;
    newNode->parent = currNode;
    if (value > currNode->value) {
        currNode->rightChild = newNode;
    } else {
        currNode->leftChild = newNode;
    }
    fixHeight();
    QTreeNode* balanceNode = isBalanceNeeded(head);
    balance(balanceNode);
    return 1;
}

void QBTree::rotateRight(QTreeNode *a) {
    QTreeNode* b = a->leftChild;
    a->leftChild = b->rightChild;
    if (a->leftChild)
        a->leftChild->parent = a;
    b->rightChild = a;
    b->parent = a->parent;
    a->parent = b;
    if (b->parent) {
        if (b->parent->leftChild == a)
            b->parent->leftChild = b;
        else
            b->parent->rightChild = b;
    }
    else {
        head = b;
    }
}
void QBTree::rotateLeft(QTreeNode* a) {
    QTreeNode* b = a->rightChild;
    a->rightChild = b->leftChild;
    if (a->rightChild)
        a->rightChild->parent = a;
    b->leftChild = a;
    b->parent = a->parent;
    a->parent = b;
    if (b->parent) {
        if (b->parent->leftChild == a)
            b->parent->leftChild = b;
        else
            b->parent->rightChild = b;
    }
    else {
        head = b;
    }
}
void QBTree::rotateLeftRight(QTreeNode* node) {
    rotateLeft(node->leftChild);
    rotateRight(node);
}
void QBTree::rotateRightLeft(QTreeNode* node) {
    rotateRight(node->rightChild);
    rotateLeft(node);
}

QTreeNode* QBTree::getMaxAVL(QTreeNode* root) {
    while (root->rightChild) {
        root = root->rightChild;
    }
    return root;
}

void QBTree::del(QTreeNode *node) {
    if (!node->leftChild and !node->rightChild) {
        if (node->parent) {
            if (node->parent->leftChild == node)
                node->parent->leftChild = nullptr;
            else
                node->parent->rightChild = nullptr;
        }
        else {
            head = nullptr;
            h = 0;
        }
        delete node;
    }
    else if (node->leftChild and !node->rightChild) {
        if (node->parent) {
            if (node->parent->leftChild == node)
                node->parent->leftChild = node->leftChild;
            else
                node->parent->rightChild = node->leftChild;
        }
        else {
            head = node->leftChild;
        }
        node->leftChild->parent = node->parent;
        delete node;
    }
    else if (node->rightChild and !node->leftChild) {
        if (node->parent) {
            if (node->parent->leftChild == node)
                node->parent->leftChild = node->rightChild;
            else
                node->parent->rightChild = node->rightChild;
        }
        else {
            head = node->rightChild;
        }
        node->rightChild->parent = node->parent;
        delete node;
    }
    else {
        QTreeNode* change = getMaxAVL(node->leftChild);
        if (change != node->leftChild){
            change->parent->rightChild = change->leftChild;
            if (change->leftChild) {
                change->leftChild->parent = change->parent;
            }
        }
        change->parent = node->parent;
        if (node == head)
            head = change;
        if (node->parent) {
            if (node->parent->leftChild == node)
                node->parent->leftChild = change;
            else
                node->parent->rightChild = change;
        }
        change->rightChild = node->rightChild;
        change->rightChild->parent = change;
        if (node->leftChild != change) {
            change->leftChild = node->leftChild;
            change->leftChild->parent = change;
        }
        delete node;
    }
    fixHeight();
    QTreeNode* balanceNode = isBalanceNeeded(head);
    while (balanceNode) {
        balance(balanceNode);
        balanceNode = isBalanceNeeded(head);
    }
}

QBTree::~QBTree() {
    QVector <QTreeNode*> nodes = depthTraversal1();
    for (int i = 0; i < nodes.length(); i++) {
        delete nodes[i];
    }
    head = nullptr;
    h = 0;
}

=======
#include "qbtree.h"

QBTree::QBTree()
{

}

QBTree::QBTree(QVector <QTreeNode*> nodes) {
    for (int i = 0; i < nodes.length(); i++)
        add(nodes[i]->value);
}

QTreeNode* QBTree::isBalanceNeeded(QTreeNode* node) {
    if (node) {
        QTreeNode* adress = nullptr;
        QTreeNode* tempAdress = nullptr;
        int leftBalance = 0, rightBalance = 0;
        if (node->rightChild)
            rightBalance = node->rightChild->heightDiff;
        if (node->leftChild)
            leftBalance = node->leftChild->heightDiff;
        if (abs(node->heightDiff) == 2 and abs(leftBalance) < 2 and abs(rightBalance) < 2)
            adress = node;
        if (node->rightChild) {
            tempAdress = isBalanceNeeded(node->rightChild);
            if (tempAdress and (!adress or tempAdress->level > adress->level))
                adress = tempAdress;
        }
        if (node->leftChild) {
            tempAdress = isBalanceNeeded(node->leftChild);
            if (tempAdress and (!adress or tempAdress->level > adress->level))
                adress = tempAdress;
        }
        return adress;
    }
    return nullptr;
}

void QBTree::balance(QTreeNode* spinNode) {
    if (spinNode) {
        if (spinNode->heightDiff == 2) {
            if ((spinNode->leftChild->rightChild and spinNode->leftChild->leftChild and spinNode->leftChild->rightChild->h <= spinNode->leftChild->leftChild->h) or (!spinNode->leftChild->rightChild) or (!spinNode->leftChild->leftChild and !spinNode->leftChild->rightChild))
                rotateRight(spinNode);
            else
                rotateLeftRight(spinNode);
        }
        else {
            if ((spinNode->rightChild->rightChild and spinNode->rightChild->leftChild and spinNode->rightChild->leftChild->h <= spinNode->rightChild->rightChild->h) or (!spinNode->rightChild->leftChild) or (!spinNode->rightChild->leftChild and !spinNode->rightChild->rightChild))
                rotateLeft(spinNode);
            else
                rotateRightLeft(spinNode);
        }
    }
    fixHeight();
}

bool QBTree::add(int value) {
    QTreeNode* currNode = head;
    QTreeNode* newNode = new QTreeNode(50);
    if (!currNode) {
        newNode = new QTreeNode(50);
        newNode->value = value;
        head = newNode;
        h = 1;
        return 1;
    }
    while (true) {
        if (value == currNode->value) {
            return 0;
        }
        if (value > currNode->value) {
            if (currNode->rightChild)
                currNode = currNode->rightChild;
            else
                break;
        }
        else {
            if (currNode->leftChild)
                currNode = currNode->leftChild;
            else
                break;
        }
    }
    newNode->value = value;
    newNode->parent = currNode;
    if (value > currNode->value) {
        currNode->rightChild = newNode;
    } else {
        currNode->leftChild = newNode;
    }
    fixHeight();
    QTreeNode* balanceNode = isBalanceNeeded(head);
    balance(balanceNode);
    return 1;
}

void QBTree::rotateRight(QTreeNode *a) {
    QTreeNode* b = a->leftChild;
    a->leftChild = b->rightChild;
    if (a->leftChild)
        a->leftChild->parent = a;
    b->rightChild = a;
    b->parent = a->parent;
    a->parent = b;
    if (b->parent) {
        if (b->parent->leftChild == a)
            b->parent->leftChild = b;
        else
            b->parent->rightChild = b;
    }
    else {
        head = b;
    }
}
void QBTree::rotateLeft(QTreeNode* a) {
    QTreeNode* b = a->rightChild;
    a->rightChild = b->leftChild;
    if (a->rightChild)
        a->rightChild->parent = a;
    b->leftChild = a;
    b->parent = a->parent;
    a->parent = b;
    if (b->parent) {
        if (b->parent->leftChild == a)
            b->parent->leftChild = b;
        else
            b->parent->rightChild = b;
    }
    else {
        head = b;
    }
}
void QBTree::rotateLeftRight(QTreeNode* node) {
    rotateLeft(node->leftChild);
    rotateRight(node);
}
void QBTree::rotateRightLeft(QTreeNode* node) {
    rotateRight(node->rightChild);
    rotateLeft(node);
}

QTreeNode* QBTree::getMaxAVL(QTreeNode* root) {
    while (root->rightChild) {
        root = root->rightChild;
    }
    return root;
}

void QBTree::del(QTreeNode *node) {
    if (!node->leftChild and !node->rightChild) {
        if (node->parent) {
            if (node->parent->leftChild == node)
                node->parent->leftChild = nullptr;
            else
                node->parent->rightChild = nullptr;
        }
        else {
            head = nullptr;
            h = 0;
        }
        delete node;
    }
    else if (node->leftChild and !node->rightChild) {
        if (node->parent) {
            if (node->parent->leftChild == node)
                node->parent->leftChild = node->leftChild;
            else
                node->parent->rightChild = node->leftChild;
        }
        else {
            head = node->leftChild;
        }
        node->leftChild->parent = node->parent;
        delete node;
    }
    else if (node->rightChild and !node->leftChild) {
        if (node->parent) {
            if (node->parent->leftChild == node)
                node->parent->leftChild = node->rightChild;
            else
                node->parent->rightChild = node->rightChild;
        }
        else {
            head = node->rightChild;
        }
        node->rightChild->parent = node->parent;
        delete node;
    }
    else {
        QTreeNode* change = getMaxAVL(node->leftChild);
        if (change != node->leftChild){
            change->parent->rightChild = change->leftChild;
            if (change->leftChild) {
                change->leftChild->parent = change->parent;
            }
        }
        change->parent = node->parent;
        if (node == head)
            head = change;
        if (node->parent) {
            if (node->parent->leftChild == node)
                node->parent->leftChild = change;
            else
                node->parent->rightChild = change;
        }
        change->rightChild = node->rightChild;
        change->rightChild->parent = change;
        if (node->leftChild != change) {
            change->leftChild = node->leftChild;
            change->leftChild->parent = change;
        }
        delete node;
    }
    fixHeight();
    QTreeNode* balanceNode = isBalanceNeeded(head);
    while (balanceNode) {
        balance(balanceNode);
        balanceNode = isBalanceNeeded(head);
    }
}

QBTree::~QBTree() {
    QVector <QTreeNode*> nodes = depthTraversal1();
    for (int i = 0; i < nodes.length(); i++) {
        delete nodes[i];
    }
    head = nullptr;
    h = 0;
}

>>>>>>> 584cbfa (Добавил бинарники)
