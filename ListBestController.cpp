#include "ListBestController.h"


ListBestController::ListBestController(List<Student> &list) : ListController(list) {


}

void ListBestController::put_after(const Student &student, std::function<bool(const Student &, const Student &)> pred) {
    if (max == -1){
        max = student.get_average();
        ListController::put_after(student, pred);
    }
    else if (max == student.get_average()){
        ListController::put_after(student, pred);
    }
    else if (max < student.get_average()) {
        max = student.get_average();
        list.clear();
        ListController::put_after(student, pred);
    }
}

void ListBestController::put_before(const Student &student, std::function<bool(const Student &, const Student &)> pred) {
    if (max == -1){
        max = student.get_average();
        ListController::put_before(student, pred);
    }
    else if (max == student.get_average()){
        ListController::put_before(student, pred);
    }
    else if (max < student.get_average()) {
        max = student.get_average();
        list.clear();
        ListController::put_before(student, pred);
    }
}

void ListBestController::put_begin(const Student &student) {
    if (max == -1){
        max = student.get_average();
        ListController::put_begin(student);
    }
    else if (max == student.get_average()){
        ListController::put_begin(student);
    }
    else if (max < student.get_average()) {
        max = student.get_average();
        ListController::put_begin(student);
    }
}

void ListBestController::clear()
{
    max = -1;
    ListController::clear();
}
