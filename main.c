#include <locale.h>
#include "print.h"
int main(void) {
	setlocale(LC_ALL, "Russian");
	prints();
	return 0;
}