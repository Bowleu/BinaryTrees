<<<<<<< HEAD
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <math.h>
#include <QVector>
#include <QQueue>
#include <QPoint>
#include <QFileInfo>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    layout = ui->verticalLayoutWidget->findChild<QVBoxLayout*>("heightLayout");
    Q_ASSERT(layout);
    tree = nullptr;
    val = new QRegExpValidator((QRegExp) "-?\\d{1,3}", this);
    ui->delValue->setValidator(val);
    ui->addValue->setValidator(val);
    ui->addBtn->setEnabled(false);
    ui->addValue->setEnabled(false);
    setWindowTitle("Деревья 2");
    connect(ui->readBtn, &QPushButton::clicked, this, &MainWindow::getTree);
    connect(timer, &QTimer::timeout, this, &MainWindow::highlightNode);
    connect(ui->traversalBtn, &QPushButton::clicked, this, &MainWindow::traversalChoice);
    connect(ui->delBtn, &QPushButton::clicked, this, &MainWindow::delNode);
    connect(ui->toAVLBtn, &QPushButton::clicked, this, &MainWindow::toAVL);
    connect(ui->addBtn, &QPushButton::clicked, this, &MainWindow::addNode);
}

void MainWindow::showError(int errCode) {
    ui->messageText->setText("Ошибка " + QString::number(errCode) + ". " + errors[errCode]);
    ui->messageText->setStyleSheet("color: red; font-size: 10pt; border: none;");
}

void MainWindow::getTree() {
    if (!QFileInfo::exists("input.txt")) {
        showError(405);
        return;
    }
    QFile file("input.txt");
    file.open(QFile::ReadOnly);
    QString s = file.readLine();
    if (s == "") {
        showError(406);
        return;
    }
    if (tree)
        delete tree;
    tree = new QTree(s);
    ui->addBtn->setEnabled(false);
    ui->addValue->setEnabled(false);
    ui->toAVLBtn->setEnabled(true);
    showTree();
}

void MainWindow::showTree() {
    for (int i = 0; i < nodes.length(); i++) {
        if (nodes[i])
            delete nodes[i];
    }
    nodes.clear();
    for (int i = 0; i < horizontalLayouts.length(); i++) {
        if (horizontalLayouts[i]){
            while (horizontalLayouts[i]->itemAt(0))
                horizontalLayouts[i]->removeItem(horizontalLayouts[i]->itemAt(0));
            layout->removeItem(horizontalLayouts[i]);
            delete horizontalLayouts[i];
        }
    }
    horizontalLayouts.clear();

    if (tree->getHeight() == 0) {
        update();
        return;
    }
    int treeWidth = (int) pow(2, tree->getHeight() - 1);
    int size = 650 / treeWidth - 4;
    for (int i = 0; i < tree->getHeight(); i++) {
        QHBoxLayout *horizontalLayout = new QHBoxLayout;
        horizontalLayout->setSpacing(0);
        layout->addLayout(horizontalLayout);
        horizontalLayouts.push_back(horizontalLayout);
        horizontalLayout->addStretch();
        for (int j = 0; j < (int) pow(2, i); j++) {
            QTreeNode *nodeShow = new QTreeNode(size);
            horizontalLayout->addWidget(nodeShow);
            horizontalLayout->addStretch();
            nodes.push_back(nodeShow);
        }
    }
    tree->showTree(&horizontalLayouts, size);
    update();
}

void MainWindow::addNode() {
    int value = ui->addValue->text().toInt();
    if (tree->add(value))
        showTree();
    else
        showError(501);
}

void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    p.setPen(QPen(Qt::black, 2));
    for (int i = 0; i < horizontalLayouts.length(); i++) {
        for (int j = 1; j < (int) pow(2, i + 1); j += 2) {
            QTreeNode* curr = qobject_cast<QTreeNode*>(horizontalLayouts[i]->itemAt(j)->widget());
            if (curr->leftChild) {
                QPoint start = curr->mapToGlobal(curr->rect().center());
                QPoint end = curr->leftChild->mapToGlobal(curr->leftChild->rect().center());
                p.drawLine(mapFromGlobal(start), mapFromGlobal(end));
            }
            if (curr->rightChild) {
                QPoint start = curr->mapToGlobal(curr->rect().center());
                QPoint end = curr->rightChild->mapToGlobal(curr->rightChild->rect().center());
                p.drawLine(mapFromGlobal(start), mapFromGlobal(end));
            }
        }
    }
}

