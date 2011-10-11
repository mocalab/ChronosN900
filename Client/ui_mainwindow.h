/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Oct 11 12:59:03 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QSlider>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *horizontalSlider_cx;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *horizontalSlider_cy;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *horizontalSlider_cz;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QSlider *horizontalSlider_nx;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QSlider *horizontalSlider_ny;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QSlider *horizontalSlider_nz;
    QTextEdit *textEdit_log;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSlider_cx = new QSlider(centralWidget);
        horizontalSlider_cx->setObjectName(QString::fromUtf8("horizontalSlider_cx"));
        horizontalSlider_cx->setMaximum(255);
        horizontalSlider_cx->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_cx);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSlider_cy = new QSlider(centralWidget);
        horizontalSlider_cy->setObjectName(QString::fromUtf8("horizontalSlider_cy"));
        horizontalSlider_cy->setMaximum(255);
        horizontalSlider_cy->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider_cy);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSlider_cz = new QSlider(centralWidget);
        horizontalSlider_cz->setObjectName(QString::fromUtf8("horizontalSlider_cz"));
        horizontalSlider_cz->setMaximum(255);
        horizontalSlider_cz->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_cz);


        verticalLayout->addLayout(horizontalLayout_3);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_7->addWidget(label_6);

        horizontalSlider_nx = new QSlider(centralWidget);
        horizontalSlider_nx->setObjectName(QString::fromUtf8("horizontalSlider_nx"));
        horizontalSlider_nx->setMinimumSize(QSize(0, 10));
        horizontalSlider_nx->setMinimum(-100);
        horizontalSlider_nx->setMaximum(100);
        horizontalSlider_nx->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider_nx);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_8->addWidget(label_7);

        horizontalSlider_ny = new QSlider(centralWidget);
        horizontalSlider_ny->setObjectName(QString::fromUtf8("horizontalSlider_ny"));
        horizontalSlider_ny->setMinimumSize(QSize(0, 10));
        horizontalSlider_ny->setMinimum(-100);
        horizontalSlider_ny->setMaximum(100);
        horizontalSlider_ny->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSlider_ny);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        horizontalSlider_nz = new QSlider(centralWidget);
        horizontalSlider_nz->setObjectName(QString::fromUtf8("horizontalSlider_nz"));
        horizontalSlider_nz->setMinimumSize(QSize(0, 10));
        horizontalSlider_nz->setMinimum(-100);
        horizontalSlider_nz->setMaximum(100);
        horizontalSlider_nz->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(horizontalSlider_nz);


        verticalLayout->addLayout(horizontalLayout_9);


        horizontalLayout_4->addLayout(verticalLayout);

        textEdit_log = new QTextEdit(centralWidget);
        textEdit_log->setObjectName(QString::fromUtf8("textEdit_log"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textEdit_log->sizePolicy().hasHeightForWidth());
        textEdit_log->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(textEdit_log);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Chronos Accelerometer", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Chronos accelerometer data", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "N900 accelerometer data", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "X", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Y", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Z", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
