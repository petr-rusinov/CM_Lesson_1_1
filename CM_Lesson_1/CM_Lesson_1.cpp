#include <iostream>
#include <optional>
#include <vector>
#include <fstream>

#include "Person.h"
#include "PhoneNumber.h"
#include "PhoneBook.h"

using namespace std;






/*
int main_1()
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
    return 0;
}
*/

void main()
{
    ifstream file("Phonebook1.txt"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    cout << book;
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;
    
    // лямбда функция, которая принимает фамилию и выводит номер телефона этого человека, либо строку с ошибкой
    auto print_phone_number = [&book](const string& surname)
    {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };

    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
        PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
        PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;

}

