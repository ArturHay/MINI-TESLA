#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPixmap pixmap("images/Matrix.png");

    QSplashScreen *splash=new QSplashScreen();
    splash->setPixmap(pixmap);
    splash->setWindowOpacity(0.7);
    splash->show();
    QTimer::singleShot(2000,splash,SLOT(close()));
    QTimer::singleShot(2000,&w,SLOT(show()));

    return a.exec();
}
