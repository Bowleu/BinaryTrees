#ifndef QTREENODE_H
#define QTREENODE_H

#include <math.h>
#include <QLabel>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QLayout>

class QTreeNode : public QLabel
{
    Q_OBJECT
public:
    QTreeNode* leftChild, *rightChild, *parent;
    int value;
    int h;
    int level;
    int heightDiff;
    QTreeNode();
    QTreeNode(int size);
    int isRight();
    QTreeNode(QString input, QTreeNode* parent);
    void showNode(int posX, QVector<QHBoxLayout*> *horizontalLayouts, int size);
    void setSize(int size);
    ~QTreeNode();
};

#endif // QTREENODE_H
