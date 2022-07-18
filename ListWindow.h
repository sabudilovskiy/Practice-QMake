#ifndef LISTWINDOW_H
#define LISTWINDOW_H

#include <QWidget>
#include "ListController.h"
namespace Ui {
class ListWindow;
}

class ListWindow : public QWidget
{
    Q_OBJECT
    ListController& list_controller;
public:
    explicit ListWindow(QString name, ListController& list_controller, QWidget *parent = nullptr);
    ~ListWindow();
protected slots:
    void added_elem();
    void clear();
private:
    Ui::ListWindow *ui;
};

#endif // LISTWINDOW_H
