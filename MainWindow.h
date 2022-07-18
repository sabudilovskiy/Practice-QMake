#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ADDStudentWindow.h"
#include "AVLWindow.h"
#include "ListWindow.h"
#include <StudentController.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    StudentController& student_controller;
    ADDStudentWindow add_student_window;
    AVLWindow tree_non_balance_window, tree_balance_window;
    ListWindow lexical_list_window, excellent_list_window, best_list_window;
    Ui::MainWindow *ui;
public:
    MainWindow(StudentController& student_controller, QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_clear_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_load_clicked();
    void on_toolButton_save_path_clicked();
    void on_toolButton_load_path_clicked();
    void on_pushButton_treeBalanced_clicked();
    void on_pushButton_tree_clicked();
    void on_pushButton_bestList_clicked();
    void on_pushButton_excellentList_clicked();
    void on_pushButton_lexicoList_clicked();
    void on_pushButton_addStudent_clicked();
};
#endif // MAINWINDOW_H
