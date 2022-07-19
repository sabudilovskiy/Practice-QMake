#include "MainWindow.h"
#include "AVLWindow.h"
#include "ADDStudentWindow.h"
#include "ListWindow.h"
#include "ListBestController.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QIcon icon("rocket.ico");
    QApplication a(argc, argv);
    List<Student> list_best, list_excellent, list_lexical;
    ListController list_controller_excellent(list_excellent), list_controller_lexical(list_lexical);
    ListBestController list_controller_best(list_best);
    AVLTree<Student> tree_balance, tree_non_balance;
    AVLTreeController tree_controller_balance(tree_balance), tree_controller_non_balance(tree_non_balance);
    StudentController student_controller(list_controller_lexical, list_controller_excellent, list_controller_best, tree_controller_balance, tree_controller_non_balance);
    MainWindow w(student_controller );
    w.show();
    return a.exec();
}
