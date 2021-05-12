#include "udpsender.h"

UDPsender::UDPsender(QObject *parent) : QObject(parent)
{
    send_socket = new QUdpSocket(this);
    qDebug()<<send_socket->bind(QHostAddress::LocalHost, 13041);
    qDebug()<<send_socket->errorString();

    rec_socket = new QUdpSocket(this);
    qDebug()<<rec_socket->bind(QHostAddress::LocalHost, 13044);
    qDebug()<<rec_socket->errorString();

    connect(rec_socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void UDPsender::send(double U1, double U2, double U3, double U4, double U5, double U6){
    sendData.Umarsh = U1;
    sendData.Ulag = U2;
    sendData.Uglub = U3;
    sendData.Ukurs = U4;
    sendData.Udiff = U5;
    sendData.Ukren = U6;
    send_socket->writeDatagram((char*)&sendData, sizeof(sendData), QHostAddress::LocalHost, 13042);
}

void UDPsender::readData(){
    while(rec_socket->hasPendingDatagrams()){
        rec_socket->readDatagram((char*)&recData, sizeof(recData));
    }
}

FromMatLab UDPsender::getData(){
    return recData;
}
