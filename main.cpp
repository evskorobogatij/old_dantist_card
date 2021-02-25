#include <QApplication>
#include <QtCore/QTextCodec>
#include <QtWidgets/QStyleFactory>
#include <QtCore/QDate>
#include "qdkcontroler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setStyle(QStyleFactory::create("Fusion"));

    qDebug(qPrintable(QDate::currentDate().toString(Qt::DefaultLocaleShortDate) ));

    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    //QTextCodec::setCodecForLocale()

    QdkControler *controler = new QdkControler();
    controler->init();

    return a.exec();
}
