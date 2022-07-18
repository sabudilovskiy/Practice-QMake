#include "StudentController.h"

StudentController::StudentController(ListController &list_lexical, ListController &list_excellent,
                                     ListController &list_max, AVLTreeController &tree_balance,
                                     AVLTreeController &tree_non_balance) : list_lexical(list_lexical),
                                                                            list_excellent(list_excellent),
                                                                            list_best(list_max),
                                                                            tree_balance(tree_balance),
                                                                            tree_non_balance(tree_non_balance) {}

bool lexical(const Student& from_list, const Student& added){
    return std::lexicographical_compare(from_list.get_FIO().begin(),  from_list.get_FIO().end(), added.get_FIO().begin(),  added.get_FIO().end());
}

bool check_5 (const Student& student){
    auto& arr = student.get_arr();
    return std::find(arr.begin(),  arr.end(), 5)  != arr.end();
};

bool check_non_5_from_list(const Student& from_list, const Student& added) {
    return !check_5(from_list);
}

void StudentController::add(const Student &student) {
    tree_balance.add(student);
    tree_non_balance.add(student, false);
    list_lexical.put_after(student, lexical);
    if (check_5(student)){
        list_excellent.put_begin(student);
    }
    else list_excellent.put_before(student, check_non_5_from_list);
    list_best.put_after(student, lexical);
}

void StudentController::clear(){
    list_lexical.clear();
    list_excellent.clear();
    list_best.clear();
    tree_balance.clear();
    tree_non_balance.clear();
}

ListController &StudentController::get_list_lexical() {
    return list_lexical;
}

ListController &StudentController::get_list_excellent() {
    return list_excellent;
}

ListController &StudentController::get_list_max() {
    return list_best;
}

AVLTreeController &StudentController::get_tree_balance() {
    return tree_balance;
}

AVLTreeController &StudentController::get_tree_non_balance() {
    return tree_non_balance;
}

StudentController::StudentController(const StudentController &another): tree_balance(another.tree_balance), tree_non_balance(tree_non_balance),
list_lexical(list_lexical), list_excellent(list_excellent), list_best(list_best){

}
