/*Напишите функцию void truncateToDot(std::string& s), 
которая будет принимать строку по ссылке и усекать её до первого символа точки. 
Размер и вместимость строки должны стать как можно более маленькими.
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

    void truncateToDot(string & a) {
        char point = '.';
        std::size_t pos = a.find(point);
        if (pos != string::npos) {
            a.erase(pos);
        }
    }

int main() {
        vector <string> test_data = {
            "cat.dog.mouse.elephant.tiger.lion",
            "wikipedia.org",
            ".com",
            "",
            "abcde"
        };

        for (auto& str : test_data) {
            truncateToDot(str);
        }

        vector <string> reference_data = {
            "cat",
            "wikipedia",
            "",
            "",
            "abcde"
        };

        return test_data == reference_data;
}