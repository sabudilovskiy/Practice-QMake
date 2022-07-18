#ifndef AVL_H
#define AVL_H

#include <QWidget>
#include "AVLTree.h"
#include "Student.h"
#include "AVLTreeController.h"
namespace Ui {
class AVLWindow;
}

class AVLWindow : public QWidget
{
    Q_OBJECT
    const AVLTreeController& tree;
    Ui::AVLWindow *ui;
public:
    explicit AVLWindow(const QString& name, const AVLTreeController& controller, QWidget *parent = nullptr);
    explicit AVLWindow(QString&& name, const AVLTreeController& controller, QWidget *parent = nullptr);
    ~AVLWindow();
    public slots:
    void change_tree();
    void clear_tree();
};



#endif // AVL_H
