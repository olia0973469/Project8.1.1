// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1. Вияснити, чи є серед цих символів всі букви, що входять в слово “while”.
// 2. Замінити кожну групу букв “while” парою зірочок “**”.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* str)
{
	if (strlen(str) < 6)
		return 0;
	int k = 0;
	for (int i = 0; str[i + 4] != 0; i++)
		if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
			k++;
	return k;
}
char* Change(char* str)
{
	size_t len = strlen(str);
	if (len < 6)
		return str;
	char* tmp = new char[len * 2 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
		while (i < len - 5)
		{
			if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
			{
				strcat(t, "**");
				t += 2;
				i += 5;
			}
			else
			{
				*t++ = str[i++];
				*t = '\0';
			}
		}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy(str, tmp);
	return tmp;
}
int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of 'while'" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}
