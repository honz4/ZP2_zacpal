#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct komplexni{
    double realna;
    double imaginarni;
} komplexni;

komplexni suma(int pocet, ...){
	va_list param;
	va_start(param, pocet);

	komplexni sum = {0, 0};

    int i;
	for (i = 0;i<pocet;i++){
		komplexni temp = va_arg(param, komplexni);
		sum.realna += temp.realna;
		sum.imaginarni += temp.imaginarni;
	}

	va_end(param);
	return sum;
}

int main(){
	komplexni vysledek;
	komplexni a = {0.1,-3.7};
	komplexni b = {1.5,-1};
	komplexni c = {7,4.2};

	vysledek = suma(3,a,b,c);
	printf("Suma je %.2g + %.2gi. \n", vysledek.realna, vysledek.imaginarni);

	return 0;
}
