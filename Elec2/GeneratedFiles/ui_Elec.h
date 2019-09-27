/********************************************************************************
** Form generated from reading UI file 'Elec.ui'
**
** Created: Mon Sep 23 18:08:42 2019
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELEC_H
#define UI_ELEC_H

#include <CenterWidget.h>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ElecClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *wgtTitle;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConfig;
    QPushButton *btnQuery;
    QPushButton *btnUser;
    QPushButton *btnQuit;
    QSpacerItem *horizontalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    CenterWidget *wgtContent;
    QWidget *page_2;
    QWidget *page_4;
    QWidget *page_5;

    void setupUi(QMainWindow *ElecClass)
    {
        if (ElecClass->objectName().isEmpty())
            ElecClass->setObjectName(QString::fromUtf8("ElecClass"));
        ElecClass->resize(1686, 1097);
        centralWidget = new QWidget(ElecClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        wgtTitle = new QWidget(centralWidget);
        wgtTitle->setObjectName(QString::fromUtf8("wgtTitle"));
        wgtTitle->setMinimumSize(QSize(0, 150));
        wgtTitle->setMaximumSize(QSize(16777215, 150));
        horizontalLayout = new QHBoxLayout(wgtTitle);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnConfig = new QPushButton(wgtTitle);
        btnConfig->setObjectName(QString::fromUtf8("btnConfig"));
        btnConfig->setMinimumSize(QSize(96, 96));
        btnConfig->setMaximumSize(QSize(96, 96));

        horizontalLayout->addWidget(btnConfig);

        btnQuery = new QPushButton(wgtTitle);
        btnQuery->setObjectName(QString::fromUtf8("btnQuery"));
        btnQuery->setMinimumSize(QSize(96, 96));
        btnQuery->setMaximumSize(QSize(96, 96));

        horizontalLayout->addWidget(btnQuery);

        btnUser = new QPushButton(wgtTitle);
        btnUser->setObjectName(QString::fromUtf8("btnUser"));
        btnUser->setMinimumSize(QSize(96, 96));
        btnUser->setMaximumSize(QSize(96, 96));

        horizontalLayout->addWidget(btnUser);

        btnQuit = new QPushButton(wgtTitle);
        btnQuit->setObjectName(QString::fromUtf8("btnQuit"));
        btnQuit->setMinimumSize(QSize(96, 96));
        btnQuit->setMaximumSize(QSize(96, 96));

        horizontalLayout->addWidget(btnQuit);

        horizontalSpacer = new QSpacerItem(1799, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(wgtTitle);

        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        wgtContent = new CenterWidget(page);
        wgtContent->setObjectName(QString::fromUtf8("wgtContent"));

        verticalLayout_2->addWidget(wgtContent);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);

        verticalLayout->addWidget(stackedWidget);

        ElecClass->setCentralWidget(centralWidget);

        retranslateUi(ElecClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ElecClass);
    } // setupUi

    void retranslateUi(QMainWindow *ElecClass)
    {
        ElecClass->setWindowTitle(QApplication::translate("ElecClass", "Elec", 0, QApplication::UnicodeUTF8));
        btnConfig->setText(QApplication::translate("ElecClass", "\347\263\273\347\273\237\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        btnQuery->setText(QApplication::translate("ElecClass", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        btnUser->setText(QApplication::translate("ElecClass", "\346\235\203\351\231\220", 0, QApplication::UnicodeUTF8));
        btnQuit->setText(QApplication::translate("ElecClass", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ElecClass: public Ui_ElecClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELEC_H
