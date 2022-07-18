#include "Student.h"

double Student::get_average() const
{
    return _average;
}

const QString &Student::get_FIO() const
{
    return _FIO;
}

QString Student::to_qstring() const
{
    return _FIO + " " + QString::number(round(_average*10)/10.0);
}

std::wstring Student::to_file_string() const
{
    auto answer = _FIO.toStdWString() + (wchar_t)',';
    for (auto i : _arr){
        answer += std::to_wstring(i) + (wchar_t)' ';
    }
    answer += '\n';
    return answer;
}

bool Student::operator<(const Student &right)const{
    return std::lexicographical_compare(_FIO.begin(), _FIO.end(), right._FIO.begin(), right._FIO.end());
}
bool Student::operator>(const Student &right)const{
    return right < *this;
}

bool Student::operator==(const Student &right) const
{
    return _FIO == right._FIO;
}

bool Student::operator<=(const Student &right) const
{
    return *this < right || *this == right;
}

bool Student::operator>=(const Student &right) const
{
    return *this > right || *this == right;
}

bool Student::operator!=(const Student &right) const
{
    return !(*this == right);
}
Student::Student()
{

}

Student::Student(QString&& _FIO, std::vector<int>&& _arr) noexcept: _FIO(_FIO), _arr(_arr) {
    double sum = 0;
    auto it = _arr.begin(), end = _arr.end();
    while (it!=end){
        sum += *it;
        ++it;
    }
    _average = sum/_arr.size();
}

Student::Student(const QString &_FIO, const std::vector<int> &_arr) noexcept:_FIO(_FIO), _arr(_arr) {
    double sum = 0;
    auto it = _arr.begin(), end = _arr.end();
    while (it!=end){
        sum += *it;
        ++it;
    }
    _average = sum/_arr.size();
}

const std::vector<int> &Student::get_arr() const {
    return _arr;
}
