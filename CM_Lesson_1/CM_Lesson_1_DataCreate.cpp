// CM_Lesson_1_DataCreate.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void splitStr(char* buf, vector<string>& parsedData)
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

void getData(ifstream& f)
{
    int i = 0;
    const int strMaxSize = 255;
    char str[strMaxSize];
    vector<string> vs;

    if (f)
    {
        while (!f.eof())
        {
            for (int i = 0; !f.eof(); ++i)
            {
                f.getline(str, strMaxSize);
                vs.clear();
                splitStr(str, vs);

                //что-то сделать с данными
                for (string s : vs)
                    cout << s << " ";
                cout << endl;
            }
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
    char str[255];
    ifstream file;
    file.open("Phonebook1.txt");
    getData(file);



}


