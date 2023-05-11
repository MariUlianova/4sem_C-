#include <cctype>
#include <string_view>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
����������� ��������� new ��� new[], ����� ������� � ���� � ����� ���������������� ��������� �������:
����������� ��� ��������� ������� �� �����.
������� ��� ��������� ������� � ������� ���������� delete � delete[].
*/

int main() {
    // ���� ������ ���� int, ������ 123.
    int* a = new int(123);
    // ���� ������ ���� std::string, ������ "Cats and Dogs".
    string* b = new string("Cats and Dogs");
    // ��c��� �������� ���� int, ������ {10, 20, 30, 40, 50}.
    int* c = new int[5]{ 10, 20, 30, 40, 50 };

    for (size_t i = 0; i < 5; ++i) {
        cout << c[i] << endl;
    }

    //��c��� �������� ���� std::string, ������ {"Cat"{}, "Dog"{}, "Mouse"}.
    string* d = new string[3]{ "Cat", "Dog", "Mouse" };
    
    for (size_t i = 0; i < 3; ++i) {
        cout << d[i] << endl;
    }
    

    //��c��� �� 3-� �������� ���� std::string_view, ����������� �� ������ �� ����������� ������.

    std::string_view sv{ "Cat" };
    //string_view* e = new string_view[3] {d[0], d[1], d[2]};
    
    for (size_t i = 0; i < 3; ++i) {
     //   cout << e[i] << endl;
    }
    

    delete a;
    delete b;
    delete[] c;
    delete[] d;
    //delete[] e;

    return 0;
}
