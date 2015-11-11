/********************************************************************************
** Form generated from reading UI file 'MessageConnectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGECONNECTIONDIALOG_H
#define UI_MESSAGECONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MessageConnectionDialog
{
public:
    QLabel *connectionLine;
    QLabel *label;
    QLabel *statusLine;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *labelDatagramsIn;
    QLabel *labelDatagramsOut;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *outboundMessagesPending;
    QLabel *messageConnectionStatus;
    QLabel *socketStatus;
    QLabel *roundTripTime;
    QLabel *lastHeardTime;
    QLabel *datagramsIn;
    QLabel *messagesIn;
    QLabel *datagramsOut;
    QLabel *messagesOut;
    QLabel *bytesIn;
    QLabel *bytesOut;
    QLabel *retransmissionTimeoutHeader;
    QLabel *datagramSendRateHeader;
    QLabel *smoothedRTTHeader;
    QLabel *rttVariationHeader;
    QLabel *outUnackedDatagramsHeader;
    QLabel *recvUnackedDatagramsHeader;
    QLabel *packetLossCountHeader;
    QLabel *packetLossRateHeader;
    QLabel *retransmissionTimeout;
    QLabel *datagramSendRate;
    QLabel *smoothedRTT;
    QLabel *rttVariation;
    QLabel *outUnackedDatagrams;
    QLabel *recvUnackedDatagrams;
    QLabel *packetLossCount;
    QLabel *packetLossRate;
    QLabel *totalBytesSent;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *totalBytesReceived;
    QLabel *label_7;
    QLabel *inboundMessagesPending;
    QPushButton *pushButtonSendSimulation;

    void setupUi(QWidget *MessageConnectionDialog)
    {
        if (MessageConnectionDialog->objectName().isEmpty())
            MessageConnectionDialog->setObjectName(QString::fromUtf8("MessageConnectionDialog"));
        MessageConnectionDialog->resize(425, 519);
        connectionLine = new QLabel(MessageConnectionDialog);
        connectionLine->setObjectName(QString::fromUtf8("connectionLine"));
        connectionLine->setGeometry(QRect(10, 10, 411, 16));
        label = new QLabel(MessageConnectionDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 211, 16));
        statusLine = new QLabel(MessageConnectionDialog);
        statusLine->setObjectName(QString::fromUtf8("statusLine"));
        statusLine->setGeometry(QRect(230, 28, 381, 20));
        label_2 = new QLabel(MessageConnectionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 221, 16));
        label_3 = new QLabel(MessageConnectionDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 90, 211, 16));
        label_4 = new QLabel(MessageConnectionDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 110, 201, 16));
        label_5 = new QLabel(MessageConnectionDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 130, 211, 16));
        label_6 = new QLabel(MessageConnectionDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 150, 211, 16));
        labelDatagramsIn = new QLabel(MessageConnectionDialog);
        labelDatagramsIn->setObjectName(QString::fromUtf8("labelDatagramsIn"));
        labelDatagramsIn->setGeometry(QRect(10, 170, 211, 16));
        labelDatagramsOut = new QLabel(MessageConnectionDialog);
        labelDatagramsOut->setObjectName(QString::fromUtf8("labelDatagramsOut"));
        labelDatagramsOut->setGeometry(QRect(10, 190, 211, 16));
        label_9 = new QLabel(MessageConnectionDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 210, 211, 16));
        label_10 = new QLabel(MessageConnectionDialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 230, 211, 16));
        label_11 = new QLabel(MessageConnectionDialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 250, 211, 16));
        label_12 = new QLabel(MessageConnectionDialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 270, 211, 16));
        outboundMessagesPending = new QLabel(MessageConnectionDialog);
        outboundMessagesPending->setObjectName(QString::fromUtf8("outboundMessagesPending"));
        outboundMessagesPending->setGeometry(QRect(230, 68, 351, 20));
        messageConnectionStatus = new QLabel(MessageConnectionDialog);
        messageConnectionStatus->setObjectName(QString::fromUtf8("messageConnectionStatus"));
        messageConnectionStatus->setGeometry(QRect(230, 88, 381, 20));
        socketStatus = new QLabel(MessageConnectionDialog);
        socketStatus->setObjectName(QString::fromUtf8("socketStatus"));
        socketStatus->setGeometry(QRect(230, 108, 381, 20));
        roundTripTime = new QLabel(MessageConnectionDialog);
        roundTripTime->setObjectName(QString::fromUtf8("roundTripTime"));
        roundTripTime->setGeometry(QRect(230, 128, 381, 20));
        lastHeardTime = new QLabel(MessageConnectionDialog);
        lastHeardTime->setObjectName(QString::fromUtf8("lastHeardTime"));
        lastHeardTime->setGeometry(QRect(230, 148, 381, 20));
        datagramsIn = new QLabel(MessageConnectionDialog);
        datagramsIn->setObjectName(QString::fromUtf8("datagramsIn"));
        datagramsIn->setGeometry(QRect(230, 168, 381, 20));
        messagesIn = new QLabel(MessageConnectionDialog);
        messagesIn->setObjectName(QString::fromUtf8("messagesIn"));
        messagesIn->setGeometry(QRect(230, 208, 381, 20));
        datagramsOut = new QLabel(MessageConnectionDialog);
        datagramsOut->setObjectName(QString::fromUtf8("datagramsOut"));
        datagramsOut->setGeometry(QRect(230, 188, 381, 20));
        messagesOut = new QLabel(MessageConnectionDialog);
        messagesOut->setObjectName(QString::fromUtf8("messagesOut"));
        messagesOut->setGeometry(QRect(230, 228, 381, 20));
        bytesIn = new QLabel(MessageConnectionDialog);
        bytesIn->setObjectName(QString::fromUtf8("bytesIn"));
        bytesIn->setGeometry(QRect(230, 248, 381, 20));
        bytesOut = new QLabel(MessageConnectionDialog);
        bytesOut->setObjectName(QString::fromUtf8("bytesOut"));
        bytesOut->setGeometry(QRect(230, 268, 381, 20));
        retransmissionTimeoutHeader = new QLabel(MessageConnectionDialog);
        retransmissionTimeoutHeader->setObjectName(QString::fromUtf8("retransmissionTimeoutHeader"));
        retransmissionTimeoutHeader->setGeometry(QRect(10, 330, 211, 16));
        datagramSendRateHeader = new QLabel(MessageConnectionDialog);
        datagramSendRateHeader->setObjectName(QString::fromUtf8("datagramSendRateHeader"));
        datagramSendRateHeader->setGeometry(QRect(10, 350, 211, 16));
        smoothedRTTHeader = new QLabel(MessageConnectionDialog);
        smoothedRTTHeader->setObjectName(QString::fromUtf8("smoothedRTTHeader"));
        smoothedRTTHeader->setGeometry(QRect(10, 370, 211, 16));
        rttVariationHeader = new QLabel(MessageConnectionDialog);
        rttVariationHeader->setObjectName(QString::fromUtf8("rttVariationHeader"));
        rttVariationHeader->setGeometry(QRect(10, 390, 211, 16));
        outUnackedDatagramsHeader = new QLabel(MessageConnectionDialog);
        outUnackedDatagramsHeader->setObjectName(QString::fromUtf8("outUnackedDatagramsHeader"));
        outUnackedDatagramsHeader->setGeometry(QRect(10, 410, 211, 16));
        recvUnackedDatagramsHeader = new QLabel(MessageConnectionDialog);
        recvUnackedDatagramsHeader->setObjectName(QString::fromUtf8("recvUnackedDatagramsHeader"));
        recvUnackedDatagramsHeader->setGeometry(QRect(10, 430, 211, 16));
        packetLossCountHeader = new QLabel(MessageConnectionDialog);
        packetLossCountHeader->setObjectName(QString::fromUtf8("packetLossCountHeader"));
        packetLossCountHeader->setGeometry(QRect(10, 450, 211, 16));
        packetLossRateHeader = new QLabel(MessageConnectionDialog);
        packetLossRateHeader->setObjectName(QString::fromUtf8("packetLossRateHeader"));
        packetLossRateHeader->setGeometry(QRect(10, 470, 211, 16));
        retransmissionTimeout = new QLabel(MessageConnectionDialog);
        retransmissionTimeout->setObjectName(QString::fromUtf8("retransmissionTimeout"));
        retransmissionTimeout->setGeometry(QRect(230, 328, 381, 20));
        datagramSendRate = new QLabel(MessageConnectionDialog);
        datagramSendRate->setObjectName(QString::fromUtf8("datagramSendRate"));
        datagramSendRate->setGeometry(QRect(230, 348, 381, 20));
        smoothedRTT = new QLabel(MessageConnectionDialog);
        smoothedRTT->setObjectName(QString::fromUtf8("smoothedRTT"));
        smoothedRTT->setGeometry(QRect(230, 368, 381, 20));
        rttVariation = new QLabel(MessageConnectionDialog);
        rttVariation->setObjectName(QString::fromUtf8("rttVariation"));
        rttVariation->setGeometry(QRect(230, 388, 381, 20));
        outUnackedDatagrams = new QLabel(MessageConnectionDialog);
        outUnackedDatagrams->setObjectName(QString::fromUtf8("outUnackedDatagrams"));
        outUnackedDatagrams->setGeometry(QRect(230, 408, 381, 20));
        recvUnackedDatagrams = new QLabel(MessageConnectionDialog);
        recvUnackedDatagrams->setObjectName(QString::fromUtf8("recvUnackedDatagrams"));
        recvUnackedDatagrams->setGeometry(QRect(230, 428, 381, 20));
        packetLossCount = new QLabel(MessageConnectionDialog);
        packetLossCount->setObjectName(QString::fromUtf8("packetLossCount"));
        packetLossCount->setGeometry(QRect(230, 448, 381, 20));
        packetLossRate = new QLabel(MessageConnectionDialog);
        packetLossRate->setObjectName(QString::fromUtf8("packetLossRate"));
        packetLossRate->setGeometry(QRect(230, 468, 381, 20));
        totalBytesSent = new QLabel(MessageConnectionDialog);
        totalBytesSent->setObjectName(QString::fromUtf8("totalBytesSent"));
        totalBytesSent->setGeometry(QRect(230, 308, 381, 20));
        label_13 = new QLabel(MessageConnectionDialog);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 290, 211, 16));
        label_14 = new QLabel(MessageConnectionDialog);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 310, 201, 16));
        totalBytesReceived = new QLabel(MessageConnectionDialog);
        totalBytesReceived->setObjectName(QString::fromUtf8("totalBytesReceived"));
        totalBytesReceived->setGeometry(QRect(230, 288, 381, 20));
        label_7 = new QLabel(MessageConnectionDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 50, 221, 16));
        inboundMessagesPending = new QLabel(MessageConnectionDialog);
        inboundMessagesPending->setObjectName(QString::fromUtf8("inboundMessagesPending"));
        inboundMessagesPending->setGeometry(QRect(230, 48, 351, 20));
        pushButtonSendSimulation = new QPushButton(MessageConnectionDialog);
        pushButtonSendSimulation->setObjectName(QString::fromUtf8("pushButtonSendSimulation"));
        pushButtonSendSimulation->setGeometry(QRect(10, 490, 91, 23));

        retranslateUi(MessageConnectionDialog);

        QMetaObject::connectSlotsByName(MessageConnectionDialog);
    } // setupUi

    void retranslateUi(QWidget *MessageConnectionDialog)
    {
        MessageConnectionDialog->setWindowTitle(QApplication::translate("MessageConnectionDialog", "Form", 0, QApplication::UnicodeUTF8));
        connectionLine->setText(QApplication::translate("MessageConnectionDialog", "Connection source and destination.", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MessageConnectionDialog", "ConnectionState:", 0, QApplication::UnicodeUTF8));
        statusLine->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MessageConnectionDialog", "# outbound messages pending:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MessageConnectionDialog", "MessageConnection status:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MessageConnectionDialog", "Socket status:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MessageConnectionDialog", "Round-trip time:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MessageConnectionDialog", "Last heard time:", 0, QApplication::UnicodeUTF8));
        labelDatagramsIn->setText(QApplication::translate("MessageConnectionDialog", "Datagrams in:", 0, QApplication::UnicodeUTF8));
        labelDatagramsOut->setText(QApplication::translate("MessageConnectionDialog", "Datagrams out:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MessageConnectionDialog", "Messages in:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MessageConnectionDialog", "Messages out:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MessageConnectionDialog", "Bytes in:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MessageConnectionDialog", "Bytes out:", 0, QApplication::UnicodeUTF8));
        outboundMessagesPending->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        messageConnectionStatus->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        socketStatus->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        roundTripTime->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        lastHeardTime->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        datagramsIn->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        messagesIn->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        datagramsOut->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        messagesOut->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        bytesIn->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        bytesOut->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        retransmissionTimeoutHeader->setText(QApplication::translate("MessageConnectionDialog", "Retransmission timeout:", 0, QApplication::UnicodeUTF8));
        datagramSendRateHeader->setText(QApplication::translate("MessageConnectionDialog", "Datagram send rate:", 0, QApplication::UnicodeUTF8));
        smoothedRTTHeader->setText(QApplication::translate("MessageConnectionDialog", "Smoothed RTT:", 0, QApplication::UnicodeUTF8));
        rttVariationHeader->setText(QApplication::translate("MessageConnectionDialog", "RTT Variation:", 0, QApplication::UnicodeUTF8));
        outUnackedDatagramsHeader->setText(QApplication::translate("MessageConnectionDialog", "Outb. unacked dgrams:", 0, QApplication::UnicodeUTF8));
        recvUnackedDatagramsHeader->setText(QApplication::translate("MessageConnectionDialog", "Recv. unacked dgrams:", 0, QApplication::UnicodeUTF8));
        packetLossCountHeader->setText(QApplication::translate("MessageConnectionDialog", "Packet loss count:", 0, QApplication::UnicodeUTF8));
        packetLossRateHeader->setText(QApplication::translate("MessageConnectionDialog", "Packet loss rate:", 0, QApplication::UnicodeUTF8));
        retransmissionTimeout->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        datagramSendRate->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        smoothedRTT->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        rttVariation->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        outUnackedDatagrams->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        recvUnackedDatagrams->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        packetLossCount->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        packetLossRate->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        totalBytesSent->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MessageConnectionDialog", "Total bytes received:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MessageConnectionDialog", "Total bytes sent:", 0, QApplication::UnicodeUTF8));
        totalBytesReceived->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MessageConnectionDialog", "# inbound messages pending:", 0, QApplication::UnicodeUTF8));
        inboundMessagesPending->setText(QApplication::translate("MessageConnectionDialog", "Status:", 0, QApplication::UnicodeUTF8));
        pushButtonSendSimulation->setText(QApplication::translate("MessageConnectionDialog", "Send Simulation", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MessageConnectionDialog: public Ui_MessageConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGECONNECTIONDIALOG_H
