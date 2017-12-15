#include "stdafx.h"
#include "06Practica_6.h"

int Tools::countWords(char *cad) {
	int count = 0;
	ifstream file("Read.txt");
	char str[255];

	while (file.getline(str, 255))
	{
		if (!strcmp(str, cad))
			count++;
	}

	return count;
}

int Tools::sumNumbers() {
	ifstream file("ReadNumbers.txt");
	char str[255];
	int sum = 0;
	while (file.getline(str, 255))
	{
		stringstream ss(str);
		int i;
		while (ss >> i) {
			sum += i;
			if (ss.peek() == ',')
				ss.ignore();
		}
	}
	return sum;
}

TList* Tools::getNumbers() {
	TList* list = new TList();
	ifstream file("ReadNumbers.txt");
	char str[255];
	int values[255];
	int index = 0;
	int sum = 0;
	string a = "";
	int step = 0;
	while (file.getline(str, 255))
	{
		stringstream ss(str);
		int i;
		while (ss >> i) {
			int val = i;
			values[index] = val;
			index++;
			if (ss.peek() == ',')
				ss.ignore();
		}
	}
	while (step < index) {
		a = to_string(values[step]);
		list->Push(a.c_str());
		step++;
	}

	return list;
}