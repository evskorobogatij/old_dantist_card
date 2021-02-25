#include "qdkcontroler.h"

QdkControler::QdkControler(QObject *parent) : QObject(parent)
{

}

void QdkControler::init(){
    wmain = new QdkMain();
    base = new QdkBase();

    QObject::connect(base,&QdkBase::sendModel,wmain,&QdkMain::setModel);
    QObject::connect(wmain,&QdkMain::find,base,&QdkBase::getData);

    QObject::connect(wmain,&QdkMain::addCard,this,&QdkControler::addCard);

    base->connect();
    base->getData("");
    wmain->show();


}

void QdkControler::addCard(){
    QdkAddCard *card = new QdkAddCard();
    QObject::connect(card,&QdkAddCard::addCard,base,&QdkBase::addCard);
    int res = card->exec();

    card->deleteLater();
}

QdkControler::~QdkControler()
{

}

