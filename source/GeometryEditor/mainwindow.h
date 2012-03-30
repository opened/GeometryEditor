#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "my3dwidget.h"
#include <QtGui>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    My3DWidget *myWidget;
    //QMdiArea *mdiArea;
    //QTabWidget *tabWidget;
    My3DWidget *createMdiChild();

public slots:
    void helpAboutQt();
    void fileNew();

protected:
    //! creates actions and configure them
    void createActions();
};

#endif // MAINWINDOW_H
