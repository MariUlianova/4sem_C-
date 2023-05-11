#include <ctype.h>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

/* 
Напишите функцию, которая принимает на вход строку в следующем формате: "[num1, num2, ... numN]".
Функция должна возвращать целое число типа int -- сумму всех чисел в квадратных скобках. 
В случае, если на вход приходит некорректная строка, то функция должна бросать исключение std::invalid_argument. 
Протестируйте эту функцию в main. Ловить исключение необязательно.
*/

int SumFromLine(const string& str) {
    if (str.empty() || (str.front() != '[') || (str.back() != ']')) {
        throw invalid_argument(str);
        //Выражение throw сигнализирует о том, что в try блоке произошло исключительное условие ( часто ошибка). 
        //В качестве операнда throw выражения можно использовать объект любого типа. 
    }

    int sum = 0;
    int number = 0;
    size_t i = 1;
    bool flag = true; //прочитали ли лмы число полностью

    while (i < str.size() - 1) { //пока массив не закончился
        if (!(isdigit(str[i]) || str[i] == ',' || str[i] == ' ')) { //не цифра не запятая не пустая
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