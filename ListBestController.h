#ifndef LISTMAXCONTROLLER_H
#define LISTMAXCONTROLLER_H
#include "ListController.h"

class ListBestController : public ListController
{
    double max = -1;
public:
    ListBestController(List<Student>& list);
    void put_after(const Student &student, std::function<bool (const Student &, const Student &)> pred) override;
    void put_before(const Student &student, std::function<bool (const Student &, const Student &)> pred) override;
    void put_begin(const Student &student) override;
    void clear() override;
};

#endif // LISTMAXCONTROLLER_H
