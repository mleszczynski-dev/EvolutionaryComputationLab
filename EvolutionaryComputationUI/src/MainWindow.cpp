#include "MainWindow.h"

#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget* parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	createMenuBar();
	createToolBar();
	createStatusBar();

	setMinimumSize(800, 600);
}

void MainWindow::createMenuBar()
{
	menuBar_ = new QMenuBar;
	setMenuBar(menuBar_);

	auto fileMenu = menuBar()->addMenu(tr("&File"));
	//fileMenu->addAction(newAct)
	auto helpMenu = menuBar()->addMenu(tr("&Help"));
}

void MainWindow::createToolBar()
{
	toolBar_ = new QToolBar("");
	addToolBar(toolBar_);

	QAction* actionOpen = new QAction(QIcon(":/icons/open.png"), "Computing nodes", this);
	toolBar_->addAction(actionOpen);
	toolBar_->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

void MainWindow::createStatusBar()
{
	statusBar_ = new QStatusBar;
	setStatusBar(statusBar_);
}