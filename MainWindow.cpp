#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QFileDialog>
#include <codecvt>
#include <fstream>
#include <locale>
#include <filesystem>
#include <qmessagebox.h>
#include <sstream>
MainWindow::MainWindow(StudentController& student_controller, QWidget *parent)
    : QMainWindow(parent)
    , student_controller(student_controller), add_student_window(student_controller),
      tree_non_balance_window("Бинарное дерево поиска", student_controller.get_tree_non_balance()),
      tree_balance_window("АВЛ дерево поиска", student_controller.get_tree_balance()),
      lexical_list_window("Студенты в лексикографическом порядке", student_controller.get_list_lexical()),
      excellent_list_window("Студенты имеющие отлично и остальные", student_controller.get_list_excellent()),
      best_list_window("Лучшие студенты", student_controller.get_list_max()),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowIcon(QIcon(":/icons/rocket.ico"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_addStudent_clicked()
{
    add_student_window.show();
}


void MainWindow::on_pushButton_lexicoList_clicked()
{
    lexical_list_window.show();
}


void MainWindow::on_pushButton_excellentList_clicked()
{
    excellent_list_window.show();
}


void MainWindow::on_pushButton_bestList_clicked()
{
    best_list_window.show();
}


void MainWindow::on_pushButton_tree_clicked()
{
    tree_non_balance_window.show();
}


void MainWindow::on_pushButton_treeBalanced_clicked()
{
    tree_balance_window.show();
}


void MainWindow::on_toolButton_load_path_clicked()
{
    QString temp = QFileDialog::getOpenFileName();
    ui->textBrowser_load_path->setText(temp);
}


void MainWindow::on_toolButton_save_path_clicked()
{
    QString temp = QFileDialog::getOpenFileName();
    ui->textBrowser_save_path->setText(temp);
}


void MainWindow::on_pushButton_load_clicked()
{
    std::wstring path = ui->textBrowser_load_path->text().toStdWString();
    if (path.empty()){
        QMessageBox message_box;
        message_box.critical(0, "Не возможно открыть файл", "Вы не ввели путь");
        message_box.setFixedSize(300, 200);
        return;
    }
    if (!std::filesystem::exists(path)){
        QMessageBox message_box;
        message_box.critical(0, "Не возможно открыть файл", "Файл не существует");
        message_box.setFixedSize(300, 200);
        return;
    }
    std::wifstream file(path);
    if (!file.is_open()){
        QMessageBox message_box;
        message_box.critical(0, "Не возможно открыть файл", "Недостаточно прав");
        message_box.setFixedSize(300, 200);
        return;
    }
    file.imbue(std::locale("ru_RU.UTF-8"));
    bool error = false;
    student_controller.clear();
    try{
        while (!file.eof() && !error){
            std::wstring buffer;
            std::getline(file, buffer);
            if (!buffer.empty()){
                int i = 0;
                int n = buffer.size();
                while (i < n && buffer[i]!=','){
                    i++;
                }
                if (i != n){
                    std::vector<int> marks;
                    QString fio = QString::fromStdWString(buffer.substr(0, i));
                    std::wstring marks_string = buffer.substr(i+1, n-i-1);
                    std::wstringstream ss(marks_string);
                    while (!ss.eof()){
                        int mark;
                        ss >> mark;
                        marks.push_back(mark);
                    }
                    Student student(std::move(fio), std::move(marks));
                    student_controller.add(student);
                }
            }
        }
    }
    catch (...){
        error = true;
    }
    if (!error){
        QMessageBox message_box;
        message_box.information(0, "Успешно", "Файл успешно загружен" );
        return;
    }
    else {
        QMessageBox message_box;
        message_box.critical(0, "Не возможно считать данные", "Файл повреждён");
        message_box.setFixedSize(300, 200);
        student_controller.clear();
        return;
    }
}


void MainWindow::on_pushButton_save_clicked()
{
    std::wstring path = ui->textBrowser_save_path->text().toStdWString();
    if (path.empty()){
        QMessageBox message_box;
        message_box.critical(0, "Не возможно открыть файл", "Вы не ввели путь");
        message_box.setFixedSize(300, 200);
        return;
    }
    if (!std::filesystem::exists(path)){
        QMessageBox message_box;
        message_box.critical(0, "Не возможно открыть файл", "Файл не существует");
        message_box.setFixedSize(300, 200);
        return;
    }
    std::wofstream file;
    file.imbue(std::locale("ru_RU.UTF-8"));
    file.open(path, std::ios::out);
    if (!file.is_open()){
        QMessageBox message_box;
        message_box.critical(0, "Не возможно открыть файл", "Недостаточно прав");
        message_box.setFixedSize(300, 200);
        return;
    }
    if (file.is_open()){
        auto it = student_controller.get_list_lexical().begin(), end = student_controller.get_list_lexical().end();
        while (it!=end){
            auto temp = it->to_file_string();
            file << temp;
            file.flush();
            it++;
        }
        file.close();
        QMessageBox message_box;
        message_box.information(0, "Успешно", "Файл успешно сохранён" );
        return;
    }
}


void MainWindow::on_pushButton_clear_clicked()
{
    student_controller.clear();
}


