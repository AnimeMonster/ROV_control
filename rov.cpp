#include "rov.h"

ROV::ROV(QObject *parent) : QObject(parent)
{
    MarshC = 0;
    LagC = 0;
    GlubC = 0;
    KursC = 0;
    DiffC = 0;
    KrenC = 0;
    MarshD = 0;
    LagD = 0;
    GlubD = 0;
    KursD = 0;
    DiffD = 0;
    KrenD = 0;
    dMarsh = 0;
    dGlub = 0;
    dLag = 0;
    Umarsh = 0;
    Ulag = 0;
    Uglub = 0;
    Ukurs = 0;
    Udiff = 0;
    Ukren = 0;
    K1 = 248.2218;
    K21 = 162.2307;
    K2 = 241.399;
    K22 = 610.0882;
    K3 = 249.2269;
    K32 = 650.3518;

}

void ROV::CompU(){
    MarshC = udp.getData().Marsh;
    dMarsh = udp.getData().dMarsh;
    LagC = udp.getData().Lag;
    dLag = udp.getData().dLag;
    GlubC = udp.getData().Glub;
    dGlub = udp.getData().dGlub;

    Umarsh = (MarshD - MarshC) * K1 - (dMarsh * K21);
    Ulag = (LagD - LagC) * K2 - (dLag * K22);
    Uglub = (GlubD - GlubC) * K3 - (dGlub * K32);

    Ukurs = KursD;
    Udiff = DiffD;
    Ukren = KrenD;
    udp.send(Umarsh, Ulag, Uglub, Ukurs, Udiff, Ukren);
}

void ROV::setKursD(int v){
    KursD = v;
}

void ROV::setMarshD(int v){
    MarshD = v;
}

void ROV::setLagD(int v){
    LagD = v;
}

void ROV::setGlubD(int v){
    GlubD = v;
}

void ROV::setDiffD(int v){
    DiffD = v;
}

void ROV::setKrenD(int v){
    KrenD = v;
}

double ROV::getKursC(){
    double v = udp.getData().Kurs;
    return v;
}

double ROV::getMarshC(){
    double v = udp.getData().Marsh;
    return v;
}

double ROV::getLagC(){
    double v = udp.getData().Lag;
    return v;
}

double ROV::getGlubC(){
    double v = udp.getData().Glub;
    return v;
}

double ROV::getDiffC(){
    double v = udp.getData().Diff;
    return v;
}

double ROV::getKrenC(){
    double v = udp.getData().Kren;
    return v;
}

double ROV::getdMarsh(){
    double v = udp.getData().dMarsh;
    return v;
}

double ROV::getdLag(){
    double v = udp.getData().dLag;
    return v;
}

double ROV::getdGlub(){
    double v = udp.getData().dGlub;
    return v;
}
