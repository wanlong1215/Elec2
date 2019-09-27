/********************************************************************************
** Form generated from reading UI file 'CenterWidget.ui'
**
** Created: Mon Sep 23 18:08:43 2019
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTERWIDGET_H
#define UI_CENTERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QStackedWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CenterWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *trwOrganization;
    QVBoxLayout *verticalLayout;
    QTreeWidget *trwDetail;
    QTableWidget *tawProperty;
    QWidget *page_2;

    void setupUi(QWidget *CenterWidget)
    {
        if (CenterWidget->objectName().isEmpty())
            CenterWidget->setObjectName(QString::fromUtf8("CenterWidget"));
        CenterWidget->resize(980, 624);
        horizontalLayout = new QHBoxLayout(CenterWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(CenterWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_2 = new QHBoxLayout(page);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        trwOrganization = new QTreeWidget(page);
        trwOrganization->setObjectName(QString::fromUtf8("trwOrganization"));
        trwOrganization->setMaximumSize(QSize(500, 16777215));

        horizontalLayout_2->addWidget(trwOrganization);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        trwDetail = new QTreeWidget(page);
        trwDetail->setObjectName(QString::fromUtf8("trwDetail"));

        verticalLayout->addWidget(trwDetail);

        tawProperty = new QTableWidget(page);
        tawProperty->setObjectName(QString::fromUtf8("tawProperty"));
        tawProperty->setMaximumSize(QSize(16777215, 400));

        verticalLayout->addWidget(tawProperty);


        horizontalLayout_2->addLayout(verticalLayout);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(CenterWidget);

        QMetaObject::connectSlotsByName(CenterWidget);
    } // setupUi

    void retranslateUi(QWidget *CenterWidget)
    {
        CenterWidget->setWindowTitle(QApplication::translate("CenterWidget", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CenterWidget: public Ui_CenterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTERWIDGET_H
