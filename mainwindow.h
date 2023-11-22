<<<<<<< HEAD
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QRegExpValidator>
#include "qtree.h"
#include "qbtree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTree *tree;
    Ui::MainWindow *ui;
    QVBoxLayout *layout;
    QVector<QHBoxLayout*> horizontalLayouts;
    QVector<QTreeNode*> nodes;
    QVector<QTreeNode*> nodesForHighlight;
    QString msg;
    QRegExpValidator *val;
    QTimer* timer = new QTimer(this);
    QMap<int, QString> errors = {
        {404, "Бинарное дерево не найдено."},
        {405, "Файл \"input.txt\" не найден."},
        {406, "Файл \"input.txt\" пуст."},
        {410, "Узел с таким значением не найден."},
        {501, "Узел с таким значением уже существует."}
    };
    bool isAVL = 0;
    void showError(int errCode);
    void widthTraversal();
    void depthTraversal1();
    void depthTraversal2();
    void depthTraversal3();
    void showTree();
protected:
    void paintEvent(QPaintEvent *event);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void traversalCancel();
    void getTree();
    void delNode();
    void highlightNode();
    void traversalChoice();
    void toAVL();
    void addNode();
};
#endif // MAINWINDOW_H
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QHBoxLayout>
#include <QLabel>
#include <QTimer>
#include <QRegExpValidator>
#include "qtree.h"
#include "qbtree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QTree *tree;
    Ui::MainWindow *ui;
    QVBoxLayout *layout;
    QVector<QHBoxLayout*> horizontalLayouts;
    QVector<QTreeNode*> nodes;
    QVector<QTreeNode*> nodesForHighlight;
    QString msg;
    QRegExpValidator *val;
    QTimer* timer = new QTimer(this);
    QMap<int, QString> errors = {
        {404, "Бинарное дерево не найдено."},
        {405, "Файл \"input.txt\" не найден."},
        {406, "Файл \"input.txt\" пуст."},
        {410, "Узел с таким значением не найден."},
        {501, "Узел с таким значением уже существует."}
    };
    bool isAVL = 0;
    void showError(int errCode);
    void widthTraversal();
    void depthTraversal1();
    void depthTraversal2();
    void depthTraversal3();
    void showTree();
protected:
    void paintEvent(QPaintEvent *event);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void traversalCancel();
    void getTree();
    void delNode();
    void highlightNode();
    void traversalChoice();
    void toAVL();
    void addNode();
};
#endif // MAINWINDOW_H
>>>>>>> 584cbfa (Добавил бинарники)