int i = 0;

void MainWindow::highlightNode() {
    nodesForHighlight[i]->setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-size: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-weight: 800;"));
    ui->messageText->setText(msg);
    if (i < nodesForHighlight.length() - 1) {
        i++;
        msg += QString::number(nodesForHighlight[i]->value) + " ";
        nodesForHighlight[i]->setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: blue; border-radius: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-size: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-weight: 800;"));
        timer->start(400);
    } else{
       traversalCancel();
    }
}

void MainWindow::traversalCancel() {
    timer->stop();
    if (i < nodesForHighlight.length() - 1)
        nodesForHighlight[i]->setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-size: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-weight: 800;"));
    if (isAVL) {
        ui->addBtn->setEnabled(true);
        ui->addValue->setEnabled(true);
    }
    ui->delBtn->setEnabled(true);
    ui->delValue->setEnabled(true);
    ui->toAVLBtn->setEnabled(true);
    ui->readBtn->setEnabled(true);
    ui->traversalType->setEnabled(true);
    nodesForHighlight.clear();
    ui->traversalBtn->setText("Обойти дерево");
    connect(ui->traversalBtn, &QPushButton::clicked, this, &MainWindow::traversalChoice);
    i = 0;
}

void MainWindow::traversalChoice() {
    if (tree == nullptr or tree->getHead() == nullptr){
        showError(404);
        return;
    }
    ui->addBtn->setEnabled(false);
    ui->addValue->setEnabled(false);
    ui->delBtn->setEnabled(false);
    ui->delValue->setEnabled(false);
    ui->readBtn->setEnabled(false);
    ui->toAVLBtn->setEnabled(false);
    ui->traversalType->setEnabled(false);
    ui->traversalBtn->setText("Отменить");
    connect(ui->traversalBtn, &QPushButton::clicked, this, &MainWindow::traversalCancel);
    int traversalIndex = ui->traversalType->currentText().toInt();
    ui->messageText->setStyleSheet("color: black; font-size: 10pt; border: none;");
    switch(traversalIndex) {
        case 1:
        nodesForHighlight = tree->widthTraversal();
        break;
        case 2:
        nodesForHighlight = tree->depthTraversal1();
        break;
        case 3:
        nodesForHighlight = tree->depthTraversal2();
        break;
        case 4:
        nodesForHighlight = tree->depthTraversal3();
        break;
    }
    msg =  QString::number(nodesForHighlight[i]->value) + " ";
    nodesForHighlight[i]->setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: blue; border-radius: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-size: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-weight: 800;"));
    timer->start(400);
}

void MainWindow::toAVL() {
    QVector<QTreeNode*> nodes;
    QVector<int> values;
    if (tree){
        nodes = tree->depthTraversal1();
        for (int i = 0; i < nodes.length(); i++) {
            values.push_back(nodes[i]->value);
        }
        delete tree;
    }
    tree = new QBTree();
    for (int i = 0; i < values.length(); i++) {
        tree->add(values[i]);
    }
    isAVL = true;
    ui->addBtn->setEnabled(true);
    ui->addValue->setEnabled(true);
    ui->toAVLBtn->setEnabled(false);
    showTree();
}

