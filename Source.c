#include <stdio.h>
#include <locale.h>
int main(void)
{
	setlocale(LC_ALL, "Russian");
	char simbol = 'a';
	while (simbol < 'z' + 1) {
		printf(" Simbol= %c=%d\n", simbol, simbol);
		simbol += 1;
	}
	printf("\n\n");
		simbol = 'A';
		while (simbol < 'Z' + 1) {
			printf(" Simbol= %c=%d\n", simbol, simbol);
			simbol += 1;
		}
		printf("\n\n");
		simbol = '�';
		while (simbol < '�' + 1) {
			printf(" Simbol= %c=%d\n", simbol, simbol);
			simbol += 1;
		}
	
		printf("\n\n");
		simbol = '�';
		while (simbol < '�' + 1) {
			printf(" Simbol= %c=%d\n", simbol, simbol);
			simbol += 1;
		}
		printf("\n\n");
		simbol = '�';
		while (simbol < '�' + 1) {
			printf(" Simbol= %c=%d\n", simbol, simbol);
			simbol += 1;
		}
	return 0;
}