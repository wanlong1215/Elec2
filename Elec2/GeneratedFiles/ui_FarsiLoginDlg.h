/********************************************************************************
** Form generated from reading UI file 'FarsiLoginDlg.ui'
**
** Created: Mon Sep 23 18:08:43 2019
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FARSILOGINDLG_H
#define UI_FARSILOGINDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FarsiLoginDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *wgtContent;
    QVBoxLayout *verticalLayout;
    QLineEdit *leUser;
    QLineEdit *lePwd;
    QPushButton *btnLogin;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *FarsiLoginDlg)
    {
        if (FarsiLoginDlg->objectName().isEmpty())
            FarsiLoginDlg->setObjectName(QString::fromUtf8("FarsiLoginDlg"));
        FarsiLoginDlg->resize(854, 485);
        FarsiLoginDlg->setStyleSheet(QString::fromUtf8("QDialog#FarsiLoginDlg{\n"
"border-image: url(:/Resources/loginBackgroundFarsi.png);}"));
        verticalLayout_2 = new QVBoxLayout(FarsiLoginDlg);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 50);
        label = new QLabel(FarsiLoginDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(label);

        widget = new QWidget(FarsiLoginDlg);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(99, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        wgtContent = new QWidget(widget);
        wgtContent->setObjectName(QString::fromUtf8("wgtContent"));
        wgtContent->setMinimumSize(QSize(311, 191));
        wgtContent->setMaximumSize(QSize(311, 191));
        wgtContent->setStyleSheet(QString::fromUtf8("QWidget#wgtContent{background-color: rgba(50, 50, 50);}"));
        verticalLayout = new QVBoxLayout(wgtContent);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(25, -1, 25, 20);
        leUser = new QLineEdit(wgtContent);
        leUser->setObjectName(QString::fromUtf8("leUser"));
        leUser->setMinimumSize(QSize(0, 30));
        leUser->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85);\n"
"    border-radius: 3px;\n"
"    background: white;\n"
"    selection-background-color: green;\n"
"    font-size: 14px;\n"
"}\n"
"QLineEdit:hover {\n"
"    border: 1px solid blue;\n"
"}"));

        verticalLayout->addWidget(leUser);

        lePwd = new QLineEdit(wgtContent);
        lePwd->setObjectName(QString::fromUtf8("lePwd"));
        lePwd->setMinimumSize(QSize(0, 30));
        lePwd->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid rgb(41, 57, 85);\n"
"    border-radius: 3px;\n"
"    background: white;\n"
"    selection-background-color: green;\n"
"    font-size: 14px;\n"
"}\n"
"QLineEdit:hover {\n"
"    border: 1px solid blue;\n"
"}"));
        lePwd->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(lePwd);

        btnLogin = new QPushButton(wgtContent);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setMinimumSize(QSize(0, 40));
        btnLogin->setStyleSheet(QString::fromUtf8("QPushButton{background-color: #999999;\n"
"border-radius:2px;\n"
"border:0px;\n"
"font-family:\345\276\256\350\275\257\351\233\205\351\273\221;\n"
"font-size:18px;\n"
"font-weight:500;\n"
"line-height:2px;\n"
"color:rgb(255,255,255);}\n"
"QPushButton:hover{background-color: #cccccc;box-shadow:0px 2px 5px 0px rgb(227,174,0);}\n"
"QPushButton:pressed{background-color: #cccccc;border-style: inset;}"));

        verticalLayout->addWidget(btnLogin);


        horizontalLayout->addWidget(wgtContent);

        horizontalSpacer_2 = new QSpacerItem(244, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addWidget(widget);


        retranslateUi(FarsiLoginDlg);

        QMetaObject::connectSlotsByName(FarsiLoginDlg);
    } // setupUi

    void retranslateUi(QDialog *FarsiLoginDlg)
    {
        FarsiLoginDlg->setWindowTitle(QApplication::translate("FarsiLoginDlg", "Elec", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FarsiLoginDlg", "Electricity Detection", 0, QApplication::UnicodeUTF8));
        leUser->setText(QApplication::translate("FarsiLoginDlg", "admin", 0, QApplication::UnicodeUTF8));
        btnLogin->setText(QApplication::translate("FarsiLoginDlg", "\347\231\273  \345\275\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FarsiLoginDlg: public Ui_FarsiLoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FARSILOGINDLG_H
