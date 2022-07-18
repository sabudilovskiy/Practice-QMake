#ifndef STUDENT_H
#define STUDENT_H
#include<QString>
#include<vector>
class Student
{
    QString _FIO;
    std::vector<int> _arr;
    double _average;
public:
    Student();
    Student(QString&& _FIO, std::vector<int>&& _arr) noexcept;
    Student(const QString& _FIO, const std::vector<int>& _arr) noexcept;
    double get_average() const;
    const QString& get_FIO() const;
    QString to_qstring() const;
    std::wstring to_file_string() const;
    const std::vector<int> &get_arr() const;
    bool operator<(const Student& right) const;
    bool operator>(const Student& right) const;
    bool operator==(const Student& right) const;
    bool operator<=(const Student& right) const;
    bool operator>=(const Student& right) const;
    bool operator!=(const Student& right) const;
};


#endif // STUDENT_H