void MainWindow::delNode() {
    if (tree == nullptr or tree->getHead() == nullptr) {
        showError(404);
        return;
    }
    int value = ui->delValue->text().toInt();
    QTreeNode* node = tree->findNode(value);
    if (!node) {
        showError(410);
        return;
    }
    tree->del(node);
    showTree();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete val;
    for (int i = 0; i < nodes.length(); i++) {
        if (nodes[i])
            delete (nodes[i]);
    }
    nodes.clear();
    for (int i = 0; i < horizontalLayouts.length(); i++) {
        delete horizontalLayouts[i];
    }
    horizontalLayouts.clear();
    if (layout)
        delete layout;
    if (timer)
        delete timer;
    if (tree)
        delete tree;
}
=======
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <math.h>
#include <QVector>
#include <QQueue>
#include <QPoint>
#include <QFileInfo>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    layout = ui->verticalLayoutWidget->findChild<QVBoxLayout*>("heightLayout");
    Q_ASSERT(layout);
    tree = nullptr;
    val = new QRegExpValidator((QRegExp) "-?\\d{1,3}", this);
    ui->delValue->setValidator(val);
    ui->addValue->setValidator(val);
    ui->addBtn->setEnabled(false);
    ui->addValue->setEnabled(false);
    setWindowTitle("Деревья 2");
    connect(ui->readBtn, &QPushButton::clicked, this, &MainWindow::getTree);
    connect(timer, &QTimer::timeout, this, &MainWindow::highlightNode);
    connect(ui->traversalBtn, &QPushButton::clicked, this, &MainWindow::traversalChoice);
    connect(ui->delBtn, &QPushButton::clicked, this, &MainWindow::delNode);
    connect(ui->toAVLBtn, &QPushButton::clicked, this, &MainWindow::toAVL);
    connect(ui->addBtn, &QPushButton::clicked, this, &MainWindow::addNode);
}

void MainWindow::showError(int errCode) {
    ui->messageText->setText("Ошибка " + QString::number(errCode) + ". " + errors[errCode]);
    ui->messageText->setStyleSheet("color: red; font-size: 10pt; border: none;");
}

void MainWindow::getTree() {
    if (!QFileInfo::exists("input.txt")) {
        showError(405);
        return;
    }
    QFile file("input.txt");
    file.open(QFile::ReadOnly);
    QString s = file.readLine();
    if (s == "") {
        showError(406);
        return;
    }
    if (tree)
        delete tree;
    tree = new QTree(s);
    ui->addBtn->setEnabled(false);
    ui->addValue->setEnabled(false);
    ui->toAVLBtn->setEnabled(true);
    showTree();
}

void MainWindow::showTree() {
    for (int i = 0; i < nodes.length(); i++) {
        if (nodes[i])
            delete nodes[i];
    }
    nodes.clear();
    for (int i = 0; i < horizontalLayouts.length(); i++) {
        if (horizontalLayouts[i]){
            while (horizontalLayouts[i]->itemAt(0))
                horizontalLayouts[i]->removeItem(horizontalLayouts[i]->itemAt(0));
            layout->removeItem(horizontalLayouts[i]);
            delete horizontalLayouts[i];
        }
    }
    horizontalLayouts.clear();

    if (tree->getHeight() == 0) {
        update();
        return;
    }
    int treeWidth = (int) pow(2, tree->getHeight() - 1);
    int size = 650 / treeWidth - 4;
    for (int i = 0; i < tree->getHeight(); i++) {
        QHBoxLayout *horizontalLayout = new QHBoxLayout;
        horizontalLayout->setSpacing(0);
        layout->addLayout(horizontalLayout);
        horizontalLayouts.push_back(horizontalLayout);
        horizontalLayout->addStretch();
        for (int j = 0; j < (int) pow(2, i); j++) {
            QTreeNode *nodeShow = new QTreeNode(size);
            horizontalLayout->addWidget(nodeShow);
            horizontalLayout->addStretch();
            nodes.push_back(nodeShow);
        }
    }
    tree->showTree(&horizontalLayouts, size);
    update();
}

void MainWindow::addNode() {
    int value = ui->addValue->text().toInt();
    if (tree->add(value))
        showTree();
    else
        showError(501);
}

void MainWindow::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    p.setPen(QPen(Qt::black, 2));
    for (int i = 0; i < horizontalLayouts.length(); i++) {
        for (int j = 1; j < (int) pow(2, i + 1); j += 2) {
            QTreeNode* curr = qobject_cast<QTreeNode*>(horizontalLayouts[i]->itemAt(j)->widget());
            if (curr->leftChild) {
                QPoint start = curr->mapToGlobal(curr->rect().center());
                QPoint end = curr->leftChild->mapToGlobal(curr->leftChild->rect().center());
                p.drawLine(mapFromGlobal(start), mapFromGlobal(end));
            }
            if (curr->rightChild) {
                QPoint start = curr->mapToGlobal(curr->rect().center());
                QPoint end = curr->rightChild->mapToGlobal(curr->rightChild->rect().center());
                p.drawLine(mapFromGlobal(start), mapFromGlobal(end));
            }
        }
    }
}

