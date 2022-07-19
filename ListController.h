//
// Created by MRV on 7/12/2022.
//

#ifndef PRACTICEGORBENKO_LISTCONTROLLER_H
#define PRACTICEGORBENKO_LISTCONTROLLER_H

#include <utility>
#include <QObject>
#include "List.h"
#include "Student.h"
class ListController : public QObject{
protected:
    Q_OBJECT
protected:
    List<Student>& list;
public:
    ListController(List<Student> &list);
    virtual void put_begin(const Student& student);
    virtual void put_before(const Student& student, std::function<bool(const Student& from_list, const Student& added)> pred);
    virtual void put_after(const Student& student, std::function<bool(const Student& from_list, const Student& added)> pred);
    List<Student>::Iterator<Student> begin();
    List<Student>::Iterator<Student> end();
    virtual void clear();
    signals:
    void added_elem();
    void clear_list();
};


#endif //PRACTICEGORBENKO_LISTCONTROLLER_H
