#ifndef QDKCONTROLER_H
#define QDKCONTROLER_H

#include <QObject>

#include "qdkmain.h"
#include "qdkbase.h"
#include "qdkaddcard.h"

class QdkControler : public QObject
{
    Q_OBJECT
public:
    explicit QdkControler(QObject *parent = 0);
    ~QdkControler();

signals:

public slots:
    void init();

private slots:
    void addCard();

private:

    QdkBase *base;
    QdkMain *wmain;
};

#endif // QDKCONTROLER_H
