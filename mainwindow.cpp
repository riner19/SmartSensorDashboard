#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Connect progress bars using object names from Qt Designer
    tempBar = ui->progressBarTemp;
    speedBar = ui->progressBarSpeed;
    voltageBar = ui->progressBarVoltage;
    startButton = ui->pushButtonStart; // if you renamed it

    // Set ranges
    tempBar->setRange(0, 100);      // Temperature in °C
    speedBar->setRange(0, 200);     // Speed in km/h
    voltageBar->setRange(0, 15);    // Voltage in V

    // Optional: Set initial values
    tempBar->setValue(0);
    speedBar->setValue(0);
    voltageBar->setValue(0);

    // Create and start the timer
    updateTimer = new QTimer(this);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateSensorValues);
    updateTimer->start(1000); // Update every 1000 ms (1 second)

    alertLabel = new QLabel(this);
    alertLabel->setText("");
    ui->verticalLayout->addWidget(alertLabel); // Add to layout
}


void MainWindow::updateSensorValues() {
    int temp = QRandomGenerator::global()->bounded(0, 101);
    int speed = QRandomGenerator::global()->bounded(0, 201);
    int voltage = QRandomGenerator::global()->bounded(0, 16);

    tempBar->setValue(temp);
    speedBar->setValue(speed);
    voltageBar->setValue(voltage);

    QString alertText = "";

    if (temp > tempThreshold) alertText += "⚠️ High Temperature!\n";
    if (speed > speedThreshold) alertText += "⚠️ High Speed!\n";
    if (voltage > voltageThreshold) alertText += "⚠️ High Voltage!\n";

    alertLabel->setText(alertText);
    alertLabel->setStyleSheet("color: red; font-weight: bold;");
}


MainWindow::~MainWindow()
{
    delete ui;
}
