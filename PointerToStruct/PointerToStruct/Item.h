#pragma once
#include "stdafx.h"
// библиотека для описания пользовательского типа

//объявляем структуру, пользовательский тип данных
struct Item{
	string name;		// 28 байт
	int key;			// 4 байта
	int info[100];		// 4*100 = 400 байт
	bool operator < (Item item){
		return key < item.key;
	}
	// оператор спавнения структуры с целым числом по полю key
	bool operator == (int k){
		return key == k;
	}
}; // итого в памяти занимает 432 байта


//оператов вывода в поток (файл)
ostream& operator <<(ostream &fout, Item item){
	fout << item.key;
	return fout;
}

//создание случайного объекта типа Item
void Random(Item& item){
	item.name = "Item";
	item.key = rand() % 100;
	for (int i = 0; i < 100; i++)
		item.info[i] = rand() % 10;
}


// !!!!!!!! ВАЖНО !!!!!!
// функции void Random(Item& item) и void Random(float &f) из файла float.h 
// нельзя объединить в шаблон, так как у них разные алгоритмы реализации


// шаблон вспомогательной функции для пирамидальной сортировки,
// которая перестраивает дерево, делая его упорядоченным
void pShift_NoTemplate(Item **t, int L, int R){
	int i = L;
	Item *temp = t[L];
	while (i < (R + 1) / 2){
		int j = 2 * i + 1;
		if (j < R && (t[j]->key) < (t[j + 1]->key)) // без вызова оператора, напрямую обращаемся к полю
			j++;
		if ((temp->key) < (t[j]->key)){				// без вызова оператора, напрямую обращаемся к полю
			t[i] = t[j];					// меняем только адреса
			i = j;
			continue;
		}
		break;
	}
	t[i] = temp;
}

//шаблон функции пирамидальной сортировки
template <class Type>
void pSortPyramid_NoTemplate(Type **t, int n){
	int R = n - 1;
	int L = n / 2 - 1;
	for (; L >= 0; L--)
		pShift_NoTemplate(t, L, R);
	L = 0;
	for (; R > 0;){
		Item*temp = t[0]; t[0] = t[R]; t[R] = temp;		
		R--;
		pShift_NoTemplate(t, L, R);
	}
}


void Shift_NoTepmlate(Item *t, int L, int R){
	int i = L;
	Item temp = t[L];
	while (i < (R + 1) / 2){
		int j = 2 * i + 1;
		if (j < R && t[j].key < t[j + 1].key) j++; // без вызова оператора, напрямую обращаемся к полю
		if (temp.key < t[j].key){			// без вызова оператора, напрямую обращаемся к полю
			t[i] = t[j];				// меняем объекты
			i = j;
			continue;
		}
		break;
	}
	t[i] = temp;
}

//шаблон функции пирамидальной сортировки
template <class Type>
void SortPyramid_NoTemplate(Type *t, int n){
	int R = n - 1;
	int L = n / 2 - 1;
	for (; L >= 0; L--)
		Shift_NoTepmlate(t, L, R);
	L = 0;
	for (; R > 0;){
		Item temp = t[0]; t[0] = t[R]; t[R] = temp;
		R--;
		Shift_NoTepmlate(t, L, R);
	}
}