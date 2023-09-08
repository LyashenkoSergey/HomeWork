#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->buttonU_L,SIGNAL(clicked()),this,SLOT(turn(bool flag, QPushbutton* btn)));
    connect(ui->buttonU_C,SIGNAL(clicked()),this,SLOT(turn(flag)));
    connect(ui->buttonU_R,SIGNAL(clicked()),this,SLOT(turn(flag)));
    connect(ui->buttonM_L,SIGNAL(clicked()),this,SLOT(turn(flag)));
    connect(ui->buttonM_C,SIGNAL(clicked()),this,SLOT(turn(flag)));
    connect(ui->buttonM_R,SIGNAL(clicked()),this,SLOT(turn(flag)));
    connect(ui->buttonD_L,SIGNAL(clicked()),this,SLOT(turn(flag)));
    connect(ui->buttonD_C,SIGNAL(clicked()),this,SLOT(turn(flag)));
    connect(ui->buttonD_R,SIGNAL(clicked()),this,SLOT(turn(flag)));
}

MainWindow::~MainWindow()
{
    if (firstTurn()){
        ui->turn->setText("Player's 1 turn (X)");
        flag=true;
    }
    else
        ui->turn->setText("Player's 2 turn (0)");
    delete ui;
}

void MainWindow::turn(bool flag)
{
    if(isEmpty()){
        if(flag==true){
        flag=false;
        ui->buttonU_L->setText("X");

        }
        else{
            flag=true;
            ui->buttonU_L->setText("0");
        }
    }
}

bool MainWindow::isEmpty()
{
    QPushButton* btn=qobject_cast<QPushButton*>(sender());
    if(btn && btn->text()==""){
        return true;
    }
    else return false;

}

bool MainWindow::firstTurn()
{
     srand(time(NULL));
     if (rand() % 2){
        flag=true;
     }
     else {
        flag= false;
     }
     return flag;
}

