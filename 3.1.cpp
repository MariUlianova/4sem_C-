/*
�������� �������, ������� ����� ��������� �� ���� ������ � ���������� ������ � ��������� ��������� ������ �����.
��������, ���� �� ���� ������ ������ {"Cat"}, �� ������� ������ ������� ������ {"cat"}.

���� �� ���� ������ ������ {"dog"}, �� ������� ������ ������� ������ {"Dog"}.
���� �� ���� ������ ������ ������, �� ������� ������ ������� ������� ������.
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