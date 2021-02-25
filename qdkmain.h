#ifndef QDKMAIN_H
#define QDKMAIN_H

#include <QWidget>
#include <QtSql/QSqlQueryModel>
#include <QtCore/QDateTime>
#include <QtWidgets/QStyledItemDelegate>

namespace Ui {
class QdkMain;
}

class QdkMain : public QWidget
{
    Q_OBJECT

public:
    explicit QdkMain(QWidget *parent = 0);
    ~QdkMain();
public slots:
    void setModel(QSqlQueryModel *model);
    void show();
private slots:

signals:
    void find(QString );
    void addCard();
private:
    Ui::QdkMain *ui;
};

class mDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    mDelegate(QWidget *parent=0):QStyledItemDelegate(parent){}

    QString displayText(const QVariant &value, const QLocale &locale) const{
        return value.toDateTime().toString("dd.MM.yyyy");
    }
};

#endif // QDKMAIN_H
