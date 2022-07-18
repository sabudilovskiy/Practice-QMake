#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H
#include "ListController.h"
#include "ListBestController.h"
#include "AVLTreeController.h"
class StudentController
{
protected:
    ListController& list_lexical, & list_excellent, &list_best;
    AVLTreeController& tree_balance, &tree_non_balance;
public:
    StudentController(ListController &list_lexical, ListController &list_excellent, ListController &list_max,
                      AVLTreeController &tree_balance, AVLTreeController &tree_non_balance);
    StudentController(const StudentController& another);
    void add(const Student& student);
    void clear();
    ListController &get_list_lexical();

    ListController &get_list_excellent();

    ListController &get_list_max();

    AVLTreeController &get_tree_balance();

    AVLTreeController &get_tree_non_balance();
};

#endif // STUDENTCONTROLLER_H
