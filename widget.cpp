#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);

    setKurs = 0;
    setKren = 0;
    setDiff = 0;
    setMarsh = 0;
    setLag = 0;
    setGlub = 0;

    Kuscene = new QGraphicsScene (KursView);
    Krscene = new QGraphicsScene (KrenView);
    Dfscene = new QGraphicsScene (DiffView);

    KursView->setScene(Kuscene);
    KrenView->setScene(Krscene);
    DiffView->setScene(Dfscene);

    KursView->setRenderHint(QPainter::Antialiasing);
    KrenView->setRenderHint(QPainter::Antialiasing);
    DiffView->setRenderHint(QPainter::Antialiasing);

    picDialKu = Kuscene->addPixmap(QPixmap(":/images/Shkala.png"));
    picArrowKu = Kuscene->addPixmap(QPixmap(":/images/StrelaR.png"));
    picDialKr = Krscene->addPixmap(QPixmap(":/images/Shkala.png"));
    picArrowKr = Krscene->addPixmap(QPixmap(":/images/StrelaG.png"));
    picDialDf = Dfscene->addPixmap(QPixmap(":/images/Shkala.png"));
    picArrowDf = Dfscene->addPixmap(QPixmap(":/images/StrelaB.png"));

    picArrowKu->setTransformOriginPoint(picArrowKu->pixmap().width()/2,picArrowKu->pixmap().height()/2);
    picArrowKr->setTransformOriginPoint(picArrowKr->pixmap().width()/2,picArrowKr->pixmap().height()/2);
    picArrowDf->setTransformOriginPoint(picArrowDf->pixmap().width()/2,picArrowDf->pixmap().height()/2);

    connect(&timer, SIGNAL(timeout()), SLOT(tick()));

    connect(RecStrBtn, SIGNAL(clicked()), this, SLOT(StartTimer()));
    connect(RecStpBtn, SIGNAL(clicked()), this, SLOT(StopTimer()));

    connect(AddBtn, SIGNAL(clicked()), this, SLOT(setKursD()));
    connect(AddBtn, SIGNAL(clicked()), this, SLOT(setDiffD()));
    connect(AddBtn, SIGNAL(clicked()), this, SLOT(setKrenD()));

    connect(QuitBtn, &QPushButton::clicked, qApp, &QApplication::quit);

    connect(AddBtn, SIGNAL(clicked()), this, SLOT(setMarshD()));
    connect(AddBtn, SIGNAL(clicked()), this, SLOT(setLagD()));
    connect(AddBtn, SIGNAL(clicked()), this, SLOT(setGlubD()));


    connect(MarshSlider, SIGNAL(valueChanged(int)), MarshNum, SLOT(setNum(int)));
    connect(LagSlider, SIGNAL(valueChanged(int)), LagNum, SLOT(setNum(int)));
    connect(GlubSlider, SIGNAL(valueChanged(int)), GlubNum, SLOT(setNum(int)));
    connect(KursDial, SIGNAL(valueChanged(int)), KursNum, SLOT(setNum(int)));
    connect(KrenDial, SIGNAL(valueChanged(int)), KrenNum, SLOT(setNum(int)));
    connect(DiffDial, SIGNAL(valueChanged(int)), DiffNum, SLOT(setNum(int)));

    connect(StopBtn, SIGNAL(clicked()), this, SLOT(StopAll()));
}

void Widget::tick(){
    rov.CompU();

    double Ma = rov.getMarshC();
    MarshNum_2->setNum(Ma);
    double La = rov.getLagC();
    LagNum_2->setNum(La);
    double Gl = rov.getGlubC();
    GlubNum_2->setNum(Gl);

    double dM = rov.getdMarsh();
    dM /= 0.28;
    MarshChange(static_cast<int>(dM));
    double dL = rov.getdLag();
    dL /= 0.28;
    LagChange(static_cast<int>(dL));
    double dG = rov.getdGlub();
    dG /= 0.28;
    GlubChange(static_cast<int>(dG));

    double Ku = rov.getKursC();
    KursChange(static_cast<int>(Ku));
    KursNum_2->setNum(Ku);
    double Di = rov.getDiffC();
    DiffChange(static_cast<int>(Di));
    DiffNum_2->setNum(Di);
    double Kr = rov.getKrenC();
    KrenChange(static_cast<int>(Kr));
    KrenNum_2->setNum(Kr);


}

void Widget::KursChange(int val){
    picArrowKu->setRotation(val);
}

void Widget::KrenChange(int val){
    picArrowKr->setRotation(val);
}

void Widget::DiffChange(int val){
    picArrowDf->setRotation(val);
}

void Widget::StopAll(){

    rov.setMarshD(0);
    rov.setLagD(0);
    rov.setGlubD(0);
    rov.setKursD(0);
    rov.setDiffD(0);
    rov.setKrenD(0);
}

void Widget::MarshChange(int v){
    if (v >= 0){
        MarshBar->setValue(v);
        MarshBarM->setValue(0);
    } else {
        MarshBarM->setValue(-v);
        MarshBar->setValue(0);
    }
}

void Widget::LagChange(int v){
    if (v >= 0){
        LagBar->setValue(v);
        LagBarM->setValue(0);
    } else {
        LagBarM->setValue(-v);
        LagBar->setValue(0);
    }
}

void Widget::GlubChange(int v){
    if (v >= 0){
        GlubBar->setValue(v);
        GlubBarM->setValue(0);
    } else {
        GlubBarM->setValue(-v);
        GlubBar->setValue(0);
    }
}

void Widget::StartTimer(){
    timer.start(10);
}

void Widget::StopTimer(){
    timer.stop();
    qDebug()<<"stop";
}

void Widget::setMarshD(){
    int v = MarshSlider->value();
    setMarsh += v;
    rov.setMarshD(setMarsh);
}

void Widget::setLagD(){
    int v = LagSlider->value();
    setLag += v;
    rov.setLagD(setLag);
}

void Widget::setGlubD(){
    int v = GlubSlider->value();
    setGlub += v;
    rov.setGlubD(setGlub);
}

void Widget::setKursD(){
    int v = KursDial->value();
    setKurs += v;
    if (setKurs > 360)
        setKurs -= 360;
    if (setKurs < 0)
        setKurs += 360;
    rov.setKursD(setKurs);
}

void Widget::setDiffD(){
    int v = DiffDial->value();
    setDiff += v;
    if (setDiff > 360)
        setDiff -= 360;
    if (setDiff < 0)
        setDiff += 360;
    rov.setDiffD(setDiff);
}

void Widget::setKrenD(){
    int v = KrenDial->value();
    setKren += v;
    if (setKren > 360)
        setKren -= 360;
    if (setKren < 0)
        setKren += 360;
    rov.setKrenD(setKren);
}

Widget::~Widget()
{}

