/*
Напишите перегруженный оператор умножения, которая будет принимать на вход строку std::string
и некоторое целое число n и возвращать строку, повторённую n раз. 
Протестируйте эту функцию в функции main.
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

string operator * (const string& str, size_t n) {
    string result = "";
    for (size_t i = 0; i < n; ++i) {
        result += str;
    }
    return result;
}

int main() {
    /*bool TestTask3() {*/
        string str = "Test";
        size_t count = 10;


        cout << count * str << endl;

        vector<string> data;
        vector<string> test_data;

        string p;
        //p.clear();

        for (size_t i = 0; i < count; ++i) {
            data.push_back(p);
            p += str;
        }

        for (size_t i = 0; i < count; ++i) {
            test_data.push_back(str * i);
        }

        return bool(test_data == data);
   // }
}