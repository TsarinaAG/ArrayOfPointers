// PointerToStruct.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Item.h"
#include "Float.h"
#include "TemplateStruct.h"
#include "TemplatePointer.h"

// SortPyramyd.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "TemplateStruct.h"

int _tmain(int argc, _TCHAR* argv[])
{	
	setlocale(LC_ALL, "Russian");

	// проверка работы функций сортировки
	int n = 10;		// количество элементов массива

	// массивы элементов
	float* A_float = Create<float>(n); // массив вещественных чисел (размер n*4 байта)
	Item *A_Item = Create<Item>(n);    // массив структру (размер n*432 байта)

	// массивы адресов (указателей)
	float **pA_float = pCreate<float>(n);	// массив указателей на вещественные числа (размер n*4 байта)
	Item **pA_Item = pCreate<Item>(n);	// массив указателей на структуры (размер n*4 байта)
	
	Check(SortPyramid, A_float, n);
	Check(SortPyramid, A_Item, n);	
	cout << endl;
	pCheck(pSortPyramid, pA_float, n);
	pCheck(pSortPyramid, pA_Item, n);
	delete[]A_float;
	delete[]A_Item;
	pDelete(pA_float, n);
	pDelete(pA_Item, n);

	// анализ времени	
	n = 100000;		// количество элементов массива

	// массивы элементов
	A_float = Create<float>(n); // массив вещественных чисел (размер n*4 байта)
	A_Item = Create<Item>(n);    // массив структру (размер n*432 байта)

	// массивы адресов (указателей)
	pA_float = pCreate<float>(n);	// массив указателей на вещественные числа (размер n*4 байта)
	pA_Item = pCreate<Item>(n);	// массив указателей на структуры (размер n*4 байта)
		
	cout << "Время, затраченное на пирамидальную сортировку массива вещественных чисел: " << TimeSort(SortPyramid, A_float, n) << endl;	
	cout << "Время, затраченное на пирамидальную сортировку массива структур: " << TimeSort(SortPyramid, A_Item, n) << endl;	
	cout << endl;
	cout << "Время, затраченное на пирамидальную сортировку массива указателей на вещественные числа: " << pTimeSort(pSortPyramid, pA_float, n) << endl;	
	cout << "Время, затраченное на пирамидальную сортировку массива указателей на структуры: " << pTimeSort(pSortPyramid, pA_Item, n) << endl;	
	cout << endl;
	// при этом необходимо обратить внимание на то, что большое количество времени тратится на обращение к оператору сравнения.
	// Если сравнивать по времени функции на основе шаблона и без него, то приоритет за функциями реализованными непосредственно для структуры/класса
	// так как они не тратят время на лишние вызовы:
	cout << "ЭКОНОМИЯ НА ВЫЗОВЕ ОПЕРАТОРА!" << endl;
	cout << "Время, затраченное на пирамидальную сортировку массива структур без шаблона: " << TimeSort(SortPyramid_NoTemplate, A_Item, n) << endl;
	cout << "Время, затраченное на пирамидальную сортировку массива указателей на структуры: " << pTimeSort(pSortPyramid_NoTemplate, pA_Item, n) << endl;

	delete[]A_float;
	delete[]A_Item;
	pDelete(pA_float, n);
	pDelete(pA_Item, n);
	return 0;
}
