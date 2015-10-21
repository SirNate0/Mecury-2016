/********************************************************************************
** Form generated from reading UI file 'NetworkDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKDIALOG_H
#define UI_NETWORKDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *machineIP;
    QLabel *label_4;
    QTreeWidget *connectionsTree;
    QLabel *label_2;
    QLabel *numRunningThreads;
    QTreeWidget *treeStats;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *comboTimePeriod;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *NetworkDialog)
    {
        if (NetworkDialog->objectName().isEmpty())
            NetworkDialog->setObjectName(QString::fromUtf8("NetworkDialog"));
        NetworkDialog->resize(524, 606);
        gridLayout_2 = new QGridLayout(NetworkDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(NetworkDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        machineIP = new QLabel(NetworkDialog);
        machineIP->setObjectName(QString::fromUtf8("machineIP"));

        gridLayout->addWidget(machineIP, 0, 1, 1, 1);

        label_4 = new QLabel(NetworkDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        connectionsTree = new QTreeWidget(NetworkDialog);
        connectionsTree->setObjectName(QString::fromUtf8("connectionsTree"));

        gridLayout->addWidget(connectionsTree, 2, 1, 1, 1);

        label_2 = new QLabel(NetworkDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        numRunningThreads = new QLabel(NetworkDialog);
        numRunningThreads->setObjectName(QString::fromUtf8("numRunningThreads"));

        gridLayout->addWidget(numRunningThreads, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        treeStats = new QTreeWidget(NetworkDialog);
        treeStats->setObjectName(QString::fromUtf8("treeStats"));

        gridLayout_2->addWidget(treeStats, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(NetworkDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboTimePeriod = new QComboBox(NetworkDialog);
        comboTimePeriod->setObjectName(QString::fromUtf8("comboTimePeriod"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboTimePeriod->sizePolicy().hasHeightForWidth());
        comboTimePeriod->setSizePolicy(sizePolicy);
        comboTimePeriod->setMinimumSize(QSize(100, 0));
        comboTimePeriod->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(comboTimePeriod);

        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(NetworkDialog);

        QMetaObject::connectSlotsByName(NetworkDialog);
    } // setupUi

    void retranslateUi(QWidget *NetworkDialog)
    {
        NetworkDialog->setWindowTitle(QApplication::translate("NetworkDialog", "kNet Network", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NetworkDialog", "Hostname:", 0, QApplication::UnicodeUTF8));
        machineIP->setText(QApplication::translate("NetworkDialog", "Machine IP text.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NetworkDialog", "Connections:", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = connectionsTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("NetworkDialog", "Item", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NetworkDialog", "# of threads:", 0, QApplication::UnicodeUTF8));
        numRunningThreads->setText(QApplication::translate("NetworkDialog", "# threads text.", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = treeStats->headerItem();
        ___qtreewidgetitem1->setText(6, QApplication::translate("NetworkDialog", "Latest value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(5, QApplication::translate("NetworkDialog", "Avg. value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(4, QApplication::translate("NetworkDialog", "Value/sec", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(3, QApplication::translate("NetworkDialog", "Count/sec", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(2, QApplication::translate("NetworkDialog", "Value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("NetworkDialog", "Count", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("NetworkDialog", "Name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NetworkDialog", "Show most recent events from:", 0, QApplication::UnicodeUTF8));
        comboTimePeriod->clear();
        comboTimePeriod->insertItems(0, QStringList()
         << QApplication::translate("NetworkDialog", "5 seconds", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NetworkDialog", "15 seconds", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NetworkDialog", "30 seconds", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NetworkDialog", "1 minute", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class NetworkDialog: public Ui_NetworkDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKDIALOG_H
