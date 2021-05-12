#ifndef ROV_H
#define ROV_H

#include <QObject>
#include <QTimer>
#include "udpsender.h"

class ROV : public QObject
{
    Q_OBJECT
public:
    explicit ROV(QObject *parent = nullptr);

    void setKursD(int v);
    void setMarshD(int v);
    void setLagD(int v);
    void setGlubD(int v);
    void setDiffD(int v);
    void setKrenD(int v);

    double getKursC();
    double getMarshC();
    double getLagC();
    double getGlubC();
    double getDiffC();
    double getKrenC();
    double getdMarsh();
    double getdLag();
    double getdGlub();

    void CompU();

signals:

public slots:

private:
    UDPsender udp;
    //текущие значения
    double MarshC, LagC, GlubC, KursC, DiffC, KrenC;
    //заданные значения
    double MarshD, LagD, GlubD, KursD, DiffD, KrenD;
    //управляющие сигналы
    double Umarsh, Ulag, Uglub, Ukurs, Udiff, Ukren;
    //скорости
    double dMarsh, dLag, dGlub;
    //коэфф.
    double K1, K21, K2, K22, K3, K32;

};

#endif // ROV_H
