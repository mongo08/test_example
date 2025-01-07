#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->transmission = new Transmission();
    QObject::connect(transmission, &Transmission::send_data, this, &MainWindow::paintGraphics);
    QGridLayout *gridLayout = ui->tab_graphics->findChild<QGridLayout *>("gridLayout");
    QGridLayout *gridPlayer= ui->tab_videos->findChild<QGridLayout *>("gridLayout_video");
    QMediaPlayer *watch=new QMediaPlayer();
    QVideoWidget *video=new QVideoWidget();
    watch->setVideoOutput(video);
    watch->setMedia(QUrl("gst-pipeline: udpsrc  port=5000 ! application/x-rtp,encoding-name=JPEG,payload=26 ! rtpjpegdepay ! jpegdec ! ximagesink name=\"qtvideosink\""));
    watch->play();
    gridPlayer->addWidget(video,0,0);
    video->show();
    int j = 0;
    for (int i = 0; i < 16; i++)
    {
        QChartView *charview = new QChartView(this);
        if (i < 8)
        {
            gridLayout->addWidget(charview, 0, i);
        }
        else
        {
            gridLayout->addWidget(charview, 1, j);
            j++;
        }
        QChart *chart = new QChart();
        QLineSeries *series = new QLineSeries();
        chart->addSeries(series);
        chart->legend()->hide();
        chart->createDefaultAxes();
        chart->axes(Qt::Vertical).first()->setRange(0, 10);
        chart->axes(Qt::Horizontal).first()->setRange(0, 10);
        this->listSeries.push_back(series);
        charview->setChart(chart);
    }
}

void MainWindow::paintGraphics(int get_x_val, int get_y_val)
{
    for (QLineSeries *series : this->listSeries){
        series->append(get_x_val,get_y_val);
    }
    if (this->counter_point == 100)
    {
        for (QLineSeries *series : this->listSeries)
            series->clear();
        this->counter_point=0;
    }
    this->counter_point++;
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
