#ifndef QTREE_H
#define QTREE_H

#include "qtreenode.h"

class QTree
{
    void depthTraversal1(QTreeNode*,  QVector<QTreeNode*>*);
    void depthTraversal2(QTreeNode*,  QVector<QTreeNode*>*);
    void depthTraversal3(QTreeNode*,  QVector<QTreeNode*>*);
    void fixHeight(QTreeNode* node);
    QTreeNode* findNode(int value, QTreeNode* node);
    void fixLevel(QTreeNode* node);
protected:
    void fixHeight();
    QTreeNode* head;
    int h;
public:
    QTree();
    QTree(QString input);
    int getHeight();
    virtual void del(QTreeNode*);
    QTreeNode* findNode(int value);
    QTreeNode* getHead();
    QVector<QTreeNode*> widthTraversal();
    QVector<QTreeNode*> depthTraversal1();
    QVector<QTreeNode*> depthTraversal2();
    QVector<QTreeNode*> depthTraversal3();
    virtual bool add(int value);
    void showTree(QVector <QHBoxLayout*> *layouts, int size);
    virtual ~QTree();
};

#endif // QTREE_H
