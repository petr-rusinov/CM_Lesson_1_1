#pragma once
#include <iostream>
#include <optional>
#include <vector>
#include <fstream>

#include "Person.h"
#include "PhoneNumber.h"
#include "PhoneBook.h"

using namespace std;





class PhoneBook
{
private:
    vector<pair<Person, PhoneNumber>> phoneBook;
    void splitStr(char* buf, vector<string>& parsedData);


public:
    PhoneBook(ifstream& ifs);

    friend ostream& operator << (ostream& out, PhoneBook pb);
    void SortByName();
    void SortByPhone();
    //tuple<string, PhoneNumber> getPhoneNumber(string lastName);

    void changePhoneNumber(Person person, PhoneNumber number);

};
