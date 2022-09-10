#include <stdio.h>
#include <locale.h>
int main(void)
{
	setlocale(LC_ALL, "Russian");
	printf("Нестеров Евгений Андреевич, ВИ921Б");
	return 0;
}
