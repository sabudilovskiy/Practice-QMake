//
// Created by MRV on 7/12/2022.
//

#include "ListController.h"

ListController::ListController(List<Student> &list) : list(list) {}

void ListController::put_begin(const Student &student){
    list.put_begin(student);
    emit added_elem();
}

void ListController::put_before(const Student &student, std::function<bool (const Student &, const Student &)> pred){
    list.put_before(student, std::move(pred));
    emit added_elem();
}

void ListController::put_after(const Student &student, std::function<bool (const Student &, const Student &)> pred){
    list.put_after(student, std::move(pred));
    emit added_elem();
}

List<Student>::Iterator<Student> ListController::begin(){
    return list.begin();
}

List<Student>::Iterator<Student> ListController::end(){
    return list.end();
}

void ListController::clear()
{
    list.clear();
    emit clear_list();
}
