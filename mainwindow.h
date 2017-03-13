#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TWordList.h"
#include "tpaper.h"

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
//    void on_pushButton_clicked();

    void on_openPaper1_clicked();

    void on_openPaper2_clicked();

    void on_pushButton_clicked();

    void on_actionWords_list_triggered();

private:
    Ui::MainWindow *ui;
    TWordList* wl;
    TPaper * p1, * p2;
//    Tpaper* p2;
};

#endif // MAINWINDOW_H
