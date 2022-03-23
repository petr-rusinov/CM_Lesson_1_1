#include <iostream>
#include <optional>

using namespace std;

struct Person
{
    string lastName;
    string firstName;
    optional<string> middleName;
    friend ostream& operator << (ostream& out, const Person& person);
    friend bool operator < (const Person& a, const Person& b);
    friend bool operator == (const Person& a, const Person& b);
};

ostream& operator << (ostream& out, const Person& person)
{
    cout << person.lastName << "\t" << person.firstName << "\t";
    if (person.middleName)
        cout << person.middleName.value();

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

int main()
{
    std::cout << "Hello World!\n";

    Person p;
    p.firstName = "Peter";
    p.lastName = "Rusinov";
    p.middleName = "Vladimirovich";
    cout << p << endl;
    Person f{ "Ivanov", "Ivan", "Petrovich" };
    cout << f << endl;
    cout << boolalpha << (f < p) << endl;
    cout << boolalpha << (f == p) << endl;
    Person pp{ "Rusinov" , "Peter", "Vladimirovich" };
    cout << boolalpha << (pp == p) << endl;
    Person z{ "Petrov", "Nick", nullopt };
    cout << z << endl;
}

