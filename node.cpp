#include "node.h"

Node::Node()
{
    value = 0;
    parent = leftChild = rightChild = nullptr;
    heightDiff = 0;
    height = 1;
    level = 1;
}

Node::Node(int value) {
    this->value = value;
    parent = leftChild = rightChild = nullptr;
    heightDiff = 0;
    height = 1;
    level = 1;
}

Node::Node(QString input, Node* parent) {
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
    qDebug() << value << ' ' << rightInput << ' ' << leftInput;

    /* recursively creatin children */
    leftChild = rightChild = nullptr;
    if (leftInput != "")
        leftChild = new Node(leftInput, this);
    if (rightInput != "")
        rightChild = new Node(rightInput, this);

    /* setting height and heightDiff values */
    if (leftChild == nullptr and rightChild == nullptr) {
        height = 1;
        heightDiff = 0;
    }
    else if (leftChild == nullptr) {
        height = 1 + rightChild->height;
        heightDiff = 0 - rightChild->height;
    }
    else if (rightChild == nullptr) {
        height = 1 + leftChild->height;
        heightDiff = leftChild->height;
    }
    else {
        height = rightChild->height > leftChild->height ? rightChild->height + 1: leftChild->height + 1;
        heightDiff = rightChild->height - leftChild->height;
    }
}

int Node::isRight() {
    if (!parent)
        return -1;
    if (this->parent->rightChild == this)
        return 1;
    return 0;
}
