#include "qdkmain.h"
#include "ui_qdkmain.h"

QdkMain::QdkMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QdkMain)
{
    ui->setupUi(this);

    QObject::connect(ui->eFind,&QLineEdit::textChanged,this,&QdkMain::find);

    QObject::connect(ui->btnAdd,&QPushButton::clicked,this,&QdkMain::addCard);

}

void QdkMain::setModel(QSqlQueryModel *model){
    ui->view->setModel(model);
    ui->view->setItemDelegateForColumn(2,new mDelegate());
    ui->view->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

    //ui->view->horizontalHeader()->ser
}

void QdkMain::show(){

    ui->view->horizontalHeader()->resizeSection(0,60);
    ui->view->horizontalHeader()->resizeSection(1,200);
    ui->view->horizontalHeader()->resizeSection(3,150);
    ui->view->horizontalHeader()->resizeSection(4,160);

    QWidget::show();
}

QdkMain::~QdkMain()
{
    delete ui;
}
