#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;



int main()
{
    const char* str = "Белеет парус одинокий в тумане моря голубом!";
    stringstream strin;
    strin << str;
    string strout = "";
    string word;
    while (strin >> word)
    {
        if (word.length() >= 5) {
            reverse(word.begin(), word.end());
        }
        strout += word + ' ';
    }
    strout.pop_back();
    cout << str << endl;
    cout << strout.c_str();
}
