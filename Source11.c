#include <stdio.h>


int main(void)
{
	int a = 0x15;
//	double
//	float, int.long;
	printf("%f\n", a);
	printf("%i\n", a);
	printf("%li\n", a);
	 a = -1;
	 printf("%i\n", a);
	 printf("%u\n\n", a);
	 double z = 0.12345;
	 printf("%i\n", z);
	 printf("%u", z);
	//int, unsigned int;
	 for (int i = -200; i < 200; i++) { printf("%i\t%u\n", i,i); }
	
	return 0;
}