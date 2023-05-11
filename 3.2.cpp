#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;
/* 
�������� �������, ������� ����� ��������� �� ���� ������ � ���������� ������, 
���������� ��� ����.�� ����, ���� �� ���� ���� ������� �������� ������ "Cat", 
�� ������� ������ ������� "CatCat".
��� ���� ����� �������� ��������� �������, ������� ������ ������ ���� � �� ��, 
�� ���������� ��������� ������� ��������.
*/

string repeat1(string_view a) {
    //������ ��������� �� ���� ������ � ���������� ���������.
    return string{a} + string{a};
}

void repeat2(string& a) {
    //������ ��������� �� ���� ������ �� ������ � �������� ��� ������.
    a += a;
}

void repeat3(string* pa) {
    //������ ��������� �� ���� ��������� �� ������ � �������� ������, ��� ����� ������ ���� ���������.
    *pa += *pa;
}

string* repeat4(string_view a) {
    /*
    * ��� ������� ������ ��������� ��������� ������ � ���� � ������� ��������� new
    � ���������� ��������� �� ��. ����� ������ ������� repeat4 �����������, 
    ������� ����� ������������ ��� ������� ��� ������ ������������ �� � ��������.
    */

    string* b = new string{a}; /*�������� new ���������� ��������� �� ������,
                               {} - ������ ���������������
                               ������������� ������ ��������� �������� ����������*/
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
