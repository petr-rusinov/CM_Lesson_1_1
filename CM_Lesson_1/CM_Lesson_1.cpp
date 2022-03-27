#include <iostream>
#include <optional>
#include <vector>
#include <fstream>

#include "Person.h"
#include "PhoneNumber.h"
#include "PhoneBook.h"

using namespace std;


void main()
{
    ifstream file("Phonebook1.txt"); // ���� � ����� PhoneBook.txt
    PhoneBook book(file);
    cout << book;
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;
    
    // ������ �������, ������� ��������� ������� � ������� ����� �������� ����� ��������, ���� ������ � �������
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

    // ������ ������
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
        PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
        PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;

}

