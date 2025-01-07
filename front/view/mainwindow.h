#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <QChart>
#include <QChartView>
#include <QGridLayout>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QtCore/QObject>
#include <QtCore/QDebug>

#include <math.h>
#include <vector>

#include "../controller/transmission_data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace QtCharts;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private Q_SLOTS:
    void paintGraphics(int get_x_val,int get_y_val);

private:
    Ui::MainWindow *ui;
    Transmission *transmission{};
    std::vector< QLineSeries*> listSeries;
    QValueAxis *x_axis{},*y_axis{};
    int counter_point=0;
};
#endif // MAINWINDOW_H
