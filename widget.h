#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <math.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>

#include "ui_widget.h"
#include "rov.h"

class Widget : public QWidget, Ui::Widget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    ROV rov;
    QTimer timer;

private:
    int setKurs, setKren, setDiff, setMarsh, setLag, setGlub;

    QGraphicsScene *Kuscene;
    QGraphicsScene *Krscene;
    QGraphicsScene *Dfscene;
    QGraphicsPixmapItem *picArrowKu;
    QGraphicsPixmapItem *picDialKu;
    QGraphicsPixmapItem *picArrowKr;
    QGraphicsPixmapItem *picDialKr;
    QGraphicsPixmapItem *picArrowDf;
    QGraphicsPixmapItem *picDialDf;

public slots:
    void tick();

    void KursChange(int);
    void KrenChange(int);
    void DiffChange(int);
    void StopAll();
    void MarshChange(int);
    void LagChange(int);
    void GlubChange(int);

    void StartTimer();
    void StopTimer();
    void setKursD();
    void setMarshD();
    void setLagD();
    void setGlubD();
    void setDiffD();
    void setKrenD();

};
#endif // WIDGET_H
