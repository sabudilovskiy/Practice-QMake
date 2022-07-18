#include "ui_ADDStudentWindow.h"
#include "ADDStudentWindow.h"
#include <vector>
#include <QMessageBox>


ADDStudentWindow::ADDStudentWindow(StudentController& student_controller, QWidget *parent) :
    QWidget(parent),
    student_controller(student_controller), ui(new Ui::ADDStudentWindow)
{
    ui->setupUi(this);
    marks_spin_boxes.push_back(ui->spinBox_1);
    marks_spin_boxes.push_back(ui->spinBox_2);
    marks_spin_boxes.push_back(ui->spinBox_3);
    marks_spin_boxes.push_back(ui->spinBox_4);
    marks_spin_boxes.push_back(ui->spinBox_5);
}

ADDStudentWindow::~ADDStudentWindow()
{
    delete ui;
}

void ADDStudentWindow::clear_field(){
    ui->FIO_textEdit->setText("");
    for (auto spin_box : marks_spin_boxes){
        spin_box->setValue(2);
    }
}

void ADDStudentWindow::on_pushButton_add_clicked(){
    QString fio = ui->FIO_textEdit->toPlainText();
    if (fio.length()>0){
        std::vector<int> marks;
        for (auto spin_box : marks_spin_boxes){
            marks.push_back(spin_box->value());
        }
        try {
            student_controller.add(Student(fio, marks));
        }
        catch (std::invalid_argument& except){
            QMessageBox message_box;
            message_box.setWindowIcon(QIcon(":/icons/icons/error.ico"));
            message_box.critical(0, "Невозможно добавить", "Студент уже в базе");
        }
        clear_field();
    }
    else {
        QMessageBox message_box;
        message_box.critical(0, "Невозможно добавить", "Вы не ввели фамилию");
   }
}
void ADDStudentWindow::on_pushButton_exit_clicked()
{
    ADDStudentWindow::hide();
}

