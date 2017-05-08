#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(480, 240);
    ui->label->setText("Welcome. Enter location to input file");
    film = 0;
    this->setWindowTitle("Filmsort v1.0");

}

MainWindow::~MainWindow()
{
    delete ui;
    delete film;
}

void MainWindow::slot1()
{
    QApplication::aboutQt();
}

void MainWindow::slot2(QString adr)
{
    inputAdr = adr.toStdString();
}

void MainWindow::slot3()
{
    bool containsTxt = false;
    for (int i = 0; i < inputAdr.size(); i++)
    {
        if (inputAdr[i] == '.') {
            if (i+3 > inputAdr.size())
                break;
            if (inputAdr[i+1] == 't' && inputAdr[i+2] == 'x' && inputAdr[i+3] == 't') {
                containsTxt = true;
                break;
             }
        } else
            continue;
    }

    if (containsTxt == true) {
        if (film == 0)
            film = new Filmsort();
        else {
            delete film;
            film = new Filmsort;
        }
        film->takeInputAndProcess(inputAdr.c_str());
        ui->label->setText("Processed! Now enter output location and click 'Write'");
    } else {
        ui->label->setText("Please enter a correct adress!");
    }
}

void MainWindow::slot4(QString adr)
{
    outputAdr = adr.toStdString();
}

void MainWindow::slot5()
{
    if (film == 0) {
        ui->label->setText("First process a file!");
        return;
    }

    bool containsTxt = false;
    for (int i = 0; i < outputAdr.size(); i++)
    {
        if (outputAdr[i] == '.') {
            if (i+3 > outputAdr.size())
                break;
            if (outputAdr[i+1] == 't' && outputAdr[i+2] == 'x' && outputAdr[i+3] == 't') {
                containsTxt = true;
                break;
             }
        } else
            continue;
    }

    if (containsTxt == false)
        ui->label->setText("Please enter a correct location on harddrive!");

    if (containsTxt == true) {
        film->takeOutputAndWrite(outputAdr.c_str());
        ui->label->setText("File written.");
        //delete film;    // release memory when work is done // skip this, use clear cache instead
    }
}

void MainWindow::slot6()
{
    delete film;
    film = 0;
    ui->label->setText("Cache cleared.");
}

