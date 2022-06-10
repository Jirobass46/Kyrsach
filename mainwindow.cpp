 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <iostream>
#include <QFileInfo>
#include <QWidget>
#include <QSize>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::F1()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
    "/home",tr("Images (*.png *.xpm *.jpg)"));
    kar.load(fileName);
    scum.load(fileName);
    pros = QImage (scum);
    ui->label->setPixmap(kar);
    ui->label->setMaximumWidth(ui->label->pixmap().width()/2);
    ui->label->setMaximumHeight(ui->label->pixmap().height()/2);
    ui->label->setPixmap(QPixmap::fromImage(pros));
}

void MainWindow::on_pushButton_clicked()
{
    F1();
}


void MainWindow::F2()
{
    QImage scumtemp = scum;
    int X = scum.width()-1;
    int Y = scum.height()-1;
    for (int i = 1; i <X; i++){
        for (int j = 1; j<Y; j++){
          QColor col(pros.pixel(i,j));
          int r = 0;
          int g = 0;
          int b = 0;
              for (int z = -1; z < 2; z++){
                  for (int x = -1; x < 2; x++){
                     int w = i + z;
                     int h = j + x;
                     QColor col(pros.pixel(w,h));
                     r = r + col.red();
                     g = g + col.green();
                     b = b + col.blue();

                  }
              }


          r = r/9;
          g = g/9;
          b = b/9;
          col.setRgb(r,g,b,0);
          scumtemp.setPixel(i,j,col.rgb());
    }
  }
    ui->label_2->setPixmap(kar);
    ui->label_2->setMaximumWidth(ui->label_2->pixmap().width()/2);
    ui->label_2->setMaximumHeight(ui->label_2->pixmap().height()/2);
    ui->label_2->setPixmap(QPixmap::fromImage(scumtemp));

}

void MainWindow::on_pushButton_2_clicked()
{
    F2();
}


void MainWindow::on_pushButton_3_clicked()
{
     QString file = QFileDialog::getSaveFileName(this, tr("Save File"),"/Обработанная фотография (3x3)" ,tr("Images(*.png *.jpg *.jpeg)"));
     ui->label_2->pixmap().save(file);
}



void MainWindow::F3()
{
    QImage scumtemp = scum;
    int X = scum.width()-2;
    int Y = scum.height()-2;
    for (int i = 2; i <X; i++){
        for (int j = 2; j<Y; j++){
                QColor col(pros.pixel(i,j));
                int r = 0;
                int g = 0;
                int b = 0;
                  for (int z = -2; z < 2; z++){
                      for (int x = -2; x < 2; x++){
                         int w = i + z;
                         int h = j + x;
                         QColor col(pros.pixel(w,h));
                         r = r + col.red();
                         g = g + col.green();
                         b = b + col.blue();



                  }
              }


          r = r/25;
          g = g/25;
          b = b/25;
          col.setRgb(r,g,b,0);
          scumtemp.setPixel(i,j,col.rgb());
    }
  }
    ui->label_3->setPixmap(kar);
    ui->label_3->setMaximumWidth(ui->label_3->pixmap().width()/2);
    ui->label_3->setMaximumHeight(ui->label_3->pixmap().height()/2);
    ui->label_3->setPixmap(QPixmap::fromImage(scumtemp));
}
void MainWindow::on_pushButton_4_clicked()
{
    F3();

}

void MainWindow::on_pushButton_5_clicked()
{
    QString file = QFileDialog::getSaveFileName(this, tr("Save File"),"/Обработанная фотография (5x5)" ,tr("Images(*.png *.jpg *.jpeg)"));
    ui->label_3->pixmap().save(file);
}

