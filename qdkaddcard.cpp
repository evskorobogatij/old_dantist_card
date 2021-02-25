#include "qdkaddcard.h"
#include "ui_qdkaddcard.h"

QdkAddCard::QdkAddCard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QdkAddCard)
{
    ui->setupUi(this);

    ui->buttonBox->button(QDialogButtonBox::Apply)->setText("Сохранить");
    ui->buttonBox->button(QDialogButtonBox::Apply)->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Отмена");

    QObject::connect(ui->buttonBox,&QDialogButtonBox::clicked,this,&QdkAddCard::clicked);
    QObject::connect(ui->eFio,&QLineEdit::textChanged,this,&QdkAddCard::fioChanged);

}

void QdkAddCard::fioChanged(QString text){
    ui->buttonBox->button(QDialogButtonBox::Apply)->setEnabled(text.simplified()!="");

}

void QdkAddCard::clicked(QAbstractButton *button){

    if (button==ui->buttonBox->button(QDialogButtonBox::Apply)) {
        qDebug("save card");
        QdkCard card;
        card.fam = ui->eFio->text();
        card.im = ui->eIm->text();
        card.ot = ui->eOt->text();
        card.birth_day = ui->eBirthDay->date();
        card.work = ui->eWork->text();
        card.adr = ui->eAdr->text();
        card.num = ui->eNum->value();

        emit addCard(card);
    }
    this->close();

}

QdkAddCard::~QdkAddCard()
{
    delete ui;
}