int i = 0;

void MainWindow::highlightNode() {
    nodesForHighlight[i]->setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-size: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-weight: 800;"));
    ui->messageText->setText(msg);
    if (i < nodesForHighlight.length() - 1) {
        i++;
        msg += QString::number(nodesForHighlight[i]->value) + " ";
        nodesForHighlight[i]->setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: blue; border-radius: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-size: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-weight: 800;"));
        timer->start(400);
    } else{
       traversalCancel();
    }
}

void MainWindow::traversalCancel() {
    timer->stop();
    if (i < nodesForHighlight.length() - 1)
        nodesForHighlight[i]->setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: #a7e8be; border-radius: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-size: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-weight: 800;"));
    if (isAVL) {
        ui->addBtn->setEnabled(true);
        ui->addValue->setEnabled(true);
    }
    ui->delBtn->setEnabled(true);
    ui->delValue->setEnabled(true);
    ui->toAVLBtn->setEnabled(true);
    ui->readBtn->setEnabled(true);
    ui->traversalType->setEnabled(true);
    nodesForHighlight.clear();
    ui->traversalBtn->setText("Обойти дерево");
    connect(ui->traversalBtn, &QPushButton::clicked, this, &MainWindow::traversalChoice);
    i = 0;
}

void MainWindow::traversalChoice() {
    if (tree == nullptr or tree->getHead() == nullptr){
        showError(404);
        return;
    }
    ui->addBtn->setEnabled(false);
    ui->addValue->setEnabled(false);
    ui->delBtn->setEnabled(false);
    ui->delValue->setEnabled(false);
    ui->readBtn->setEnabled(false);
    ui->toAVLBtn->setEnabled(false);
    ui->traversalType->setEnabled(false);
    ui->traversalBtn->setText("Отменить");
    connect(ui->traversalBtn, &QPushButton::clicked, this, &MainWindow::traversalCancel);
    int traversalIndex = ui->traversalType->currentText().toInt();
    ui->messageText->setStyleSheet("color: black; font-size: 10pt; border: none;");
    switch(traversalIndex) {
        case 1:
        nodesForHighlight = tree->widthTraversal();
        break;
        case 2:
        nodesForHighlight = tree->depthTraversal1();
        break;
        case 3:
        nodesForHighlight = tree->depthTraversal2();
        break;
        case 4:
        nodesForHighlight = tree->depthTraversal3();
        break;
    }
    msg =  QString::number(nodesForHighlight[i]->value) + " ";
    nodesForHighlight[i]->setStyleSheet(QString("border-width: 2px; border-color: black; border-style: solid; background-color: blue; border-radius: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-size: " + QString::number(nodesForHighlight[i]->height() / 2) + "px; font-weight: 800;"));
    timer->start(400);
}

void MainWindow::toAVL() {
    QVector<QTreeNode*> nodes;
    QVector<int> values;
    if (tree){
        nodes = tree->depthTraversal1();
        for (int i = 0; i < nodes.length(); i++) {
            values.push_back(nodes[i]->value);
        }
        delete tree;
    }
    tree = new QBTree();
    for (int i = 0; i < values.length(); i++) {
        tree->add(values[i]);
    }
    isAVL = true;
    ui->addBtn->setEnabled(true);
    ui->addValue->setEnabled(true);
    ui->toAVLBtn->setEnabled(false);
    showTree();
}

void MainWindow::delNode() {
    if (tree == nullptr or tree->getHead() == nullptr) {
        showError(404);
        return;
    }
    int value = ui->delValue->text().toInt();
    QTreeNode* node = tree->findNode(value);
    if (!node) {
        showError(410);
        return;
    }
    tree->del(node);
    showTree();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete val;
    for (int i = 0; i < nodes.length(); i++) {
        if (nodes[i])
            delete (nodes[i]);
    }
    nodes.clear();
    for (int i = 0; i < horizontalLayouts.length(); i++) {
        delete horizontalLayouts[i];
    }
    horizontalLayouts.clear();
    if (layout)
        delete layout;
    if (timer)
        delete timer;
    if (tree)
        delete tree;
}
>>>>>>> 584cbfa (Добавил бинарники)
