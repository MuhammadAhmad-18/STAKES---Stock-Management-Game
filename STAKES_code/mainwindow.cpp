#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPair>
#include <QStringList>
#include <QDebug>
#include <algorithm>
#include <QRandomGenerator>
#include <QFileDialog>
#include <QFile>
#include <QVector>
#include <cstdlib>
#include <ctime>
#include <QTextBrowser>
#include <vector>
#include <map>
#include <string>
#include <QMessageBox>
#include <QGridLayout>
#include <QInputDialog>
#include <QMap>
#include <QDialog>
#include <QLabel>
#include <QComboBox>
#include <QMessageBox>
#include <QDoubleSpinBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTableWidgetItem>



#include"BASIC_VARIABLES.h"
#include"DATA_STAKES.h"
#include"FUNCTION_STAKES.h"
#include"SAVE_LOAD_GAME.h"
#include"ARREST.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



#include"NEXT_DAY_MANAGEMENT.h"
#include"STOCK_MANAGEMENT.h"
#include"CRYPTO_MANAGEMENT.h"
#include"LOAN_MANAGEMENT.h"
#include"REAL_ESTATE_MANAGEMENT.h"
#include"DIPLOMACY_MANAGEMENT.h"
#include"PORTFOLIO.h"
#include"COURT_STATUS.h"
#include"QUIT_RESTART.h"
#include"SAVE_LOAD_BUTTONS.h"






