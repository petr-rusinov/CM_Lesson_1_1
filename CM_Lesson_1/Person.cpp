#include "Person.h"
#include <iomanip>

ostream& operator << (ostream& out, const Person& person)
{
    out << setw(11) << person.lastName << " " << setw(10) << person.firstName << " ";

    if (person.middleName)
        out << setw(14) << person.middleName.value();

    return out;
}

bool operator < (const Person& a, const Person& b)
{
    return tie(a.lastName, a.firstName, a.middleName) < tie(b.lastName, b.firstName, b.middleName);
}

bool operator == (const Person& a, const Person& b)
{
    return !(a < b) && !(b < a);
}
