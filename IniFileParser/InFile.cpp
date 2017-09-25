#include "stdafx.h"

class InFile {

private:
	map<string, map<string, string>> information;

public:
	map<string, string> GetSectionInf(string SecNum) {
		try {
			return information.find(SecNum)->second;
		}
		catch (exception) {
			cout << "There is no this section";
		}
	}

	auto GetSectionFieldInf(string SecNum, string SecField) {
		map<string, string> Section = GetSectionInf(SecNum);
		return Section.find(SecField)->second;
	}

	InFile(string file) {
		ifstream reader;
		try
		{
			reader.open(file);
			map<string, string> new_map;
			string SectionName;
			//пока файл не закончился, считываем
			while (reader) {
				string str;
				//считали строку
				getline(reader, str);
				if (str[0] == '[') {
					if (!new_map.empty()) {
						information.insert(pair<string, map<string, string>>(SectionName, new_map));
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
					char* FieldName = (char*)malloc((position - 1) * sizeof(char));
					char* FieldValue = (char*)malloc((str.size() - (position + 1)) * sizeof(char));
					str.copy(FieldName, 0, position - 1);
					str.copy(FieldValue, position + 1, (str.size() - (position + 1)));
					new_map.insert(pair<string, string>(FieldName, FieldValue));
				}
			}
			information.insert(pair<string, map<string, string>>(SectionName, new_map));
		}
		catch (exception ex) {
			cout << ex.what();
		}
	}

	~InFile() {
		information.clear();
	}
};