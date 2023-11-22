<<<<<<< HEAD
/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *administrationPanel;
    QPushButton *readBtn;
    QLabel *panelHeader;
    QFrame *line;
    QPushButton *toAVLBtn;
    QPushButton *addBtn;
    QLineEdit *addValue;
    QLineEdit *delValue;
    QPushButton *delBtn;
    QPushButton *traversalBtn;
    QComboBox *traversalType;
    QFrame *line_2;
    QLabel *messageHeader;
    QLabel *messageText;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *heightLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        administrationPanel = new QWidget(centralwidget);
        administrationPanel->setObjectName(QString::fromUtf8("administrationPanel"));
        administrationPanel->setEnabled(true);
        administrationPanel->setGeometry(QRect(10, 20, 241, 651));
        administrationPanel->setAutoFillBackground(false);
        administrationPanel->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-color: lightgray;\n"
"border-width: 2px;\n"
"border-style: solid;"));
        readBtn = new QPushButton(administrationPanel);
        readBtn->setObjectName(QString::fromUtf8("readBtn"));
        readBtn->setEnabled(true);
        readBtn->setGeometry(QRect(10, 140, 221, 31));
        readBtn->setCursor(QCursor(Qt::PointingHandCursor));
        readBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        readBtn->setCheckable(true);
        panelHeader = new QLabel(administrationPanel);
        panelHeader->setObjectName(QString::fromUtf8("panelHeader"));
        panelHeader->setGeometry(QRect(10, 10, 221, 91));
        panelHeader->setLayoutDirection(Qt::LeftToRight);
        panelHeader->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 120 16pt \"MS Shell Dlg 2\";\n"
"border: none;"));
        panelHeader->setTextFormat(Qt::PlainText);
        panelHeader->setScaledContents(false);
        panelHeader->setAlignment(Qt::AlignCenter);
        panelHeader->setWordWrap(true);
        line = new QFrame(administrationPanel);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 110, 241, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        toAVLBtn = new QPushButton(administrationPanel);
        toAVLBtn->setObjectName(QString::fromUtf8("toAVLBtn"));
        toAVLBtn->setEnabled(true);
        toAVLBtn->setGeometry(QRect(10, 190, 221, 31));
        toAVLBtn->setCursor(QCursor(Qt::PointingHandCursor));
        toAVLBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        toAVLBtn->setCheckable(true);
        addBtn = new QPushButton(administrationPanel);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setEnabled(true);
        addBtn->setGeometry(QRect(110, 240, 121, 31));
        addBtn->setCursor(QCursor(Qt::PointingHandCursor));
        addBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        addBtn->setCheckable(true);
        addValue = new QLineEdit(administrationPanel);
        addValue->setObjectName(QString::fromUtf8("addValue"));
        addValue->setGeometry(QRect(10, 240, 91, 31));
        addValue->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"padding-left: 5px;"));
        addValue->setMaxLength(32767);
        delValue = new QLineEdit(administrationPanel);
        delValue->setObjectName(QString::fromUtf8("delValue"));
        delValue->setGeometry(QRect(10, 290, 91, 31));
        delValue->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"padding-left: 5px;"));
        delValue->setInputMethodHints(Qt::ImhNone);
        delBtn = new QPushButton(administrationPanel);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));
        delBtn->setEnabled(true);
        delBtn->setGeometry(QRect(110, 290, 121, 31));
        delBtn->setCursor(QCursor(Qt::PointingHandCursor));
        delBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        delBtn->setCheckable(true);
        traversalBtn = new QPushButton(administrationPanel);
        traversalBtn->setObjectName(QString::fromUtf8("traversalBtn"));
        traversalBtn->setEnabled(true);
        traversalBtn->setGeometry(QRect(10, 340, 171, 31));
        traversalBtn->setCursor(QCursor(Qt::PointingHandCursor));
        traversalBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        traversalBtn->setCheckable(true);
        traversalType = new QComboBox(administrationPanel);
        traversalType->addItem(QString());
        traversalType->addItem(QString());
        traversalType->addItem(QString());
        traversalType->addItem(QString());
        traversalType->setObjectName(QString::fromUtf8("traversalType"));
        traversalType->setGeometry(QRect(190, 340, 41, 31));
        traversalType->setStyleSheet(QString::fromUtf8("font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 5px;"));
        line_2 = new QFrame(administrationPanel);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 400, 241, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        messageHeader = new QLabel(administrationPanel);
        messageHeader->setObjectName(QString::fromUtf8("messageHeader"));
        messageHeader->setGeometry(QRect(10, 410, 221, 20));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        messageHeader->setFont(font1);
        messageHeader->setStyleSheet(QString::fromUtf8("border: none;"));
        messageHeader->setAlignment(Qt::AlignCenter);
        messageText = new QLabel(administrationPanel);
        messageText->setObjectName(QString::fromUtf8("messageText"));
        messageText->setGeometry(QRect(10, 450, 221, 171));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(13);
        font2.setItalic(false);
        messageText->setFont(font2);
        messageText->setStyleSheet(QString::fromUtf8("padding: 5px;\n"
"border: none; font-size: 13pt;"));
        messageText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        messageText->setWordWrap(true);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 20, 1001, 651));
        heightLayout = new QVBoxLayout(verticalLayoutWidget);
        heightLayout->setSpacing(0);
        heightLayout->setObjectName(QString::fromUtf8("heightLayout"));
        heightLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        heightLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        readBtn->setText(QApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \320\261\320\270\320\275\320\260\321\200\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        panelHeader->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\261\320\270\320\275\320\260\321\200\320\275\321\213\320\274 \320\264\320\265\321\200\320\265\320\262\320\276\320\274", nullptr));
        toAVLBtn->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\321\202\321\214 \320\262 \320\220\320\222\320\233-\320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        addBtn->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        addValue->setInputMask(QString());
        addValue->setText(QString());
        delValue->setText(QString());
        delBtn->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        traversalBtn->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\276\320\271\321\202\320\270 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        traversalType->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        traversalType->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        traversalType->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));
        traversalType->setItemText(3, QApplication::translate("MainWindow", "4", nullptr));

        traversalType->setCurrentText(QApplication::translate("MainWindow", "1", nullptr));
        //traversalType->setPlaceholderText(QString());
        messageHeader->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265:", nullptr));
        messageText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
