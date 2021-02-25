#ifndef QDKADDCARD_H
#define QDKADDCARD_H

#include <QDialog>
#include <QtWidgets/QPushButton>

#include "qdkadding.h"

namespace Ui {
class QdkAddCard;
}

class QdkAddCard : public QDialog
{
    Q_OBJECT

public:
    explicit QdkAddCard(QWidget *parent = 0);
    ~QdkAddCard();

private slots:
    void clicked(QAbstractButton * button);
    void fioChanged(QString text);
signals:
    void addCard(QdkCard );
private:
    Ui::QdkAddCard *ui;
};

#endif // QDKADDCARD_H
