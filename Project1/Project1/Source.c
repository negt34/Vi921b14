#include <locale.h>
//#include "print.h"
#include "../StaticLib1/Header.h"
int main(void) {
	setlocale(LC_ALL, "Russian");
	printsa(); return 0;
}