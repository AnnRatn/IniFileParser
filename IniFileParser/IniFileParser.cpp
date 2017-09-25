// IniFileParser.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "InFile.cpp"


int main()
{
	setlocale(LC_ALL, "English");
	InFile NewIni("text.txt");
	map<string, string> section = NewIni.GetSectionInf("Section1");
	for (auto& it : section) {
		cout << it.first << "  " << it.second << endl;
	}
	auto obj = NewIni.GetSectionFieldInf("Section1", "tcp");
	cout << obj << endl;
	system("pause");
}

