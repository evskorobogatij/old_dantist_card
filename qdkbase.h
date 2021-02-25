#ifndef QDKBASE_H
#define QDKBASE_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QtSql/QSqlError>
#include <QtWidgets/QMessageBox>


#include <iostream>

#include "qdkadding.h"

class QdkBase : public QObject
{
    Q_OBJECT
public:
    explicit QdkBase(QObject *parent = 0);
    ~QdkBase();

signals:
    void sendModel(QSqlQueryModel *);
public slots:
    void connect();
    void getData(QString filter);
    void addCard(QdkCard card);
private:
    QSqlDatabase db;

    QSqlQueryModel *model;
    QSqlQuery *query;

    QString old_find;
};

#endif // QDKBASE_H
