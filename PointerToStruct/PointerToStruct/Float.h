#pragma once
#include "stdafx.h"

// ���������� - ���������� ��� ����� float

// ��������� ���������� ������������� �����
void Random(float &f){ f = (float)(rand() % 100); }



// !!!!!!!! ����� !!!!!!
// ������� void Random(Item& item) �� ����� Item.h  � void Random(float &f) 
// ������ ���������� � ������, ��� ��� � ��� ������ ��������� ����������