#include "dialog.h"
#include "ui_dialog.h"

int integer, decimal;


long citaj_temp() {

    int fd = -1, ret;
    char *tmp1, tmp2[10], ch='t';
    char devname_head[50] = "/sys/devices/w1_bus_master1/28-00000";  // =====>     DODAJ TU BROJ NA KRAJU !!!

    char devname_end[10] = "/w1_slave";
    char dev_name[100];
    long value;
    char buffer[100];


    strcpy(dev_name, devname_head);
    strcat(dev_name, devname_end);

    if ((fd = open(dev_name, O_RDONLY)) < 0)
        {
        perror("Greška pri otvaranju!");
        exit(1);
        }

        ret = read(fd, buffer, sizeof(buffer));

        if (ret < 0)
        {
        perror("Greška pri čitanju!");
        exit(1);
        }

        tmp1 = strchr(buffer, ch);
        sscanf(tmp1, "t=%s", tmp2);
        value = atoi(tmp2);

        close(fd);

return value;
}



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    timer=new QTimer(this);
    connect (timer, SIGNAL(timeout()), this,SLOT(ispis_broja()));
    timer->setInterval(1000);
    timer->start();
}



Dialog::~Dialog()
{
    delete ui;
}



void Dialog::ispis_broja()
{
    integer = citaj_temp() / 1000;
    decimal = citaj_temp() % 1000;
    broj="%1.%2";

    ui->lcdNumber->display(broj.arg(integer).arg(decimal));
}














