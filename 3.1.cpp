/*
Напишите функцию, которая будет принимать на вход строку и возвращать строку с изменённым регистром первой буквы.
Например, если на вход пришла строка {"Cat"}, то функция должна вернуть строку {"cat"}.

Если на вход пришла строка {"dog"}, то функция должна вернуть строку {"Dog"}.
Если на вход пришла пустая строка, то функция должна вернуть простую строку.
*/

#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <utility>
#include <string>

using namespace std;

string registr(string s) {
	//string* s_res;
	//s_res = new string;

	if (s == ("")) {
		return s;
	}
	else {
		if (std::islower(s[0])) 
		{
			s[0] = std::toupper(s[0]);
		}
		else
		{
			s[0] = std::tolower(s[0]);
		}
		return s;
	}
}

int main(int argc, char** argv)
{
	string s;	
	std::getline(std::cin, s);
	std::cout << registr(s);
	return 0;
}