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
    char buf[strMaxSize];
    vector<string> vs;
    Person p; PhoneNumber pn;
    int entryNum = 0;
    const int NUM_OF_ENTRIES = 7; //кол-во данных в строке

    if (ifs)
    {
        while (!ifs.eof())
        {
            ifs.getline(buf, strMaxSize);
            string str{ buf };
            int j = 0;
            entryNum = 0;
            pn.additionalNum = nullopt;
            for (i = 0; i != str.size(); ++i)
            {
                j = str.find_first_of(',', i);
                if (j == str.npos)
                    break;

                string s = str.substr(i, j - i);
                //разбираем данные
                switch (entryNum)
                {
                case 0:
                    p.lastName = s;
                    break;
                case 1:
                    p.firstName = s;
                    break;
                case 2:
                    p.middleName = s;
                    break;
                case 3:
                    pn.countryCode = stoi(s);
                    break;
                case 4:
                    pn.cityCode = stoi(s);
                    break;
                case 5:
                    pn.number = s;
                    break;
                case 6:
                    pn.additionalNum = stoi(s);
                    break;

                default:
                    break;
                }
                ++entryNum;
                i = j;
            }
            if (i > (NUM_OF_ENTRIES - 1) - 1) // -1 т.к. последняя запись (доб номер) не обязательна
            {
                //Все правильно прочитали
                phoneBook.push_back(pair(p, pn));
            }
            else
            {
                //кол-во данных не верное, значит, строка битая
                cout << "error reading data" << endl;
            }
        }
    }
}


void PhoneBook::SortByName()
{
    sort(phoneBook.begin(), phoneBook.end(), [](const pair<const Person&, const PhoneNumber&>& p1, 
                                                const pair<const Person&, const PhoneNumber&>& p2)->bool 
                                                { return p1.first < p2.first; });
}
void PhoneBook::SortByPhone()
{
    sort(phoneBook.begin(), phoneBook.end(), [](const pair<const Person&, const PhoneNumber&>& p1,
                                                const pair<const Person&, const PhoneNumber&>& p2)->bool
                                                { return p1.second < p2.second; });

}
tuple<string, PhoneNumber> PhoneBook::GetPhoneNumber(const string& lastName)
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

void PhoneBook::ChangePhoneNumber(const Person& person, const PhoneNumber& number)
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
