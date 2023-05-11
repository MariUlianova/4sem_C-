#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;
/* 
Напишите функции, которые будут принимать на вход строку и возвращать строку, 
повторённую два раза.То есть, если на вход этой функции приходит строка "Cat", 
то функция должна вернуть "CatCat".
При этом нужно написать несколько функций, которые должны делать одно и то же, 
но возвращать результат разными методами.
*/

string repeat1(string_view a) {
    //Должна принимать на вход строку и возвращать результат.
    return string{a} + string{a};
}

void repeat2(string& a) {
    //Должна принимать на вход строку по ссылке и изменять эту строку.
    a += a;
}

void repeat3(string* pa) {
    //Должна принимать на вход указатель на строку и изменять строку, чей адрес хранит этот указатель.
    *pa += *pa;
}

string* repeat4(string_view a) {
    /*
    * Эта функция должна создавать удвоенную строку в куче с помощью оператора new
    и возвращать указатель на неё. После вызова функции repeat4 программист, 
    который будет использовать эту функцию сам должен позаботиться об её удалении.
    */

    string* b = new string{a}; /*оператор new возвращает указатель на объект,
                               {} - список инициализаторов
                               Инициализатор задает начальное значение переменной*/
    *b += *b;
    return b;
}

int main()
{
        string s = "Cat";
        string ans = "CatCat";

        bool repeat1_right = (repeat1(s) == ans);

        string r2;
        repeat2(r2);
        bool repeat2_right = (s == ans);

        string r3;
        repeat3(&r3);
        bool repeat3_right = (r3 == ans);

        string* r4 = repeat4(s);
        bool repeat4_right = (*r4 == ans);
        delete r4;

        return repeat1_right;
}
