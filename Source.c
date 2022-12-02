#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>
#include<stdlib.h>
//int m = 1;
//int main(int argc, char *argv[]) {
//	int m = 5;
//	printf("%i\n", m);
//		return 0;
//}
int selectfigure = 4;
HANDLE hSTd;
COORD point;
COORD pointf;
HANDLE hout;
int selectpos = 0;
int selectable = 0;
int shag = 0;
//8x8
int a[10][10] = {
	1,1,1,1,1,1,1,1,1,1,
	1,2,3,2,3,2,3,2,3,1,//1
	1,3,2,3,2,3,2,3,2,1,//2
	1,2,3,2,3,2,3,2,3,1,//3
	1,3,2,3,2,3,2,3,2,1,//4
	1,2,3,2,3,2,3,2,3,1,//5
	1,3,2,3,2,3,2,3,2,1,//6
	1,2,3,2,3,2,3,2,3,1,//7
	1,3,2,3,2,3,2,3,2,1,//8
	1,1,1,1,1,1,1,1,1,1
};
int main(void)
{
	 selectable = 0;
	setlocale(LC_ALL, "Russian");
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	point.X = 0; point.Y = 0;
	int v1 = 0;
	//for (int v = 0; v < 10; v++) { 
	//	
	//	for (int s = 0; s < 10; s++) {
	//		if (a[v][s] == 1) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  BACKGROUND_RED);
	//		if (s == 0 || s == 9) {
	//			if (v == 0 || v == 9) { printf(" "); }
	//			else
	//			{
	//				printf("%d", v);
	//			} 
	//		}
	//		else
	//		{
	//			int q = (int)'a';
	//			printf("%c",q+s-1);
	//		}
	//		}
	//		if (a[v][s] == 3) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_RED); printf("3"); }
	//		if (a[v][s] == 2) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN|BACKGROUND_INTENSITY | FOREGROUND_RED); printf("2"); }
	//	}
	//	printf("\n");
	//}
	draw();
//закончили рисовать доску
	
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
point.Y = 10;
SetConsoleCursorPosition(hout, point); 
	printf("выберите фигуру\n1)ферзь\n2)ладья\n3)слон\n4)конь");
	point.Y = 14;
	SetConsoleCursorPosition(hout, point);
	
	
	mooving();
		//закончили выбирать фигуру
	//system("cls"); draw();
		point.Y = 15;
		point.X =0 ;
		SetConsoleCursorPosition(hout, point);
		printf("выберите позицию для фигуры");

		point.Y = 1;
		point.X = 1;
		selectable = 0;
		SetConsoleCursorPosition(hout, point);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE| FOREGROUND_RED); printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); printf("");
		while (!selectable) {
	
			int sele = _getch();
			switch (sele)
			{
			case (int)'W':case (int)'w':case 150: case 230: if (point.Y>1) {
				system("cls");
				point.Y = point.Y - 1; draw(); SetConsoleCursorPosition(hout, point); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); printf("");
				
			}
						 else
			{
				SetConsoleCursorPosition(hout, point);
			}; break;
			case (int)'s':case (int)'S':case 155: case 235: if (point.Y<8) {
				system("cls");
				point.Y = point.Y + 1; draw(); SetConsoleCursorPosition(hout, point); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); printf(" "); 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); printf("");
				
			}
						 else
			{
			//	SetConsoleCursorPosition(hout, point); 
			}break;
			case (int)'D':case (int)'d':case 162: case 130: if (point.X < 8) {
				system("cls");
				point.X = point.X + 1; draw(); SetConsoleCursorPosition(hout, point); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); printf("");
			}
						 else
			{
				SetConsoleCursorPosition(hout, point);
			}; break;


			case (int)'a':case (int)'A':case 148: case 228: if (point.X > 1) {
				system("cls");
				point.X = point.X - 1; draw(); SetConsoleCursorPosition(hout, point); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); printf(" ");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); printf("");

			}
						 else
			{
				SetConsoleCursorPosition(hout, point);
			}; break;


			case 13: selectable = 1; pointf = point; 
				SetConsoleCursorPosition(hout, pointf); selectpos = 1; system("cls"); draw(); moovingpointer(); 
				pravilohoda(); 
				if (shag) {
					setfigure();
				}	int sele = _getch();

			 break;
			}
	}
	
	/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE | FOREGROUND_RED);
	printf("text");*/

};
int setfigure(void) {
	switch (selectfigure)
	{
	case 1:SetConsoleCursorPosition(hout, pointf);  printf("Ф");
		break;
	case 2:SetConsoleCursorPosition(hout, pointf);  printf("Л");
		break;
	case 3:SetConsoleCursorPosition(hout, pointf);  printf("С");
		break;
	case 4:SetConsoleCursorPosition(hout, pointf);  printf("K");
		break;
	};
	
	
	if (pointf.Y == 1 && pointf.X == 8) {
		point.Y = 12, point.X = 1; SetConsoleCursorPosition(hout, point); printf("вот и пришли");
	
	
	}
}
int draw(void) {
	for (int v = 0; v < 10; v++) {

		for (int s = 0; s < 10; s++) {
			if (a[v][s] == 1) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
				if (s == 0 || s == 9) {
					if (v == 0 || v == 9) { printf(" "); }
					else
					{
						printf("%d", v);
					}
				}
				else
				{
					int q = (int)'a';
					printf("%c", q + s - 1);
				}
			}
			if (a[v][s] == 3) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); printf(" "); }
			if (a[v][s] == 2) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_RED); printf(" "); }
		}
		printf("\n");
	}
	if (selectpos) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); printf("");/* pravilohoda(); */if (shag) { setfigure(); } }
	else
	{

	}

}
int mooving() {
	
	while (!selectable) {
		int sele = _getch();
		switch (sele)
		{
		case (int)'W':case (int)'w':case 150: case 230: if (selectfigure > 1) {
			point.Y = point.Y - 1; selectfigure = selectfigure - 1;
			SetConsoleCursorPosition(hout, point);
		}
					 else
		{
			SetConsoleCursorPosition(hout, point);
		}; break;
		case (int)'s':case (int)'S':case 155: case 235: if (selectfigure < 4) {
			point.Y = point.Y + 1; selectfigure = selectfigure + 1;
			SetConsoleCursorPosition(hout, point);
		}
					 else
		{
			SetConsoleCursorPosition(hout, point);
		}; break;
		case 13: selectable = 1; break;
		}
	}
}
int moovingpointer(void) 
{
	selectable = 0;

	while (!selectable) {
		selectable = 0;
	/*	SetConsoleCursorPosition(hout, point);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED); printf(" ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); printf(" ");*/
		setfigure();
		int sele = _getch();
		switch (sele)
		{
		case (int)'W':case (int)'w':case 150: case 230: if (point.Y > 1) {
			system("cls");
			point.Y = point.Y - 1; draw(); SetConsoleCursorPosition(hout, point); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);/* printf(" ");*/
		}
					 else
		{
			SetConsoleCursorPosition(hout, point);
		}; break;
		case (int)'s':case (int)'S':case 155: case 235: if (point.Y < 8) {
			system("cls");
			point.Y = point.Y + 1; draw(); SetConsoleCursorPosition(hout, point); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);/* printf(" ");*/
		}
					 else
		{
			//	SetConsoleCursorPosition(hout, point); 
		}break;
		case (int)'D':case (int)'d':case 162: case 130: if (point.X < 8) {
			system("cls");

			point.X = point.X + 1; draw(); SetConsoleCursorPosition(hout, point); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); /*printf(" ");*/
		}
					 else
		{
			SetConsoleCursorPosition(hout, point);
		}; break;
		case (int)'a':case (int)'A':case 148: case 228: if (point.X > 1) {
			system("cls");
			point.X = point.X - 1; draw(); SetConsoleCursorPosition(hout, point); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE); printf(" ");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); /*printf(" ");*/
		}
					 else
		{
			SetConsoleCursorPosition(hout, point);
		}; break;
		case 13: selectable = 0;
			pravilohoda();
			if (shag) {
				pointf = point;
				SetConsoleCursorPosition(hout, pointf); selectpos = 1; /* setfigure();*/
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED); printf(" ");	system("cls"); draw(); /*int sele = _getch();*/
				selectable = 0;
			}
			break;
		}
	}
}
int pravilohoda(void) {
	shag = 0;
	switch (selectfigure)
	{
	case 1:if (point.X == pointf.X && point.Y != pointf.Y) { shag = 1; };
		  if (point.X != pointf.X && point.Y == pointf.Y) { shag = 1; }; 
		  if (abs(pointf.X - point.X) == abs(pointf.Y - point.Y)) { shag = 1; }; break;
	case 2:
		if (point.X == pointf.X && point.Y != pointf.Y) { shag = 1; };
		if (point.X != pointf.X && point.Y == pointf.Y) { shag = 1; };
		
		break;
	case 3:	if (abs(pointf.X-point.X)==abs(pointf.Y-point.Y)) { shag = 1; };
		  break;
	case 4:if (abs(pointf.X - point.X)==2 && abs(pointf.Y - point.Y) == 1) { shag = 1; };
		  if (abs(pointf.X - point.X) == 1 && abs(pointf.Y - point.Y) == 2) { shag = 1; };
		  break;
	}
}