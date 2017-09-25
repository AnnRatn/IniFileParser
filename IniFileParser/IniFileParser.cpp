// IniFileParser.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "InFile.cpp"


int main()
{
	wstring file, section1, section2, field;
	//cout << "Enter file name" << endl;
	//wcin >> file;
	InFile NewIni(L"text.txt");
	//cout << "Enter section name" << endl;
	//wcin >> section1;
	map<wstring, wstring> section = NewIni.GetSectionInf(L"Section1");

	for (auto it = section.begin(); it != section.end(); ++it) {
		wcout << (*it).first << "  " << (*it).second << endl; //Вывод ключей и значений
	}
	//cout << "Enter section name" << endl;
	//wcin >> section2;
	//cout << "Enter field name" << endl;
	//wcin >> field;
	wstring obj = NewIni.GetSectionFieldInf(L"Section2", L"tcp");
	wcout << obj << endl;
	system("pause");

	return 0;
}

