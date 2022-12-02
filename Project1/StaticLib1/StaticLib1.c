


#include "pch.h"
#include "framework.h"
#include <stdio.h>
#include "Header.h"
#include<locale.h>

// TODO: Это пример библиотечной функции.
void printsa() {
	setlocale(LC_ALL, "Russian");
	printf("Нестеров Евгений Андреевич ВИ921Б взято отсюда");
	return 0;
}
