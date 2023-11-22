<<<<<<< HEAD
#include "qtreenode.h"

QTreeNode::QTreeNode() : QLabel()
{
    QSizePolicy sp = sizePolicy();
    sp.setRetainSizeWhenHidden(true);
    setSizePolicy(sp);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setVisible(false);
    leftChild = rightChild = parent = nullptr;
    value = 0;
    h = 1;
    heightDiff = 0;
    level = 1;
}

QTreeNode::QTreeNode(int size) {
    setMaximumSize(size, size);
    setMinimumSize(size, size);
    QSizePolicy sp = sizePolicy();
    sp.setRetainSizeWhenHidden(true);
    setSizePolicy(sp);
    setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(size / 2) + "px; font-size: " + QString::number(size / 2) + "px; font-weight: 800;"));
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setVisible(false);
    leftChild = rightChild = parent = nullptr;
    value = 0;
    h = 1;
    heightDiff = 0;
    level = 1;
}

void QTreeNode::setSize(int size) {
    setMaximumSize(size, size);
    setMinimumSize(size, size);
    setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(size / 2) + "px; font-size: " + QString::number(size / 2) + "px; font-weight: 800;"));
    if (leftChild)
        leftChild->setSize(size);
    if (rightChild)
        rightChild->setSize(size);
}

QTreeNode::QTreeNode(QString input, QTreeNode* parent) {
    QString leftInput = "";
    QString rightInput = "";
    QString number = "";
    int i = 1;
    this->parent = parent;
    if (parent)
        level = parent->level + 1;
    else
        level = 1;
    while (input[i] != '(' and i < input.length() - 1) {
        number += input[i];
        i++;
    }
    if (input[i] == '(') {
        int leftParenthesis = 1;
        int rightParenthesis = 0;
        leftInput += input[i];
        i++;
        while (leftParenthesis > rightParenthesis and i < input.length() - 1) {
            if (input[i] == '(')
                leftParenthesis++;
            if (input[i] == ')')
                rightParenthesis++;
            leftInput += input[i];
            i++;
        }
    }
    while (input[i] == ' ' or input[i] == '\t') {
        i++;
    }
    if (input[i] == '(') {
        int leftParenthesis = 1;
        int rightParenthesis = 0;
        rightInput += input[i];
        i++;
        while (leftParenthesis > rightParenthesis and i < input.length() - 1) {
            if (input[i] == '(')
                leftParenthesis++;
            if (input[i] == ')')
                rightParenthesis++;
            rightInput += input[i];
            i++;
        }
    }
    value = number.toInt();

    /* recursively creatin children */
    leftChild = rightChild = nullptr;
    if (leftInput != "")
        leftChild = new QTreeNode(leftInput, this);
    if (rightInput != "")
        rightChild = new QTreeNode(rightInput, this);

    /* setting height and heightDiff values */
    if (leftChild == nullptr and rightChild == nullptr) {
        h = 1;
        heightDiff = 0;
    }
    else if (leftChild == nullptr) {
        h = 1 + rightChild->h;
        heightDiff = 0 - rightChild->h;
    }
    else if (rightChild == nullptr) {
        h = 1 + leftChild->h;
        heightDiff = leftChild->h;
    }
    else {
        h = rightChild->h > leftChild->h ? rightChild->h + 1: leftChild->h + 1;
        heightDiff = rightChild->h - leftChild->h;
    }
    QSizePolicy sp = sizePolicy();
    sp.setRetainSizeWhenHidden(true);
    setSizePolicy(sp);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setVisible(false);
}

void QTreeNode::showNode(int posX, QVector<QHBoxLayout*> *horizontalLayouts, int size) {
    QTreeNode* temp = qobject_cast<QTreeNode*>((*horizontalLayouts)[level - 1]->itemAt(posX * 2 - 1)->widget());
    (*horizontalLayouts)[level - 1]->removeWidget(temp);
    (*horizontalLayouts)[level - 1]->insertWidget(posX * 2 - 1, this);
    setVisible(true);
    setMaximumSize(size, size);
    setMinimumSize(size, size);
    setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(size / 2) + "px; font-size: " + QString::number(size / 2) + "px; font-weight: 800;"));
    setText(QString::number(value));
    if (leftChild) {
        leftChild->showNode(posX * 2 - 1, horizontalLayouts, size);
    }
    if (rightChild) {
        rightChild->showNode(posX * 2, horizontalLayouts, size);
    }
}

int QTreeNode::isRight() {
    if (!parent)
        return -1;
    if (parent->leftChild == this)
        return 0;
    return 1;
}

QTreeNode::~QTreeNode() {}

