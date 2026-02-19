#pragma once

#include <QMainWindow>

class QMenuBar;
class QStatusBar;
class QToolBar;

class MainWindow
	: public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

private:
	QMenuBar* menuBar_ = nullptr;
	void createMenuBar();

	QToolBar* toolBar_ = nullptr;
	void createToolBar();

	QStatusBar* statusBar_ = nullptr;
	void createStatusBar();
};
