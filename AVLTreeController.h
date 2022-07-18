#ifndef AVLTREEMANIPULATOR_H
#define AVLTREEMANIPULATOR_H

#include <QObject>
#include <vector>
#include <Student.h>
#include "AVLTree.h"
class AVLTreeController : public QObject
{
    Q_OBJECT
    AVLTree<Student>& tree;
public:
    explicit AVLTreeController(AVLTree<Student>& avl_tree, QObject *parent = nullptr);
    auto get_root() const{
        return tree.get_root();
    }
    void add(Student&& student, bool need_balance = true);
    void add(const Student& student, bool need_balance = true);
    void clear();
signals:
   void change_tree();
   void clear_tree();
};

#endif // AVLTREEMANIPULATOR_H
