#include <cctype>
#include <string_view>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Используйте операторы new или new[], чтобы создать в куче и сразу инициализировать следующие объекты:
Напечатайте все созданные объекты на экран.
Удалите все созданные объекты с помощью операторов delete и delete[].
*/

int main() {
    // Один объект типа int, равный 123.
    int* a = new int(123);
    // Один объект типа std::string, равный "Cats and Dogs".
    string* b = new string("Cats and Dogs");
    // Маcсив объектов типа int, равный {10, 20, 30, 40, 50}.
    int* c = new int[5]{ 10, 20, 30, 40, 50 };

    for (size_t i = 0; i < 5; ++i) {
        cout << c[i] << endl;
    }

    //Маcсив объектов типа std::string, равный {"Cat"{}, "Dog"{}, "Mouse"}.
    string* d = new string[3]{ "Cat", "Dog", "Mouse" };
    
    for (size_t i = 0; i < 3; ++i) {
        cout << d[i] << endl;
    }
    

    //Маcсив из 3-х объектов типа std::string_view, указывающих на строки из предыдущего пункта.

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
