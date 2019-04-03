#pragma once
#include "stdafx.h"
// ���������� ��������� �� ������ � �������� ��������



// ������ ��� ���� ��������� �� ������� - ��������� �����! �������, �������
// �� ���������� �������� �������� � ����� ��� ���������:
// 1) ������ ��������, �� ����� �������� ������� ��� �������
// 2) ����� �����
template<class Type>
using functionSort = void(*) (Type*t, int n);

// ������ ������� �������� ������� �� n ���������,
// ��� ���� � ����������� ���� Type ������ ���� ��������� ������� Random
template <class Type>
Type *Create(int n){
	Type*res = new Type[n];
	for (int i = 0; i < n; i++)
		Random(res[i]);
	return res;
}

// ������ ������� ������ �� �����,
// ��� ���� ��� ���� Type ������ ���� ���������� �������� ������ � ����� 
template <class Type>
void Write(Type *a, int n){
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << endl;
}

// ������ ������� ����� ���������� ����� ����� �����������
template <class Type>
void Swap(Type &a, Type &b){
	Type temp = a; a = b; b = temp;
}

// ������ ��������������� ������� ��� ������������� ����������,
// ������� ������������� ������, ����� ��� �������������
template <class Type>
void Shift(Type *t, int L, int R){
	int i = L;
	Type temp = t[L];
	while (i < (R + 1) / 2){
		int j = 2 * i + 1;
		if (j < R && t[j] < t[j + 1]) j++;
		if (temp < t[j]){
			t[i] = t[j];
			i = j;
			continue;
		}
		break;
	}
	t[i] = temp;
}

//������ ������� ������������� ����������
template <class Type>
void SortPyramid(Type *t, int n){
	int R = n - 1;
	int L = n / 2 - 1;
	for (; L >= 0; L--)
		Shift(t, L, R);
	L = 0;
	for (; R > 0;){
		Swap(t[0], t[R]);
		R--;
		Shift(t, L, R);
	}
}

// ������ �������, ������� ���������� ����� ������ ���������� ������� f,
// ������� ������������ ������ �� n ��������� A 
template <class Type>
clock_t TimeSort(functionSort<Type> f, Type *A, int n){
	clock_t t1 = clock();
	f(A, n);
	clock_t t2 = clock();
	return t2 - t1;
}

// ������ �������, ������� ���������� ������������ ������ ���������� ������� f,
// ������� ������������ ������ �� n ��������� A, ������ ��������� �� ������ �� �����
template <class Type>
void Check(functionSort<Type> f, Type *A, int n){
	Write(A, n);
	f(A, n);
	Write(A, n);
}