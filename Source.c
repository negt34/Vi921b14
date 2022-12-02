#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#define LengArr 10
int mas[LengArr] ;

COORD point;
HANDLE hout;

int main(void) {
	setlocale(LC_ALL, "Russian");
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	point.X = 0; point.Y = 1;
	printf("выберите сортировку\n1)пузырь\n2)шейкер\n3)расчестка\n4)вставка");
	SetConsoleCursorPosition(hout, point);
	int selectable = 0, selectеtipe = 1;
	while (!selectable) {
		int sele = _getch();
		switch (sele)
		{
		case (int)'W':case (int)'w':case 150: case 230: if (selectеtipe > 1) {
			point.Y = point.Y - 1; selectеtipe = selectеtipe - 1;
			SetConsoleCursorPosition(hout, point);
		}
					 else
		{
			SetConsoleCursorPosition(hout, point);
		}; break;
		case (int)'s':case (int)'S':case 155: case 235: if (selectеtipe < 4) {
			point.Y = point.Y + 1; selectеtipe = selectеtipe + 1;
			SetConsoleCursorPosition(hout, point);
		}
					 else
		{
			SetConsoleCursorPosition(hout, point);
		}; break;
		case 13: selectable = 1; break;
		}
	}
	srand(time(NULL));
	point.Y = 6;
	SetConsoleCursorPosition(hout, point);
	for (int i = 0; i < LengArr; i++)
	{
		mas[i] = 1 + rand() % 100;
	}
	for (int i = 0; i < LengArr; i++)
	{
		printf("%i ", mas[i]);
	}
	
	printf("\n");
	
	switch (selectеtipe){
	case 1:bubleSortF(); break;
	case 2:shakeF();	 break;
	case 3:combF(); break;
	case 4:insertF(); break;
	}
	
	for (int i = 0; i < LengArr; i++)
	{
		printf("%i ", mas[i]);
	}
}


int bubleSortF()
{
	int sch = 0, res = 0;
	do
	{
		sch = 0;
		for (int i = 0; i < LengArr - 1; i++)
		{
			if (mas[i] <= mas[i + 1]) {}
			else
			{
				res = mas[i]; mas[i] = mas[i + 1];
				mas[i + 1] = res;
				sch = 1;

			}
		}
	} while (sch);
}
int shakeF() {
	int sch = 0, res = 0;
	do
	{
		sch = 0;
		for (int i = 0; i < LengArr - 1; i++)
		{
			if (mas[i] <= mas[i + 1]) {}
			else
			{
				res = mas[i]; mas[i] = mas[i + 1];
				mas[i + 1] = res;
				sch = 1;

			}
		}
		for (int i = 0; i < LengArr; i++)
		{
			printf("%i ", mas[i]);
		}
		printf("\n");
		for (int i = LengArr - 2; i >1; i--)
		{
			if (mas[i] >= mas[i - 1]) {}
			else
			{
				res = mas[i]; mas[i] = mas[i - 1];
				mas[i - 1] = res;
				sch = 1;

			}
		}
		for (int i = 0; i < LengArr; i++)
		{
			printf("%i ", mas[i]);
		}
		printf("\n");
	} while (sch);

}

int combF() {
	int sch = 0, res = 0,
	shag = 5;

	do
	{
		sch = 0;
		for (int i = 0; i < LengArr - shag; i++)
		{
			if (mas[i] <= mas[i + shag]) {}
			else
			{
				res = mas[i]; mas[i] = mas[i + shag];
				mas[i + shag] = res;
				sch = 1;

			}
		}
		for (int i = 0; i < LengArr; i++)
		{
			printf("%i ", mas[i]);
		}
		printf("\n");
		if (shag > 1) { shag--; }
	} while (sch||shag>1);

}
int insertF() {
	int leng = 1, sch = 0, next = 0, res = 0, i = 0;
	
		while (!next)
		{
			if (mas[sch] <= mas[sch + 1])
			{
				leng = leng + 1;
				sch++;
			}
			else { next = 1; };
		}

	/*	for (int i = leng - 1; i < LengArr; i++)
		{
			for (int s = leng-1; s>0; s--) {
				if (mas[s] <= mas[i+1]) {

					res = mas[i+1 ];
					for (int sch1 = 0; sch > sch1;sch1++) {
						mas[i - sch1 ] = mas[i - sch1-1];
					}
					mas[i - sch] = res;
				
				}
				else { sch += 1; };
			}

		}*/
		do {
			res = mas[leng];
			i = leng;
			while (res < mas[i - 1]) { mas[i] = mas[i - 1]; i -= 1; };
			mas[i] = res;
			leng++;
			for (int i = 0; i < LengArr; i++)
			{
				printf("%i ", mas[i]);
			}
			printf("\n");
		} while (leng<LengArr);
}