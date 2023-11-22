#include "qtree.h"

#include <QQueue>

QTree::QTree()
{
    h = 0;
    head = nullptr;
}

QTree::QTree(QString input) {
    head = new QTreeNode(input, nullptr);
    h = head->h;
    int treeWidth = (int) pow(2, h - 1);
    int size = 1000 / treeWidth - 4;
    head->setSize(size);
}

QTree::~QTree() {
    del(head);
    head = nullptr;
    h = 0;
}

QTreeNode* QTree::findNode(int value, QTreeNode* node) {
    QTreeNode* foundNode = nullptr;
    if (node->value == value)
        return node;
    if (node->leftChild)
        foundNode = qMax(foundNode, findNode(value, node->leftChild));
    if (node->rightChild)
        foundNode = qMax(foundNode, findNode(value, node->rightChild));
    return foundNode;
}

QTreeNode* QTree::findNode(int value) {
    return findNode(value, head);
}

void QTree::del(QTreeNode* node) {
    if (node == nullptr)
        return;
    if (node->leftChild != nullptr)
        del(node->leftChild);
    if (node->rightChild != nullptr)
        del(node->rightChild);
    if (node->parent) {
        if (node->isRight() == 1)
            node->parent->rightChild = nullptr;
        else if (node->isRight() == 0)
            node->parent->leftChild = nullptr;
    }
    delete node;
    if (node == head) {
        head = nullptr;
        h = 0;
        return;
    }
    fixHeight();
}

void QTree::fixHeight(QTreeNode* node) {
    if (node->leftChild)
        fixHeight(node->leftChild);
    if (node->rightChild)
        fixHeight(node->rightChild);

    if (node->leftChild and node->rightChild){
        node->h = 1 + qMax(node->rightChild->h, node->leftChild->h);
        node->heightDiff = node->leftChild->h - node->rightChild->h;
    }
    else if (node->leftChild){
        node->h = 1 + node->leftChild->h;
        node->heightDiff = node->leftChild->h;
    }
    else if (node->rightChild){
        node->h = 1 + node->rightChild->h;
        node->heightDiff = -node->rightChild->h;
    }
    else{
        node->h = 1;
        node->heightDiff = 0;
    }

}

void QTree::fixLevel(QTreeNode* node) {
    if (!node->parent)
        node->level = 1;
    else
        node->level = node->parent->level + 1;
    if (node->leftChild)
        fixLevel(node->leftChild);
    if (node->rightChild)
        fixLevel(node->rightChild);
}

void QTree::fixHeight() {
    if (!head)
        return;
    fixHeight(head);
    fixLevel(head);
    h = head->h;
}

int QTree::getHeight() {
    return h;
}

QVector<QTreeNode*> QTree::widthTraversal() {
    QVector <QTreeNode*> arr;
    QQueue <QTreeNode*> queue;
    if (!head)
        return arr;
    queue.push_back(head);
    while (queue.length()) {
        QTreeNode* curr = queue.head();
        if (curr)
            arr.push_back(curr);
        queue.pop_front();
        if (curr->leftChild)
            queue.push_back(curr->leftChild);
        if (curr->rightChild)
            queue.push_back(curr->rightChild);
    }
    return arr;
}

void QTree::depthTraversal1(QTreeNode* node, QVector <QTreeNode*> *arr) {
    arr->push_back(node);
    if (node->leftChild)
        depthTraversal1(node->leftChild, arr);
    if (node->rightChild)
        depthTraversal1(node->rightChild, arr);
}

void QTree::depthTraversal2(QTreeNode* node, QVector <QTreeNode*> *arr) {
    if (node->leftChild)
        depthTraversal2(node->leftChild, arr);
    arr->push_back(node);
    if (node->rightChild)
        depthTraversal2(node->rightChild, arr);
}

void QTree::depthTraversal3(QTreeNode* node, QVector <QTreeNode*> *arr) {
    if (node->leftChild)
        depthTraversal3(node->leftChild, arr);
    if (node->rightChild)
        depthTraversal3(node->rightChild, arr);
    arr->push_back(node);
}

QVector<QTreeNode*> QTree::depthTraversal1() {
    QVector <QTreeNode*> arr;
    if (head)
        depthTraversal1(head, &arr);
    return arr;
}

QVector<QTreeNode*> QTree::depthTraversal2() {
    QVector <QTreeNode*> arr;
    if (head)
        depthTraversal2(head, &arr);
    return arr;
}

QVector<QTreeNode*> QTree::depthTraversal3() {
    QVector <QTreeNode*> arr;
    if (head)
        depthTraversal3(head, &arr);
    return arr;
}

bool QTree::add(int value) {
    return 0;
}

void QTree::showTree(QVector<QHBoxLayout *> *layouts, int size) {
    head->showNode(1, layouts, size);
}

QTreeNode* QTree::getHead() {
    return head;
}
