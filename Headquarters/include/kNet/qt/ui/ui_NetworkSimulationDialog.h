/********************************************************************************
** Form generated from reading UI file 'NetworkSimulationDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKSIMULATIONDIALOG_H
#define UI_NETWORKSIMULATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetworkSimulationDialog
{
public:
    QLabel *label_11;
    QLabel *labelConnectionName;
    QGroupBox *groupBox_2;
    QCheckBox *checkBoxPacketDelayEnabled;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_8;
    QSpinBox *spinBoxConstantDelay;
    QSpinBox *spinBoxRandomDelay;
    QSpinBox *spinBoxNormalMean;
    QDoubleSpinBox *doubleSpinBoxNormalVar;
    QGroupBox *groupBox_3;
    QLabel *label_13;
    QLabel *label_14;
    QCheckBox *checkBoxPacketLossEnabled;
    QSpinBox *spinBoxUniformLoss;
    QGroupBox *groupBox_5;
    QLabel *label_17;
    QLabel *label_18;
    QCheckBox *checkBoxPacketDuplicationEnabled;
    QSpinBox *spinBoxUniformDuplication;
    QGroupBox *groupBox_7;
    QCheckBox *checkBoxPacketCorruptionEnabled;
    QCheckBox *checkBoxCorruptPayload;
    QLabel *label_21;
    QSpinBox *spinBoxToggleBitsPr;
    QLabel *label_22;
    QLabel *label_23;
    QSpinBox *spinBoxBitsMin;
    QLabel *label_24;
    QSpinBox *spinBoxBitsMax;
    QGroupBox *groupBox;
    QCheckBox *checkBoxBurstsEnabled;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBoxBurstInterval;
    QLabel *label_25;
    QSpinBox *spinBoxBurstLength;
    QLabel *label_26;

    void setupUi(QWidget *NetworkSimulationDialog)
    {
        if (NetworkSimulationDialog->objectName().isEmpty())
            NetworkSimulationDialog->setObjectName(QString::fromUtf8("NetworkSimulationDialog"));
        NetworkSimulationDialog->resize(432, 360);
        label_11 = new QLabel(NetworkSimulationDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 10, 71, 16));
        labelConnectionName = new QLabel(NetworkSimulationDialog);
        labelConnectionName->setObjectName(QString::fromUtf8("labelConnectionName"));
        labelConnectionName->setGeometry(QRect(80, 10, 341, 16));
        groupBox_2 = new QGroupBox(NetworkSimulationDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 30, 221, 171));
        checkBoxPacketDelayEnabled = new QCheckBox(groupBox_2);
        checkBoxPacketDelayEnabled->setObjectName(QString::fromUtf8("checkBoxPacketDelayEnabled"));
        checkBoxPacketDelayEnabled->setGeometry(QRect(10, 20, 70, 17));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 81, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(170, 50, 46, 13));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 80, 91, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 110, 81, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(170, 80, 46, 13));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(96, 110, 41, 16));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(100, 140, 31, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(190, 110, 21, 16));
        spinBoxConstantDelay = new QSpinBox(groupBox_2);
        spinBoxConstantDelay->setObjectName(QString::fromUtf8("spinBoxConstantDelay"));
        spinBoxConstantDelay->setGeometry(QRect(100, 47, 61, 22));
        spinBoxConstantDelay->setMaximum(10000);
        spinBoxConstantDelay->setSingleStep(100);
        spinBoxRandomDelay = new QSpinBox(groupBox_2);
        spinBoxRandomDelay->setObjectName(QString::fromUtf8("spinBoxRandomDelay"));
        spinBoxRandomDelay->setGeometry(QRect(100, 77, 61, 22));
        spinBoxRandomDelay->setMaximum(10000);
        spinBoxRandomDelay->setSingleStep(100);
        spinBoxNormalMean = new QSpinBox(groupBox_2);
        spinBoxNormalMean->setObjectName(QString::fromUtf8("spinBoxNormalMean"));
        spinBoxNormalMean->setGeometry(QRect(131, 107, 51, 22));
        spinBoxNormalMean->setMaximum(10000);
        spinBoxNormalMean->setSingleStep(100);
        doubleSpinBoxNormalVar = new QDoubleSpinBox(groupBox_2);
        doubleSpinBoxNormalVar->setObjectName(QString::fromUtf8("doubleSpinBoxNormalVar"));
        doubleSpinBoxNormalVar->setGeometry(QRect(130, 137, 71, 22));
        doubleSpinBoxNormalVar->setMaximum(10);
        doubleSpinBoxNormalVar->setSingleStep(0.1);
        doubleSpinBoxNormalVar->setValue(1);
        groupBox_3 = new QGroupBox(NetworkSimulationDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(240, 30, 181, 81));
        groupBox_3->setMinimumSize(QSize(0, 0));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 50, 51, 16));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(140, 50, 31, 16));
        checkBoxPacketLossEnabled = new QCheckBox(groupBox_3);
        checkBoxPacketLossEnabled->setObjectName(QString::fromUtf8("checkBoxPacketLossEnabled"));
        checkBoxPacketLossEnabled->setGeometry(QRect(10, 20, 70, 17));
        spinBoxUniformLoss = new QSpinBox(groupBox_3);
        spinBoxUniformLoss->setObjectName(QString::fromUtf8("spinBoxUniformLoss"));
        spinBoxUniformLoss->setGeometry(QRect(80, 47, 51, 22));
        spinBoxUniformLoss->setMaximum(100);
        spinBoxUniformLoss->setSingleStep(10);
        groupBox_5 = new QGroupBox(NetworkSimulationDialog);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(240, 120, 181, 81));
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(140, 50, 31, 16));
        label_18 = new QLabel(groupBox_5);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 50, 51, 16));
        checkBoxPacketDuplicationEnabled = new QCheckBox(groupBox_5);
        checkBoxPacketDuplicationEnabled->setObjectName(QString::fromUtf8("checkBoxPacketDuplicationEnabled"));
        checkBoxPacketDuplicationEnabled->setGeometry(QRect(10, 20, 70, 17));
        spinBoxUniformDuplication = new QSpinBox(groupBox_5);
        spinBoxUniformDuplication->setObjectName(QString::fromUtf8("spinBoxUniformDuplication"));
        spinBoxUniformDuplication->setGeometry(QRect(80, 47, 51, 22));
        spinBoxUniformDuplication->setMaximum(100);
        spinBoxUniformDuplication->setSingleStep(10);
        groupBox_7 = new QGroupBox(NetworkSimulationDialog);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 210, 221, 141));
        checkBoxPacketCorruptionEnabled = new QCheckBox(groupBox_7);
        checkBoxPacketCorruptionEnabled->setObjectName(QString::fromUtf8("checkBoxPacketCorruptionEnabled"));
        checkBoxPacketCorruptionEnabled->setGeometry(QRect(10, 20, 70, 17));
        checkBoxCorruptPayload = new QCheckBox(groupBox_7);
        checkBoxCorruptPayload->setObjectName(QString::fromUtf8("checkBoxCorruptPayload"));
        checkBoxCorruptPayload->setGeometry(QRect(80, 20, 131, 17));
        label_21 = new QLabel(groupBox_7);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(10, 50, 81, 16));
        spinBoxToggleBitsPr = new QSpinBox(groupBox_7);
        spinBoxToggleBitsPr->setObjectName(QString::fromUtf8("spinBoxToggleBitsPr"));
        spinBoxToggleBitsPr->setGeometry(QRect(90, 47, 71, 22));
        spinBoxToggleBitsPr->setMaximum(100);
        label_22 = new QLabel(groupBox_7);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(170, 50, 31, 16));
        label_23 = new QLabel(groupBox_7);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(14, 80, 81, 16));
        spinBoxBitsMin = new QSpinBox(groupBox_7);
        spinBoxBitsMin->setObjectName(QString::fromUtf8("spinBoxBitsMin"));
        spinBoxBitsMin->setGeometry(QRect(90, 77, 71, 22));
        spinBoxBitsMin->setMaximum(10000);
        label_24 = new QLabel(groupBox_7);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 110, 81, 16));
        spinBoxBitsMax = new QSpinBox(groupBox_7);
        spinBoxBitsMax->setObjectName(QString::fromUtf8("spinBoxBitsMax"));
        spinBoxBitsMax->setGeometry(QRect(90, 107, 71, 22));
        spinBoxBitsMax->setMaximum(10000);
        groupBox = new QGroupBox(NetworkSimulationDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(240, 210, 181, 141));
        checkBoxBurstsEnabled = new QCheckBox(groupBox);
        checkBoxBurstsEnabled->setObjectName(QString::fromUtf8("checkBoxBurstsEnabled"));
        checkBoxBurstsEnabled->setGeometry(QRect(10, 20, 151, 17));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 71, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 80, 71, 16));
        spinBoxBurstInterval = new QSpinBox(groupBox);
        spinBoxBurstInterval->setObjectName(QString::fromUtf8("spinBoxBurstInterval"));
        spinBoxBurstInterval->setGeometry(QRect(90, 47, 61, 22));
        spinBoxBurstInterval->setMaximum(100000);
        spinBoxBurstInterval->setSingleStep(1000);
        label_25 = new QLabel(groupBox);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(160, 50, 46, 13));
        spinBoxBurstLength = new QSpinBox(groupBox);
        spinBoxBurstLength->setObjectName(QString::fromUtf8("spinBoxBurstLength"));
        spinBoxBurstLength->setGeometry(QRect(90, 77, 61, 22));
        spinBoxBurstLength->setMaximum(100000);
        spinBoxBurstLength->setSingleStep(500);
        label_26 = new QLabel(groupBox);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(160, 80, 46, 13));

        retranslateUi(NetworkSimulationDialog);

        QMetaObject::connectSlotsByName(NetworkSimulationDialog);
    } // setupUi

    void retranslateUi(QWidget *NetworkSimulationDialog)
    {
        NetworkSimulationDialog->setWindowTitle(QApplication::translate("NetworkSimulationDialog", "Form", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NetworkSimulationDialog", "Connection:", 0, QApplication::UnicodeUTF8));
        labelConnectionName->setText(QApplication::translate("NetworkSimulationDialog", "<Connection name>", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NetworkSimulationDialog", "Packet Delay", 0, QApplication::UnicodeUTF8));
        checkBoxPacketDelayEnabled->setText(QApplication::translate("NetworkSimulationDialog", "Enabled", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NetworkSimulationDialog", "Constant Delay:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NetworkSimulationDialog", "ms", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NetworkSimulationDialog", "Uniform Random:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NetworkSimulationDialog", "Normal Random:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NetworkSimulationDialog", "ms", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("NetworkSimulationDialog", "Mean:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NetworkSimulationDialog", "Var:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NetworkSimulationDialog", "ms", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("NetworkSimulationDialog", "Packet Loss", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("NetworkSimulationDialog", "Uniform:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("NetworkSimulationDialog", "%", 0, QApplication::UnicodeUTF8));
        checkBoxPacketLossEnabled->setText(QApplication::translate("NetworkSimulationDialog", "Enabled", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("NetworkSimulationDialog", "Packet Duplication", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("NetworkSimulationDialog", "%", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("NetworkSimulationDialog", "Uniform:", 0, QApplication::UnicodeUTF8));
        checkBoxPacketDuplicationEnabled->setText(QApplication::translate("NetworkSimulationDialog", "Enabled", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("NetworkSimulationDialog", "Packet Corruption", 0, QApplication::UnicodeUTF8));
        checkBoxPacketCorruptionEnabled->setText(QApplication::translate("NetworkSimulationDialog", "Enabled", 0, QApplication::UnicodeUTF8));
        checkBoxCorruptPayload->setText(QApplication::translate("NetworkSimulationDialog", "Corrupt Payload Only", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("NetworkSimulationDialog", "Toggle Bits Pr:", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("NetworkSimulationDialog", "%", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("NetworkSimulationDialog", "Num Bits Min:", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("NetworkSimulationDialog", "Num Bits Max:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NetworkSimulationDialog", "Bursts", 0, QApplication::UnicodeUTF8));
        checkBoxBurstsEnabled->setText(QApplication::translate("NetworkSimulationDialog", "Apply Simulation in Bursts", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NetworkSimulationDialog", "Burst Interval:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NetworkSimulationDialog", "Burst Length:", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("NetworkSimulationDialog", "ms", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("NetworkSimulationDialog", "ms", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NetworkSimulationDialog: public Ui_NetworkSimulationDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKSIMULATIONDIALOG_H
