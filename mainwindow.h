#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QTimer>
#include <QRandomGenerator>
#include <QLabel>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QProgressBar *tempBar;
    QProgressBar *speedBar;
    QProgressBar *voltageBar;
    QPushButton *startButton;

    QTimer *updateTimer;
    void updateSensorValues();

    int tempThreshold = 75;
    int speedThreshold = 150;
    int voltageThreshold = 12;

    QLabel *alertLabel;


};
#endif // MAINWINDOW_H
