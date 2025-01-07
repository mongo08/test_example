#include "view/mainwindow.h"

#include <QtCore/QObject>
#include <QtCore/QCoreApplication>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
