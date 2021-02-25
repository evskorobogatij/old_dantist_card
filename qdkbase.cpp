#include "qdkbase.h"

QdkBase::QdkBase(QObject *parent) : QObject(parent)
{
    old_find = "";

}

void QdkBase::connect(){
    db = QSqlDatabase::addDatabase("QSQLITE","dantist");
    db.setDatabaseName("dantist.db");
    if (!db.open()) {
        QMessageBox::warning(0,"",db.lastError().text(),QMessageBox::Close);
        return ;
    }



    query = new QSqlQuery(db);
    model = new QSqlQueryModel();
    model->setHeaderData(0,Qt::Horizontal,"Number");

    query->exec("SELECT icu_load_collation('ru_RU', 'RUSSIAN')" );

    emit sendModel(model);
}

void QdkBase::getData(QString filter){
    old_find = filter;
    QString str = "SELECT num, upper(fam) || \' \' || im || \' \' || ot as fio, birthday,  adr, work FROM adrbook "
                  " where (fam) like :fam "
                  "order by fam,im,ot";

    QString tmp;
    filter = filter.simplified();
    if (filter.length()>1) {
        QString f1 = filter.left(1);
        QString f_etc = filter.right(filter.length()-1);
        tmp = f1.toUpper()+f_etc.toLower();
    } else {
        tmp = filter.toUpper();
    }
    query->prepare(str);
    query->bindValue(":fam",QString(tmp+"%").toLocal8Bit());
    //query->addBindValue(filter.simplified()+"%");
    qDebug(filter.toLocal8Bit());
    if(!query->exec()){
        QMapIterator<QString, QVariant> i(query->boundValues());
        while (i.hasNext()) {
                i.next();
                std::cout << i.key().toUtf8().data() << " : "
                     << i.value().toString().toUtf8().data() << std::endl;
        }
        QMessageBox::warning(0,"",query->lastQuery() +"\n"+ query->lastError().text(),QMessageBox::Close);
        return ;
    }

    //QMessageBox::information(0,"",query->lastQuery() +"\n",QMessageBox::Close);
    model->setQuery(*query);
    model->setHeaderData(0,Qt::Horizontal,"№ карты");
    model->setHeaderData(1,Qt::Horizontal,"Ф.И.О.");
    model->setHeaderData(2,Qt::Horizontal,"Дата\nрождения");
    model->setHeaderData(3,Qt::Horizontal,"Адрес");
    model->setHeaderData(4,Qt::Horizontal,"Место работы");

}

void QdkBase::addCard(QdkCard card){

    QString s = "insert into adrbook(num,fam,im,ot,birthday,adr,work) VALUES(:num,:fam,:im,:ot,:birthday,:adr,:work)";
    query->prepare(s);
    query->bindValue(":num",card.num);
    query->bindValue(":fam",card.fam);
    query->bindValue(":im",card.im);
    query->bindValue(":ot",card.ot);
    query->bindValue(":birthday",card.birth_day);
    query->bindValue(":adr",card.adr);
    query->bindValue(":work",card.work);

    if (!query->exec()) {
        QMessageBox::warning(0,"",query->lastError().text());
    }

    getData(old_find);

}

QdkBase::~QdkBase()
{

}

