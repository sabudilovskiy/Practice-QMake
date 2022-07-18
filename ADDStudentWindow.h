#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include "StudentController.h"
#include <QWidget>
#include <qspinbox.h>

namespace Ui {
class ADDStudentWindow;
}

class ADDStudentWindow : public QWidget
{
    Q_OBJECT
protected:
    StudentController& student_controller;
    Ui::ADDStudentWindow *ui;
    std::vector<QSpinBox*> marks_spin_boxes;
public:
    explicit ADDStudentWindow(StudentController& student_controller, QWidget *parent = nullptr);
    ~ADDStudentWindow();
protected slots:
    void on_pushButton_exit_clicked();
    void on_pushButton_add_clicked();
protected:
    void clear_field();
};

#endif // ADDWINDOW_H
