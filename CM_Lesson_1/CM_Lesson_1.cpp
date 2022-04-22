#include <iostream>
#include <optional>
#include <vector>
#include <fstream>
#include <tuple>

#include "Person.h"
#include "PhoneNumber.h"
#include "PhoneBook.h"
#include <gtest/gtest.h>
using namespace std;

TEST(PhoneBook, GetPhoneNumber)
{

    ifstream file("Phonebook1.txt"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);

    auto answer = book.GetPhoneNumber("Ilin");
    PhoneNumber number{ 7, 17, "4559767" };
    ASSERT_TRUE(get<1>(answer) == number);
    
    answer = book.GetPhoneNumber("Zaitsev");
    number = { 125, 44, "4164751" };
    ASSERT_TRUE(get<1>(answer) == number);
}

TEST(PhoneBook, ChangePhoneNumber)
{
    ifstream file("Phonebook1.txt"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    PhoneNumber number = { 7, 123, "15344458" };
    auto answer = book.GetPhoneNumber("Kotov");
    ASSERT_FALSE(get<1>(answer) == number);


    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
        PhoneNumber{ 7, 123, "15344458", nullopt });
    answer = book.GetPhoneNumber("Kotov");
    ASSERT_TRUE(get<1>(answer) == number);
}


int main()
{
    testing::InitGoogleTest();

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

    
    return RUN_ALL_TESTS();
}

