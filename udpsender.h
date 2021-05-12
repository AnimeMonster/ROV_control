#ifndef UDPSENDER_H
#define UDPSENDER_H

#include <QObject>
#include <QUdpSocket>

struct ToMatLab{
    ToMatLab(){
        Umarsh = 0;
        Ulag = 0;
        Uglub = 0;
        Ukurs = 0;
        Udiff = 0;
        Ukren = 0;
    }
    double Umarsh, Ulag, Uglub, Ukurs, Udiff, Ukren;
};

struct FromMatLab{
    FromMatLab(){
        Marsh = 0;
        dMarsh = 0;
        Lag = 0;
        dLag = 0;
        Glub = 0;
        dGlub = 0;
        Kurs = 0;
        Diff = 0;
        Kren = 0;
    }
    double Marsh, dMarsh, Lag, dLag, Glub, dGlub, Kurs, Diff, Kren;
};

class UDPsender : public QObject
{
    Q_OBJECT
public:
    UDPsender(QObject *parent = nullptr);

    FromMatLab getData();

private:
    ToMatLab sendData;
    FromMatLab recData;
    QUdpSocket *send_socket;
    QUdpSocket *rec_socket;

public slots:
    void send(double U1, double U2, double U3, double U4, double U5, double U6);
    void readData();

signals:

};

#endif // UDPSENDER_H
