#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Submit_pressed()
{
    static bool won = false;
    static int right = 0;
    static int wrong = 0;
    if (!won)
    {
        int answer = ui->Num1->text().toInt() + ui->Num2->text().toInt();
        if (answer == ui->UserAnswer->text().toInt())
        {
            right++;
            ui->Confirmation->setText("Correct");
            ui->Num1->setText(QString::number(qrand()%10));
            ui->Num2->setText(QString::number(qrand()%10));
            ui->UserAnswer->setText("");
            ui->Correct->setText("Correct: " + QString::number(right));
        }
        else
        {
            wrong++;
            ui->Confirmation->setText("Incorrect");
            ui->Incorrect->setText("Incorrect: " + QString::number(wrong));
        }
        if (right == 3)
        {
            ui->Confirmation->setText("Completed!");
            won = true;
        }
    }
}
