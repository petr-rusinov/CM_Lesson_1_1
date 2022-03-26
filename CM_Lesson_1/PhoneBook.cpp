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
        while (!ifs.eof()) //это убрать?
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

            //что-то сделать с данными
            //for (string s : vs)
            //    cout << s << " ";
            //cout << endl;
        }
    }

}


void PhoneBook::SortByName()
{
    //sort(phoneBook.begin(), phoneBook.end(), [](const Person& p1, const Person& p2)->bool { return false; });
}
void PhoneBook::SortByPhone()
{

}
//tuple<string, PhoneNumber> getPhoneNumber(string lastName)
//{
//    return tie()
//}

void PhoneBook::changePhoneNumber(Person person, PhoneNumber number)
{

}


ostream& operator << (ostream& out, PhoneBook pb)
{
    for (auto p : pb.phoneBook)
    {
        out << p.first << "\t" << p.second << endl;
    }


    return out;
}
