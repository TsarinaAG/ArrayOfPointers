#pragma once
#include "stdafx.h"
// ���������� ��� �������� ����������������� ����

//��������� ���������, ���������������� ��� ������
struct Item{
	string name;		// 28 ����
	int key;			// 4 �����
	int info[100];		// 4*100 = 400 ����
	bool operator < (Item item){
		return key < item.key;
	}
	// �������� ��������� ��������� � ����� ������ �� ���� key
	bool operator == (int k){
		return key == k;
	}
}; // ����� � ������ �������� 432 �����


//�������� ������ � ����� (����)
ostream& operator <<(ostream &fout, Item item){
	fout << item.key;
	return fout;
}

//�������� ���������� ������� ���� Item
void Random(Item& item){
	item.name = "Item";
	item.key = rand() % 100;
	for (int i = 0; i < 100; i++)
		item.info[i] = rand() % 10;
}


// !!!!!!!! ����� !!!!!!
// ������� void Random(Item& item) � void Random(float &f) �� ����� float.h 
// ������ ���������� � ������, ��� ��� � ��� ������ ��������� ����������


// ������ ��������������� ������� ��� ������������� ����������,
// ������� ������������� ������, ����� ��� �������������
void pShift_NoTemplate(Item **t, int L, int R){
	int i = L;
	Item *temp = t[L];
	while (i < (R + 1) / 2){
		int j = 2 * i + 1;
		if (j < R && (t[j]->key) < (t[j + 1]->key)) // ��� ������ ���������, �������� ���������� � ����
			j++;
		if ((temp->key) < (t[j]->key)){				// ��� ������ ���������, �������� ���������� � ����
			t[i] = t[j];					// ������ ������ ������
			i = j;
			continue;
		}
		break;
	}
	t[i] = temp;
}

//������ ������� ������������� ����������
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
		if (j < R && t[j].key < t[j + 1].key) j++; // ��� ������ ���������, �������� ���������� � ����
		if (temp.key < t[j].key){			// ��� ������ ���������, �������� ���������� � ����
			t[i] = t[j];				// ������ �������
			i = j;
			continue;
		}
		break;
	}
	t[i] = temp;
}

//������ ������� ������������� ����������
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