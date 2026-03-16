#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void about();
	void quit();

private:
	void openDbConnectionDialog();
	void createStatusBar();
	void createActions();
	void createMenus();

	QStatusBar *mainStatusBar;
	QMenu *fileMenu;
	QMenu *helpMenu;
	QAction *aboutAct;
	QAction *quitAct;
	QAction *connectAct;
	QDialog *loginDialog;
};

#endif // MAINWINDOW_H

