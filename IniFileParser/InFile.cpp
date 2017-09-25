#include "stdafx.h"

class InFile {

private:
	map<wstring, map<wstring, wstring>> information;

public:
	/*��������� ���������� � ������*/
	map<wstring, wstring> GetSectionInf(wstring SecNum) {
		try {
			return information.find(SecNum)->second;
		}
		catch (exception) {
			cout << "There is no this section";
		}
	}

	/*��������� ���������� � ���������� ���� ��������� ������*/
	wstring GetSectionFieldInf(wstring SecNum, wstring SecField) {
		try {
			map<wstring, wstring> Section = GetSectionInf(SecNum);
			return Section.find(SecField)->second;
		}
		catch (exception) {
			cout << "There is no this section";
		}
	}

	/*�����������, ������������ ����������� �����*/
	InFile(wstring file) {
		wifstream reader;
		try
		{
			reader.open(file);
			map<wstring, wstring> new_map;
			wstring SectionName;
			while (reader) {
				wstring str;
				getline(reader, str);
				if (str[0] == '[') {
					if (!new_map.empty()) {
						information.insert(pair<wstring, map<wstring, wstring>>(SectionName, new_map));
						new_map.clear();
						str.erase(0, 1);
						str.erase(str.size() - 1, 1);
						SectionName = str;
					}
					else {
						str.erase(0, 1);
						str.erase(str.size() - 1, 1);
						SectionName = str;
					}
				}
				else {
					int position = str.find_first_of(' ');
					if (position != -1){
					wchar_t* FieldName = (wchar_t*)calloc((position - 1) , sizeof(wchar_t));
					wchar_t* FieldValue = (wchar_t*)calloc((str.size() - (position + 1)) , sizeof(wchar_t));
					str.copy(FieldName, 0, position - 1);
					str.copy(FieldValue, position + 1, (str.size() - (position + 1)));
					new_map.insert(pair<wstring, wstring>(FieldName, FieldValue));
					delete(FieldName);
					delete(FieldValue);
					}
				}
			}
			information.insert(pair<wstring, map<wstring, wstring>>(SectionName, new_map));
		}
		catch (exception ex) {
			cout << ex.what();
		}
	}

	/*���������� ������*/
	~InFile() {
		information.clear();
	}
};