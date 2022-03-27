#pragma once
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