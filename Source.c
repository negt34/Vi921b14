#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int z = 0,v=0,s=0,v1=0,s1=0;
	int a[8][8] = { 1,1,1,1,1,1,1,1,
				    1,0,0,0,1,1,3,1,
				    1,0,0,0,0,0,0,1,
				    1,0,0,1,1,0,0,1,
				    1,0,1,0,0,0,0,1,
				    1,0,1,0,1,0,0,1,
				    1,4,0,0,1,0,0,1,
				    1,1,1,1,1,1,1,1 };
		while (!z)
	{
			for ( v = 0; v <8; v++) {
				for ( s = 0; s < 8; s++) {
					int c = a[v][s];
					switch (c)
					{
					case 0: printf(" "); break;
					case 1:printf("*"); break;
					case 3:printf("@"); break;
					case 4:printf("+"), v1 = v;s1=s; break;
					}	
				}
				printf("\n");
			}
			int q = getch();
			system("cls");
		//printf("char%d", q);
		switch (q)
			{
		case  (int)'A':case (int)'a':case 148: case 228:/* printf("влево");*/ if (a[v1][s1 - 1] != 1) {
			
			if (a[v1][s1 - 1] == 3) { system("cls"); printf("Игра пройдена"); z = 1; }
			a[v1][s1] = 0; a[v1][s1 - 1] = 4; };
		break;
		case (int)'D':case 162: case 130: case (int)'d':/*printf("вправо");*/ if (a[v1][s1 + 1] != 1) {
				if(a[v1][s1 + 1] == 3) { system("cls"); printf("Игра пройдена"); z = 1;
				};
				a[v1][s1] = 0; a[v1][s1 + 1] = 4;
			}; break;
		case (int)'w':case (int)'W':case 150: case 230 :/*printf("вверх"); */if (a[v1 - 1][s1] != 1) {
				if (a[v1 - 1][s1] == 3) { system("cls"); printf("Игра пройдена"); z = 1;
				};
				a[v1][s1] = 0; a[v1-1][s1 ] = 4;
			}; break;
		case (int)'s':case (int)'S':case 155: case 235:/* printf("вниз");*/ if (a[v1+1][s1 ] != 1) {
					if (a[v1 + 1][s1] == 3) { system("cls"); printf("Игра пройдена"); z = 1;
					};
				a[v1][s1] = 0; a[v1+1][s1 ] = 4;
			}; break;
			}	
	}

}