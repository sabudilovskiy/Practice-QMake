#include "AVLTreeController.h"


AVLTreeController::AVLTreeController(AVLTree<Student> &avl_tree, QObject *parent): QObject{parent}, tree(avl_tree)
{

}



void AVLTreeController::add(Student &&student, bool need_balance){
    tree.add(std::move(student), need_balance);
    emit change_tree();
}

void AVLTreeController::add(const Student &student, bool need_balance){
    tree.add(student, need_balance);
    emit change_tree();
}

void AVLTreeController::clear(){
    tree.clear();
    emit clear_tree();
}
