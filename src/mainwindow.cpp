#include <QApplication>
#include "mainwindow.h"

// Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
    setWindowTitle(tr("Menu Bar Example"));
    resize(400, 300);
}

// Destructor
MainWindow::~MainWindow()
{
}

// Method to create the actions
void MainWindow::createActions()
{
    // Create the "About" action, connect its triggered() signal to the about() slot
    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    // Create the "Quit" action with a standard shortcut, connect to the quit() slot
    quitAct = new QAction(tr("&Quit"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Exit the application"));
    connect(quitAct, &QAction::triggered, this, &MainWindow::quit);
}

// Method to create the menus
void MainWindow::createMenus()
{
    // Get the main window's menu bar and add menus
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(quitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}

// Callback to display "about" information
void MainWindow::about()
{
    QMessageBox::about(this, tr("About Menu"),
                       tr("The <b>Qt</b> example demonstrates how to "
                          "use various Qt features."));
}

void MainWindow::quit()
{
    QApplication::quit();
}

