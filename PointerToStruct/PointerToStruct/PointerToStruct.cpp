// PointerToStruct.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Item.h"
#include "Float.h"
#include "TemplateStruct.h"
#include "TemplatePointer.h"

// SortPyramyd.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include "TemplateStruct.h"

int _tmain(int argc, _TCHAR* argv[])
{	
	setlocale(LC_ALL, "Russian");

	// �������� ������ ������� ����������
	int n = 10;		// ���������� ��������� �������

	// ������� ���������
	float* A_float = Create<float>(n); // ������ ������������ ����� (������ n*4 �����)
	Item *A_Item = Create<Item>(n);    // ������ �������� (������ n*432 �����)

	// ������� ������� (����������)
	float **pA_float = pCreate<float>(n);	// ������ ���������� �� ������������ ����� (������ n*4 �����)
	Item **pA_Item = pCreate<Item>(n);	// ������ ���������� �� ��������� (������ n*4 �����)
	
	Check(SortPyramid, A_float, n);
	Check(SortPyramid, A_Item, n);	
	cout << endl;
	pCheck(pSortPyramid, pA_float, n);
	pCheck(pSortPyramid, pA_Item, n);
	delete[]A_float;
	delete[]A_Item;
	pDelete(pA_float, n);
	pDelete(pA_Item, n);

	// ������ �������	
	n = 100000;		// ���������� ��������� �������

	// ������� ���������
	A_float = Create<float>(n); // ������ ������������ ����� (������ n*4 �����)
	A_Item = Create<Item>(n);    // ������ �������� (������ n*432 �����)

	// ������� ������� (����������)
	pA_float = pCreate<float>(n);	// ������ ���������� �� ������������ ����� (������ n*4 �����)
	pA_Item = pCreate<Item>(n);	// ������ ���������� �� ��������� (������ n*4 �����)
		
	cout << "�����, ����������� �� ������������� ���������� ������� ������������ �����: " << TimeSort(SortPyramid, A_float, n) << endl;	
	cout << "�����, ����������� �� ������������� ���������� ������� ��������: " << TimeSort(SortPyramid, A_Item, n) << endl;	
	cout << endl;
	cout << "�����, ����������� �� ������������� ���������� ������� ���������� �� ������������ �����: " << pTimeSort(pSortPyramid, pA_float, n) << endl;	
	cout << "�����, ����������� �� ������������� ���������� ������� ���������� �� ���������: " << pTimeSort(pSortPyramid, pA_Item, n) << endl;	
	cout << endl;
	// ��� ���� ���������� �������� �������� �� ��, ��� ������� ���������� ������� �������� �� ��������� � ��������� ���������.
	// ���� ���������� �� ������� ������� �� ������ ������� � ��� ����, �� ��������� �� ��������� �������������� ��������������� ��� ���������/������
	// ��� ��� ��� �� ������ ����� �� ������ ������:
	cout << "�������� �� ������ ���������!" << endl;
	cout << "�����, ����������� �� ������������� ���������� ������� �������� ��� �������: " << TimeSort(SortPyramid_NoTemplate, A_Item, n) << endl;
	cout << "�����, ����������� �� ������������� ���������� ������� ���������� �� ���������: " << pTimeSort(pSortPyramid_NoTemplate, pA_Item, n) << endl;

	delete[]A_float;
	delete[]A_Item;
	pDelete(pA_float, n);
	pDelete(pA_Item, n);
	return 0;
}
