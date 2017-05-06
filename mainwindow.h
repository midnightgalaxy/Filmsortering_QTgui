#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "filmsort.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slot1();             // actionAbout  (actionQuit uses MainWindow::close() )
    void slot2(QString);      // inputAdr
    void slot3();             // takeInputAndProcess
    void slot4(QString);      // outputAdr
    void slot5();             // takeOutputAndWrite
    void slot6();             // clear cache


private:
    Ui::MainWindow *ui;
    Filmsort * film;
    std::string inputAdr;
    std::string outputAdr;
};

#endif // MAINWINDOW_H
