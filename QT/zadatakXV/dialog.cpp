#include "dialog.h"
#include "ui_dialog.h"

int i=1;
int k;
float napon=0;


//sudo apt install libqt5charts5-dev

void read_sensors(){
    const char PCF8591 = 0x48;
    int fd;

    if (wiringPiSetup () == -1) exit (1);
    fd = wiringPiI2CSetup(PCF8591);

    napon= wiringPiI2CReadReg8(fd, PCF8591 + 3);
}



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //kreiranje podataka za prikaz
     series = new QLineSeries();
     series->append(0, 0);



     // pravljenje grafika
     chart = new QChart();
     chart->legend()->hide();
     chart->addSeries(series);
     chart->setTitle("Mjerenje napona");
     //chart->createDefaultAxes();



     // pravljenje X i Y osa
     xAxis = new QValueAxis();
     yAxis = new QValueAxis();


     // opseg za X i Y osu
     xAxis->setRange(0, 5);
     yAxis->setRange(0, 4);


     // stavljanje osa na grafik
     chart->addAxis(xAxis, Qt::AlignBottom);
     chart->addAxis(yAxis, Qt::AlignLeft);
     series->attachAxis(xAxis);
     series->attachAxis(yAxis);

     // ispis grafika
     chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     chartView->setParent(ui->horizontalFrame);


     timer=new QTimer(this);
     connect(timer, &QTimer::timeout, this, &Dialog::ispis);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{
    timer->stop();
    series->clear();
    i=1;
}


void Dialog::on_pushButton_2_clicked()
{
    timer->start(1000);
    series->append(0,0);
}



void Dialog::ispis()
{
    i++;
    read_sensors();
    napon=napon*3.3/255;

    if (i>5) {
        i=0;
        series->clear();
    }

    series->append(i,napon);
}




