#include "AVLWindow.h"
#include <QObject>
#include "ui_AVLWindow.h"


AVLWindow::AVLWindow(const QString& name, const AVLTreeController& controller, QWidget *parent) :
        QWidget(parent),
        tree(controller), ui(new Ui::AVLWindow)
{
    ui->setupUi(this);
    ui->label->setText(name);
    this->setWindowTitle(name);
    QObject::connect(&tree, SIGNAL(change_tree()), this, SLOT(change_tree()));
    QObject::connect(&tree, SIGNAL(clear_tree()), this, SLOT(clear_tree()));
}

AVLWindow::AVLWindow(QString &&name, const AVLTreeController &controller, QWidget *parent) :
    QWidget(parent),
    tree(controller), ui(new Ui::AVLWindow)
{
    ui->setupUi(this);
    ui->label->setText(name);
    this->setWindowTitle(name);
    QObject::connect(&tree, SIGNAL(change_tree()), this, SLOT(change_tree()));
    QObject::connect(&tree, SIGNAL(clear_tree()), this, SLOT(clear_tree()));
}

AVLWindow::~AVLWindow()
{
    delete ui;
}

void AVLWindow::change_tree(){
    auto node = tree.get_root();
    if (node) ui->label_1_1->setText(node->key.to_qstring());
    else ui->label_1_1->setText("Пустой узел");
    if (node->left){
        ui->label_2_1->setText(node->left->key.to_qstring());
        if (node->left->left){
            ui->label_3_1->setText(node->left->left->key.to_qstring());
        }
        else ui->label_3_1->setText("Пустой узел");
        if (node->left->right){
            ui->label_3_2->setText(node->left->right->key.to_qstring());
        }
        else ui->label_3_2->setText("Пустой узел");
    }
    else ui->label_2_1->setText("Пустой узел");
    if (node->right){
        ui->label_2_2->setText(node->right->key.to_qstring());
        if (node->right->left){
            ui->label_3_3->setText(node->right->left->key.to_qstring());
        }
        else ui->label_3_3->setText("Пустой узел");
        if (node->right->right){
            ui->label_3_4->setText(node->right->right->key.to_qstring());
        }
        else ui->label_3_4->setText("Пустой узел");
    }
    else ui->label_2_2->setText("Пустой узел");
}

void AVLWindow::clear_tree()
{
    ui->label_1_1->setText("Пустой узел");
    ui->label_2_1->setText("Пустой узел");
    ui->label_2_2->setText("Пустой узел");
    ui->label_3_1->setText("Пустой узел");
    ui->label_3_2->setText("Пустой узел");
    ui->label_3_3->setText("Пустой узел");
    ui->label_3_4->setText("Пустой узел");
}
