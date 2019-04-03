#pragma once
#include "stdafx.h"

// библиотека - надстройка над типом float

// генерация случайного вещественного числа
void Random(float &f){ f = (float)(rand() % 100); }



// !!!!!!!! ВАЖНО !!!!!!
// функции void Random(Item& item) из файла Item.h  и void Random(float &f) 
// нельзя объединить в шаблон, так как у них разные алгоритмы реализации