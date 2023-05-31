#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
QT_CHARTS_USE_NAMESPACE



QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void ispis();


private:
    Ui::Dialog *ui;
    QTimer *timer;
    QLineSeries *series;
    QChart *chart;
    QChartView *chartView;
    QValueAxis *xAxis;
    QValueAxis *yAxis;
};
#endif // DIALOG_H
