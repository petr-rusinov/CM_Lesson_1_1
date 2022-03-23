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

struct PhoneNumber
{
    int countryCode;
    int cityCode;
    string number;
    optional<int> additionalNum;
    friend ostream& operator << (ostream& out, PhoneNumber pn);
    friend bool operator < (const PhoneNumber& a, const PhoneNumber& b);
    friend bool operator == (const PhoneNumber& a, const PhoneNumber& b);

};

ostream& operator << (ostream& out, PhoneNumber pn)
{
    cout << "+" << pn.countryCode << "(" << pn.cityCode << ")" << pn.number;
    if (pn.additionalNum)
        cout << " " << pn.additionalNum.value();

    return out;
}

bool operator < (const PhoneNumber& a, const PhoneNumber& b)
{
    return tie(a.countryCode, a.cityCode, a.number, a.additionalNum) < tie(b.countryCode, b.cityCode, b.number, b.additionalNum);
}

bool operator == (const PhoneNumber& a, const PhoneNumber& b)
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

    PhoneNumber pn1{ 7, 495, "1112233", 7 };
    PhoneNumber pn2{ 7, 495, "3334455", 10 };
    cout << pn1 << endl;
    cout << pn2 << endl;
    cout << boolalpha << (pn1 == pn2) << endl;
    cout << boolalpha << (pn1 < pn2) << endl;
}

