#include "ListWindow.h"
#include "ui_ListWindow.h"

ListWindow::ListWindow(QString name, ListController& list_controller, QWidget *parent) :
    QWidget(parent),
    list_controller(list_controller),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(name);
    QObject::connect(&list_controller, SIGNAL(added_elem()), this, SLOT(added_elem()));
    QObject::connect(&list_controller, SIGNAL(clear_list()), this, SLOT(clear()));
}

ListWindow::~ListWindow()
{
    delete ui;
}

void ListWindow::added_elem()
{
    ui->listWidget->clear();
    auto it = list_controller.begin(), end = list_controller.end();
    while (it!=end){
       ui->listWidget->addItem(it->to_qstring());
       it++;
    }
}

void ListWindow::clear()
{
    ui->listWidget->clear();
}
