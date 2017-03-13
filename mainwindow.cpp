#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tpaper.h"
#include "TWordList.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wl = NULL;
    p1 = NULL;
    p2 = NULL;
    ui->openPaper1->setEnabled(false);
    ui->openPaper2->setEnabled(false);
    ui->pushButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete wl;
    delete p1;
    delete p2;
}

void MainWindow::on_actionWords_list_triggered()
{
    QString fName = QFileDialog::getOpenFileName(this, tr("打开词表文件"), " ",  tr("Allfile(*.*);;txtfile(*.txt)"));
    if (fName!="")
    {
        wl = new TWordList(fName.toStdString());
        ui->openPaper1->setEnabled(true);
        ui->openPaper2->setEnabled(true);
    }
}

void MainWindow::on_openPaper1_clicked()
{
    p1 = new TPaper(ui->filename1->text().toStdString(),wl->getNum());
    p1->doc2vec(wl->getNum(),wl->getList());
    ui->title1->setText(QString::fromStdString(p1->getTitle()));
    ui->textEdit1->setText(QString::fromStdString(p1->getPaper()));
    if (p2!=NULL)
        ui->pushButton->setEnabled(true);
}

void MainWindow::on_openPaper2_clicked()
{
    p2 = new TPaper(ui->filename2->text().toStdString(),wl->getNum());
    p2->doc2vec(wl->getNum(),wl->getList());
    ui->title2->setText(QString::fromStdString(p2->getTitle()));
    ui->textEdit2->setText(QString::fromStdString(p2->getPaper()));
    if (p1!=NULL)
        ui->pushButton->setEnabled(true);
}

void MainWindow::on_pushButton_clicked()
{
    int* vect1 = p1->getTitleVec();
    int* vect2 = p2->getTitleVec();
    int* vect3 = p1->getVect();
    int* vect4 = p2->getVect();
    int word_num = wl->getNum();

    double sum_title=0;
    double sum_text=0;
    for (int i=0; i<word_num; i++)
    {
        int d = vect1[i]-vect2[i];
        sum_title += d*d;
        d = vect3[i]-vect4[i];
        sum_text += d*d;
    }

    ui->titleSim->setText(QString::number(sqrt(sum_title)));
    ui->textSim->setText(QString::number(sqrt(sum_text)));

}