=======
/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *administrationPanel;
    QPushButton *readBtn;
    QLabel *panelHeader;
    QFrame *line;
    QPushButton *toAVLBtn;
    QPushButton *addBtn;
    QLineEdit *addValue;
    QLineEdit *delValue;
    QPushButton *delBtn;
    QPushButton *traversalBtn;
    QComboBox *traversalType;
    QFrame *line_2;
    QLabel *messageHeader;
    QLabel *messageText;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *heightLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        administrationPanel = new QWidget(centralwidget);
        administrationPanel->setObjectName(QString::fromUtf8("administrationPanel"));
        administrationPanel->setEnabled(true);
        administrationPanel->setGeometry(QRect(10, 20, 241, 651));
        administrationPanel->setAutoFillBackground(false);
        administrationPanel->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-color: lightgray;\n"
"border-width: 2px;\n"
"border-style: solid;"));
        readBtn = new QPushButton(administrationPanel);
        readBtn->setObjectName(QString::fromUtf8("readBtn"));
        readBtn->setEnabled(true);
        readBtn->setGeometry(QRect(10, 140, 221, 31));
        readBtn->setCursor(QCursor(Qt::PointingHandCursor));
        readBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        readBtn->setCheckable(true);
        panelHeader = new QLabel(administrationPanel);
        panelHeader->setObjectName(QString::fromUtf8("panelHeader"));
        panelHeader->setGeometry(QRect(10, 10, 221, 91));
        panelHeader->setLayoutDirection(Qt::LeftToRight);
        panelHeader->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 120 16pt \"MS Shell Dlg 2\";\n"
