#pragma once
#include <iostream>
#include <optional>

using namespace std;

struct PhoneNumber
{
    int countryCode;
    int cityCode;
    string number;
    optional<int> additionalNum;
    friend ostream& operator << (ostream& out, const PhoneNumber& pn);
    friend bool operator < (const PhoneNumber& a, const PhoneNumber& b);
    friend bool operator == (const PhoneNumber& a, const PhoneNumber& b);

};
