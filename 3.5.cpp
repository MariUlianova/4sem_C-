#include <ctype.h>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

/* 
�������� �������, ������� ��������� �� ���� ������ � ��������� �������: "[num1, num2, ... numN]".
������� ������ ���������� ����� ����� ���� int -- ����� ���� ����� � ���������� �������. 
� ������, ���� �� ���� �������� ������������ ������, �� ������� ������ ������� ���������� std::invalid_argument. 
������������� ��� ������� � main. ������ ���������� �������������.
*/

int SumFromLine(const string& str) {
    if (str.empty() || (str.front() != '[') || (str.back() != ']')) {
        throw invalid_argument(str);
        //��������� throw ������������� � ���, ��� � try ����� ��������� �������������� ������� ( ����� ������). 
        //� �������� �������� throw ��������� ����� ������������ ������ ������ ����. 
    }

    int sum = 0;
    int number = 0;
    size_t i = 1;
    bool flag = true; //��������� �� ��� ����� ���������

    while (i < str.size() - 1) { //���� ������ �� ����������
        if (!(isdigit(str[i]) || str[i] == ',' || str[i] == ' ')) { //�� ����� �� ������� �� ������
            throw invalid_argument(str);
        }
        if (flag) {
            number *= 10;
            number += str[i] - '0';
            if (!isdigit(str[i + 1])) {
                flag = false;
                sum += number;
                number = 0;
            }
            i++;
            continue;
        }

        if (!flag) {
            if (str[i] == ',' && str[i + 1] == ' ') {
                i += 2;
                flag = true;
            }
            else {
                throw invalid_argument(str);
            }
        }
    }
    sum += number;
    return sum;
}

int main()
{
    vector <string> test_data = {
        "[10, 20, 30, 40, 50]",
        "[4, 8, 15, 16, 23, 42]",
        "[20]",
        "[0]",
    };

    vector<int> result;

    for (const auto& str : test_data) {
        result.push_back(SumFromLine(str));
    }

    vector <int> reference_data = {
        150, 108, 20, 0
    };

    return result == reference_data;
}