"border: none;"));
        panelHeader->setTextFormat(Qt::PlainText);
        panelHeader->setScaledContents(false);
        panelHeader->setAlignment(Qt::AlignCenter);
        panelHeader->setWordWrap(true);
        line = new QFrame(administrationPanel);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 110, 241, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        toAVLBtn = new QPushButton(administrationPanel);
        toAVLBtn->setObjectName(QString::fromUtf8("toAVLBtn"));
        toAVLBtn->setEnabled(true);
        toAVLBtn->setGeometry(QRect(10, 190, 221, 31));
        toAVLBtn->setCursor(QCursor(Qt::PointingHandCursor));
        toAVLBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        toAVLBtn->setCheckable(true);
        addBtn = new QPushButton(administrationPanel);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setEnabled(true);
        addBtn->setGeometry(QRect(110, 240, 121, 31));
        addBtn->setCursor(QCursor(Qt::PointingHandCursor));
        addBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        addBtn->setCheckable(true);
        addValue = new QLineEdit(administrationPanel);
        addValue->setObjectName(QString::fromUtf8("addValue"));
        addValue->setGeometry(QRect(10, 240, 91, 31));
        addValue->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"padding-left: 5px;"));
        addValue->setMaxLength(32767);
        delValue = new QLineEdit(administrationPanel);
        delValue->setObjectName(QString::fromUtf8("delValue"));
        delValue->setGeometry(QRect(10, 290, 91, 31));
        delValue->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"padding-left: 5px;"));
        delValue->setInputMethodHints(Qt::ImhNone);
        delBtn = new QPushButton(administrationPanel);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));
        delBtn->setEnabled(true);
        delBtn->setGeometry(QRect(110, 290, 121, 31));
        delBtn->setCursor(QCursor(Qt::PointingHandCursor));
        delBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        delBtn->setCheckable(true);
        traversalBtn = new QPushButton(administrationPanel);
        traversalBtn->setObjectName(QString::fromUtf8("traversalBtn"));
        traversalBtn->setEnabled(true);
        traversalBtn->setGeometry(QRect(10, 340, 171, 31));
        traversalBtn->setCursor(QCursor(Qt::PointingHandCursor));
        traversalBtn->setStyleSheet(QString::fromUtf8("border-radius: 6px; background-color: lightgray; \n"
"font: 8pt \"MS Shell Dlg 2\";\n"
"font-weight: 600;"));
        traversalBtn->setCheckable(true);
        traversalType = new QComboBox(administrationPanel);
        traversalType->addItem(QString());
        traversalType->addItem(QString());
        traversalType->addItem(QString());
        traversalType->addItem(QString());
        traversalType->setObjectName(QString::fromUtf8("traversalType"));
        traversalType->setGeometry(QRect(190, 340, 41, 31));
        traversalType->setStyleSheet(QString::fromUtf8("font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 5px;"));
        line_2 = new QFrame(administrationPanel);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 400, 241, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        messageHeader = new QLabel(administrationPanel);
        messageHeader->setObjectName(QString::fromUtf8("messageHeader"));
        messageHeader->setGeometry(QRect(10, 410, 221, 20));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        messageHeader->setFont(font1);
        messageHeader->setStyleSheet(QString::fromUtf8("border: none;"));
        messageHeader->setAlignment(Qt::AlignCenter);
        messageText = new QLabel(administrationPanel);
        messageText->setObjectName(QString::fromUtf8("messageText"));
        messageText->setGeometry(QRect(10, 450, 221, 171));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(13);
        font2.setItalic(false);
        messageText->setFont(font2);
        messageText->setStyleSheet(QString::fromUtf8("padding: 5px;\n"
"border: none; font-size: 13pt;"));
        messageText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        messageText->setWordWrap(true);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 20, 1001, 651));
        heightLayout = new QVBoxLayout(verticalLayoutWidget);
        heightLayout->setSpacing(0);
        heightLayout->setObjectName(QString::fromUtf8("heightLayout"));
        heightLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        heightLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        readBtn->setText(QApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \320\261\320\270\320\275\320\260\321\200\320\275\320\276\320\265 \320\264\320\265\321\200\320\265\320\262\320\276 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        panelHeader->setText(QApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\261\320\270\320\275\320\260\321\200\320\275\321\213\320\274 \320\264\320\265\321\200\320\265\320\262\320\276\320\274", nullptr));
        toAVLBtn->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\321\202\321\214 \320\262 \320\220\320\222\320\233-\320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        addBtn->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        addValue->setInputMask(QString());
        addValue->setText(QString());
        delValue->setText(QString());
        delBtn->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        traversalBtn->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\276\320\271\321\202\320\270 \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        traversalType->setItemText(0, QApplication::translate("MainWindow", "1", nullptr));
        traversalType->setItemText(1, QApplication::translate("MainWindow", "2", nullptr));
        traversalType->setItemText(2, QApplication::translate("MainWindow", "3", nullptr));
        traversalType->setItemText(3, QApplication::translate("MainWindow", "4", nullptr));

        traversalType->setCurrentText(QApplication::translate("MainWindow", "1", nullptr));
        //traversalType->setPlaceholderText(QString());
        messageHeader->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265:", nullptr));
        messageText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
>>>>>>> 584cbfa (Добавил бинарники)
