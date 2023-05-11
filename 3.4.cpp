/*�������� ������� void truncateToDot(std::string& s), 
������� ����� ��������� ������ �� ������ � ������� � �� ������� ������� �����. 
������ � ����������� ������ ������ ����� ��� ����� ����� ����������.
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