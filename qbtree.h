<<<<<<< HEAD
#ifndef QBTREE_H
#define QBTREE_H

#include <qtree.h>

class QBTree : public QTree
{
    QTreeNode* isBalanceNeeded(QTreeNode* node);
    void rotateRight(QTreeNode* node);
    void rotateLeft(QTreeNode* node);
    void rotateLeftRight(QTreeNode* node);
    void rotateRightLeft(QTreeNode* node);
    void balance(QTreeNode* spinNode);
    QTreeNode* getMaxAVL(QTreeNode* root);
public:
    bool add(int value) override;
    void del(QTreeNode* node) override;
    QBTree();
    QBTree(QVector <QTreeNode*> nodes);
    ~QBTree() override;
};

#endif // QBTREE_H
=======
#ifndef QBTREE_H
#define QBTREE_H

#include <qtree.h>

class QBTree : public QTree
{
    QTreeNode* isBalanceNeeded(QTreeNode* node);
    void rotateRight(QTreeNode* node);
    void rotateLeft(QTreeNode* node);
    void rotateLeftRight(QTreeNode* node);
    void rotateRightLeft(QTreeNode* node);
    void balance(QTreeNode* spinNode);
    QTreeNode* getMaxAVL(QTreeNode* root);
public:
    bool add(int value) override;
    void del(QTreeNode* node) override;
    QBTree();
    QBTree(QVector <QTreeNode*> nodes);
    ~QBTree() override;
};

#endif // QBTREE_H
>>>>>>> 584cbfa (Добавил бинарники)
