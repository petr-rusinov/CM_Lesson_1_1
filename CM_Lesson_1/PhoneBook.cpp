#include "PhoneBook.h"
#include <algorithm>
#include <string>

using namespace std;

void PhoneBook::splitStr(char* buf, vector<string>& parsedData)
{
    string str(buf);
    vector<string> vs;
    int j = 0;

    for (int i = 0; i != str.size(); ++i)
    {
        j = str.find_first_of(',', i);
        if (j == str.npos)
            break;

        string s = str.substr(i, j - i);
        parsedData.push_back(s);
        i = j;

    }
}

PhoneBook::PhoneBook(ifstream& ifs)
{
    int i = 0;
    const int strMaxSize = 255;
    char str[strMaxSize];
    vector<string> vs;

    if (ifs)
    {
        while (!ifs.eof())
        {
            ifs.getline(str, strMaxSize);
            vs.clear();
            splitStr(str, vs);
            Person p; PhoneNumber pn;
            p.lastName = vs[0];
            p.firstName = vs[1];
            p.middleName = vs[2];
            pn.countryCode = stoi(vs[3]);
            pn.cityCode = stoi(vs[4]);
            pn.number = vs[5];
            pn.additionalNum = 0;

            phoneBook.push_back(pair(p, pn));
        }
    }

}


void PhoneBook::SortByName()
{
    sort(phoneBook.begin(), phoneBook.end(), [](const pair<Person, PhoneNumber>& p1, 
                                                const pair<Person, PhoneNumber>& p2)->bool 
                                                { return p1.first < p2.first; });
}
void PhoneBook::SortByPhone()
{
    sort(phoneBook.begin(), phoneBook.end(), [](const pair<Person, PhoneNumber>& p1,
                                                const pair<Person, PhoneNumber>& p2)->bool
                                                { return p1.second < p2.second; });

}
tuple<string, PhoneNumber> PhoneBook::GetPhoneNumber(string lastName)
{
    int numEntries = 0;
    PhoneNumber pn;
    string foundStr;

    for_each(phoneBook.begin(), phoneBook.end(), [&](const auto& entry) 
                                                    {  
                                                        if (entry.first.lastName == lastName)
                                                        {
                                                            ++numEntries;
                                                            pn = entry.second;
                                                        }
                                                    });

    if (numEntries == 0)
    {
        foundStr = "not found";
    }
    else if (numEntries == 1)
    {
        foundStr = "";
    }
    else if (numEntries > 1)
    {
        foundStr = "found more than 1";
    }

    return make_tuple(foundStr, pn);
}

void PhoneBook::ChangePhoneNumber(Person person, PhoneNumber number)
{
    auto result = find_if(phoneBook.begin(), phoneBook.end(), [&](const auto& entry) { return entry.first == person; });
    if (result != phoneBook.end())
    {
        (*result).second = number;
    }
}


ostream& operator << (ostream& out, const PhoneBook& pb)
{
    for (auto p : pb.phoneBook)
    {
        out << p.first << "\t" << p.second << endl;
    }


    return out;
}
