#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("3D Geometry Editor");
    showMaximized();
    setWindowIcon(QIcon(":/media/icons/3d.jpg"));
    ui->statusBar->showMessage("Ready",3000);

    /*
    mdiArea = new QMdiArea();
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setViewMode(QMdiArea::TabbedView);
    setCentralWidget(mdiArea);
    */

    // creating actions
    createActions();

    myWidget = new My3DWidget();
    setCentralWidget(myWidget);
}

MainWindow::~MainWindow()
{
    delete myWidget;
    delete ui;
}

void MainWindow::helpAboutQt()
{
    QMessageBox::aboutQt(this,"About Qt");
}

void MainWindow::createActions()
{
    connect(ui->actionAbout_Qt,SIGNAL(triggered()),this,SLOT(helpAboutQt()));
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(fileNew()));
}

void MainWindow::fileNew()
{
    //My3DWidget *child = createMdiChild();
    //child->show();
}

My3DWidget *MainWindow::createMdiChild()
{
    My3DWidget *child = new My3DWidget();
    mdiArea->addSubWindow(child);
    //tabWidget->addTab(child,"Unname");
    return child;
}
