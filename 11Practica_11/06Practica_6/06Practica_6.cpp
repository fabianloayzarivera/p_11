// 06Practica_6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "06Practica_6.h"

int main()
{
	char *cad = "yes";
	int count = Tools::countWords(cad);
	cout <<"Word: "<<cad<< " Count: "<<count<<endl;
	int sum = Tools::sumNumbers();
	cout << "Numbers sum: " << sum<<endl;
	TList* list = Tools::getNumbers();
	cout << "List Size: "<<list->Size() << endl;
	delete(list);
	getchar();
    return 0;
}




