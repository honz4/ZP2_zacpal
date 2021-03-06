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
long double dradek=0.0L, dsum=0.0L;
char buf[1024+1];
int done = 0;
int done2, len;
char *pch;


fvstup = fopen(vstup, "r");
if (fvstup == NULL ) {
    perror("otevreni vstupu");
    exit(EXIT_FAILURE);
    }


fvystup = fopen(vystup, "w");
if (fvystup == NULL ) {
    perror("otevreni vystupu");
    exit(EXIT_FAILURE);
    }


while (!done) {
pch = fgets(buf, 1024, fvstup)  ;
if (pch == NULL) {
    break;

}
//printf("%s", buf)  ; // continue;
dradek = 0.0L;
done2 = 0;
while (!done2) {
n = sscanf(pch, "%Lf%n", &d, &len);
// printf("n = %i, d= %Lg\n", n, d);
switch (n) {  //switch pro jedno nactene cislo z radku
    case 1: dradek += d;
    pch += len;
    //printf("d = %Lf\n", d);
    break;
    case EOF:
        done2 = 1; break;
    case 0:
    default: //printf("n = %i", n);
        done2 = 1;
}
}
fprintf( fvystup, "%Lf\n", dradek);
dsum += dradek;  //mame jeden radek
}
fprintf(fvystup, "Suma:  %Lg", dsum);
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
