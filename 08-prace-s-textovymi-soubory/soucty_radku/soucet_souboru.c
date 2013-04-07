#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
Napište v jazyku C funkci int soucty(const char *vstup, const char *vystup),
která čte ze vstupního souboru vstup desetinná čísla, počítá součty na jednotlivých řádcích a zapisuje je do výstupního souboru vystup.
Na konec výstupního souboru pak navíc vloží sumu všech čísel ve vstupním souboru.

http://jazykc.inf.upol.cz/prace-s-textovymi-soubory/soucty-radku.htm
*/

int soucty(const char *vstup, const char *vystup) {
FILE* fvstup;
FILE* fvystup;
int n;
long double d;
long double dsum=0.0L;
char buf[1024];
int done = 0;

fvstup = fopen(vstup, "r");
if ( fvstup == NULL ) {
    perror("otevreni vstupu");
    exit(EXIT_FAILURE);
}
fvystup = fopen(vystup, "w");
if ( fvystup == NULL ) {
    perror("otevreni vystupu");
    exit(EXIT_FAILURE);
}

while (!done) {
	//fgets(buf, 1024, fvstup)  ;
	//printf("%s \n", buf)  ; continue;
	n = fscanf(fvstup, "%Lf", &d);
	switch (n) {
	    case 1: dsum += d;
	//  printf("d = %Lf\n", d);
	    break;
	    case EOF:
		done = 1; break;
	    case 0:
	    default: printf("n = %L", n);
	}

}
//printf("d radek = %Lf\n", dsum);
 fprintf("Suma cisel v souboru %s je %Lg\n", vstup, dsum);
 fclose(fvstup);
 fclose(fvystup);
 return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("usage: %s vstup vystup\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    soucty(argv[1], argv[2]);
    return 0;
}