=======
#include "qtreenode.h"

QTreeNode::QTreeNode() : QLabel()
{
    QSizePolicy sp = sizePolicy();
    sp.setRetainSizeWhenHidden(true);
    setSizePolicy(sp);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setVisible(false);
    leftChild = rightChild = parent = nullptr;
    value = 0;
    h = 1;
    heightDiff = 0;
    level = 1;
}

QTreeNode::QTreeNode(int size) {
    setMaximumSize(size, size);
    setMinimumSize(size, size);
    QSizePolicy sp = sizePolicy();
    sp.setRetainSizeWhenHidden(true);
    setSizePolicy(sp);
    setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(size / 2) + "px; font-size: " + QString::number(size / 2) + "px; font-weight: 800;"));
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setVisible(false);
    leftChild = rightChild = parent = nullptr;
    value = 0;
    h = 1;
    heightDiff = 0;
    level = 1;
}

void QTreeNode::setSize(int size) {
    setMaximumSize(size, size);
    setMinimumSize(size, size);
    setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(size / 2) + "px; font-size: " + QString::number(size / 2) + "px; font-weight: 800;"));
    if (leftChild)
        leftChild->setSize(size);
    if (rightChild)
        rightChild->setSize(size);
}

QTreeNode::QTreeNode(QString input, QTreeNode* parent) {
    QString leftInput = "";
    QString rightInput = "";
    QString number = "";
    int i = 1;
    this->parent = parent;
    if (parent)
        level = parent->level + 1;
    else
        level = 1;
    while (input[i] != '(' and i < input.length() - 1) {
        number += input[i];
        i++;
    }
    if (input[i] == '(') {
        int leftParenthesis = 1;
        int rightParenthesis = 0;
        leftInput += input[i];
        i++;
        while (leftParenthesis > rightParenthesis and i < input.length() - 1) {
            if (input[i] == '(')
                leftParenthesis++;
            if (input[i] == ')')
                rightParenthesis++;
            leftInput += input[i];
            i++;
        }
    }
    while (input[i] == ' ' or input[i] == '\t') {
        i++;
    }
    if (input[i] == '(') {
        int leftParenthesis = 1;
        int rightParenthesis = 0;
        rightInput += input[i];
        i++;
        while (leftParenthesis > rightParenthesis and i < input.length() - 1) {
            if (input[i] == '(')
                leftParenthesis++;
            if (input[i] == ')')
                rightParenthesis++;
            rightInput += input[i];
            i++;
        }
    }
    value = number.toInt();

    /* recursively creatin children */
    leftChild = rightChild = nullptr;
    if (leftInput != "")
        leftChild = new QTreeNode(leftInput, this);
    if (rightInput != "")
        rightChild = new QTreeNode(rightInput, this);

    /* setting height and heightDiff values */
    if (leftChild == nullptr and rightChild == nullptr) {
        h = 1;
        heightDiff = 0;
    }
    else if (leftChild == nullptr) {
        h = 1 + rightChild->h;
        heightDiff = 0 - rightChild->h;
    }
    else if (rightChild == nullptr) {
        h = 1 + leftChild->h;
        heightDiff = leftChild->h;
    }
    else {
        h = rightChild->h > leftChild->h ? rightChild->h + 1: leftChild->h + 1;
        heightDiff = rightChild->h - leftChild->h;
    }
    QSizePolicy sp = sizePolicy();
    sp.setRetainSizeWhenHidden(true);
    setSizePolicy(sp);
    setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setVisible(false);
}

void QTreeNode::showNode(int posX, QVector<QHBoxLayout*> *horizontalLayouts, int size) {
    QTreeNode* temp = qobject_cast<QTreeNode*>((*horizontalLayouts)[level - 1]->itemAt(posX * 2 - 1)->widget());
    (*horizontalLayouts)[level - 1]->removeWidget(temp);
    (*horizontalLayouts)[level - 1]->insertWidget(posX * 2 - 1, this);
    setVisible(true);
    setMaximumSize(size, size);
    setMinimumSize(size, size);
    setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(size / 2) + "px; font-size: " + QString::number(size / 2) + "px; font-weight: 800;"));
    setText(QString::number(value));
    if (leftChild) {
        leftChild->showNode(posX * 2 - 1, horizontalLayouts, size);
    }
    if (rightChild) {
        rightChild->showNode(posX * 2, horizontalLayouts, size);
    }
}

int QTreeNode::isRight() {
    if (!parent)
        return -1;
    if (parent->leftChild == this)
        return 0;
    return 1;
}

QTreeNode::~QTreeNode() {}

>>>>>>> 584cbfa (Добавил бинарники)
